#include "Candidate.h"

Candidate::Candidate(char p_letter, std::string c_name) : party(p_letter), name(c_name) { status = true; }

std::string Candidate::getName() { return name; }

char Candidate::getParty() { return party; }

int Candidate::getNumBallots() { return ballots.size(); }

void Candidate::addBallot(Ballot ballot) { ballots.push_back(ballot); }

void Candidate::negateStatus() { status = !status; }

bool Candidate::operator<(Candidate& r) { return this->getNumBallots() < r.getNumBallots(); }
