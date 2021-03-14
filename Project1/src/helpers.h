#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int OPLBallotToIndex(std::string ballot);

int IRBallotToIndex(std::string ballot);

std::vector<int> BallotToVec(int num, std::string ballot);

std::vector<int> IRBallotToVec(int num, std::string ballot);

std::string popItem(std::string &line, char l, char r);

std::vector<std::string> extractOPLNames(std::string line);

std::vector<std::string> extractIRNames(std::string line);

void printVec(std::vector<std::string> vec);

void printVecI(std::vector<int> vec);
