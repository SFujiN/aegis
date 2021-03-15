#include "OPL.h"

OPL::OPL(std::string type, int candidates, int seats, int ballots) {
  electionType = type;
  numCandidates = candidates;
  numSeats = seats;
  numBallots = ballots;
}

void OPL::sortByVotes() {
  int i, j;
  for (i = 1; i < parties.size(); i++) {
    Party key = parties[i];
    j = i - 1;
    while (j >= 0 && parties[j].getNumBallots() < key.getNumBallots()) {
      parties[j + 1] = parties[j];
      j = j - 1;
    }
    parties[j + 1] = key;
  }
}

void OPL::sortByRemainder() {
  int i, j;
  for (i = 1; i < parties.size(); i++) {
    Party key = parties[i];
    j = i - 1;
    while (j >= 0 && parties[j].getRemainder() < key.getRemainder()) {
      parties[j + 1] = parties[j];
      j = j - 1;
    }
    parties[j + 1] = key;
  }
}

void OPL::allocateSeats() {
  sortByVotes();
  for (int i = 0; i < parties.size(); i++) {  // For loop start for each party
    Party &currParty = parties[i];
    int seats = (int)currParty.getNumBallots() / quota;
    if (currParty.getPartyMembers().size() > seats) {
      numSeats -= seats;
      currParty.setRemainder(currParty.getNumBallots() % quota);
    } else if (currParty.getPartyMembers().size() == seats) {
      numSeats -= seats;
      currParty.setRemainder(0);
    } else {
      numSeats -= currParty.getPartyMembers().size();
      currParty.setRemainder(0);
    }
    currParty.setSeatsWon(seats);
  }  // For loop end
  sortByRemainder();

  int i = 0;
  while (numSeats != 0) {
    parties[i].setSeatsWon(parties[i].getSeatsWon() + 1);
    i++;
    numSeats--;
  }
}

void OPL::findPartyWinners() {
  for (int i = 0; i < parties.size(); i++) {
    parties[i].sortByVotes();
    std::vector<Candidate *> partyMembers = parties[i].getPartyMembers();

    numSeats = parties[i].getSeatsWon();
    for (int k = 0; k < partyMembers.size(); k++) {
      if (numSeats != 0) {
        addWinners(*partyMembers[k]);
        numSeats--;
      } else {
        addLosers(*partyMembers[k]);
      }

    }
  }
}

void OPL::runElection() {
  makeAuditFile();
  // iterate through all parties and add up ballots
  for (int i = 0; i < parties.size(); i++) {
    std::vector<Candidate *> partyMembers = parties[i].getPartyMembers();
    for (int j = 0; j < partyMembers.size(); j++) {
      parties[i].setNumBallots(parties[i].getNumBallots() +
                               partyMembers[j]->getNumBallots());

    }
  }

  quota = numBallots / numSeats;
  writeToAuditFile("Quota per seat is: " + std::to_string(quota) + "\n");
  allocateSeats();
  findPartyWinners();
}

void OPL::printPartyInfo() {
  for (int i = 0; i < parties.size(); i++) {
    std::cout << "name: " << parties[i].getPartyName() << std::endl;
    std::cout << "numBallots: " << parties[i].getNumBallots() << std::endl;
    std::cout << "seatsWon: " << parties[i].getSeatsWon() << std::endl;
    std::cout << "remainder: " << parties[i].getRemainder() << std::endl;
  }
}

void OPL::displayResults() {
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

void OPL::setParties(std::vector<Party> parties_) { parties = parties_; }
