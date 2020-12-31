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
	//�ж϶����Ƿ���
	bool IsFull() const;
	//�ж϶����Ƿ��
	bool isEmpty() const;
public:
	//���й���
	SyncQueue(int maxSize = MAX_NUM);
	//��������
	virtual ~SyncQueue();

	//�������м���Ԫ��
	void Put(const T& x);
	//�Ӷ�����ȡ��һ��Ԫ��
	void Take(T& x);
private:
	//������
	std::list<T> m_QueueList;  
	//��������������������
	std::condition_variable_any m_cnvNotFull; 
	//���������գ���������
	std::condition_variable_any m_cnvNotEmpty;
	//������ͬ����
	std::mutex m_mutex;
	//�����������
	int m_maxSize;                            
};
#endif // !_SYNCQUEUE_H


