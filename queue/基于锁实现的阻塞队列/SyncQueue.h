#ifndef _SYNCQUEUE_H
#define _SYNCQUEUE_H
#include <list>
#include <mutex>
#include <condition_variable>
#include <iostream>

#define MAX_NUM 4096
template <typename T>
class SyncQueue
{
private:
	//判断队列是否满
	bool IsFull() const;
	//判断队列是否空
	bool isEmpty() const;
public:
	//队列构造
	SyncQueue(int maxSize = MAX_NUM);
	//队列析构
	virtual ~SyncQueue();

	//往队列中加入元素
	void Put(const T& x);
	//从队列中取走一个元素
	void Take(T& x);
private:
	//缓冲区
	std::list<T> m_QueueList;  
	//缓冲区不满，条件变量
	std::condition_variable_any m_cnvNotFull; 
	//缓冲区不空，条件变量
	std::condition_variable_any m_cnvNotEmpty;
	//缓冲区同步锁
	std::mutex m_mutex;
	//队列最大数量
	int m_maxSize;                            
};
#endif // !_SYNCQUEUE_H


