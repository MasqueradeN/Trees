#include <iostream>
#include "Node.hpp"
#include "BinaryTree.hpp"

int main()
{
	BinaryTree<int> b;

	b.Push(24);
	b.Push(52);
	b.Push(69);
	b.Push(37);
	b.Push(1);
	b.Push(45);
	b.Push(70);
	b.Push(8);

	//b.Remove(45);

	if (b.Search(24))
	{
		std::cout << "Node found" << std::endl;
	}
	else
	{
		std::cout << "No nodes?" << std::endl;
	}

	if (b.Search(5))
	{
		std::cout << "Node found" << std::endl;
	}
	else
	{
		std::cout << "No nodes?" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Pre order tree: " << std::endl;
	b.DisplayPreOrder();

	std::cout << std::endl;

	std::cout << "Post order tree: " << std::endl;
	b.DisplayPostOrder();

	std::cout << std::endl;

	std::cout << "In order tree: " << std::endl;
	b.DisplayInOrder();

	std::cout << std::endl;
   // Node* root = new Node(1);
   // Node* subtree1 = new Node(3);
   // 
   // root->AddChild(new Node(2));

   // subtree1->AddChild(new Node(5));
   // subtree1->AddChild(new Node(6));

   //root->AddChild(subtree1);
   // root->AddChild(new Node(4));

   // std::cout << std::endl;

   // subtree1->DisplayTree();

   // std::cout << std::endl;
   // std::cout << std::endl;

   // root->DisplayTree();

   // std::cout << std::endl;

   // if (root->Search(10))
   // {
   //     std::cout << "Node found" << std::endl;
   // }
   // else
   // {
   //     std::cout << "No nodes?" << std::endl;
   // }
}
