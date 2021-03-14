#include "gtest/gtest.h"
#include "OPL.h"
#include <vector>


class OPLTest : public ::testing::Test {
public:
    void SetUp() {
        
        Bob = Candidate('I',"Bob",5);
        Jane = Candidate('D',"Jane",7);
        David = Candidate('L',"David",1000);

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
    Party I, D, L;
    OPL election;
    VotingSystem Aegis;
};

TEST_F (OPLTest, allocateSeatsTest) {
    election.allocateSeats();

    EXPECT_TRUE(D>I) << "Error with allocate seats";
    EXPECT_TRUE(L>D) << "Error with allocate seats";  
}

TEST_F(OPLTest, findPartyWinnersTest) {
    election.findPartyWinners();

    EXPECT_EQ(election.winners[0], David) << "Error with findPartyWinners";
}
