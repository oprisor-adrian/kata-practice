#include <gtest/gtest.h>

#include "../include/afile_cipher.h"

TEST(TestAfileCipher, TestEncryptMethod) {
  Cipher::Afile afile(26);
  std::string output = afile.Encrypt("LICENTA", {3, 6});
  std::string expected_output = "NEMSTLG";
  EXPECT_STREQ(output.c_str(), expected_output.c_str());
}

TEST(TestAfileCipher, TestDecryptMethod) {
  Cipher::Afile afile(26);
  std::string output = afile.Decrypt("NEMSTLG", {3, 6});
  std::string expected_output = "LICENTA";
  EXPECT_STREQ(output.c_str(), expected_output.c_str());
}