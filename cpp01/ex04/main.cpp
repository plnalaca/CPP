#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	if (s1.empty())
		return str;

	while ((found = str.find(s1, pos)) != std::string::npos)
	{
		result.append(str, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(str, pos, str.length() - pos);
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return 1;
	}

	std::string outFilename = filename + ".replace";
	std::ofstream outfile(outFilename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Cannot create file " << outFilename << std::endl;
		infile.close();
		return 1;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		outfile << replaceAll(line, s1, s2) << std::endl;
	}

	infile.close();
	outfile.close();

	std::cout << "File created: " << outFilename << std::endl;
	return 0;
}
