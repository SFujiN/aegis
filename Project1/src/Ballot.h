#ifndef BALLOT_H
#define BALLOT_H
#include <vector>

class Ballot {
 public:
  // constructor
  Ballot(std::vector<int> v1);

  // setters methods
  void incrCurrent();

 private:
  std::vector<int> candidates;
  int currBallot = 0;
};

#endif
