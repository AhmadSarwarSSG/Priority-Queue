#include<iostream>
#include"Queue.h"
#include"Queue.cpp"
#include"Priority_queue.h"
#include"Priority_queue.cpp"
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of Jobs you want to enter:";
	cin >> n;
	priority_queue<char>q(n);//Making a queue of specific size and storing elements in it
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the Job name as Any Letter (e.g: P=President): \n";
		char c;
		cin >> c;
		int n;
		cout << "Enter the Priority of this Job: \n";
		cin >> n;
		q.enqueue(c, n);// Big-Oh of this fuction is O()
	}
	cout << "Jobs According to Priority are: \n";
	q.showstructire();
	return 0;
}