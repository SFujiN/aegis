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
  OPL();
  void groupIndependentParties();
  void allocateSeats();
  
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
  void findPartyWinners();
  /**
 * @brief Add winners to winners vector.
 * 
 * Goes through every party and adds the top of each party
 * to the winners vector depending on the amount of seats 
 * each party has.
 * 
 * @return void.

*/
  bool sortRemainder(Party first, Party second) {
    return first.getRemainder() < second.getRemainder();
  }
  /**
 * @brief Sorts the vector of remainders.
 * 
 * In order to distribute the remaining votes
 * Sort the remaining vector from largest to least
 * and then assign the remainder votes until theres no more.
 * 
 * @return bool.

*/
  bool sortNumBallots(Party first, Party second) {
    return first.getNumBallots() < second.getNumBallots();
  }

  /**
 * @brief Sorts the number of ballots from parties.
 * 
 * Goes through each of the parties and sorts them from
 * Greatest to least in order to allocate votes correctly.
 * 
 * @return bool.

*/
  void runElection();

  /**
 * @brief Runs the IR election..
 * 
 * Runs all of the methods needed to run a IR election.
 * 
 * @return void.

*/
  void displayResults();

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

void setParties(std::vector<Party> parties_);

/**
 * @brief A setter for parties.
 * 
 * Sets the parties vector 
 * 
 * @return char.

*/

 private:

  int quota;
  std::vector<Party> parties;
  int numCandidates;

 protected:
  int numSeats;
};

#endif OPL_H