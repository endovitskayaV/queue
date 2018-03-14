// queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "queue.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	queue<int> queueInt;
	try {
		int intBack = queueInt.back();
	}
	catch (const char* msg) {
		cout << msg<<endl;
	}
	catch (...) {
		cout << "error getting back\n";
	}

	try {
		int  intFront = queueInt.front();
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	catch (...) {
		cout << "error getting front\n";
	}

	bool b = queueInt.isEmpty();
	queueInt.push(1);
	queueInt.push(24);
	queueInt.push(11);
	queueInt.push(35);
	queueInt.push(0);
	queueInt.push(3);
	queueInt.push(17);
	queueInt.push(88);
	int intFirst=queueInt.pop();
	int s = queueInt.size();
	b = queueInt.isEmpty();
	int intBack = queueInt.back();
	intFirst =queueInt.front();
	intFirst = queueInt.pop();


	queue<string> queueStr;
	b = queueStr.isEmpty();
	queueStr.push("str0");
	queueStr.push("str1");
	string first = queueStr.pop();
	s = queueStr.size();
	b = queueStr.isEmpty();
	string back = queueStr.back();
	first = queueStr.front();
	first = queueStr.pop();


	queue<double> queueD;
	b = queueD.isEmpty();

	try {
		int intBack = queueD.pop();
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	catch (...) {
		cout << "error getting first\n";
	}

	queueD.push(3.67);
	queueD.push(9.0);
	double firstD = queueD.pop();
	s = queueD.size();
	b = queueD.isEmpty();
	double backD = queueD.back();
	firstD = queueD.front();
	firstD = queueD.pop();


	cin.ignore();
    return 0;
}

