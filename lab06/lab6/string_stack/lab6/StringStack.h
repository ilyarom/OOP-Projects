#pragma once
#include <string>

using namespace std;

struct Stack
{
	string element;
	Stack* prev;
};

class CStringStack
{
public:
	CStringStack();

	~CStringStack();
	string pop();
	void push(string newElement);
	string top();
	int GetSize();

private:
	Stack *m_top;
	int m_stackSize;
};