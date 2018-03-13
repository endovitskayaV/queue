// queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "queue.h"

int main()
{
	queue<int> queue;
	queue.push(1);
	queue.push(24);
	int z=queue.pop();
	int s = queue.size();
	bool b = queue.isEmpty();
	int r = queue.back();
	int t=queue.front();
    return 0;
}

