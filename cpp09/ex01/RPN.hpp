#pragma once

#include <iostream>
#include <stack>
#include <string>

class Node {
	private:
	public:
		Node*	left;
		Node*	right;
		char	data;
		Node();
		~Node();
		Node(char c);
		Node(const Node &c);
		Node & operator=(const Node &c);
};

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &c);
		RPN & operator=(const RPN &c);
		Node*	BuildDTree(const std::string& input);
		int executeTree(Node* root);
		void	deleteTree(Node* root);
};
