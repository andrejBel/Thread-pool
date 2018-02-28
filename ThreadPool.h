#ifndef ThreadPool_H
#define ThreadPool_H

#include <atomic>
#include <condition_variable>
#include <functional>
#include <queue>
#include <vector>
#include <mutex>
#include <thread>
#include <iostream>

class ThreadPool {



private:
	std::queue<std::function<void(void)> > tasks_;
	std::vector<std::thread> threads_;
	bool end_;
	std::condition_variable conditionVariable_;
	std::mutex mutex_;
	int undoneTasks_;
	void joinAll();
	void run();
	
	enum Action
	{
		SLEEP, WORK, END
	};
	
public:
	
	ThreadPool::Action getNextAction();
	ThreadPool(int c);

	ThreadPool(const ThreadPool& other) = delete;

	ThreadPool& operator=(const ThreadPool& other) = delete;

	~ThreadPool();

	void addTask(std::function<void(void)> job);

	void finishAll();

};

#endif /* ThreadPool_H */