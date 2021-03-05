#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
	std::string fileName, fileContent;
	std::fstream file;
	std::cout << "Prototype: Aegis 0.0" << std::endl;

	if(argc != 2) {
		std::cout << "Usage: ./proto <file name>" << std::endl;
	}
	if(argc == 2) {
		fileName = argv[1];
		file.open(fileName, std::ios::in);

		if(!file.is_open()) {
			std::cout << "Couldn't open: " << fileName << std::endl;
		} else {
			file.seekg(0, std::ios::end);
			auto size = file.tellg();
			fileContent = std::string(size, '\0');
			file.seekg(0);
			file.read(&fileContent[0], size);

			std::cout << "file name: " << fileName << std::endl;
			std::cout << "file content: \n" << fileContent << std::endl;
		}

		file.close();
	}

	return 0;
}
