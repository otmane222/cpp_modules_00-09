#pragma once

#include <iostream>
#include <map>
#include <ctime>
#include <time.h>
#include <fstream>
#include <sstream>
#include <string>


class DateTime
{
	public:
		std::tm timeStruct;
		DateTime(std::tm timeStruct);
		DateTime(const DateTime& c);
		DateTime& operator = (const DateTime& c);

		bool operator<(const DateTime& other) const;

		bool operator<=(const DateTime& other) const;

		bool operator>(const DateTime& other) const;

		bool operator>=(const DateTime& other) const;

		bool operator==(const DateTime& other) const;

		bool operator!=(const DateTime& other) const;
		~DateTime();
};

class BitcoinExchange
{
	private:
		std::map<DateTime, double > myMap;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &c);
		BitcoinExchange & operator=(const BitcoinExchange &c);
		std::map<DateTime, double > getMap();
};

bool	not_valid(std::string input , char *s1, char *s2,char c);
bool	not_valid_input(std::string input, char c);