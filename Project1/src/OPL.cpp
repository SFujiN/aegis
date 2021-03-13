#include "OPL.h"
OPL::OPL(){}
void OPL::groupIndependentParties() {}

void OPL::allocateSeats() {
  sort(parties.begin(), parties.end(),
       sortNumBallots);  // sort by num votes TODO: If there's a problem, it's
                         // probably here lul
  for (int i = 0; i < parties.size(); i++) {  // For loop start for each party
    Party currParty = parties[i];
    int seats = (int)currParty.getNumBallots() / quota;
    if (currParty.getPartyMembers().size() > seats) {
      numSeats -= seats;
      currParty.setRemainder(currParty.getNumBallots() % quota);
    } else if (currParty.getPartyMembers().size() == seats) {
      numSeats -= seats;
      currParty.setRemainder(0);
    } else {  // party.sizeof(Candidates) < seats
      numSeats -= currParty.getPartyMembers().size();
      currParty.setRemainder(0);
    }
    currParty.setSeatsWon(numSeats);
  }  // For loop end
  sort(parties.begin(), parties.end(),
       sortRemainder);  // sort by remainder TODO: If there's a problem, it's
                        // probably here lul
  int i = 0;
  while (numSeats != 0) {
    parties[i].setSeatsWon(parties[i].getSeatsWon() + 1);
    i++;
    numSeats--;
  }
}

void OPL::findPartyWinners() {
  for (int i = 0; i < parties.size(); i++) {
    std::vector<Candidate> partyMembers = parties[i].getPartyMembers();
    std::sort(
        partyMembers.begin(),
        partyMembers.end());  // write candidates overload operator function
    for (int j = 0; j < parties[i].getSeatsWon(); j++) {
      addWinners(partyMembers[j]);
    }
  }
}

//[Pike,D],[Foster,D],[Deustsch,R],[Borg,R],[Jones,R],[Smith,I]

void OPL::runElection() {
  for (int i = 0; i < parties.size(); i++) {
    std::vector<Candidate> partyMembers = parties[i].getPartyMembers();
    for (int j = 0; j < partyMembers.size(); j++) {
      parties[i].setNumBallots(parties[i].getNumBallots() +
                               partyMembers[j].getNumBallots());
    }
  }

  quota = numBallots / numSeats;
  allocateSeats();
  findPartyWinners();
}

void OPL::displayResults() {
  std::cout << "General Election Information" << std::endl;
  printf("\tElection Type: OPL\n");
  printf("\tTotal Ballots: %d\n", numBallots);

  std::cout << "\nWinners\n" << std::endl;
  printf("\t%60s, %15s, %s", "Name", "Party", "Number of Ballots");
  for (int i = 0; i < winners.size(); i++) {
    printf("\t%60s, %15s, %d\n", winners[i].getName(), winners[i].getParty(), winners[i].getNumBallots());
  }

  std::cout << "\nLosers\n" << std::endl;
  printf("\t%60s, %15s, %s", "Name", "Party", "Number of Ballots");
  for (int i = 0; i < losers.size(); i++) {
    printf("\t%60s, %15s, %d\n", losers[i].getName(), losers[i].getParty(), losers[i].getNumBallots());
  }
}

void OPL::setParties(std::vector<Party> parties_){
  parties = parties_;
}
