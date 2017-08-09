#ifndef H_THREAD_SAFE_QUEUE_H
#define H_THREAD_SAFE_QUEUE_H

#include "common.h"
#include <mutex>
#include <condition_variable>
#include <queue>
namespace ThreadPool
{

template<typename T>
class ThreadSafeQueue
{

public:
	ThreadSafeQueue() {};/*default Construcstor */
	void WaitAndPop(T & value);
	std::shared_ptr<T> WaitAndPop();
	std::shared_ptr<T> TryPop();
	bool TryPop(T & value);	
	void Push(T new_value);
	bool Empty() const;

private:

	/* mx_ is a mutable variable, const
	   member function can modify it */
	mutable std::mutex mx_; 
	std::queue<std::shared_ptr<T> > data_queue_;
	std::condition_variable cond_;
};

}
#endif
