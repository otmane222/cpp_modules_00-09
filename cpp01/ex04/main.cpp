#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <target_string> <replacement_string>" << std::endl;
		return (1);
	}
	std::string	filename = av[1];
	std::string	target = av[2];
	std::string	replacement = av[3];
	std::string	filereplace = filename + ".replace";
	std::string	line;

	std::ifstream	inputFile(filename);
	if (!inputFile)
	{
		std::cerr << "Error: Unable to open file." << std::endl;
		return (1);
	}
	std::ofstream	outputFile(filereplace);
	if (!outputFile)
	{
		std::cerr << "Error: Unable to create file." << std::endl;
		inputFile.close();
		return (1);
	}
	while (std::getline(inputFile, line))
	{
		size_t	pos;
		size_t	k = line.find(target);
		while ((pos = line.find(target, k)) != std::string::npos) // std::string::npos == -1
		{
			line.erase(pos, target.length());
			line.insert(pos, replacement);
			k = pos + replacement.length();
			
		}
		if (!inputFile.eof())
			outputFile << line << std::endl;
		else
			outputFile << line;
	}
	inputFile.close();
	outputFile.close();

	return (0);
}