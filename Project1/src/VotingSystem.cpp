#include "VotingSystem.h"

int VotingSystem::getNumBallots(){
  return numBallots;
}

double VotingSystem::getTimeTaken(){
  //return timeStart - timeEnd;
}

Candidate VotingSystem::breakTie(){}

Candidate VotingSystem::addWinners(Candidate candidate){ //what does this return?
  winners.push_back(candidate);
}

std::fstream VotingSystem::makeAuditFile(){} //

void VotingSystem::writeToAuditFile(std::fstream, std::string){}

std::string VotingSystem::makeMediaFile(){}

void VotingSystem::printEverything(){}
