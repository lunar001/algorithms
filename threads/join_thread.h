#ifndef H_JOIN_THREAD_H
#define H_JOIN_THREAD_H

#include "common.h"
#include <thread>
namespace ThreadPool
{

class JoinThread
{
public:
	explicit JoinThread(std::vector<std::thread> & threads):
		threads_(threads) {};
	~JoinThread()
	{
		for(unsigned long i = 0; i < threads_.size(); i++)
		{
			if(threads_[i].joinable())
				threads_[i].join();
		}
	}
private:
	std::vector<std::thread> & threads_;
};

}
#endif
