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

void VotingSystem::makeAuditFile() {}

void VotingSystem::writeToAuditFile(std::fstream, std::string) {}

std::string VotingSystem::makeMediaFile() { return "Hello"; }

void VotingSystem::printEverything() {}

void VotingSystem::addCandidate(Candidate candidate) {
  candidates.push_back(candidate);
}

void VotingSystem::addWinners(Candidate candidate) {
  winners.push_back(candidate);
}

void VotingSystem::addLosers(Candidate candidate) {
  losers.push_back(candidate);
}

void VotingSystem::addParty(Party party) { parties.push_back(party); }

std::vector<Candidate> &VotingSystem::getCandidates() { return candidates; }

std::vector<Party> &VotingSystem::getParties() { return parties; }

bool VotingSystem::partyExists(char party) {
  for (Party curr : parties) {
  //std::cout << "partyExists Parties: " << parties[0].getPartyName() << std::endl;
  //for (int i = 0; i < parties.size(); i++) {
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

void VotingSystem::displayResults() {
  std::cout << "General Election Information" << std::endl;
  printf("\tElection Type: OPL\n");
  printf("\tTotal Ballots: %d\n", numBallots);

  std::cout << "\nWinners" << std::endl;
  printf("\t%-60s %-15s %-s", "Name", "Party", "Number of Ballots\n");
  for (int i = 0; i < winners.size(); i++) {
    printf("\t%-60s %-15c %-d\n", winners[i].getName().c_str(),
           winners[i].getParty(), winners[i].getNumBallots());
  }

  std::cout << "\nLosers\n" << std::endl;
  printf("\t%-60s %-15s %-s", "Name", "Party", "Number of Ballots\n");
  for (int i = 0; i < losers.size(); i++) {
    printf("\t%-60s %-15c %-d\n", losers[i].getName().c_str(),
           losers[i].getParty(), losers[i].getNumBallots());
  }
}