#include <iostream>
#include <string>
#include <chrono>
#include <mutex>
#include "ThreadPool.h"

using namespace std;

int main()
{
	ThreadPool t(4);
	mutex mutex_;
	const int iterations = 1000000;
	int number = 0;
	for (size_t i = 0; i < iterations; i++)
	{
		t.addTask([&mutex_, &number]() 
		{
			lock_guard<mutex> lock(mutex_);
			++number;
		});
		if (i % 20 == 0)
		{
			t.finishAll();
			cout << "Finished " << i << ", number: " << number << endl;
		}
	}
	t.finishAll();
	if (number == iterations) 
	{
		cout << "Test passed\n";
	}
	else 
	{
		cout << "Test failed\n";
	}
	
	return 0;
}
