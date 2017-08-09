#ifndef H_THREAD_POOL_H
#define H_THREAD_POOL_H

#include "common.h"
#include "thread_safe_queue.h"
#include "join_thread.h"
#include <thread>

namespace ThreadPool
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
    JoinThread joiner_;

    void WorkThread();
};

}
#endif
