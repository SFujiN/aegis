#include <vector>
#include <string>

#include "gmock/gmock.h"
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

// TEST(HelperTests, BallotToVec) {
//     int num_0 = 0, num_5 = 5;
//     std::string empty = "";
//     std::string empty_ballot = ",,,,";
//     std::string first_pos = "1,,,,";
//     std::string last_pos = ",,,,1";
//     std::string full = "1,1,1,1,1";

//     ASSERT_THAT(BallotToVec(5,first_pos), ElementsAre(1,0,0,0,0));

// }