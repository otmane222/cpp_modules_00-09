/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:04:04 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/11/19 17:28:30 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

int	check_type(std::string data, int *type, double *d, float *f, int j)
{
	if ((data[j + 1] == 'd' || data[j + 1] == 'D'))
	{
		if (data[j + 2])
		{
			*type = 4;
			return (2);
		}
		*d = std::stod(data);
		*type = 0;
		return (1) ;
	}
	else if (data[j + 1] == 'f')
	{
		if (data[j + 2])
		{
			*type = 4;
			return (2);
		}
		*f = std::stof(data);
		*type = 1;
		return (1) ;
	}
	else if (data[j + 1] && (data[j + 1] < '0' || data[j + 1] > '9') && \
		data[j + 1] != 'd' && data[j + 1] != 'D' && data[j + 1] != 'f')
	{
		*type = 4;
		return (2) ;
	}
	if (!data[j + 1])
	{
		*d = std::stod(data);
		*type = 0;
		return (1);
	}
	return (0);
}

void ScalarConverter::convert(std::string data)
{
	long long	k = 0;
	double	d;
	float	f = 0.0f;
	char	c;
	int		i = 0;
	int		type = -1;
	int		j = 0;

	if (data.length() == 1)
	{
		if (!(data[0] >= '0' && data[0] <= '9'))
		{
			type = 2;
			c = data[0];
		}
	}
	if (type == -1)
	{
		if (data[j] == '-')
			j++;
		while (data[j] && data[j] >= '0' && data[j] <= '9')
			j++;
		if (j > 308)
		{
			std::cout<<"char: Non displayable"<<std::endl;
			std::cout<<"int: out of range"<<std::endl;
			if (data[0] == '-')
			{
				std::cout<<"float: -inff"<<std::endl;
				std::cout<<"double: -inf"<<std::endl;
			}
			else
			{
				std::cout<<"float: inff"<<std::endl;
				std::cout<<"double: inf"<<std::endl;
			}
		}
		else if (!data[j])
		{
			type = 3;
			if (j > 13)
			{
				std::cout<<"char: impossible"<<std::endl;
				std::cout<<"int: impossible"<<std::endl;
				if (j < 20)
				{
					k = std::stoll(data);
					std::cout<<"float: "<<static_cast<float>(k)<<".0f"<<std::endl;
					std::cout<<"double: "<<static_cast<double>(k)<<".0"<<std::endl;
				}
				else
				{
					std::cout<<"float: impossible"<<std::endl;
					std::cout<<"double: impossible"<<std::endl;
				}
				exit(0);
			}
			k = std::stoll(data);
			if (k > INT_MAX || k < INT_MIN)
			{
				std::cout<<"char: impossible"<<std::endl;
				std::cout<<"int: impossible"<<std::endl;
				std::cout<<"float: "<<static_cast<float>(k)<<".0f"<<std::endl;
				std::cout<<"double: "<<static_cast<double>(k)<<".0"<<std::endl;
				exit(0);
			}
			else
				i = k;
		}
		else
			j = 0;
		if (data[j] == '-')
			j++;
		while (data[j] && data[j] >= '0' && data[j] <= '9' && type == -1)
		{
			if (check_type(data, &type, &d, &f, j) == 1)
				break ;
			if (data[j + 1] == '.')
			{
				if (check_type(data, &type, &d, &f, j + 1))
					break ;
				j += 2;
				if (!data[j])
				{
					d = std::stod(data);
					type = 0;
					break;
				}
				while (data[j] && data[j] >= '0' && data[j] <= '9')
				{
					if (check_type(data, &type, &d, &f, j))
						break ;
					j++;
				}
				break ;
			}
			j++;
		}
		if (data[j + 1] && type == -1)
			type = 4;
	}
	if (type == 0)
	{
		std::cout<<"double"<< std::endl;
		if (static_cast<int>(d) > 0 && static_cast<int>(d) > 32 && static_cast<int>(d) <= 126)
			std::cout<<"char: "<< static_cast<char>(d) <<std::endl;
		else if (static_cast<int>(d) < 0)
			std::cout<<"char: impossible"<<std::endl;
		else
			std::cout<<"char: Non displayable"<<std::endl;
		std::cout<<"int: "<<static_cast<int>(d) <<std::endl;
		std::cout<<"float: "<<static_cast<float>(d)<<"f"<<std::endl;
		if (static_cast<int>(d) == d)
			std::cout<<"double: "<<d<<".0"<<std::endl;
		else
			std::cout<<"double: "<<d<<std::endl;
	}
	if (type == 1)
	{
		std::cout<<"float"<< std::endl;
		if (static_cast<int>(f) > 0 && static_cast<int>(f) > 32 && static_cast<int>(f) <= 126)
			std::cout<<"char: "<< static_cast<char>(f) <<std::endl;
		else if (static_cast<int>(f) < 0)
			std::cout<<"char: impossible"<<std::endl;
		else
			std::cout<<"char: Non displayable"<<std::endl;
		std::cout<<"int: "<<static_cast<int>(f) <<std::endl;
		std::cout<<"float: "<<f<<".0f"<<std::endl;
		std::cout<<"double: "<<static_cast<double>(f)<<".0"<<std::endl;
	}
	if (type == 2)
	{
		std::cout<<"char"<< std::endl;
		std::cout<<"char: "<< c <<std::endl;
		std::cout<<"int: "<<static_cast<int>(c) <<std::endl;
		std::cout<<"float: "<<static_cast<float>(c)<<".0f"<<std::endl;
		std::cout<<"double: "<<static_cast<double>(c)<<".0"<<std::endl;
	}
	if (type == 3)
	{
		std::cout<<"int"<< std::endl;
		if (i > 0 && i > 32 && i <= 126)
			std::cout<<"char: "<< static_cast<char>(i) <<std::endl;
		else if (i < 0 || i >= 256)
			std::cout<<"char: impossible"<<std::endl;
		else
			std::cout<<"char: Non displayable"<<std::endl;
		std::cout<<"int: "<<i <<std::endl;
		std::cout<<"float: "<<static_cast<float>(i)<<".0f"<<std::endl;
		std::cout<<"double: "<<static_cast<double>(i)<<".0"<<std::endl;
	}
	if (type == 4)
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: nanf"<<std::endl;
		std::cout<<"double: nan"<<std::endl;
	}
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &c)
{
	(void)c;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &c)
{
	*this = c;
}


ScalarConverter::~ScalarConverter()
{

}
