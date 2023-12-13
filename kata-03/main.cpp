#include <iostream>

#include "include/afile_cipher.h"

int main() {
  Cipher::Afile afile(26);
  std::cout << afile.Encrypt("LICENTA", {3, 6}) << std::endl;
  std::cout << afile.Decrypt(afile.Encrypt("LICENTA", {3, 6}), {3, 6}) << std::endl;
  return 0;
}