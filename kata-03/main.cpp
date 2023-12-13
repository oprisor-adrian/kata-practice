#include <iostream>

#include "include/affine_cipher.h"

int main() {
  Cipher::Affine affine(26);
  std::cout << affine.Encrypt("LICENTA", {3, 6}) << std::endl;
  std::cout << affine.Decrypt(affine.Encrypt("LICENTA", {3, 6}), {3, 6}) << std::endl;
  return 0;
}