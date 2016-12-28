#include "stdafx.h"
#include "StringStack.h"
#include <stack>
#include<iostream>

CStringStack::~CStringStack()
{
	while (m_top->prev != nullptr)
	{
		auto tempElement = m_top;
		delete m_top;
		m_top = tempElement->prev;
	}
}

CStringStack::CStringStack()
{
	m_top = nullptr;
	m_stackSize = 0;
}


void CStringStack::push(string newString)
{
	Stack *newElement = new Stack;
	newElement->element = newString;
	newElement->prev = m_top;
	m_top = newElement;
	m_stackSize++;
}

string CStringStack::pop()
{
	if (m_stackSize > 0)
	{
		Stack returnElement = *m_top;
		m_top = returnElement.prev;
		m_stackSize--;
		return returnElement.element;
	}
	else
	{
		throw "Stack is empty";
	}
}


string CStringStack::top()
{
	if (m_stackSize > 0)
	{
		return m_top->element;
	}
	else
	{
		throw "Stack is empty";
	}
}


int CStringStack::GetSize()
{
	return m_stackSize;
}