#ifndef H_THREAD_POOL_H
#define H_THREAD_POOL_H

#include <atomic.h>

namespace threadpool
{

class ThreadPool
{

public:
    ThreadPool();
    ~ThreadPool();
    template<typename FunctionType>
    void SubMit(FunctionType f);

private:
    std::atomic_bool done_;
    ThreadSafeQueue<std::function<void()> > work_queue_;
    std::vector<std::thread> threads_;
    JoinThreads joiner_;

    void WorkThread();
};

}
#endif
