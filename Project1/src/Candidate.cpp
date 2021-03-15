#include "../src/Candidate.h"

Candidate::Candidate(char partyLetter, std::string candidateName) : party(partyLetter), name(candidateName) { status = true; }

std::string Candidate::getName() { return name; }

char Candidate::getParty() { return party; }

std::vector<Ballot> &Candidate::getBallots() { return ballots; }

int Candidate::getInitBallots(){ return initBallots; }

int Candidate::getNumBallots() { return ballots.size(); }

void Candidate::addBallot(Ballot ballot) { ballots.push_back(ballot); }

void Candidate::negateStatus() { status = !status; }

bool Candidate::operator<(Candidate& r) { return this->getNumBallots() < r.getNumBallots(); }

void Candidate::setInitBallots(int numBallots){initBallots = numBallots;}

void Candidate::setBallots(std::vector<Ballot> newBallots){ ballots = newBallots;}
