#ifndef PO_H
#define PO_H

#include "../src/Party.h"
#include "../src/VotingSystem.h"

class PO : public VotingSystem {
  public:
  PO(int candidates, int ballots);
  /**
   * @brief Runs the PO based election.
   *
   * Runs all of the methods needed to run a PO election.
   *
   * @return void.
   */
  void runElection();


  /**
   * @brief Prints the results of the election.
   *
   * Displays all the information an election official would need in an
   * election. Such information includes: Number of Ballots, Winners, Losers
   * and Election Type
   *
   * @return void.
   */
  void displayResults();
};

#endif