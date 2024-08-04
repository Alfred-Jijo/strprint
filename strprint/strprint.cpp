#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>

std::string to_lower(const std::string& str) {
	std::string result = str;
	for (char& c : result) {
		c = tolower(c);
	}
	return result;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		std::cout << "Usage: strprint /path/to/file <string>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string strToFind(argv[2]);
	std::ifstream searchFile(argv[1]);
	std::string line;

#if _DEBUG // shows cli args
	       // prints full file
	std::cout << "Read from file:" << '\t' << argv[1] << std::endl
			  << "Search in file:" << '\t' << argv[2] << std::endl
		      << std::endl;

	
	while (std::getline(searchFile, line)) {
		std::cout << line << std::endl;
	}
#endif

	int lineNo = 1;
	while (std::getline(searchFile, line)) {
		line = to_lower(line);
		if (line.find(strToFind) != std::string::npos) {
			std::cout << lineNo << ":\t" 
				      << line << std::endl;
		}
		lineNo++;
	}

	searchFile.close();

#if _DEBUG
	std::cin.get();
#endif
	return EXIT_SUCCESS;
}
