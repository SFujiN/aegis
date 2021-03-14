<<<<<<< HEAD
// #include <fstream>
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <vector>

#include "helpers.h"
#include "VotingSystem.h"

int main(int argc, char *argv[]) {
  std::string fileName, fileContent, electionType, line;
  std::fstream file;
  int candidateNum, seatNum, ballotNum;
  std::vector<std::string> candidateNames, rawBallotInfo;
  VotingSystem *Aegis;
  std::cout << "Prototype: Aegis 0.0" << std::endl;

  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <file name>" << std::endl;
  }
  if (argc == 2) {
    fileName = argv[1];
    file.open(fileName, std::ios::in);

    if (!file.is_open()) {
      std::cout << "Couldn't open: " << fileName << std::endl;
    } else {
      getline(file, electionType);
      file >> candidateNum;
      getline(file, line);
      getline(file, line);
      if (electionType == "OPL") {
        candidateNames = extractOPLNames(line);
        file >> seatNum >> ballotNum;
      }
      if (electionType == "IR") {
        candidateNames = extractIRNames(line);
        seatNum = 1;
        file >> ballotNum;
      }
      getline(file, line);
      while (getline(file, line)) {
        rawBallotInfo.push_back(line);
      }
      Aegis = new VotingSystem(electionType, candidateNum, seatNum, ballotNum);

      if (electionType == "OPL") {
        for (auto it = candidateNames.begin(); it != candidateNames.end();
             it++) {
          char partyLetter = it->at(it->find(',') + 1);
          if (!Aegis->partyExists(partyLetter)) {
            Aegis->addParty(Party(partyLetter));
          }
          Aegis->addCandidate(
              Candidate(partyLetter, it->substr(0, it->find(','))));
        }
        for (auto it = rawBallotInfo.begin(); it != rawBallotInfo.end(); it++) {
          Aegis->getCandidates()
              .at(OPLBallotToIndex(*it))
              .addBallot(Ballot(BallotToVec(candidateNum, *it)));
        }
      }

      if (electionType == "IR") {
        for (auto it = candidateNames.begin(); it != candidateNames.end();
             it++) {
          std::string line = *it;
          char partyLetter = it->at(it->find('(') + 1);
          if (!Aegis->partyExists(partyLetter)) {
            Aegis->addParty(Party(partyLetter));
          }
          Aegis->addCandidate(
              Candidate(partyLetter, it->substr(0, it->find(' '))));
        }
        for (auto it = rawBallotInfo.begin(); it != rawBallotInfo.end(); it++) {
          Aegis->getCandidates()
              .at(IRBallotToIndex(*it))
              .addBallot(Ballot(IRBallotToVec(candidateNum, *it)));
        }
      }
      // print out the vector of strings holding ballot info
      // printVec(rawBallotInfo);

      // print out the index value of first ballet
      // std::cout << OPLBallotToIndex(rawBallotInfo.at(0)) << std::endl;

      // print to see what's in a ballot vector
      // printVecI(test2);

      for (auto it = Aegis->getParties().begin();
           it != Aegis->getParties().end(); it++) {
        std::cout << it->getPartyName() << " ";
      }
      std::cout << std::endl;

      // Aegis->assignParty();
      Aegis->runElection();

      // std::cout << "Election Type: \t" << electionType << std::endl;
      // std::cout << "Number of Candidates: \t" << candidateNum << std::endl;
      // std::cout << "Names of Candidates:" << std::endl;
      // printVec(candidateNames);
      // std::cout << "Number of seats: \t" << seatNum << std::endl;
      // std::cout << "Number of ballots: \t" << ballotNum << std::endl;
      // std::cout << "Raw ballow info:" << std::endl;
      // printVec(rawBallotInfo);
    }

    delete Aegis;

    file.close();
  }

  return 0;
=======
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> *extractOPLNames(std::string line) {
  std::vector<std::string> *names = new std::vector<std::string>();
  std::string name;
  char open = '[';
  char close = ']';
  std::size_t f, s, f_old = 0, s_old = 0;

  while ((f = line.find(open, f_old)) != std::string::npos &&
         (s = line.find(close, s_old)) != std::string::npos) {
    f_old = f + 1;
    s_old = s + 1;

    name = line.substr(f + 1, s - f - 1);
    names->push_back(name);
  }
  return names;
}

std::vector<std::string> *extractIRNames(std::string line) {
	std::vector<std::string> *names = new std::vector<std::string>();
	std::stringstream strStream(line);
	std::string name;

	while(std::getline(strStream, name, ',')) {
		names->push_back(name);
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
			if (electionType == "OPL") {
				candidateNames = extractOPLNames(line);
				file >> seats >> ballotNum;
			}
			if (electionType == "IR") {
				candidateNames = extractIRNames(line);
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
>>>>>>> development
}
