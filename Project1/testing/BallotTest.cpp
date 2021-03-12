#include "googletest/googletest/include/gtest/gtest.h"
#include "../src/Ballot.h"


class BallotTest : public ::testing::Test {
public:
    void SetUp() {
        default = Ballot();
        Bob = new Candidate(“I”,5,”Bob”);
        Jane = new Candidate(“D”,7,”Jane”);
        David = new Candidate(“L”,1000,”Dave”);

        ballot1={Bob,Jane,David};
    }

protected:
    Candidate default;
    Candidate Bob;
    Candidate Jane;
    Candidate David;
    std::vector<Ballot> ballot1;
};

TEST_F (BallotTest, incrCurrent) {
    EXPECT_EQ(Bob, b1.getCandidate());
    b1.incrCurrent(); //currBallot = 1
    EXPECT_EQ(Jane, b1.getCandidate());
}

TEST_F (BallotTest, getCandidate) { 
    EXPECT_EQ(Bob, b1.getCandidate());
    b1.incrCurrent(); //currBallot = 1
    b1.incrCurrent(); //currBallot = 2
    b1.incrCurrent(); //currBallot = 3
    EXPECT_EQ(nullptr, b1.getCandidate());
}

int main(int argc, char ∗∗argv) {
    printf("Please work");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}