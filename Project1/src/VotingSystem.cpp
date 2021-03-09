#include "VotingSystem.h"

int VotingSystem::getNumBallots() { return numBallots; }

double VotingSystem::getTimeTaken() {
  // return timeStart - timeEnd;
}

// takes in vector of candidates that are tied and
// chooses a winner from them
Candidate VotingSystem::breakTie(std::vector<Candidate> candidates) {
  // gives a number between 0 and the size of
  // the vector minus 1. Returns the candidate
  // at that index of the vector
  return candidates.at(rand() % candidates.size());
}

void VotingSystem::addWinners(Candidate candidate) {  // what does this return?
  winners.push_back(candidate);
}

std::fstream VotingSystem::makeAuditFile() {
  
}

void VotingSystem::writeToAuditFile(std::fstream, std::string) {}

std::string VotingSystem::makeMediaFile() {}

void VotingSystem::printEverything() {}