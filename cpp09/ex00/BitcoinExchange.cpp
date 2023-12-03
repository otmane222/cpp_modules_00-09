#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std:: map <DateTime , double > mapo;
	double		val;

	std::string input;
	std::ifstream	inputFile(filename.c_str());
	std::tm timeStruct = {};
	std::istringstream dateStream;

	if (!std::getline(inputFile, input))
	{
		std::cerr<<"Empty file"<<std::endl;
		exit (1);
	}
	if (not_valid(input, strdup("date"), strdup("exchange_rate"), ','))
	{
		std::cerr<<"Error in organzition"<<std::endl;
		exit (1);
	}
	while (std::getline(inputFile, input))
	{
		if (not_valid_input(input, ','))
		{
			std::cout<<"Error parsing"<<std::endl;
			continue ;
		}
		dateStream.clear();
		dateStream.str(input);
		dateStream >> std::get_time(&timeStruct, "%Y-%m-%d,");
		int k = input.find_first_of(",");
		std::istringstream ss(&input.at(k + 1));
		if (ss.fail())
		{
			std::cout<<"Error parsing"<<std::endl;
			exit (1);
		}
		ss >> val;
		if (val < 0)
		{
			std::cerr<<"Error in file *.csv"<<std::endl;
			exit (1);
		}
		if (dateStream.fail())
		{
			std::cerr << "Error parsing date: " << input << std::endl;
			exit (1);
		}
		else
		{
			DateTime a(timeStruct);
			mapo[a] = val;
		}
	}
	myMap = mapo;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &c)
{
	*this = c;
}

std::map<DateTime, double > BitcoinExchange::getMap()
{
	return (myMap);
}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &c)
{
	if(this != &c)
	{
		this->myMap = c.myMap;
	}
	return(*this);
}

DateTime::DateTime(std::tm timeStruct) : timeStruct(timeStruct) {}
DateTime::DateTime(const DateTime& c) {*this = c;}
DateTime& DateTime::operator = (const DateTime& c)
{
	if (this != &c)
	{
		timeStruct = c.timeStruct;
	}
	return (*this);
}

bool DateTime::operator<(const DateTime& other) const
{
	return (std::mktime(const_cast<std::tm*>(&timeStruct)) < std::mktime(const_cast<std::tm*>(&other.timeStruct)));
}

bool DateTime::operator<=(const DateTime& other) const
{
	return (std::mktime(const_cast<std::tm*>(&timeStruct)) <= std::mktime(const_cast<std::tm*>(&other.timeStruct)));
}

bool DateTime::operator>(const DateTime& other) const
{
	return (std::mktime(const_cast<std::tm*>(&timeStruct)) > std::mktime(const_cast<std::tm*>(&other.timeStruct)));
}

bool DateTime::operator>=(const DateTime& other) const
{
	return (std::mktime(const_cast<std::tm*>(&timeStruct)) >= std::mktime(const_cast<std::tm*>(&other.timeStruct)));
}

bool DateTime::operator==(const DateTime& other) const
{
	return (std::mktime(const_cast<std::tm*>(&timeStruct)) == std::mktime(const_cast<std::tm*>(&other.timeStruct)));
}

bool DateTime::operator!=(const DateTime& other) const
{
	return (std::mktime(const_cast<std::tm*>(&timeStruct)) != std::mktime(const_cast<std::tm*>(&other.timeStruct)));
}
DateTime::~DateTime(){}