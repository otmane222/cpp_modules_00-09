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
		Node(char c);
		Node(const Node &c);
		Node & operator=(const Node &c);
};

class RPN
{
	public:
		Node*	BuildDTree(const std::string& input)
		{
			int	flag = 0;

			std::stack<Node* > stacko;
			for (size_t i = 0; input[i]; i++)
			{
				if (std::isdigit(input[i]))
				{
					flag = 0;
					stacko.push(new Node(input[i]));
				}
				else if (input[i] == ' ' && flag == 0)
					flag = 1;
				else if ((input[i] == ' ' && flag == 1))
				{
					std::cerr<<"Error"<<std::endl;
					exit(1);
				}
				else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
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
			return (stacko.top());
		}
		int executeTree(Node* root)
		{
			if (!root)
				return (0);
			if (root->data >= '0' && root->data <= '9')
				return (root->data - '0');
			switch (root->data)
			{
			case ('+'):
				return (executeTree(root->left) + executeTree(root->right));
				break;
			case ('-'):
				return (executeTree(root->left) - executeTree(root->right));
				break;
			case ('*'):
				return (executeTree(root->left) * executeTree(root->right));
				break;
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
				break;
			default:
				return (0);
			}
		}
		void	deleteTree(Node* root)
		{
			if (!root)
				return ;
			if (root->left)
				deleteTree(root->left);
			if (root->right)
				deleteTree(root->right);
			delete root;
		}
};
