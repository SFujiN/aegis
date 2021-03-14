#include "Party.h"

Party::Party(char p) : name(p) {}

char Party::getPartyName() { return name; }

int Party::getNumBallots() {
  int total = 0;
  for (auto it = partyMembers.begin(); it != partyMembers.end(); it++) {
    total += (*it)->getNumBallots();
  }
  return total;
}

int Party::getSeatsWon() { return seatsWon; }

int Party::getRemainder() { return Remainder; }

void Party::setSeatsWon(int seats) { seatsWon = seats; }

void Party::setRemainder(int num) { Remainder = num; }

void Party::addCandidate(Candidate *candidate) {
  partyMembers.push_back(candidate);
}