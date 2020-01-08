#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>

class semaphore {
private:
	std::atomic<int> resourcecount;
	std::mutex MyMutex;
	std::condition_variable cv;
	
public:
	semaphore(int resourcecount)
	{
		this->resourcecount = resourcecount; // set the max count
	}

	void wait()
	{
		std::unique_lock<std::mutex> m(MyMutex);
		while (resourcecount == 0) {
			cv.wait(m);
		}
		resourcecount--;
		cv.notify_all();
	}

	void release() 
	{
		std::unique_lock<std::mutex> m(MyMutex);
		resourcecount++; // releasing the thread, thus the count has to be increased
		cv.notify_all();
	}
};

semaphore sema(1); // only one at a time so it's like a mutex

void lowerCaseLetters()
{
	sema.wait();	
	char letter = 'a';
	for (int i = 0; i >= 0 && i < 26; i++)
	{
		std::cout << letter << "\n"; // issues depending on "\n" and std::endl ?
		letter++;
	}
	sema.release();	
}

void naturalNumbers()
{
	sema.wait();	
	int number = 0;
	for (int cnt = 0; cnt >= 0 && cnt < 33; cnt++)
	{
		std::cout << number << "\n";
		number++;
	}
	sema.release();	
}

void upperCaseLetters()
{
	sema.wait();	
	char letter = 'A';
	for (int i = 0; i >= 0 && i < 26; i++)
	{
		std::cout << letter << "\n";
		letter++;
	}
	sema.release();	
}

int main()
{
	std::thread t1(lowerCaseLetters);
	std::thread t2(naturalNumbers);
	std::thread t3(upperCaseLetters);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}