#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <stdexcept>

using namespace std;

/**
 * @class Queue
 * @brief A thread-safe queue supporting a finite number of elements with blocking and non-blocking pop operations.
 *
 * @tparam T The type of elements stored in the queue.
 */
template <typename T>

class Queue {
public:
	/**
	 * @brief Constructor to initialize the queue with a given size.
	 *
	 * @param size The maximum number of elements the queue can hold.
	 */
	Queue(int size) : size(size), count(0), front(0), rear(0) {
		elements = new T[size];
	}

	/**
	 * @brief Destructor to clean up dynamic memory allocation.
	 */
	~Queue() {
		delete[] elements;
	}

	/**
	 * @brief Pushes an element into the queue. If the queue is full, it drops the oldest element.
	 *
	 * @param element The element to be pushed into the queue.
	 */
	void Push(T element) {
		unique_lock<mutex> lock(mtx);

		if (count == size) {
			front = (front + 1) % size; // Drop the oldest element
		}
		else {
			++count;
		}

		elements[rear] = element;
		rear = (rear + 1) % size;

		cond_var.notify_one();
	}

	/**
	 * @brief Pops an element from the queue. Blocks indefinitely if the queue is empty.
	 *
	 * @return The element popped from the queue.
	 */
	T Pop() {
		unique_lock<mutex> lock(mtx);

		cond_var.wait(lock, [this]() { return count > 0; });

		T element = elements[front];
		front = (front + 1) % size;
		--count;

		return element;
	}

	/**
	 * @brief Pops an element from the queue. Throws a timeout exception if the queue is empty for the specified duration.
	 *
	 * @param milliseconds The timeout duration in milliseconds.
	 * @return The element popped from the queue.
	 * @throws std::runtime_error If the queue is empty for the specified duration.
	 */
	T PopWithTimeout(int milliseconds) {
		unique_lock<mutex> lock(mtx);

		if (!cond_var.wait_for(lock, chrono::milliseconds(milliseconds), [this]() { return count > 0; })) {
			throw runtime_error("Timeout: No elements in queue");
		}

		T element = elements[front];
		front = (front + 1) % size;
		--count;

		return element;
	}

	/**
	 * @brief Returns the current number of elements in the queue.
	 *
	 * @return The number of elements currently in the queue.
	 */
	int Count() const {
		lock_guard<mutex> lock(mtx);
		return count;
	}

	/**
	 * @brief Returns the maximum number of elements the queue can hold.
	 *
	 * @return The maximum size of the queue.
	 */
	int Size() const {
		return size;
	}

private:
	T* elements;                    ///< Dynamic array to store queue elements.
	int size;                       ///< Maximum number of elements in the queue.
	int count;                      ///< Current number of elements in the queue.
	int front;                      ///< Index of the front element.
	int rear;                       ///< Index of the rear element.

	mutable mutex mtx;         ///< Mutex for thread synchronization.
	condition_variable cond_var; ///< Condition variable for blocking pop.
};

int main() {
	Queue<int> q(2);

	thread writer([&q]() {
		q.Push(1);
		this_thread::sleep_for(chrono::milliseconds(100));
		q.Push(2);
		this_thread::sleep_for(chrono::milliseconds(100));
		q.Push(3);
		this_thread::sleep_for(chrono::milliseconds(100));
		q.Push(4); // Element 2 dropped!
		this_thread::sleep_for(chrono::milliseconds(100));
		q.Push(5);
	});

	thread reader([&q]() {
		this_thread::sleep_for(chrono::milliseconds(150));
		cout << "Pop() -> " << q.Pop() << endl;
		this_thread::sleep_for(chrono::milliseconds(150));
		cout << "Pop() -> " << q.Pop() << endl;
		try {
			this_thread::sleep_for(chrono::milliseconds(150));
			cout << "PopWithTimeout() -> " << q.PopWithTimeout(200) << endl;
		}
		catch (const runtime_error& e) {
			cout << e.what() << endl;
		}
	});

	writer.join();
	reader.join();

	return 0;
}
