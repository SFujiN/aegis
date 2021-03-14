#include "IR.h"
#include "Ballot.h"
#include "Candidate.h"
#include "VotingSystem.h"



IR::IR(){
    
}

Candidate IR::findWinner(){
    std::vector<Candidate> ties;
  elim = &Candidate('a',"a",-1);
  for(int i = 0; i <= numCandidates; i++){
      if(candidates[i].getNumBallots() / totalBallots > 0.5){ //Checking for over 50%
        return candidates[i];
      }
      if((candidates[i].getNumBallots() < elim->getNumBallots()) && candidates[i].getNumBallots() != 0){
          elim = &candidates[i];
      }
      else if(candidates[i].getNumBallots() == elim->getNumBallots() && candidates[i].getNumBallots() != 0){
          *elim = breakTie(candidates[i],*elim);

      } 
  }
}


void IR::elimination(){
    for(int i = 0; i < elim->getNumBallots(); i++){
        elim->getBallots()[i].incrCurrent(); //Increment every ballot from that candidate
        candidates[elim->getBallots()[i].getCurrBallotIndex()].addBallot(elim->getBallots()[i]); 
        //Inside each ballot, getCurrBallotIndex takes in the current index of the Ballot and returns 
        //The value corresponding to the next highest voted candidiate in that ballot. That value
        //represents the position of the candidate in the candidates vector.
        // elim->getBallots()[i] = a ballot
        // getCurrBallotIndex() = the candidate index ( not the ballot)
        // candidates[elim->getBallots()[i].getCurrBallotIndex()] = Specific candidate
        // addBallot(elim->getBallots()[i]) = take current ballot and add to that candidate.
    }
}

Candidate IR::breakTie(Candidate a, Candidate b){
    int random = rand() % 100;
    if(random > 50){
        return a;
    }
    else return b;
}



