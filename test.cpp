#include <iostream>
#include <string>
#include <chrono>
#include "ThreadPool.h"

using namespace std;

void mainlySleep()
{
	this_thread::sleep_for(chrono::microseconds(1));
}

int main()
{
	ThreadPool t(4);
	for (size_t i = 0; i < 10000000; i++)
	{
		t.addTask(mainlySleep);
		if (i % 20 == 0)
		{
			t.finishAll();
			cout << "Finished " << i << endl;
		}
	}
	t.finishAll();
	cout << "test passed\n";
	return 0;
}