/**
 * @file Party.h
 *
 * @copyright 2020, All rights reserved.
 */

#ifndef CANDIDATE_H
#define CANDIDATE_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include <vector>

#include "Ballot.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief A class representing Candidates, who will be filled with Ballots
 * voting for them and put into Parties that the represent.
 */
class Candidate {
 public:
  /**
   * @brief Candidate constructor that takes in the party they represent and the
   * candidate's name.
   *
   * @param partyLetter, a char representing the name of the party.
   * @param candidateName, a string representing the name of the candidate.
   */
  Candidate(char partyLetter, std::string candidateName);
  /**
   * @brief Method that gets the name of the candidate.
   *
   * @return Returns name of the candidate.
   */
  std::string getName();
  /**
   * @brief Method that gets the party name the candidate belongs to.
   *
   * @return Returns the party name.
   */
  char getParty();
  /**
   * @brief Method that gets the number of ballots that belong to the Candidate.
   *
   * @return Returns the number of ballots.
   */
  int getNumBallots();
  /**
   * @brief Method that adds a ballot the vector of Ballots.
   *
   * @param ballot, represents the Ballot to be added to the vector.
   */
  void addBallot(Ballot ballot);
  /**
   * @brief Method that changes the status of the candidate from true to false.
   */
  void negateStatus();
  /**
   * @brief Overload operator for comparisons between Candidates' number of
   * ballots.
   *
   * @param r, represents the Candidate to compare "this" to.
   *
   * @return Returns true or false to represent which candidate has a larger
   * number of ballots.
   */
  bool operator<(Candidate& r);

 private:
  char party;  ///< A char representing the name of the party the Candidate
               ///< belongs to.
  std::string name;    ///< A string that holds the name of the Candidate.
  bool status = true;  ///< A boolean that represents whether the Candidate is
                       ///< still in the running. Defaults to true.
  std::vector<Ballot> ballots;  ///< A vector of Ballots that holds all ballots
                                ///< currently voting for this Candidate.
};

#endif