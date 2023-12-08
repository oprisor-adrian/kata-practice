#include <gtest/gtest.h>

#include "../include/caesar_cipher.h"

TEST(TestCaesarCipher, TestEncrypt) {
  Cipher::Caesar caesar;
  std::string output = caesar.Encrypt("Cryptography", 6);
  std::string expected_output = "Ixevzumxgvne";
  EXPECT_STREQ(output.c_str(), expected_output.c_str());
}

TEST(TestCaesarCipher, TestDescrypt) {
  Cipher::Caesar caesar;
  std::string output = caesar.Decrypt("Ixevzumxgvne", 6);
  std::string expected_output = "Cryptography";
  EXPECT_STREQ(output.c_str(), expected_output.c_str());
}