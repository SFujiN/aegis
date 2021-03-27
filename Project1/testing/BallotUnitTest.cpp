#include <gtest/gtest.h>

#include "../src/Ballot.cpp"

class BallotTest : public ::testing::Test {
 protected:
  void SetUp() { ballot = new Ballot(std::vector<int>{1, 2, 3}); }
  void TearDown() { delete ballot; }

  Ballot *ballot;
};

TEST_F(BallotTest, IncrementCurrent) {
  ASSERT_EQ(ballot->getCurrBallot(), 0);
  ASSERT_EQ(ballot->getCurrBallotIndex(), 0);
  ballot->incrCurrent();
  ASSERT_EQ(ballot->getCurrBallot(), 1);
  ASSERT_EQ(ballot->getCurrBallotIndex(), 1);
}

TEST_F(BallotTest, GetCandidates) {
  ASSERT_EQ(ballot->getCandidates(), (std::vector<int>{1, 2, 3}));
}

TEST_F(BallotTest, GetCurrentBallot) { ASSERT_EQ(ballot->getCurrBallot(), 0); }

TEST_F(BallotTest, PrintBallot) {
  std::ostringstream output;
  ballot->printBallot(output);
  ASSERT_EQ(output.str(),
            "candidate[0]: 1\ncandidate[1]: 2\ncandidate[2]: 3\n");
}

TEST_F(BallotTest, PrintEmptyBallot) {
  Ballot *emptyBallot = new Ballot(std::vector<int>{});
  std::ostringstream output;
  emptyBallot->printBallot(output);
  ASSERT_EQ(output.str(), "");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
