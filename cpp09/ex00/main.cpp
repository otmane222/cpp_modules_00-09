
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <map>
#include "BitcoinExchange.hpp"

// ft_substr start
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	sum_of_size;
	char	*p;

	if (s == NULL)
		return (0);
	j = 0;
	sum_of_size = strlen(s) + start;
	if (strlen(s) < start)
	{
		p = new char;
		*p = '\0';
		return (p);
	}
	if (sum_of_size < len)
		len = sum_of_size;
	p = new char[len + 1];
	if (!p)
		return (0);
	while (s[start] && j < len)
		p[j++] = s[start++];
	p[j] = '\0';
	return (p);
}
// ft_substr end

// ft_split // // // 
static size_t	ft_count_strings(char const *str, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c && j == 0)
		{
			j = 1;
			k++;
		}
		else if (str[i] == c)
		{
			j = 0;
		}
		i++;
	}
	return (k);
}

static size_t	ft_count_char(char const *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	**free_all(char **s, int i)
{
	i--;
	while (i >= 0 && s[i] != NULL)
	{
		delete [] s[i];
		i--;
	}
	delete [] s;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strs;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	strs = new (std::nothrow) char *[ft_count_strings(s, c) + 1];
	if (!strs)
		return (0);
	while (j < ft_count_strings(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		strs[j] = ft_substr(&s[i], 0, (ft_count_char(s, i, c)));
		if (!strs[j] && j < ft_count_strings(s, c))
			return (free_all(strs, j));
		i += ft_count_char(s, i, c);
		j++;
	}
	strs[j] = 0;
	return (strs);
}
// end ft_split // // // 

bool	not_valid_input(std::string input, char c)
{
	if (input == "\n")
		return (true);
	if (!std::strchr(input.c_str(), c))
		return (true);
	return (false);
}

bool	not_valid(std::string input , char *s1, char *s2,char c)
{
	size_t a = 0;
	std::string data = s1;
	std::string value = s2;
	for (; input[a] == ' '; a++)
		;
	for (size_t i = 0; input[a] != c && input[a] != ' ' ; i++, a++)
	{
		if (input[a] != data[i])
			return (delete s1 ,delete s2 , true);
	}
	for (; input[a]  == ' '; a++)
		;
	if (input[a] == c)
		a++;
	else
		return (delete s1 ,delete s2 , true);
	for (; input[a] == ' '; a++)
		;
	for (size_t i = 0; input[a] != '\0' && input[a] != ' ' ; i++, a++)
	{
		if (input[a] != value[i])
			return (delete s1 ,delete s2 , true);
	}
	for (; input[a]; a++)
	{
		if (input[a] != ' ')
			return (delete s1 ,delete s2 , true);
	}
	return (delete s1 ,delete s2 , false);
}

int	count_num_of_char(const char *s, char c)
{
	int j = 0;
	for (size_t i = 0; s[i]; i++)
	{
		if ((int)s[i] == c)
			j++;
	}
	return (j);
}

int	ft_isdigit(const char *s)
{
	for (size_t i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

int	ft_isdigit2(const char *s)
{
	int	flag = 0;
	size_t i = 0;

	if (s[i] == '.')
	{
		flag = 1;
		i++;
	}
	for (; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			if (s[i] == '.' && flag == 1)
				return (0);
			if (s[i] == '.' && flag == 0)
				flag = 1;
			else
				return (0);
		}
	}
	return (1);
}

// ft_strtrim // // //
static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	while (ft_char_in_set(s1[start], set) && s1[start])
		start++;
	end = strlen(s1);
	while (ft_char_in_set(s1[end - 1], set) && end > start)
		end--;
	str = new char [end - start + 1];
	if (!str)
		return (0);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
// end ft_strtrim // // //


void	parsing_file_input(std::string filename, std::map<DateTime, double> myMap)
{
	double	val;
	char	* str;
	char	* ptr;
	char	**minus;
	char	**pipe;
	char	*endstr;

	std::string input;
	std::ifstream	inputFile(filename.c_str());
	std::istringstream dateStream;

	if (!std::getline(inputFile, input))
	{
		std::cerr<<"Empty file"<<std::endl;
		exit (1);
	}
	if (not_valid(input, strdup("date"), strdup("value"), '|'))
	{
		std::cerr<<"Error in organzition"<<std::endl;
		exit (1);
	}
	while (std::getline(inputFile, input))
	{
		val = 0;
		int	j;
		j = count_num_of_char(input.c_str(), '|');
		if (j > 1 || j == 0)
		{
			std::cerr << "Error: invalide input => " << "'" <<input << "'" << std::endl;
			continue ;
		}
		pipe = ft_split(input.c_str(), '|');
		str = ft_strtrim(pipe[0], " \t");
		j = count_num_of_char(str, '-');
		if (j > 2 || j == 0)
		{
			std::cerr << "Error: invalide input => " << "'" <<input << "'" << std::endl;
			free_all(pipe, ft_count_strings(input.c_str(), '|'));
			delete str;
			continue ;
		}
		minus = ft_split(str, '-');
		if (!ft_isdigit(minus[0]) || !ft_isdigit(minus[1]) || !ft_isdigit(minus[2]))
		{
			std::cerr << "Error: invalide input => " << "'" <<input << "'" << std::endl;
			free_all(pipe, ft_count_strings(input.c_str(), '|'));
			free_all(minus, ft_count_strings(str, '-'));
			delete str;
			continue ;
		}
		ptr = ft_strtrim(pipe[1], " \t");
		if (!ft_isdigit2(ptr))
		{
			std::cerr << "Error: invalide value => " << ptr << std::endl;
			free_all(pipe, ft_count_strings(input.c_str(), '|'));
			free_all(minus, ft_count_strings(str, '-'));
			delete str;
			delete ptr;
			continue;
		}
		val = strtof(pipe[1], &endstr);
		if (val > 999)
		{
			std::cerr << "Error: too large a number." << std::endl;
			free_all(pipe, ft_count_strings(input.c_str(), '|'));
			free_all(minus, ft_count_strings(str, '-'));
			delete str;
			delete ptr;
			continue ;
		}
		int y = std::atoi(minus[0]);
		int m = std::atoi(minus[1]);
		int d = std::atoi(minus[2]);
		free_all(pipe, ft_count_strings(input.c_str(), '|'));
		free_all(minus, ft_count_strings(str, '-'));
		// for (size_t i = 0; i < ft_count_strings(input.c_str(), '|'); i++)
		// {
		// 	delete[] pipe[i];
		// }
		// for (size_t i = 0; i < ft_count_strings(str, '-'); i++)
		// {
		// 	delete[] minus[i];
		// }
		
		delete str;
		delete ptr;

		int	check = m % 2;
		int	check2 = y % 4;
		int days;
		if (check2)
			days = 28;
		else
			days = 29;
		if ((check && d > 31) || (!check && m == 2 && d > days) || (!check && d > 30))
		{
			std::cerr << "Error: bad date => " <<y<<"-"<<m<<"-"<<d<< std::endl;
			continue ;
		}
		int t = (((y * 100) + m) * 100) + d;
		int y1;
		int m1;
		int d1;
		int t1;
		// std::stringstream a;
		std::map<DateTime, double>::iterator it = myMap.begin();
		std::map<DateTime, double>::iterator ite = myMap.end();
		std::map<DateTime, double>::iterator tmp;
		for (; it != ite; it++)
		{
		// std::cout<<"here"<<std::endl;
			tmp = it;
			y1 = it->first.timeStruct.tm_year + 1900;
			m1 = it->first.timeStruct.tm_mon + 1;
			d1 = it->first.timeStruct.tm_mday;
			t1 = (((y1 * 100) + m1) * 100) + d1;
			if (t1 == t)
			{
				char c = '0';
				std::cout<<y<<"-"<< c <<m<<"-"<<d<<" => "<< val <<" = " << val * it->second<<std::endl;
				break ;
			}

			tmp++;
			if (tmp != ite)
			{
				y1 = tmp->first.timeStruct.tm_year + 1900;
				m1 = tmp->first.timeStruct.tm_mon + 1;
				d1 = tmp->first.timeStruct.tm_mday;
				t1 = (((y1 * 100) + m1) * 100) + d1;
			}
			if (t < t1 || tmp == ite)
			{
				y1 = it->first.timeStruct.tm_year + 1900;
				m1 = it->first.timeStruct.tm_mon + 1;
				d1 = it->first.timeStruct.tm_mday;
				t1 = (((y1 * 100) + m1) * 100) + d1;
				char c = '\0';
				char c2 = '\0';
				if (m <= 9)
					c = '0';
				if (d <= 9)
					c2 = '0';
				std::cout<<y<<"-"<<c<<m<<"-"<<c2<<d<<" => "<< val <<" = " << val * it->second<<std::endl;
				break ;
			}
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr<<"Error: file isn't exist."<<std::endl;
		return (1);
	}
	std::string filename = av[1];
	try
	{
		BitcoinExchange	b("data.csv");
		parsing_file_input(filename, b.getMap());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
