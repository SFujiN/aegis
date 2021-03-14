/**
 * @file Ballot.h
 *
 * @copyright 2020, All rights reserved.
 */

#ifndef BALLOT_H
#define BALLOT_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief A class representing Ballots, who will be assigned to Candidates based
 * on their top vote.
 */
class Ballot {
 public:
  /**
   * @brief Default constructor. Takes in only a vector of ints representing
   * ranked choices and assigns it to candidates.
   *
   * @param vector, vector of ints representing ranked chocies. Assigned to
   * candidates.
   */
  Ballot(std::vector<int> v1);

  /**
   * @brief Increments currBallot pointer to next value in the candidates
   * vector.
   */
  void incrCurrent();

  /**
   * @brief Method to return candidates vector.
   *
   * @return Returns a vector of ints.
   */
  std::vector<int> getCandidates();

  /**
   * @brief Method to get the current ballot index required to identify the
   * candidate the ballot currently belongs to.
   *
   * @return Returns an integer.
   */
  int getCurrBallotIndex();  // candidates[ballot1.getCandidates().at(ballot1.getCurrent())-1]

 private:
  std::vector<int> candidates;  ///< A vector of ints representing the order in
                                ///< which the ballot favors candidates.
  int currBallot =
      0;  ///< An integer representing which candidate the ballot is currently
          ///< voting for. Starts at 0 and only increments by 1.
};

#endif
