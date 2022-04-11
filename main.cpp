#include <iostream>
#include <thread>

using namespace std;
//untuk print number di thread
static int number;

int get_number(int i)
{
	return number = i;
}

//multi handled thread
void printed()
{
	using namespace literals::chrono_literals;

	if (number % 2 != 0)
	{
		cout << "Printed : " << number << endl;
		this_thread::sleep_for(1s);
	}
	else
	{
		cout << "Printed : " << number << endl;
		this_thread::sleep_for(2.5s);
	}
}

//single handled thread
void print_odd_thread()
{
	using namespace literals::chrono_literals;

	cout << "Thread " << number << " is working" << endl;
	this_thread::sleep_for(1s);
}

void print_even_thread()
{
	using namespace literals::chrono_literals;

	cout << "Thread " << number << " is working" << endl;
	this_thread::sleep_for(2.5s);
}

int main()
{
	//handler single thread
	for (int i = 1; i <= 20; i++)
	{
		get_number(i);
		if (i % 2 != 0)
		{
			//thread odd
			thread odd(print_odd_thread);
			odd.join(); //lanjut jika thread sebelumnya selesai
		}
		else
		{
			//thread even
			thread even(print_even_thread);
			even.join(); //lanjut jika thread sebelumnya selesai
		}
	}

	cout << "Thread Complete..." << endl;
	cin.get();

	return 0;
}