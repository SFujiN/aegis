#ifndef OPL_H
#define OPL_H
#include <vector>

class OPL : public VotingSystem {
  public:
    void groupIndependentParties();
    void allocateSeats(Party);
    void findPartyWinners();
    int findQuota();

  private:
    int numSeats;
    int quota;
    std::vector<Party> parties;
};

#endif OPL_H