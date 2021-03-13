#include "gtest/gtest.h"
#include "Ballot.h"
#include"Candidate.h"
#include <vector>


class CandidateTest : public ::testing::Test {
public:
    void SetUp() {
        
         Bob = Candidate('I',5,"Bob");
        Jane = Candidate('D',7,"Jane");
        David = Candidate('L',1000,"Dave");

        Party All();
        All.setNumBallots(100);
        All.setRemainder(5);
        All.setSeatsWon(3);
        All.addCandidate(Bob);
        All.addCandidate(Jane);
        All.addCandidate(David);
    
       
    }

protected:
    Candidate default;
    Candidate Bob;
    Candidate Jane;
    Candidate David;
    Party All;
};

TEST_F (PartyTest, getNumBallotTest) {
    
    EXPECT_EQ(All.getNumBallots(),100) << "getNumBallot has errors";
   
}

TEST_F (PartyTest, getRemainderTest) {
    
    EXPECT_EQ(All.getRemainder(),5) << "getRemainder has errors";
   
}

TEST_F (PartyTest, getSeatsWonTest) {
    
    EXPECT_EQ(All.getSeatsWon(),3) << "getSeatsWon has errors";
   
}

TEST_F (PartyTest, CandidateTest) {
    std::vector<Candidate> test1
    EXPECT_EQ(test1[0],Bob) << "Candidate Vector has errors";
    EXPECT_EQ(test1[1],Jane) << "Candidate Vector has errors";
    EXPECT_EQ(test1[2],David)<< "Candidate Vector has errors";
   
}

