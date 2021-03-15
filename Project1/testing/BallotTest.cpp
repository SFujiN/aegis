#include "../src/Candidate.h"
#include "gtest/gtest.h"

class BallotTest : public ::testing::Test {
 public:
    BallotTest();
  void SetUp() {
    // ballot1 is: 3, 1, 2
    // ballot1 new order is: 2, 3, 1
    Bob = Candidate('I', "Bob");
    candidates.push_back(Bob);
    Jane = Candidate('D', "Jane");
    candidates.push_back(Jane);
    David = Candidate('L', "Dave");
    candidates.push_back(David);
    ballotCandidates.push_back(2);
    ballotCandidates.push_back(3);
    ballotCandidates.push_back(1);
    Ballot ballot1(ballotCandidates);
  }

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