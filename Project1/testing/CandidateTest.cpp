#include "gtest/gtest.h"
#include "Ballot.h"
#include"Candidate.h"
#include <vector>


class CandidateTest : public ::testing::Test {
public:
    void SetUp() {
        
        Bob = Candidate(“I”,5,”Bob”);
        Jane = Candidate(“D”,7,”Jane”);
        David = Candidate(“L”,1000,”Dave”);

       
    }

protected:
    Candidate default;
    Candidate Bob;
    Candidate Jane;
    Candidate David;
};

TEST_F (CandidateTest, getPartyTest) {
    EXPECT_EQ(Bob.getParty(),"I") << "GetParty has errors";
    EXPECT_EQ(Jane.getParty(),"D") << "GetParty has errors";
    EXPECT_EQ(David.getParty(),"L") << "GetParty has errors";
   
}

TEST_F (CandidateTest, getNumBallotsTest) { 
    EXPECT_EQ(Bob.getBallots(),5) << "GetBallots has errors";
    EXPECT_EQ(Jane.getBallots(),7) << "GetBallots has errors";
    EXPECT_EQ(David.getBallots(),1000) << "GetBallots has errors";
}
