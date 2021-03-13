#include "Party.h"

Party::Party(char Party){
    party = Party;
}

bool Party::operator>(Party& rhs) const{
    return(this->numBallots > rhs.numBallots){
       
}

int Party::getNumBallots(){
    return numBallots;
}

int Party::getRemainder(){
    return Remainder;
}

int Party::getSeatsWon(){
    return seatsWon;

}

std::vector<Candidate> Party::getPartyMembers(){
    return partyMembers;
}

void Party::setNumBallots(int ballots){
    numBallots = ballots;
}

//Note change SDD
void Party::setRemainder(int num){
    Remainder = num;
}

void Party::setSeatsWon(int seats){
    seatsWon = seats;
}

void Party::addCandidate(Candidate candidate){
    getPartyMembers().push_back(candidate);
}

