#include <vector>
#include <string>
#include <fstream>

class VotingSystem{
  public:
    int getNumBallots();
    double getTimeTaken();
    Candidate breakTie();
    Candidate addWinners(Candidate);
    virtual void runElection();
    virtual void displayResults();
    std::fstream makeAuditFile();
    void writeToAuditFile(std::fstream, std::string);
    std::string makeMediaFile();
    void printEverything();

  private:
    std::string fileName;
    int numBallots;
    double timeTaken;
    std::vector<Candidate> candidates;
    std::vector<Candidate> winners;
};