#ifndef VOTINGSYSTEM_H
#define VOTINGSYSTEM_H

#include <stdlib.h>

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Ballot.h"
#include "Candidate.h"
#include "Party.h"

class VotingSystem {
 public:
  //VotingSystem(std::string type, int candidates, int seats, int ballots);
  int getNumBallots();
  double getTimeTaken();
  // Candidate breakTie(std::vector<Candidate>);
  void addWinners(Candidate candidate);
  void addLosers(Candidate candidate);
  virtual void runElection();
  virtual void displayResults();
  void makeAuditFile();
  void writeToAuditFile(std::fstream, std::string);
  std::string makeMediaFile();
  void printEverything();
  void addCandidate(Candidate candidate);
  void addParty(Party party);
  std::vector<Candidate> &getCandidates();
  std::vector<Party> &getParties();
  bool partyExists(char party);
  void assignParty();

 protected:
  std::string electionType;
  int numCandidates;
  int numSeats;
  int numBallots;
  double timeTaken;
  std::vector<Candidate> candidates;
  std::vector<Party> parties;

  std::vector<Candidate> winners;
  std::vector<Candidate> losers; //this can be: print out vector of candidates after popping all winners(?)
};
#endif