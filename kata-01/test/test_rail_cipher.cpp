#include <gtest/gtest.h>

#include "rail_cipher.h"

struct TestCase {
  std::string input;
  std::string expected_output;
  unsigned int rails_number;
};

TEST(TestRailFenceCipher, TestEncode) {
  ASSERT_NO_FATAL_FAILURE(RailFenceCipher::Encode("TEST", 2));

  TestCase test_cases[] = {
    {"TEST", "TSET", 2},
    {"WEAREDISCOVEREDFLEEATONCE", "WECRLTEERDSOEEFEAOCAIVDEN", 3}};
  for (const auto& test_case : test_cases) {
    std::string output = RailFenceCipher::Encode(test_case.input, test_case.rails_number);
    EXPECT_STREQ(output.c_str(), test_case.expected_output.c_str());
  }
}

TEST(TestRailFenceCipher, TestDecodePerfectLength) {
  TestCase test_cases[] = {
    {"TSET", "TEST", 2},
    {"WEBERTEETAHS", "WEARETHEBEST", 3},
    {"Hetor  o?wayudy oa", "How are you today?", 4}};
  for (const auto& test_case : test_cases) {
    std::string output = RailFenceCipher::Decode(test_case.input, test_case.rails_number);
    EXPECT_STREQ(output.c_str(), test_case.expected_output.c_str());
  }
}
