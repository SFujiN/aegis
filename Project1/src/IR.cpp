#include "IR.h"

IR::IR(std::string type, int candidates, int seats, int ballots) {
  electionType = type;
  numCandidates = candidates;
  numSeats = seats;
  numBallots = ballots;
}

void IR::findWinner() {
  // printCandidateInfo();
  // std::cout << "findWinnerStart" << std::endl;
  // tempElim = new Candidate('a', "temp");
  elim = &candidates[0];
  if ((elim->getNumBallots() / numBallots > 0.5)) {  // Checking for over 50%
    //std::cout << "majority" << std::endl;
    addWinners(*elim);
  }
  for (int i = 1; i < numCandidates; i++) {
    // std::cout << "candidate name: " << candidates[i].getName() << std::endl;
    // std::cout << "candidate votes: " << candidates[i].getNumBallots()
    //<< std::endl;
    // candidates[i].setInitBallots(candidates[i].getNumBallots());
    //printCandidateInfo();
    // std::cout << "findWinner" << std::endl;
    if ((candidates[i].getNumBallots() / numBallots >
         0.5)) {  // Checking for over 50%
      //std::cout << "majority" << std::endl;
      addWinners(candidates[i]);
    }
    if ((candidates[i].getNumBallots() < elim->getNumBallots()) &&
        candidates[i].getNumBallots() != 0) {
      //std::cout << "loser" << std::endl;
      elim = &candidates[i];
    } else if (candidates[i].getNumBallots() == elim->getNumBallots() &&
               candidates[i].getNumBallots() != 0) {
      //std::cout << "loser tie" << std::endl;
      *elim = breakTie(candidates[i], *elim);
    }
  }
}

void IR::elimination() {
  // std::cout << "elimination1: " << elim->getNumBallots() << std::endl;
  //std::cout << "elim: " << elim->getName() << std::endl;
  for (int i = elim->getNumBallots() - 1; i >= 0; i--) {
    // std::cout << "elimination inside: " << elim->getNumBallots() <<
    // std::endl;
    //elim->getBallots().at(i).printBallot();
    // std::cout << "elimBallot1: " << elim->getBallots().at(i).getCurrBallot()
    // << std::endl;
    elim->getBallots()
        .at(i)
        .incrCurrent();  // Increment every ballot from that candidate
    Ballot ballot = elim->getBallots().at(i);
    //std::cout << "index: " << ballot.getCurrBallotIndex() << std::endl;
    while (ballot.getCurrBallotIndex() >= 0 && (candidates[ballot.getCurrBallotIndex()].getNumBallots() == 0) && (ballot.getCurrBallot() < candidates.size() - 1)) {
      //std::cout << "currBallot: " << ballot.getCurrBallot() << std::endl;
      //std::cout << "size: " << candidates.size() << std::endl;
      ballot.incrCurrent();
    }
    //printCandidateInfo();
    // std::cout << "elimBallot2: " <<
    // elim->getBallots().at(i).getCurrBallot()<< std::endl;
    // std::cout << "elim: " << elim->getName() << std::endl;
    //Ballot ballot = elim->getBallots().at(i);
    // std::cout << "currBallotIndex: " << ballot.getCurrBallotIndex() <<
    // std::endl;
    if (ballot.getCurrBallotIndex() >= 0) {
      candidates[ballot.getCurrBallotIndex()].addBallot(ballot);
    }
    // std::cout << "elimBallot2: " << elim->getBallots().at(i).getCurrBallot()
    //<< std::endl;
    // std::cout << "elimIndex: " << elim->getBallots()[i].getCurrBallotIndex()
    // << std::endl; std::cout << "elimCandidate: " <<
    // candidates[elim->getBallots()[i].getCurrBallotIndex()].getName() <<
    // std::endl;
    // std::cout << "elimbefore: " << elim->getNumBallots() << std::endl;
    // elim->getBallots().pop_back();
    // std::cout << "elimafter: " << elim->getNumBallots() << std::endl;
    // Inside each ballot, getCurrBallotIndex takes in the current index of the
    // Ballot and returns The value corresponding to the next highest voted
    // candidiate in that ballot. That value represents the position of the
    // candidate in the candidates vector.
    // elim->getBallots()[i] = a ballot
    // getCurrBallotIndex() = the candidate index ( not the ballot)
    // candidates[elim->getBallots()[i].getCurrBallotIndex()] = Specific
    // candidate addBallot(elim->getBallots()[i]) = take current ballot and add
    // to that candidate.
  }
  std::vector<Ballot> noBallots{};
  elim->setBallots(noBallots);
}

Candidate IR::breakTie(Candidate a, Candidate b) {
  int random = rand() % 100;
  if (random > 50) {
    return a;
  } else
    return b;
}

void IR::checkIfOneCand() {
  int flag = -1;
  //int i = 0;
  int index = 0;
  for (int i = 0; i < candidates.size(); i++){
    if (candidates[i].getNumBallots() != 0) {
      flag++;
      index = i;
    }
  }
  /* while (flag && i < candidates.size()) {
    if (candidates[i].getNumBallots() != 0) {
      flag++;
      index = i;
    }
    i++;
  } */
  if (!flag) {
    //std::cout << "flag: " << flag << std::endl;
    //std::cout << candidates[index].getName() << " is a winner" << std::endl;
    addWinners(candidates[index]);
  }
}

void IR::runElection() {
  for (int j = 0; j < candidates.size(); j++){
    candidates[j].setInitBallots(candidates[j].getNumBallots());
  }
  findWinner();
  while (winners.size() == 0) {
    elimination();
    checkIfOneCand();
    findWinner();
  }
  for (int i = 0; i < candidates.size(); i++){
    if(candidates[i].getName() != winners[0].getName()){
      addLosers(candidates[i]);
    }
  }
}

void IR::printCandidateInfo() {
  for (int i = 0; i < candidates.size(); i++) {
    std::cout << "name: " << candidates[i].getName() << std::endl;
    std::cout << "numBallots: " << candidates[i].getNumBallots() << std::endl;
  }
  std::cout << "end print" << std::endl;
}

void IR::displayResults() {
  std::cout << "General Election Information" << std::endl;
  printf("\tElection Type: OPL\n");
  printf("\tTotal Ballots: %d\n", numBallots);

  std::cout << "\nWinners" << std::endl;
  printf("\t%-60s %-15s %-s", "Name", "Party", "Number of Ballots\n");
  for (int i = 0; i < winners.size(); i++) {
    printf("\t%-60s %-15c %-d\n", winners[i].getName().c_str(),
           winners[i].getParty(), winners[i].getInitBallots());
  }

  std::cout << "\nLosers\n" << std::endl;
  printf("\t%-60s %-15s %-s", "Name", "Party", "Number of Ballots\n");
  for (int i = 0; i < losers.size(); i++) {
    printf("\t%-60s %-15c %-d\n", losers[i].getName().c_str(),
           losers[i].getParty(), losers[i].getInitBallots());
  }
}