#pragma once
#include <iostream>
//#include "BinaryTree.hpp"

//class Node
//{
//private:
//	int _obj;
//
//	Node* _next, *_prev, *_child;
//public:
//	Node(int value) : _obj(value), _next(nullptr), _prev(nullptr), _child(nullptr)
//	{
//		std::cout << "Node created" << std::endl;
//	}
//
//	~Node()
//	{
//		_prev = nullptr;
//
//		if (_child != nullptr)
//		{
//			delete _child;
//		}
//		if (_next != nullptr)
//		{
//			delete _next;
//		}
//
//		_child = nullptr;
//		_next = nullptr;
//
//		std::cout << "Node deleted" << std::endl;
//	}
//
//	void AddSibling(Node* node)
//	{
//		Node* ptr = _next;
//		if (_next == nullptr)
//		{
//			_next = node;
//			node->_prev = this;
//		}
//		else
//		{
//			while (ptr->_next != nullptr)
//			{
//				ptr = ptr->_next;
//			}
//			ptr->_next = node;
//			node->_prev = this;
//		}
//	}
//
//	void AddChild(Node* node)
//	{
//		if (_child == nullptr)
//		{
//			_child = node;
//		}
//		else
//		{
//			_child->AddSibling(node);
//		}
//	}
//
//	void DisplayTree()
//	{
//		std::cout << _obj;
//		if (_next != nullptr)
//		{
//			std::cout << std::endl;
//			_next->DisplayTree();
//		}
//
//		if (_child != nullptr)
//
//		{
//			std::cout << std::endl;
//			_child->DisplayTree();
//		}
//	}
//
//	bool Search(int value)
//	{
//		if (_obj == value)
//		{
//			return true;
//		}
//
//
//		if (_child != nullptr)
//		{
//			if (_child->Search(value) == true)
//			{
//				return true;
//			}
//		}
//
//		if (_next != nullptr)
//		{
//			if (_next->Search(value) == true)
//			{
//				return true;
//			}
//		}
//
//		return false;
//	}
//};
template<typename T>
class BinaryTree;

template<typename T>
class Node
{

	friend BinaryTree<T>;

public:
	Node(T key) : _key(key), _left(nullptr), _right(nullptr)
	{

	}

	~Node()
	{
		if (_left != nullptr)
		{
			delete _left;
			_left = nullptr;
		}

		if (_right != nullptr)
		{
			delete _right;
			_right = nullptr;
		}
	}

	T GetKey()
	{
		return _key;
	}

private:
	T _key;
	Node* _left, *_right;
};