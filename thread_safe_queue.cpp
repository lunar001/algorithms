#include "thread_safe_queue.h"

namespace ThreadPool
{

template<typename T>
void ThreadSafeQueue<T>::WaitAndPop(T &value)
{
	std::unique_lock<std::mutex> lk(mx_);
	cond_.wait(lk, [this] () { return !data_queue_.empty(); });
	/* move copy assign*/
	value = std::move(*data_queue_.front());
	data_queue_.pop();
}

template<typename T>
bool ThreadSafeQueue<T>::TryPop(T & value)
{
	std::lock_guard<std::mutex> lk(mx_);
	if(data_queue_.empty())
		return false;
	value = std::move(*data_queue_.front());
	data_queue_.pop();
	return true;
}

template<typename T>
void ThreadSafeQueue<T> Push(T new_value)
{
	std::shared_ptr<T> data(
			std::make_shared<T>(std::move(new_value));
	std::lock_guard<std::mutex> lk(mx_);
	data_queue_.push(data);
	cond_.notify_one();
}

template<typename T>
bool ThreadSafeQueue<T> Empty() const
{
	std::lock_guard<std::mutex> lk(mx_);
	return data_queue_.empyt();
}

}/* end of namespace */
