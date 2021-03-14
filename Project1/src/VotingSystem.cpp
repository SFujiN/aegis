#include "VotingSystem.h"

VotingSystem::VotingSystem(std::string type, int candidates, int seats,
                           int ballots)
    : electionType(type),
      numCandidates(candidates),
      numSeats(seats),
      numBallots(ballots) {}

int VotingSystem::getNumBallots() { return numBallots; }

double VotingSystem::getTimeTaken() { return 0; }

void VotingSystem::runElection() {
  std::sort(candidates.begin(),candidates.end());
  std::reverse(candidates.begin(),candidates.end());
}

void VotingSystem::displayResults() {
  for (Candidate curr : candidates) {
    std::cout << curr.getName() << " " << curr.getParty() <<  " with " << curr.getNumBallots() << " votes." << std::endl;
  }
}

void VotingSystem::setAuditFileName(){
  std::chrono::system_clock::time_point tp = system_clock::now();
  std::chrono::system_clock::duration dtn = tp.time_since_epoch();
  auditfilename = std::to_string(dtn.count())+"txt";
}

void VotingSystem::makeAuditFile() {
   std::chrono::system_clock::time_point tp = system_clock::now();
   std::chrono::system_clock::duration dtn = tp.time_since_epoch();
   auditFile.open(auditfilename);
   auditFile.close();
}

void VotingSystem::writeToAuditFile(std::string string) {
  auditFile.open(auditfilename);
  auditFile << string << std::endl;
  auditFile.close();
}

void VotingSystem::makeMediaFile(std::string string) { 
  mediaFile.open("Media" + auditfilename);
  mediaFile << string << std::endl;
  mediaFile.close();

}

void VotingSystem::printEverything() {}

void VotingSystem::addCandidate(Candidate candidate) {
  candidates.push_back(candidate);
}

void VotingSystem::addParty(Party party) { parties.push_back(party); }

std::vector<Candidate> &VotingSystem::getCandidates() { return candidates; }

std::vector<Party> &VotingSystem::getParties() { return parties; }

bool VotingSystem::partyExists(char party) {
  for (Party curr : parties) {
    if (curr.getPartyName() == party) {
      return true;
    }
  }
  return false;
}

void VotingSystem::assignParty() {
  for(auto party = parties.begin(); party != parties.end(); party++) {
    for(auto candidate = candidates.begin(); candidate != candidates.end(); candidate++ ) {
      if (party->getPartyName() == candidate->getParty()) {
        this->addCandidate(*candidate);
      }
    }
  }
}