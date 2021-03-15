#include <vector>

#include "../src/Ballot.cpp"
#include "../src/Candidate.cpp"
#include "../src/OPL.cpp"
#include "../src/Party.cpp"
#include "../src/VotingSystem.cpp"

using namespace std;
    Candidate Bob = Candidate('I', "Bob");
    
    Candidate Jane = Candidate('D', "Jane");
    
   Candidate David = Candidate('L', "Dave");
    
    


int main(int argc, char *argv[]) {
  std::vector<int> ballotCandidates;
  std::vector<Candidate> candidates;
  candidates.push_back(Bob);
  candidates.push_back(Jane);
  candidates.push_back(David);
  ballotCandidates.push_back(2);
  ballotCandidates.push_back(3);
  ballotCandidates.push_back(1);
  Ballot ballot1(ballotCandidates);



///////////////////////////////////////////////////////////////////////////
// TESTING FOR INCREMENT 
//////////////////////////////////////////////////////////////////////////

if("Jane"==candidates[ballot1.getCurrBallotIndex()].getName()){
  cout << "True" << endl;
}
  else{
    cout << "False, candidate initialization went wrong." << endl;
  }

ballot1.incrCurrent();

if("Dave"==candidates[ballot1.getCurrBallotIndex()].getName()){
  cout << "True" << endl;
}
  else{
    cout << "False, Incr Ballot is broken." << endl;
  }


///////////////////////////////////////////////////////////////////////////
// TESTING FOR GET CURR BALLOT
//////////////////////////////////////////////////////////////////////////

if(1 ==ballot1.getCurrBallot()){
  cout << "True" << endl;
}
else{
    cout << "False, GetCurrBallot is broken." << endl;
}

///////////////////////////////////////////////////////////////////////////
// TESTING FOR GETCANDIDATES
//////////////////////////////////////////////////////////////////////////
if(vector<int>{2,3,1} == ballot1.getCandidates()){
  cout << "True" << endl;
}
else{
    cout << "False, GetCandidates is broken." << endl;
}



}//end main



