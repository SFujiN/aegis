#ifndef OPL_H
#define OPL_H
// TODO: delete these and put in votingSystem
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

#include "Party.h"
#include "VotingSystem.h"

class OPL : public VotingSystem {
 public:
  OPL(std::string type, int candidates, int seats, int ballots);
  void sortByVotes();
  void sortByRemainder();
  void groupIndependentParties();
    /**
 * @brief Gives Seats to parties.
 * 
 * Sorts the parties by number of votes and then allocates the amount of seats
 * by the amount of votes that they got divided by the quota.
 * This is done twice. The first passthrough is just dividing by quota. 
 * The second passthrough is to distribute remaining votes.
 * 
 * @return void.

*/
  void allocateSeats();
    /**
 * @brief Add winners to winners vector.
 * 
 * Goes through every party and adds the top of each party
 * to the winners vector depending on the amount of seats 
 * each party has.
 * 
 * @return void.

*/
  void findPartyWinners();
    bool sortRemainder(Party first, Party second) {
    return first.getRemainder() < second.getRemainder();
  }
  bool sortNumBallots(Party first, Party second) {
    return first.getNumBallots() < second.getNumBallots();
  }
    /**
 * @brief Runs the IR election..
 * 
 * Runs all of the methods needed to run a IR election.
 * 
 * @return void.

*/
  void runElection();
    /**
 * @brief Prints the results of the election.
 * 
 * Displays all the information an election official would need in an election.
 * Such information includes:
 * Number of Ballots
 * Winners
 * Losers
 * Election Type
 * 
 * @return void.

*/
  void displayResults();

/**
 * @brief A setter for parties.
 * 
 * Sets the parties vector 
 * 
 * @return char.

*/
  void setParties(std::vector<Party> parties_);

  void printPartyInfo();

 private:
  int quota;
};

#endif
