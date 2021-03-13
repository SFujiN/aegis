#include "gtest/gtest.h"
#include "Ballot.h"
#include"Candidate.h"
#include "Party.h"
#include "OPL.h"
#include "VotingSystem.h"
#include <vector>


class OPLTest : public ::testing::Test {
public:
    void SetUp() {
        
        Bob = Candidate('I',5,"Bob");
        Jane = Candidate('D',7,"Jane");
        David = Candidate('L',1000,"Dave");

        I = Party('I');
        D = Party('D');
        L = Party('L');

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
};

TEST_F (OPLTest, AllocateSeatsTest) {
    election.allocateSeats();

    EXPECT_TRUE(D>I) << "Error with allocate seats"
    EXPECT_TRUE(L>D) << "Error with allocate seats";  
}

TEST_F(OPLTest, FindPartyWinnersTest){
    election.findPartyWinners();

    EXPECT_EQ(election.winners[0], David) << "ERror with findPartyWinners";
}
