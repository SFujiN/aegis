#include <vector>
#include <string>

#include "gmock/gmock.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"
#include "../src/helpers.cpp"

// TEST(HelperTests, getNameTest) {
//   std::string test1 = "5";
//   std::string test2 = "-1";
//   std::string test3 = "0";
//   EXPECT_EQ(OPLBallotToIndex(test1), 5) << "GetParty has errors";
//   EXPECT_EQ(OPLBallotToIndex(test2), -1) << "GetParty has errors";
//   EXPECT_EQ(OPLBallotToIndex(test3), 0) << "GetParty has errors";
// }

TEST(HelperTests, OPLBallotToIndex) {
  std::string garbage = "fjdkasl;";
  std::string empty = "";
  std::string no_ones = ",,,,";
  std::string first_pos = "1,,,,";

  EXPECT_EQ(std::string::npos, OPLBallotToIndex(garbage));
  EXPECT_EQ(std::string::npos, OPLBallotToIndex(empty));
  EXPECT_EQ(std::string::npos, OPLBallotToIndex(no_ones));
  EXPECT_EQ(0, OPLBallotToIndex(first_pos));
}

TEST(HelperTests, IRBallotToIndex) {
  std::string garbage = "fjdkasl;";
  std::string empty = "";
  std::string no_ones = ",,,,";
  std::string first_pos = "1,,,,";
  std::string third_pos_only_one = ",,1,,";
  std::string third_pos_full = "2,3,1,4,5";

  EXPECT_EQ(0, IRBallotToIndex(garbage));
  EXPECT_EQ(0, IRBallotToIndex(empty));
  EXPECT_EQ(0, IRBallotToIndex(no_ones));
  EXPECT_EQ(0, IRBallotToIndex(first_pos));
  EXPECT_EQ(2, IRBallotToIndex(third_pos_only_one));
  EXPECT_EQ(2, IRBallotToIndex(third_pos_full));
}

TEST(HelperTests, BallotToVec) {
    int num_0 = 0, num_5 = 5;
    std::string empty = "";
    std::string empty_ballot = ",,,,";
    std::string first_pos = "1,,,,";
    std::string last_pos = ",,,,1";
    std::string full = "1,1,1,1,1";
    std::string vary = "1,2,3,4,5";

    EXPECT_EQ(0, BallotToVec(0,empty).size());
    EXPECT_EQ(5, BallotToVec(5, empty).size());
    EXPECT_THAT(BallotToVec(5, empty), testing::ElementsAre(0,0,0,0,0));
    EXPECT_THAT(BallotToVec(5, empty_ballot), testing::ElementsAre(0,0,0,0,0));
    EXPECT_THAT(BallotToVec(5,first_pos), testing::ElementsAre(1,0,0,0,0));
    EXPECT_THAT(BallotToVec(5,last_pos), testing::ElementsAre(0,0,0,0,1));
    EXPECT_THAT(BallotToVec(5,full), testing::ElementsAre(1,1,1,1,1));
    EXPECT_THAT(BallotToVec(5,vary), testing::ElementsAre(1,2,3,4,5));
}

TEST(HelperTests, IRBallotToVec) {
    int num_0 = 0, num_5 = 5;
    std::string empty = "";
    std::string one_vote = "1,,,,";
    std::string two_vote = "1,,2,,";
    std::string three_vote = "1,,3,2,";
    std::string four_vote = "1,2,3,,4";
    std::string five_vote = "5,4,3,2,1";

    EXPECT_EQ(0, IRBallotToVec(0,empty).size());
    EXPECT_EQ(5, IRBallotToVec(5, empty).size());
    EXPECT_THAT(IRBallotToVec(5, empty), testing::ElementsAre(0,0,0,0,0));
    EXPECT_THAT(IRBallotToVec(5, one_vote), testing::ElementsAre(1,0,0,0,0));
    EXPECT_THAT(IRBallotToVec(5, two_vote), testing::ElementsAre(1,3,0,0,0));
    EXPECT_THAT(IRBallotToVec(5, three_vote), testing::ElementsAre(1,4,3,0,0));
    EXPECT_THAT(IRBallotToVec(5, four_vote), testing::ElementsAre(1,2,3,5,0));
    EXPECT_THAT(IRBallotToVec(5, five_vote), testing::ElementsAre(5,4,3,2,1));
    
}

// TEST(HelperTests, popItem) {

// }