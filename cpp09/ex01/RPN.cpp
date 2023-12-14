#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &c)
{
	(void)c;
}

RPN & RPN::operator=(const RPN &c)
{
	(void)c;
	return (*this);
}

Node*	RPN::BuildDTree(const std::string& input)
{
	int	flag = 0;
	int	dig = 0;

	std::stack<Node* > stacko;
	for (size_t i = 0; input[i]; i++)
	{
		if (std::isdigit(input[i]))
		{
			if (std::isdigit(input[i + 1]))
			{
				std::cerr<<"Error"<<std::endl;
				exit(1);
			}
			flag = 0;
			dig = 1;
			stacko.push(new Node(input[i]));
		}
		else if (input[i] == ' ' && flag == 0)
		{
			if (i == 0)
			{
				std::cerr<<"Error"<<std::endl;
				exit(1);
			}
			dig = 0;
			flag = 1;
		}
		else if ((input[i] == ' ' && flag == 1))
		{
			std::cerr<<"Error"<<std::endl;
			exit(1);
		}
		else if ((input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*') && dig == 0)
		{
			flag = 0;
			if (stacko.empty())
			{
				std::cerr<<"Error"<<std::endl;
				exit (0);
			}
			Node*	rightN = stacko.top();
			stacko.pop();

			if (stacko.empty())
			{
				std::cerr<<"Error"<<std::endl;
				exit (0);
			}
			Node*	leftN = stacko.top();
			stacko.pop();

			Node*	root = new Node(input[i]);
			root->left = leftN;
			root->right = rightN;
			stacko.push(root);
		}
		else
		{
			std::cerr<<"Error"<<std::endl;
			exit(1);
		}
	}
	if (stacko.empty())
		return (NULL);
	if (std::isdigit(stacko.top()->data))
	{
		std::cerr<<"Error"<<std::endl;
		exit(1);
	}
	if (stacko.empty())
		return (NULL);
	if (stacko.size() >= 2)
	{
		std::cerr<<"Error"<<std::endl;
		exit(1);
	}
	return (stacko.top());
}

int RPN::executeTree(Node* root)
{
	if (!root)
		return (0);
	if (root->data >= '0' && root->data <= '9')
		return (root->data - '0');
	switch (root->data)
	{
	case ('+'):
		return (executeTree(root->left) + executeTree(root->right));
	case ('-'):
		return (executeTree(root->left) - executeTree(root->right));
	case ('*'):
		return (executeTree(root->left) * executeTree(root->right));
	case ('/'):
	{
		int b = executeTree(root->right);
		if (b == 0)
		{
			std::cerr<<"Deviding by Zero, Are u crazy!!"<<std::endl;
			exit (0);
		}
		return (executeTree(root->left) / b);
	}
	default:
		return (0);
	}
}

void	RPN::deleteTree(Node* root)
{
	if (!root)
		return ;
	if (root->left)
		deleteTree(root->left);
	if (root->right)
		deleteTree(root->right);
	delete root;
}

Node::Node() : left(nullptr), right(nullptr) {}
Node::~Node() {}

Node::Node(char c) : left(nullptr), right(nullptr), data(c) {}

Node::Node(const Node &c)
{
	(void)c;
}
Node & Node::operator=(const Node &c)
{
	(void)c;
	return(*this);
}

