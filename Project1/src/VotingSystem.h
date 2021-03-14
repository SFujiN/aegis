#ifndef VOTINGSYSTEM_H
#define VOTINGSYSTEM_H

#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Ballot.h"
#include "Candidate.h"
#include "Party.h"

class VotingSystem {
 public:
  VotingSystem(std::string type, int candidates, int seats, int ballots);

  /**
 * @brief Constructor for the voting system.
 *
 * Creates a voting system with its type, the number of candidates, seats, and
 ballots.
 *

*/
  int getNumBallots();
  /**
   * @brief Returns the number of ballots in the system..
   *
   * Returns the number of ballots in the current system which is a parameter
   * given when created.
   *
   * @return int.

  */
  double getTimeTaken();

  /**
 * @brief Returns the time taken.
 *
 * Returns the amount needed to run the entire program.
 *
 * @return int.

*/
  // Candidate breakTie(std::vector<Candidate>);
  // void addWinners(Candidate);

  virtual void runElection();
  /**
 * @brief Will be used to run elections.
 *
 * Used by inherited classes to run their respective elections.
 *
 * @return void.

*/
  virtual void displayResults();

  /**
 * @brief Used to display results.
 *
 * Used by inherited classes to run display their own results.
 *
 * @return void.

*/
  void makeAuditFile();
  /**
   * @brief Creates an audit file.
   *
   * Creates a new file that will be used as an audit for the election
   *
   * @return void.

  */

  void writeToAuditFile(std::string string);

  /**
 * @brief Writes to the audit file.
 *
 *
*  @param[in] string What will be written into the audit file.
 *
 * @return void.

*/
  void makeMediaFile(std::string string);
  void printEverything();
  void addCandidate(Candidate candidate);

  /**
 * @brief Adds a Candidate to candidates vector.
 *
 * @param[in] candidate the candidate that will be added
 *
 * Takes in a candidate and then adds the candidate to the vector of candidates.
 *
 * @return void.
*/

  void addParty(Party party);
  /**
 * @brief Adds a party to parties vector.
 *
 * @param[in] party the party that will be added
 *
 * Takes in a party and then adds the party to the vector of parties.
 *
 * @return void.

*/
  std::vector<Candidate> &getCandidates();

  /**
   * @brief Gets the vector of candidates.
   *
   * Returns the vector of candidates which contain candidates.
   *
   * @return std::vector<Candidate>.

  */

  std::vector<Party> &getParties();
  /**
   * @brief Gets the vector of candidates.
   *
   * Returns the vector of candidates which contain candidates.
   *
   * @return std::vector<Candidate>.

  */
  bool partyExists(char party);
  /**
   * @brief Checks if a party exists.
   *
   * @param[in] party The party that will be checked
   * Checks through the vector of parties to see if it exists or not.
   *
   * @return bool.

  */
  void assignParty();

  /**
 * @brief Adds candidates to parties.
 *
 * Goes through every candidate and party and checks the candidate's party.
 * Then adds the candidate to that party if the party matches
 * Repeat for all of the candidates and parties.
 *
 * @return void.

*/

  void setAuditFileName();

 protected:
  std::string electionType;
  int numCandidates;
  int numSeats;
  int numBallots;
  double timeTaken;
  std::vector<Candidate> candidates;
  std::vector<Party> parties;
  std::ofstream auditFile;
  std::string auditfilename;
  std::ofstream mediaFile;

  // std::vector<Candidate> winners;
};
#endif
