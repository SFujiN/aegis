#include <stdlib.h>

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "Candidate.h"


class VotingSystem {
 public:
  int getNumBallots();
  double getTimeTaken();
  Candidate breakTie(std::vector<Candidate>);
  void addWinners(Candidate);
  virtual void runElection();
  virtual void displayResults();
  std::fstream makeAuditFile();
  void writeToAuditFile(std::fstream, std::string);
  std::string makeMediaFile();
  void printEverything();
  VotingSystem();


 protected:
  std::string fileName;
  int numBallots;
  double timeTaken;
  std::vector<Candidate> candidates;
  std::vector<Candidate> winners;
};