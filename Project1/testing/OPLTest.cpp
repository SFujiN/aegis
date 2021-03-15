#include <cassert>
#include <vector>

#include "../src/Ballot.cpp"
#include "../src/Candidate.cpp"
#include "../src/OPL.cpp"
#include "../src/Party.cpp"
#include "../src/VotingSystem.cpp"

std::vector<int> i1{1, 0, 0};
Ballot ballot1(i1);
std::vector<int> i2{1, 0, 0};
Ballot ballot2(i2);
std::vector<int> i3{1, 0, 0};
Ballot ballot3(i3);
std::vector<int> i4{1, 0, 0};
Ballot ballot4(i4);
std::vector<int> i5{1, 0, 0};
Ballot ballot5(i5);
std::vector<int> i6{1, 0, 0};
Ballot ballot6(i6);
std::vector<int> i7{1, 0, 0};
Ballot ballot7(i7);
std::vector<int> i8{1, 0, 0};
Ballot ballot8(i8);
std::vector<int> i9{1, 0, 0};
Ballot ballot9(i9);
std::vector<int> i10{1, 0, 0};
Ballot ballot10(i10);

OPL election{"OPL", 3, 2, 10};
Candidate Bob1 = Candidate('I', "Bob");
Candidate Jane1 = Candidate('D', "Jane");
Candidate David1 = Candidate('L', "David");
Party I1{'I'};
Party D1{'D'};
Party L1{'L'};

OPL election2{"OPL", 3, 2, 10};
Candidate Bob2 = Candidate('I', "Bob");
Candidate Jane2 = Candidate('D', "Jane");
Candidate David2 = Candidate('L', "David");
Party I2{'I'};
Party L2{'L'};

OPL election3{"OPL", 3, 2, 10};
Candidate Bob3 = Candidate('I', "Bob");
Candidate Jane3 = Candidate('D', "Jane");
Candidate David3 = Candidate('L', "Dave");
Party I3{'I'};
Party D3{'D'};
Party L3{'L'};

void allocateSeatsTest() {
  if (election.getParties()[0].getSeatsWon() == 0) {      // David
    if (election.getParties()[1].getSeatsWon() == 1) {    // Bob
      if (election.getParties()[2].getSeatsWon() == 1) {  // Jane
        printf("allocateSeatsTest passed!\n");
      } else {  // Jane
        printf("allocateSeatsTest failed.\n");
        printf("Expected: Jane received %d seats\n", 1);
        printf("Actual: Jane received %d seats\n",
               election.getParties()[2].getSeatsWon());
      }
    } else {  // Bob
      printf("allocateSeatsTest failed.\n");
      printf("Expected: Bob received %d seats\n", 1);
      printf("Actual: Bob received %d seats\n",
             election.getParties()[1].getSeatsWon());
    }
  } else {  // David
    printf("allocateSeatsTest failed.\n");
    printf("Expected: David received %d seats\n", 0);
    printf("Actual: David received %d seats\n",
           election.getParties()[0].getSeatsWon());
  }
}

void findPartyWinnersTest() {
  if (election2.getWinners().at(0) == Bob2) {  // Bob
    if (1) {                                   // David
      printf("findPartyWinnersTest passed!\n");
    } else {  // David
      printf("findPartyWinnersTest failed.\n");
      printf("Expected: Winners are: Bob, David \n");
      printf("Actual: Winners are: %s, %s\n",
             election2.getWinners()[0].getName().c_str(),
             election2.getWinners()[1].getName().c_str());
    }
  } else {  // Bob
    printf("findPartyWinnersTest failed.\n");
    printf("Expected: Winners are: Bob, David \n");
    printf("Actual: Winners are: %s, %s\n",
           election2.getWinners()[0].getName().c_str(),
           election2.getWinners()[1].getName().c_str());
  }
}

void sortByVotesTest() {
  if (election3.getParties()[0].getNumBallots() >
      election3.getParties()[1].getNumBallots()) {
    if (election3.getParties()[1].getNumBallots() >
        election3.getParties()[2].getNumBallots()) {
      printf("sortByVotesTest passed!\n");
    } else {
      printf("sortByVotesTest failed.\n");
      printf("Expected: Order: Bob, Jane, Dave\n");
      printf("Actual: Order: %s, %s, %s\n",
             election3.getParties()[0].getPartyMembers()[0]->getName().c_str(),
             election3.getParties()[0].getPartyMembers()[1]->getName().c_str(),
             election3.getParties()[0].getPartyMembers()[2]->getName().c_str());
    }
  } else {
    printf("sortByVotesTest failed.\n");
    printf("Expected: Order: Bob, Jane, Dave\n");
    printf("Actual: Order: %s, %s, %s\n",
           election3.getParties()[0].getPartyMembers()[0]->getName().c_str(),
           election3.getParties()[0].getPartyMembers()[1]->getName().c_str(),
           election3.getParties()[0].getPartyMembers()[2]->getName().c_str());
  }
}

void sortByRemainderTest() {
  if (election3.getParties()[0].getRemainder() >
      election3.getParties()[1].getRemainder()) {
    if (election3.getParties()[1].getRemainder() >
        election3.getParties()[2].getRemainder()) {
      printf("sortByRemainderTest passed!\n");
    } else {
      printf("sortByRemainderTest failed.\n");
      printf("Expected: Order: Bob, Jane, Dave\n");
      printf("Actual: Order: %s, %s, %s\n",
             election3.getParties()[0].getPartyMembers()[0]->getName().c_str(),
             election3.getParties()[0].getPartyMembers()[1]->getName().c_str(),
             election3.getParties()[0].getPartyMembers()[2]->getName().c_str());
    }
  } else {
    printf("sortByRemainderTest failed.\n");
    printf("Expected: Order: Bob, Jane, Dave\n");
    printf("Actual: Order: %s, %s, %s\n",
           election3.getParties()[0].getPartyMembers()[0]->getName().c_str(),
           election3.getParties()[0].getPartyMembers()[1]->getName().c_str(),
           election3.getParties()[0].getPartyMembers()[2]->getName().c_str());
  }
}

int main(int argc, char *argv[]) {
  election.setQuota(3);
  I1.addCandidate(&Bob1);
  D1.addCandidate(&Jane1);
  L1.addCandidate(&David1);
  election.addParty(I1);
  election.addParty(D1);
  election.addParty(L1);
  Bob1.addBallot(ballot1);
  Bob1.addBallot(ballot7);
  Bob1.addBallot(ballot8);
  Bob1.addBallot(ballot10);
  Bob1.addBallot(ballot9);
  Jane1.addBallot(ballot2);
  Jane1.addBallot(ballot5);
  Jane1.addBallot(ballot6);
  David1.addBallot(ballot3);
  David1.addBallot(ballot4);
  election.allocateSeats();
  allocateSeatsTest();

  ////

  I2.addCandidate(&Bob2);
  I2.addCandidate(&Jane2);
  L2.addCandidate(&David2);
  election2.addParty(I2);
  election2.addParty(L2);
  election2.getParties()[0].setSeatsWon(1);
  election2.getParties()[1].setSeatsWon(1);
  election2.findPartyWinners();
  findPartyWinnersTest();

  ////

  I3.addCandidate(&Bob3);
  D3.addCandidate(&Jane3);
  L3.addCandidate(&David3);
  Bob3.addBallot(ballot1);
  Bob3.addBallot(ballot7);
  Bob3.addBallot(ballot8);
  Bob3.addBallot(ballot10);
  Bob3.addBallot(ballot9);
  Jane3.addBallot(ballot2);
  Jane3.addBallot(ballot5);
  Jane3.addBallot(ballot6);
  David3.addBallot(ballot3);
  David3.addBallot(ballot4);
  election3.addParty(I3);
  election3.addParty(D3);
  election3.addParty(L3);
  election3.sortByVotes();
  sortByVotesTest();

  election3.sortByRemainder();
  sortByRemainderTest();
}