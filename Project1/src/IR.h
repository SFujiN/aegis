/**
 * @file IR.h
 *
 * @copyright 2021 Aegis, All rights reserved.
 */



#ifndef IR_H
#define IR_H
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "Candidate.h"
#include "Ballot.h"
#include "VotingSystem.h"
#include "IR.h"

class IR : public VotingSystem{

public:

/**
 * @brief Empty constructor for the IR election.
 * 
 

*/
IR();

Candidate findWinner();
/**
 * @brief Attempts to find a winner in the IR election.
 * 
 *
 * 
 * @return Candidate.

*/
void elimination();

/**
 * @brief Eliminates a candidate.
 * 
 * Recieves the candidate with the lowest ballots and redistributes their ballots
 * 
 * @return void.

*/

Candidate breakTie(Candidate a, Candidate b);

/**
 * @brief Returns a candidate after tie.
 * 
 * Takes in two candidates that are "tied" and randomly decides one to remove.
 * 
 * @return char.

*/

private:

int totalBallots;
int numCandidates;
Candidate* elim;



};

#endif