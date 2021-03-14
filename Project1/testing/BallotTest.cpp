#include "../src/Candidate.h"
#include "gtest/gtest.h"

class BallotTest : public ::testing::Test {
<<<<<<< HEAD
public:
    void SetUp() {
        default = Ballot();
         Bob = Candidate('I',5,"Bob");
        Jane = Candidate('D',7,"Jane");
        David = Candidate('L',1000,"Dave");
        ballot1={Bob,John,Jane,David};
    }
=======
 public:
    BallotTest();
  void SetUp() {
    // ballot1 is: 3, 1, 2
    // ballot1 new order is: 2, 3, 1
    Bob = Candidate('I', "Bob", 5);
    candidates.push_back(Bob);
    Jane = Candidate('D', "Jane", 7);
    candidates.push_back(Jane);
    David = Candidate('L', "Dave", 1000);
    candidates.push_back(David);
    ballotCandidates.push_back(2);
    ballotCandidates.push_back(3);
    ballotCandidates.push_back(1);
    Ballot ballot1(ballotCandidates);
  }
>>>>>>> 8021105ff8706b04139d9a51cc54f08f6b3b2256

  void TearDown() {}
  // Candidate Norm;
  Candidate Bob;
  Candidate Jane;
  Candidate David;
  Ballot ballot1;
  std::vector<int> ballotCandidates;
  std::vector<Candidate> candidates;
};

TEST_F(BallotTest, incrCurrent) {
  // int current = ballot1.getCurrent();
  // int cand = ballot1.getCandidates().at(current);
  // ballot1.getCandidates().at(ballot1.getCurrent());
  EXPECT_EQ(Jane, candidates[ballot1.getCurrBallotIndex()]);
  ballot1.incrCurrent();  // currBallot = 1
  EXPECT_EQ(David, candidates[ballot1.getCurrBallotIndex()]);
}

int main(int argc, char *argv[]) {
  printf("Please work");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}