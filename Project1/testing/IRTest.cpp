#include "gtest/gtest.h"
#include "Ballot.h"
#include"Candidate.h"
#include "Party.h"
#include "Ballot.h"
#include "VotingSystem.h"
#include <vector>


class IRTest : public ::testing::Test {
public:
    void SetUp() {
        
        Bob = Candidate('I',5,"Bob");
        Jane = Candidate('D',7,"Jane");
        David = Candidate('L',1000,"Dave");

        Ballot a1(std::vector<int> {0,1,2});
        Ballot a2(std::vector>int> {1,2,0});
        Ballot a3(std::vector<int> {2,0,1});


        I.addCandidate(Bob);
        D.addCandidate(Jane);
        L.addCandidate(David);

        std::vector<Party> parties;
        parties.push_back(I);
        parties.push_back(D);
        parties.push_back(L);

        election.setParties(parties);

       
    }

protected:
    Candidate default;
    Candidate Bob;
    Candidate Jane;
    Candidate David;
    Party I;
    OPL election;
    VotingSystem Aegis;
    Ballot a1;
    Ballot a2;
    Ballot a3;
};

TEST_F (IRTest, EliminationTest) {
    a1.incrCurrent();

    EXPECT_EQ(a1.getBallot(),1) << "Elimination error";
    EXPECT_EQ(David.getNumBallots(),2);


}

TEST_F(IRTest, FindWinnerTest){
    Candidate winner = IR.FindWinner();
    EXPECT_EQ(David, winner) >> "FindWinner test has errors";
}

