#include <gtest/gtest.h>

#include "../include/vernam_cipher.h"

TEST(TestVernamCipher, TestEncryptMethod) {
  Cipher::Vernam vernam;
  std::string output = vernam.Encrypt("abcd", "1234");
  std::string expected_output = "PPPP";
  EXPECT_STREQ(output.c_str(), expected_output.c_str());
}

TEST(TestVernamCipher, TestDecryptMethod) {
  Cipher::Vernam vernam;
  std::string output = vernam.Decrypt("PPPP", "1234");
  std::string expected_output = "abcd";
  EXPECT_STREQ(output.c_str(), expected_output.c_str());
}