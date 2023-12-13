#include <gtest/gtest.h>

#include "../include/affine_cipher.h"

TEST(TestAffineCipher, TestEncryptMethod) {
  Cipher::Affine afile(26);
  std::string output = afile.Encrypt("LICENTA", {3, 6});
  std::string expected_output = "NEMSTLG";
  EXPECT_STREQ(output.c_str(), expected_output.c_str());
}

TEST(TestAffineCipher, TestDecryptMethod) {
  Cipher::Affine afile(26);
  std::string output = afile.Decrypt("NEMSTLG", {3, 6});
  std::string expected_output = "LICENTA";
  EXPECT_STREQ(output.c_str(), expected_output.c_str());
}