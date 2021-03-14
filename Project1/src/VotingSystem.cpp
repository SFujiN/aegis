#include "VotingSystem.h"

/* VotingSystem::VotingSystem(std::string type, int candidates, int seats,
                           int ballots)
    : electionType(type),
      numCandidates(candidates),
      numSeats(seats),
      numBallots(ballots) {}
 */
int VotingSystem::getNumBallots() { return numBallots; }

double VotingSystem::getTimeTaken() { return 0; }

void VotingSystem::runElection() {
  std::sort(candidates.begin(), candidates.end());
  std::reverse(candidates.begin(), candidates.end());
}

void VotingSystem::displayResults() {
  for (Candidate curr : candidates) {
    std::cout << curr.getName() << " " << curr.getParty() << " with "
              << curr.getNumBallots() << " votes." << std::endl;
  }
}

void VotingSystem::makeAuditFile() {}

void VotingSystem::writeToAuditFile(std::fstream, std::string) {}

std::string VotingSystem::makeMediaFile() { return "Hello"; }

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
  for (int i = 0; i < parties.size(); i++) {
    for (int j = 0; j < candidates.size(); j++) {
      if (parties[i].getPartyName() == candidates[j].getParty()) {
        parties[i].addCandidate(
            &candidates[j]);  // If the party names (char) are the same
      }
    }
  }
}