#include "gtest/gtest.h"
#include "Candidate.h"
#include "Party.h"
#include <vector>


class CandidateTest : public ::testing::Test {
public:
    void SetUp() {
        
        Bob = Candidate('I',"Bob",5);
        Jane = Candidate('D',"Jane",7);
        David = Candidate('L',"Dave",1000);

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

TEST_F (PartyTest, candidateTest) {
    EXPECT_EQ(All[0].getName(),"Bob") << "Candidate Vector has errors";
    EXPECT_EQ(All[1]getName(),"Jane") << "Candidate Vector has errors";
    EXPECT_EQ(All[2]getName(),"David")<< "Candidate Vector has errors";
   
}

