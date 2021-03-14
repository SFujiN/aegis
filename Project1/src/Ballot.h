#ifndef BALLOT_H
#define BALLOT_H
#include <vector>

class Ballot {
 public:
  // constructor
  Ballot(std::vector<int> v1);

  // setters methods
  void incrCurrent();

  // getters methods
  std::vector<int> getCandidates();
  int getCurrBallotIndex(); //candidates[ballot1.getCandidates().at(ballot1.getCurrent())-1]

 private:
  std::vector<int> candidates;
  int currBallot = 0;
};

#endif
