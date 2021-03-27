#include <vector>

// #include "../src/Ballot.cpp"
// #include "../src/Candidate.cpp"
#include "../src/IR.cpp"
// #include "../src/Party.cpp"
#include "../src/VotingSystem.cpp"
#include "gtest/gtest.h"

class IRTest : public ::testing::Test {
 public:
  void SetUp() {
    // numCandidates = 3;
    // numSeats = 2;
    // numBallots = 6;

    // Round 1 No winner, Ibble eliminted

    ir = new IR("IR", 3, 2, 6);

    Candidate *Dribble = new Candidate('D', "Dribble");
    Candidate *Ribble = new Candidate('R', "Ribble");
    Candidate *Ibble = new Candidate('I', "Ibble");

    Ballot b1(std::vector<int>{1, 0, 0});
    Ballot b2(std::vector<int>{1, 0, 0});
    Ballot b3(std::vector<int>{1, 0, 0});
    Ballot b4(std::vector<int>{2, 0, 0});
    Ballot b5(std::vector<int>{2, 0, 0});
    Ballot b6(std::vector<int>{3, 0, 0});

    Dribble->addBallot(b1);
    Dribble->addBallot(b2);
    Dribble->addBallot(b3);

    Ribble->addBallot(b4);
    Ribble->addBallot(b5);

    Ibble->addBallot(b6);

    ir->addCandidate(*Dribble);
    ir->addCandidate(*Ribble);
    ir->addCandidate(*Ibble);
  }

  void TearDown() {
    // code here will be called just after the test completes
    // ok to throw exceptions from here if need be
  }

  ~IRTest() {
    // cleanup any pending stuff, but no exceptions allowed
  }

  IR *ir;
};

TEST_F(IRTest, findWinnerNoWinnerNoTie) {
  ir->setElim(&ir->getCandidates()[0]);
  float temp = (float)ir->getElim()->getNumBallots() / 6.0;
  EXPECT_LE(temp, 0.5)
      << "Error with checking for 50% when they should be equal";
  for (int i = 0; i < 3; i++) {
    float temp2 = (float)ir->getCandidates()[i].getNumBallots() / 6.0;
    EXPECT_LE(temp2, 0.5) << "Error, the result should be less than 50%";
  }
  ir->setElim(&ir->getCandidates()[2]);
}

TEST_F(IRTest, findWinnerHasWinner) {
  IR *ir2 = new IR("IR", 2, 2, 5);

  Candidate *Dave = new Candidate('D', "Dribble");
  Candidate *Rave = new Candidate('R', "Ribble");

  Ballot a1(std::vector<int>{1, 0, 0});
  Ballot a2(std::vector<int>{1, 0, 0});
  Ballot a3(std::vector<int>{1, 0, 0});
  Ballot a4(std::vector<int>{2, 0, 0});
  Ballot a5(std::vector<int>{2, 0, 0});

  Dave->addBallot(a1);
  Dave->addBallot(a2);
  Dave->addBallot(a3);

  Rave->addBallot(a4);
  Rave->addBallot(a5);

  ir2->addCandidate(*Dave);
  ir2->addCandidate(*Rave);

  ir2->setElim(&ir2->getCandidates()[0]);
  float temp = (float)ir2->getElim()->getNumBallots() / 6;
  EXPECT_GE(temp, 0.5)
      << "Error with checking for 50% when they should be equal";
}

TEST_F(IRTest, elimination) {
  Ballot b1(std::vector<int>{3, 1, 0});  //{2,0,1}
  Ballot b2(std::vector<int>{3, 2, 0});  //{0,2,1}
  ir->getCandidates().at(2).addBallot(b1);
  ir->getCandidates().at(2).addBallot(b2);

  ir->setElim(&(ir->getCandidates().at(2)));
  ir->elimination();
  EXPECT_EQ(ir->getCandidates().at(0).getNumBallots(), 4);
  EXPECT_EQ(ir->getCandidates().at(1).getNumBallots(), 3);
  EXPECT_EQ(ir->getCandidates().at(2).getNumBallots(), 0);
}

TEST_F(IRTest, eliminationBallotToEliminatedCandidate) {
  Ballot b1(std::vector<int>{3, 1, 0});  //{2,0,1}
  Ballot b2(std::vector<int>{3, 2, 0});  //{0,2,1}
  ir->getCandidates().at(2).addBallot(b1);
  ir->getCandidates().at(2).addBallot(b2);

  ir->setElim(&(ir->getCandidates().at(2)));
  ir->elimination();

  Ballot b3(std::vector<int>{2, 3, 0});  // {0,1,2}
  ir->getCandidates().at(1).addBallot(b3);
  ir->setElim(&(ir->getCandidates().at(1)));

  ir->elimination();  // all ballots should be discarded Dribble isn't one of
                      // their votes

  EXPECT_EQ(ir->getCandidates().at(0).getNumBallots(), 4);
  EXPECT_EQ(ir->getCandidates().at(1).getNumBallots(), 0);
  EXPECT_EQ(ir->getCandidates().at(2).getNumBallots(), 0);
}

TEST_F(IRTest, checkIfOneCandOneCand) {
  std::vector<Ballot> noBallots{};
  ir->getCandidates().at(0).setBallots(noBallots);
  ir->getCandidates().at(1).setBallots(noBallots);
  ir->checkIfOneCand();
  EXPECT_TRUE(ir->getWinners().size() == 1);
}

TEST_F(IRTest, checkIfOneCandTwoCands) {
  std::vector<Ballot> noBallots{};
  ir->getCandidates().at(0).setBallots(noBallots);
  ir->checkIfOneCand();
  EXPECT_TRUE(ir->getWinners().size() == 0);
}

TEST_F(IRTest, checkIfOneCandThreeCands) {
  ir->checkIfOneCand();
  EXPECT_TRUE(ir->getWinners().size() == 0);
}

// int main(int argc, char *argv[]) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
