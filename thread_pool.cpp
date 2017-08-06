#include "thread_pool.h"

namespace threadpool
{

void ThreadPool::ThreadPool():
	done_(false), joiner_(threads_)
	{
		unsigned const thread_count = std::thread::hardware_concurrency();
		try
		{
			for( unsigned i = 0; i < thread_count; ++i)
			{
				thread_.push_back(std::thread(&ThreadPool::WorkThread, this));
			}
		}
		catch (Exception)
		{
			done_ = true;
			throw;
		}
	}

ThreadPool::~ThreadPool()
{
	done_ = true;
}

template<typename FunctionType>
void ThreadPool::SubMit(FunctionType f)
{
	work_queue_.push(std::function<void()>(f));
}
}
