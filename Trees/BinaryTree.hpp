#pragma once
#include "Node.hpp"

template<typename T>
class BinaryTree
{
public:
	BinaryTree() : _root(nullptr)
	{

	}

	~BinaryTree()
	{
		if (_root != nullptr)
		{
			delete _root;
			_root = nullptr;
		}
	}

	bool Push(T key)
	{
		Node<T>* newNode = new Node<T>(key);
		if (_root == nullptr)
		{
			_root = newNode;
		}
		else
		{
			Node<T>* parent = nullptr;
			Node<T>* currentNode = _root;

			while (1)
			{
				parent = currentNode;
				if (key == currentNode->_key)
				{
					delete newNode;
					return false;
				}

				if (key < currentNode->_key)
				{
					currentNode = currentNode->_left;
					if (currentNode == nullptr)
					{
						parent->_left = newNode;
						return true;
					}
				}
				else
				{
					currentNode = currentNode->_right;
					if (currentNode == nullptr)
					{
						parent->_right = newNode;
						return true;
					}
				}
			}
		}
		return true;
	}

	bool Search(T key)
	{
		if (_root == nullptr)
		{
			return false;
		}

		Node<T>* currentNode = _root;
		while (currentNode->_key != key)
		{
			if (key < currentNode->_key)
			{
				currentNode = currentNode->_left;
			}
			else
			{
				currentNode = currentNode->_right;
			}

			if (currentNode == nullptr)
			{
				return false;
			}
		}
		return true;
	}

	void DisplayPreOrder()
	{
		DisplayPreOrder(_root);
	}

	void DisplayPostOrder()
	{
		DisplayPostOrder(_root);
	}

	void DisplayInOrder()
	{
		DisplayInOrder(_root);
	}

	void Remove(T key)
	{
		if (_root == nullptr)
		{
			return;
		}

		Node<T>* parent = _root;
		Node<T>* node = _root;
		bool isLeftNode = false;

		while (node->_key != key)
		{
			parent = node;
			if (key < node->_key)
			{
				node = node->_left;
				isLeftNode = true;
			}
			else
			{
				node = node->_right;
				isLeftNode = false;
			}

			if (node == nullptr)
			{
				return;
			}
		}

		if (node->_left == nullptr && node->_right == nullptr)
		{
			if (node == _root)
			{
				_root = nullptr;
			}
			else if (isLeftNode)
			{
				parent->_left = nullptr;
			}
			else
			{
				parent->_right = nullptr;
			}
		}
		else if (node->_left == nullptr)
		{
			if (node == _root)
			{
				_root = node->_right;
			}
			else if (isLeftNode == true)
			{
				parent->_left = node->_right;
			}
			else
			{
				parent->_right = node->_right;
			}
		}
		else if (node->_right == nullptr)
		{
			if (node == _root)
			{
				_root = node->_left;
			}
			else if (isLeftNode == true)
			{
				parent->_left = node->_left;
			}
			else
			{
				parent->_right = node->_left;
			}
		}
		else
		{
			Node<T>* tempNode = node->_right;
			Node<T>* succesor = node;
			Node<T>* succesorParent = node;

			while (tempNode != nullptr)
			{
				succesorParent = succesor;
				succesor = tempNode;
				tempNode = tempNode->_left;
			}

			if (succesor != node->_right)
			{
				succesorParent->_left = succesor->_right;
				succesor->_right = node->_right;
			}

			if (node == _root)
			{
				_root = succesor;
			}
			else if (isLeftNode)
			{
				node = parent->_left;
				parent->_left = succesor;
			}
			else
			{
				node = parent->_right;
				parent->_right = succesor;
			}

			succesor->_right = node->_left;
		}

		node->_left = nullptr;
		node->_right = nullptr;
		delete node;
	}

private:
	Node<T>* _root;

	void DisplayPreOrder(Node<T>* node)
	{
		if (node != nullptr)
		{
			std::cout << node->_key << " ";
			DisplayPreOrder(node->_left);
			DisplayPreOrder(node->_right);
		}
	}

	void DisplayPostOrder(Node<T>* node)
	{
		if (node != nullptr)
		{
			DisplayPostOrder(node->_left);
			DisplayPostOrder(node->_right);
			std::cout << node->_key << " ";
		}
	}

	void DisplayInOrder(Node<T>* node)
	{
		if (node != nullptr)
		{
			DisplayInOrder(node->_left);
			std::cout << node->_key << " ";
			DisplayInOrder(node->_right);
		}
	}
};