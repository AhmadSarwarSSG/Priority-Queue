#include "Priority_queue.h"
#include<iostream>
using namespace std;
template<class Type>
void priority_queue<Type>::enqueue(Type value, int c)
{
	if (!(queue<Type>::isfull()))
	{
		for (int i = queue<Type>::front; i < queue<Type>::count; i = (i + 1) % queue<Type>::size)
		{	//Here we sort the elements as some new element comes
			Type check = queue<Type>::q[i];
			int check1 = num[i];
			if (num[i] > c || num[i] == c)//If elements is less then or equal to the elements we swap them
			{
				queue<Type>::q[i] = value;
				num[i] = c;
				value = check;
				c = check1;
			}
		}
		queue<Type>::q[queue<Type>::rear] = value;//At the end storing coming value
		num[queue<Type>::rear] = c;
		queue<Type>::rear = (queue<Type>::rear + 1) % queue<Type>::size;//Round behaviour
		queue<Type>::count++;
	}
	else
	{
		int f = queue<Type>::front;
		queue<Type>::resize(1);
		int* RS = num;//WE copy our array
		num = new int[queue<Type>::size];//Make a new one
		int j = 0;
		for (int i = queue<Type>::f; j != queue<Type>::count; i = (i + 1) % queue<Type>::size)
		{
			num[j++] = RS[i];//Here we paste it
		}
		//Similarly if size exceeds we resize it and again sort elements
		for (int i = queue<Type>::front; i < queue<Type>::count; i = (i + 1) % queue<Type>::size)
		{
			Type check = queue<Type>::q[i];
			int check1 = num[i];
			if (num[i] > c || num[i] == c)
			{
				queue<Type>::q[i] = value;
				num[i] = c;
				value = check;
				c = check1;
			}
		}
		queue<Type>::q[queue<Type>::rear] = value;
		num[queue<Type>::rear] = c;
		queue<Type>::rear = (queue<Type>::rear + 1) % queue<Type>::size;
		queue<Type>::count++;
	}
}