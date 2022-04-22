#pragma once
#include"Queue.h"
template<class Type>
class priority_queue : public queue<Type>
{
private:
	int* num;//Array to store integers
public:
	priority_queue(int a)
	{
		num = new int[queue<Type>::size];
	}
	void enqueue(Type, int);
	void Resize();
};

