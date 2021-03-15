#include <vector>

#include "../src/Ballot.cpp"
#include "../src/Candidate.cpp"
#include "../src/OPL.cpp"
#include "../src/Party.cpp"
#include "../src/VotingSystem.cpp"

using namespace std;
Party test = Party('P');
Candidate Bob = Candidate('I', "Bob");
int main(int argc, char *argv[]) {

///////////////////////////////////////////////////////////////////////////
// TESTING FOR getPartyName
//////////////////////////////////////////////////////////////////////////

if(test.getPartyName() == 'P'){
  cout << "True" << endl;
}
  else{
    cout << "False, getPartyName went wrong." << endl;
  }



///////////////////////////////////////////////////////////////////////////
// TESTING getSeatsWon
//////////////////////////////////////////////////////////////////////////
test.setSeatsWon(10);
if(test.getSeatsWon() == 10){
  cout << "True" << endl;
}
  else{
    cout << "False, getSeatsWon went wrong." << endl;
  }
  test.setSeatsWon(20);
if(test.getSeatsWon() == 20){
  cout << "True" << endl;
}
  else{
    cout << "False, getSeatsWon went wrong." << endl;
  }

///////////////////////////////////////////////////////////////////////////
// TESTING getRemainder
//////////////////////////////////////////////////////////////////////////
test.setRemainder(7);
if(test.getRemainder() == 7){
  cout << "True" << endl;
}
  else{
    cout << "False, getRemainder went wrong." << endl;
  }
test.setRemainder(-1);
if(test.getRemainder() == -1){
  cout << "True" << endl;
}
  else{
    cout << "False, getRemainder went wrong." << endl;
  }

///////////////////////////////////////////////////////////////////////////
// TESTING getPartyMembers
//////////////////////////////////////////////////////////////////////////
std::vector<int> ballot;
ballot.push_back(1);
Bob.addBallot(ballot);

test.addCandidate(&Bob);
if(test.getPartyMembers()[0] == &Bob){
  cout << "True" << endl;
}
  else{
    cout << "False, getPartyMembers went wrong." << endl;
  }

///////////////////////////////////////////////////////////////////////////
// TESTING FOR getNumBallots
//////////////////////////////////////////////////////////////////////////


if(test.getNumBallots() == 1){
  cout << "True" << endl;
}
  else{
    cout << "False, getNumBallots went wrong." << endl;
  }

}//end main



