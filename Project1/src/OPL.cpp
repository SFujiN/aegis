#include "OPL.h"

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
  std::string fileLine;
  std::getline(fileName, fileLine);  // make sure fileName is fstream or w/e
  numCandidates = std::stoi(fileLine);
  std::getline(fileName, fileLine);  // get third line of file
  // assign candidates
  for (int j = 0; j < numCandidates; j++) { //TODO: halp
    std::getline(fileLine, fileLine, ',');
    std::string name;
    char party;
    name = fileLine[0];
    party = fileLine[1];
    Candidate newCandidate = new Candidate;
    Candidate.name = name;
    Candidate.party = party;
  }

  std::getline(fileName, fileLine);
  numSeats = fileLine;
  if (numSeats > numCandidates) {
    numSeats = numCandidates;  // handles exception of too many seats
  }
  std::getline(fileName, fileLine);
  numBallots = fileLine;
  for (int i = 0; i < numBallots; i++) {
    std::getline(fileName, fileLine);
    Ballot ballot = new Ballot();
    // fill this in
  }

  quota = numBallots / numSeats;
  allocateSeats();
  findPartyWinners();
}

void OPL::displayResults() {}