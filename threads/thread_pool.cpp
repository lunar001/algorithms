#include "thread_pool.h"
#include <exception>
namespace ThreadPool
{

ThreadPool::ThreadPool():
	done_(false), joiner_(threads_)
	{
		unsigned const thread_count = std::thread::hardware_concurrency();
		try
		{
			for( unsigned i = 0; i < thread_count; ++i)
			{
				threads_.push_back(std::thread(&ThreadPool::WorkThread, this));
			}
		}
		catch (const std::exception &e)
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
	work_queue_.Push(std::function<void()>(f));
}
}
