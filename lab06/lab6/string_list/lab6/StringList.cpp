#include "stdafx.h"
#include "StringList.h"
#include <cassert>

using namespace std;


CStringList::CStringList(CStringList & list)
{
	CStringList tempList;
	for (auto const& elem : list)
	{
		tempList.AppendBack(elem);
	}
	std::swap((*this).m_firstNode, tempList.m_firstNode);
	std::swap((*this).m_lastNode, tempList.m_lastNode);
	(*this).m_size = tempList.m_size;
}

CStringList::CStringList(CStringList && list)
{
	(*this).m_firstNode = move(list.m_firstNode);
	(*this).m_lastNode =  move(list.m_lastNode);
	(*this).m_size = list.m_size;
	list.m_firstNode = nullptr;
	list.m_lastNode = nullptr;
	list.m_size = 0;
}

size_t CStringList::GetSize() const
{
	return m_size;
}

void CStringList::Clear()
{
	while (m_lastNode)
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
		--m_size;
	}
	m_firstNode = nullptr;
}

CStringList::~CStringList()
{
	Clear();
}

void CStringList::AppendBack(const string & data)
{
	auto newNode = make_unique<Node>(data, m_lastNode, nullptr);
	Node *newLastNode = newNode.get();
	if (m_lastNode)
	{
		m_lastNode->next = move(newNode);
	}
	else
	{
		m_firstNode = move(newNode);
	}
	m_lastNode = newLastNode;
	++m_size;
}

void CStringList::AppendFront(const string & data)
{
	auto newNode = make_unique<Node>(data, nullptr, nullptr);
	if (m_firstNode)
	{
		m_firstNode->prev = newNode.get();
		newNode->next = move(m_firstNode);
	}
	else
	{
		m_lastNode = newNode.get();
	}
	m_firstNode = move(newNode);
	++m_size;

}

bool CStringList::isEmpty() const
{
	return (m_firstNode == nullptr);
}

CStringList::CIterator CStringList::Insert(const string & element, CIterator & iter)
{
	if (iter.m_node == m_firstNode.get())
	{
		AppendFront(element);
	}
	else if (iter == end())
	{
		AppendBack(element);
	}
	else
	{
		if (!iter.m_node)
		{
			throw invalid_argument("Invalid iterator");
		}
		auto node = make_unique<Node>(element, iter->prev, move(iter->prev->next));
		iter->prev = move(node.get());
		node->prev->next = move(node);
		++m_size;
	}
	return iter;
}

CStringList::CIterator CStringList::begin()
{
	return CIterator(m_firstNode.get());
}

CStringList::CIterator CStringList::end()
{
	return CIterator(m_lastNode);
}

CStringList::CIterator const CStringList::cbegin() const
{
	return CIterator(m_firstNode.get());
}

CStringList::CIterator const CStringList::cend() const
{
	return CIterator(m_lastNode);
}

CStringList::CIterator CStringList::rbegin()
{
	return CIterator(m_lastNode, true);
}

CStringList::CIterator CStringList::rend()
{
	return CIterator(m_firstNode->prev, true);
}

CStringList::CIterator const CStringList::crbegin() const
{
	return CIterator(m_lastNode, true);
}

CStringList::CIterator const CStringList::crend() const
{
	return CIterator(m_firstNode->prev, true);
}

CStringList::CIterator CStringList::Delete(CIterator & iter)
{
	if (m_size == 1)
	{
		Clear();
		return this->end();
	}
	else if (isEmpty())
	{
		throw runtime_error("Delete element from empty list");
	}
	if (iter == begin())
	{
		iter->next->prev = nullptr;
		m_firstNode = move(iter->next);
	}
	else if (iter.m_node == m_lastNode)
	{
		iter->prev->next = nullptr;
		m_lastNode = move(iter->prev);
		iter = m_lastNode->next.get();
	}
	else
	{
		auto next = move(iter.m_node->next);
		auto prev = iter.m_node->prev;
		next->prev = prev;
		prev->next = move(next);
		iter = prev->next.get();
	}

	--m_size;

	return iter;
}

string & CStringList::GetBackElement()
{
	//assert(m_lastNode);
	if (isEmpty())
	{
		throw out_of_range("List is empty");
	}
	return m_lastNode->data;
}

string const & CStringList::GetBackElement() const
{
	//assert(m_lastNode);
	if (isEmpty())
	{
		throw out_of_range("List is empty");
	}
	return m_lastNode->data;
}

string & CStringList::GetFrontElement()
{
	//assert(m_firstNode);
	if (isEmpty())
	{
		throw out_of_range("List is empty");
	}
	return m_firstNode->data;
}

string const& CStringList::GetFrontElement()const
{
	//assert(m_firstNode);
	if (isEmpty())
	{
		throw out_of_range("List is empty");
	}
	return m_firstNode->data;
}

CStringList::CIterator::CIterator(Node * node, bool isReverse)
	:m_node(node)
	, m_isReverse(isReverse)
{
}

string & CStringList::CIterator::operator*() const
{
	return m_node->data;
}

bool CStringList::CIterator::operator==(CIterator const & argument) const
{
	return m_node == argument.m_node;
}

bool CStringList::CIterator::operator!=(CIterator const & argument) const
{
	return m_node != argument.m_node;
}


CStringList::CIterator & CStringList::CIterator::operator++()
{
	m_node = (m_isReverse ? m_node->prev : m_node->next.get());
	return *this;
}

CStringList::CIterator & CStringList::CIterator::operator--()
{
	m_node = (m_isReverse ? m_node->next.get() : m_node->prev);
	return *this;
}

CStringList::Node * CStringList::CIterator::operator->() const
{
	return m_node;
}
