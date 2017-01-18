#pragma once

#include "stdafx.h"

class CStringList
{
public:
	struct Node
	{
		Node(const std::string & data, Node * prev, std::unique_ptr<Node> && next)
			: data(data), prev(prev), next(std::move(next))
		{
		}
		std::string data;
		Node *prev;
		std::unique_ptr<Node> next;
	};
	CStringList() = default;
	CStringList(CStringList& list);
	CStringList(CStringList&& list);
	~CStringList();
	size_t GetSize()const;
	void AppendBack(const std::string& data);
	bool isEmpty() const;

	void AppendFront(const std::string& data);

	class CIterator
	{
		friend CStringList;
		CIterator(Node *node, bool isReverse = false);
	public:
		CIterator() = default;
		std::string & operator*()const;
		bool operator ==(CIterator const & argument) const;
		bool operator !=(CIterator const & argument) const;
		CIterator &operator++();
		CIterator &operator--();
		Node * operator->()const;
	private:
		Node *m_node = nullptr;
		bool m_isReverse = false;
	};

	CIterator Insert(const std::string& data, CIterator  & iter);

	CIterator begin();
	CIterator end();
	CIterator const cbegin() const;
	CIterator const cend() const;

	CIterator rbegin();
	CIterator rend();
	CIterator const crbegin() const;
	CIterator const crend() const;
	CIterator Delete(CIterator & iter);

	
	std::string & GetBackElement();
	std::string & GetFrontElement();
	std::string const& GetBackElement()const;
	std::string const& GetFrontElement()const;

	void Clear();
private:
	size_t m_size = 0;
	std::unique_ptr<Node> m_firstNode;
	Node * m_lastNode = nullptr;
};