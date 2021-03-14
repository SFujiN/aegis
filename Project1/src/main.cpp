// #include <fstream>
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <vector>

#include "VotingSystem.h"

int OPLBallotToIndex(std::string ballot) { return ballot.find('1'); }

int IRBallotToIndex(std::string ballot) {
  int index = 0;
  std::string number{};
  int length = ballot.find('1');
  std::string line = ballot.substr(0, length);
  std::stringstream strStream(line);

  while (std::getline(strStream, number, ',')) {
    index++;
  }

  return index;
}

std::vector<int> BallotToVec(int num, std::string ballot) {
  std::vector<int> result(num);
  std::stringstream strStream(ballot);
  std::string val;

  for (int i = 0; std::getline(strStream, val, ','); i++) {
    if (val.length() != 0) {
      result.at(i) = std::stoi(val);
    }
  }

  return result;
}

std::vector<int> IRBallotToVec(int num, std::string ballot) {
  std::vector<int> result(num);
  std::vector<int> ballotVec = BallotToVec(num, ballot);

  for (int i = 0; i < num; i++) {
    if (ballotVec.at(i) != 0) {
      result.at(ballotVec.at(i) - 1) = i + 1;
    }
  }

  return result;
}

std::string popItem(std::string &line, char l, char r) {
  std::size_t open, close, len;
  std::string name;
  open = line.find(l);
  close = line.find(r);
  len = close - open;

  name = line.substr(open + 1, (len)-1);
  line = line.substr(close + 1, line.length() - close - 1);

  return name;
}

std::vector<std::string> extractOPLNames(std::string line) {
  std::vector<std::string> names;
  std::string name;
  char open = '[';
  char close = ']';

  while ((name = popItem(line, open, close)) != "") {
    names.push_back(name);
  }

  return names;
}

std::vector<std::string> extractIRNames(std::string line) {
  std::vector<std::string> names;
  std::stringstream strStream(line);
  std::string name;

  while (std::getline(strStream, name, ',')) {
    names.push_back(name);
  }

  return names;
}

void printVec(std::vector<std::string> vec) {
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << "\t" << *it << std::endl;
  }
}

void printVecI(std::vector<int> vec) {
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << "\t" << *it << " ";
  }
  std::cout << std::endl;
}

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
}
