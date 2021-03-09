#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> *extractNames(std::string line) {
  std::vector<std::string> *names = new std::vector<std::string>();
  std::string word;
  char open = '[';
  char close = ']';
  std::size_t f, s, f_old = 0, s_old = 0;

  while ((f = line.find(open, f_old)) != std::string::npos &&
         (s = line.find(close, s_old)) != std::string::npos) {
    f_old = f + 1;
    s_old = s + 1;

    word = line.substr(f + 1, s - f - 1);
    names->push_back(word);
  }
  return names;
}

void printVec(std::vector<std::string> *vec) {
	for(auto it = vec->begin(); it != vec->end(); it++) {
		std::cout << "\t" << *it << std::endl;
	}
}

int main(int argc, char *argv[]) {
	std::string fileName, fileContent, electionType, line;
	std::fstream file;
	int candidateNum, seats, ballotNum;
	std::vector<std::string> *candidateNames, *rawBallotInfo = new std::vector<std::string>();
	std::cout << "Prototype: Aegis 0.0" << std::endl;

	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <file name>" << std::endl;
	}
	if(argc == 2) {
		fileName = argv[1];
		file.open(fileName, std::ios::in);

		if(!file.is_open()) {
			std::cout << "Couldn't open: " << fileName << std::endl;
		} else {
			// file.seekg(0, std::ios::end);
			// auto size = file.tellg();
			// fileContent = std::string(size, '\0');
			// file.seekg(0);
			// file.read(&fileContent[0], size);

			// std::cout << "file name: " << fileName << std::endl;
			// std::cout << "file content: \n" << fileContent << std::endl;

			getline(file, electionType);
			file >> candidateNum;
			getline(file, line);
			getline(file, line);
			candidateNames = extractNames(line);
			if (electionType == "OPL") {
				file >> seats >> ballotNum;
			}
			if (electionType == "IR") {
				seats = 1;
				file >> ballotNum;
			}
			getline(file, line);
			while(getline(file, line)) {
				rawBallotInfo->push_back(line);
			}

			std::cout << "Election Type: \t" << electionType << std::endl;
			std::cout << "Number of Candidates: \t" << candidateNum << std::endl;
			std::cout << "Names of Candidates:" << std::endl;
			printVec(candidateNames);
			std::cout << "Number of seats: \t" << seats << std::endl;
			std::cout << "Number of ballots: \t" << ballotNum << std::endl;
			std::cout << "Raw ballow info:" << std::endl;
			printVec(rawBallotInfo);
		}

		delete candidateNames;
		delete rawBallotInfo;

		file.close();
	}

	return 0;
}
