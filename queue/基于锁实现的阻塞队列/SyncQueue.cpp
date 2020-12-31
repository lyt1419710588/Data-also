#include "SyncQueue.h"

template <typename T>
bool SyncQueue<T>::IsFull() const
{
	return m_QueueList.size() == m_maxSize;
}

template <typename T>
bool SyncQueue<T>::isEmpty() const
{
	return m_QueueList.empty();
}


template <typename T>
SyncQueue<T>::SyncQueue(int maxSize):m_maxSize(maxSize)
{
}


template <typename T>
SyncQueue<T>::~SyncQueue()
{
	m_QueueList.clear();
}

template <typename T>
void SyncQueue<T>::Put(const T& x)
{
	std::lock_grand<std::mutex> lock(m_mutex);

	while (IsFull())
	{
		m_cnvNotFull.wait(m_mutex);
	}

	m_QueueList.push_back(x);
	m_cnvNotEmpty.notify_one();
}


template<typename T>

void SyncQueue<T>::Take(T& x)
{
	std::lock_guard<std::mutex> lock(m_mutex);

	while (isEmpty());
	{
		m_cnvNotEmpty.wait(m_mutex);
	}

	x = m_QueueList.front();
	m_QueueList.pop_front();
	m_cnvNotFull.notify_one();
}
