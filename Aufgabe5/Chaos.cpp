#include <iostream>
#include <thread>

void lowerCaseLetters()
{
	char letter = 'a';
	for (int i = 0; i >= 0 && i < 26; i++)
	{
		std::cout << letter << "\n";
		letter++;
	}
}

void naturalNumbers()
{

	int number = 0;
	for (int cnt = 0; cnt >= 0 && cnt < 33; cnt++)
	{
		std::cout << number << std::endl;
		number++;
	}
}

void upperCaseLetters()
{
	char letter = 'A';
	for (int i = 0; i >= 0 && i < 26; i++)
	{
		std::cout << letter << "\n";
		letter++;
	}
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