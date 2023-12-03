#include "RPN.hpp"


Node::Node() : left(nullptr), right(nullptr) {}

Node::Node(char c) : left(nullptr), right(nullptr), data(c) {}

Node::Node(const Node &c)
{
	(void)c;
}
Node & Node::operator=(const Node &c)
{
	(void)c;
	if(this != &c)
	{
		
	}
	return(*this);
}

