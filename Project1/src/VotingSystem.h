#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

class VotingSystem{
  public:
    int getNumBallots();
    double getTimeTaken();
    Candidate breakTie(std::vector<Candidate>);
    void addWinners(Candidate);
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