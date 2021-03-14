#include "OPL.h"
OPL::OPL(std::string type, int candidates, int seats, int ballots) {
  electionType = type;
  numCandidates = candidates;
  numSeats = seats;
  numBallots = ballots;
}
void OPL::groupIndependentParties() {}

void OPL::sortByVotes() {  // I know this is insertion sort, may God have mercy
                           // on my soul
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
  // sort(parties.begin(), parties.end(), sortNumBallots);
  sortByVotes();
  for (int i = 0; i < parties.size(); i++) {  // For loop start for each party
    // std::cout << "allocateSeatsParties" << std::endl;
    // std::cout << "num seats: " << numSeats << std::endl;
    Party &currParty = parties[i];
    int seats = (int)currParty.getNumBallots() / quota;
    if (currParty.getPartyMembers().size() > seats) {
      numSeats -= seats;
      currParty.setRemainder(currParty.getNumBallots() % quota);
    } else if (currParty.getPartyMembers().size() == seats) {
      numSeats -= seats;
      currParty.setRemainder(0);
    } else {  // party.sizeof(Candidates) < seats THESE GUYS MIGHT GET TOO MANY
              // SEATS
      numSeats -= currParty.getPartyMembers().size();
      currParty.setRemainder(0);
    }
    // std::cout << "party: " << currParty.getPartyName() << std::endl;
    // std::cout << "allocateSeats seats: " << seats << std::endl;
    currParty.setSeatsWon(seats);
    // std::cout << "getSeats: " << currParty.getSeatsWon() << std::endl;
  }  // For loop end
  // sort(parties.begin(), parties.end(), sortRemainder);
  sortByRemainder();
  int i = 0;
  // std::cout << "allocateSeats numSeats while: " << numSeats << std::endl;
  while (numSeats != 0) {
    // std::cout << "i: " << i << std::endl;
    // Party &currParty = parties[i];
    // std::cout << "allocateSeats getSeatsWon while: " <<
    // currParty.getSeatsWon() << std::endl;
    parties[i].setSeatsWon(parties[i].getSeatsWon() + 1);
    i++;
    numSeats--;
  }
  // printPartyInfo();
}

void OPL::findPartyWinners() {
  for (int i = 0; i < parties.size(); i++) {
    // std::cout << "findPartyWinnersParties" << std::endl;
    parties[i].sortByVotes();
    std::vector<Candidate *> partyMembers = parties[i].getPartyMembers();
    // std::cout << "seats won: " << parties[i].getSeatsWon() << std::endl;
    // std::cout << "parties size: " << partyMembers.size() << std::endl;

    for (int j = 0; j < parties[i].getSeatsWon(); j++) {
      addWinners(*partyMembers[j]);
    }

    /* numSeats = parties[i].getSeatsWon();
    for (size of parties[i]) {
      if (numSeats != 0) {
        addWinners(*partyMembers[j]);
        numSeats--;
      } else {
        addLosers(*partyMembers[j]);
      }
    } */
  }
}

//[Pike,D],[Foster,D],[Deustsch,R],[Borg,R],[Jones,R],[Smith,I]

void OPL::runElection() {
  // iterate through all parties and add up ballots
  for (int i = 0; i < parties.size(); i++) {
    // std::cout << "runElectionParties" << std::endl;
    std::vector<Candidate *> partyMembers = parties[i].getPartyMembers();
    for (int j = 0; j < partyMembers.size(); j++) {
      parties[i].setNumBallots(parties[i].getNumBallots() +
                               partyMembers[j]->getNumBallots());
    }
  }

  quota = numBallots / numSeats;
  // printPartyInfo();
  allocateSeats();
  // printPartyInfo();
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
  printf("\t%60s, %15s, %s", "Name", "Party", "Number of Ballots");
  for (int i = 0; i < winners.size(); i++) {
    printf("\t%60s, %15c, %d\n", winners[i].getName().c_str(),
           winners[i].getParty(), winners[i].getNumBallots());
  }

  std::cout << "\nLosers\n" << std::endl;
  printf("\t%60s, %15s, %s", "Name", "Party", "Number of Ballots");
  for (int i = 0; i < losers.size(); i++) {
    printf("\t%60s, %15c, %d\n", losers[i].getName().c_str(),
           losers[i].getParty(), losers[i].getNumBallots());
  }
}

void OPL::setParties(std::vector<Party> parties_) { parties = parties_; }

// void OPL::runElection() { std::cout << "run" << std::endl; }
// void OPL::displayResults() { std::cout << "display" << std::endl; }