#include <vector>

#include "../src/Ballot.cpp"
#include "../src/Candidate.cpp"
#include "../src/OPL.cpp"
#include "../src/Party.cpp"
#include "../src/VotingSystem.cpp"

using namespace std;
    Candidate Bob = Candidate('I', "Bob");
    
    
    


int main(int argc, char *argv[]) {
std::vector<int> ballot;
ballot.push_back(1);
///////////////////////////////////////////////////////////////////////////
// TESTING FOR getName
//////////////////////////////////////////////////////////////////////////

if(Bob.getName() == "Bob"){
  cout << "True" << endl;
}
  else{
    cout << "False, getName went wrong." << endl;
  }

///////////////////////////////////////////////////////////////////////////
// TESTING FOR getParty
//////////////////////////////////////////////////////////////////////////

if(Bob.getParty() == 'I'){
  cout << "True" << endl;
}
  else{
    cout << "False, getParty went wrong." << endl;
  }

///////////////////////////////////////////////////////////////////////////
// TESTING BALLOT USAGE
//////////////////////////////////////////////////////////////////////////
Bob.addBallot(ballot);

if(Bob.getNumBallots() == 1){
  cout << "True" << endl;
}
  else{
    cout << "False, getNumBallots or addBallot went wrong." << endl;
  }

if(Bob.getBallots()[0].getCurrBallot() == ballot[1]){
  cout << "True" << endl;
}
  else{
    cout << "False, getCurrBallot went wrong." << endl;
  }

Bob.setInitBallots(1);
if(Bob.getInitBallots() == 1){
  cout << "True" << endl;
}
  else{
    cout << "False, getInitBallots went wrong." << endl;
  }


}//end main



