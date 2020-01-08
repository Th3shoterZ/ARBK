#include <iostream>
#include <thread>
#include <mutex>

std::mutex myMutex;

void lowerCaseLetters()
{
	myMutex.lock();
	char letter = 'a';
	for (int i = 0; i >= 0 && i < 26; i++)
	{
		std::cout << letter << "\n";
		letter++;
	}
	myMutex.unlock();
}

void naturalNumbers()
{
	myMutex.lock();
	int number = 0;
	for(int cnt = 0; cnt >= 0 && cnt < 33; cnt++)
	{
		std::cout << number << std::endl;
		number++;
	}
	myMutex.unlock();
}

void upperCaseLetters()
{
	myMutex.lock();
	char letter = 'A';
	for (int i = 0; i >= 0 && i < 26; i++)
	{
		std::cout << letter << "\n";
		letter++;
	}
	myMutex.unlock();
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