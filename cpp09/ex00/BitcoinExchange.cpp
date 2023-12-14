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
	if (!inputFile.is_open())
		throw std::exception();
	std::tm timeStruct = {};

	if (!std::getline(inputFile, input))
	{
		std::cerr<<"Empty file"<<std::endl;
		exit (1);
	}
	std::string	name1 = "exchange_rate";
	std::string	name2 = "date";
	if (not_valid(input, const_cast<char *>(name2.c_str()), const_cast<char *>(name1.c_str()), ','))
	{
		std::cerr<<"Error in organzition"<<std::endl;
		exit (1);
	}
	while (std::getline(inputFile, input))
	{
		if (not_valid_input(input, ','))
		{
			std::cout<<"Error parsing *.csv"<<std::endl;
			exit (1);
		}
		if (sscanf(input.c_str(), "%d-%d-%d", &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday) == 3)
		{
			int	check = timeStruct.tm_mon % 2;
			int	check2 = timeStruct.tm_year % 4;
			int days;
			if (check2)
				days = 28;
			else
				days = 29;
			if ((check && timeStruct.tm_mday > 31) || (!check && timeStruct.tm_mon == 2 && timeStruct.tm_mday > days) || (!check && timeStruct.tm_mon != 8 && timeStruct.tm_mon != 10 && timeStruct.tm_mon != 12 && timeStruct.tm_mday > 30))
			{
				std::cout<<timeStruct.tm_mon<< " " << check <<std::endl;
				std::cerr << "Failed to parse date "<< input << std::endl;
				exit (1);
			}
			if (timeStruct.tm_mday > 31 || timeStruct.tm_mon > 12 || timeStruct.tm_year < 0)
			{
				std::cerr << "Failed to parse date" << std::endl;
				exit (1);
			}
		}
		else
		{
			std::cerr << "Failed to parse date" << std::endl;
			exit(1);
		}
		int k = input.find_first_of(",");
		char	*err;

		val = strtod(&input.at(k + 1), &err);
		err = ft_strtrim(err, " \t");
		if (*err)
		{
			std::cerr<<"Error in file *.csv"<<std::endl;
			exit(0);
		}
		delete err;
		if (val < 0)
		{
			std::cerr<<"Error in file *.csv"<<std::endl;
			exit (1);
		}
		else
		{
			DateTime a(timeStruct.tm_year, timeStruct.tm_mon, timeStruct.tm_mday);
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


DateTime::DateTime(int year, int month, int day) : year(year), month(month), day(day) {}

DateTime::DateTime(const DateTime& c)
{
	*this = c;
}

DateTime& DateTime::operator = (const DateTime& c)
{
	if (this != &c)
	{
		year = c.year;
		month = c.month;
		day = c.day;
	}
	return (*this);
}

bool DateTime::operator<(const DateTime& other) const
{
	int y1;
	int m1;
	int d1;
	int t1;
	int t2;

	y1 = this->year;
	m1 = this->month;
	d1 = this->day;
	t2 = (((y1 * 100) + m1) * 100) + d1;
	
	y1 = other.year;
	m1 = other.month;
	d1 = other.day;
	t1 = (((y1 * 100) + m1) * 100) + d1;
	if (t2 < t1)
		return (true);
	return (false);
}

bool DateTime::operator==(const DateTime& other) const
{
	int y1;
	int m1;
	int d1;
	int t1;
	int t2;

	y1 = this->year;
	m1 = this->month;
	d1 = this->day;
	t2 = (((y1 * 100) + m1) * 100) + d1;
	
	y1 = other.year;
	m1 = other.month;
	d1 = other.day;
	t1 = (((y1 * 100) + m1) * 100) + d1;
	if (t1 == t2)
		return (true);
	return (false);
}

bool DateTime::operator!=(const DateTime& other) const
{
	int y1;
	int m1;
	int d1;
	int t1;
	int t2;

	y1 = this->year;
	m1 = this->month;
	d1 = this->day;
	t2 = (((y1 * 100) + m1) * 100) + d1;
	
	y1 = other.year;
	m1 = other.month;
	d1 = other.day;
	t1 = (((y1 * 100) + m1) * 100) + d1;
	if (t1 == t2)
		return (false);
	return (true);
}

DateTime::~DateTime(){}