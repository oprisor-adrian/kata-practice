#include <iostream>

#include "include/caesar_cipher.h"

int main() {
  Cipher::Caesar caesar;
  std::string message = "Cryptography";
  int key = 6;
  std::cout << caesar.Encrypt(message, key) << std::endl;
  std::cout << caesar.Decrypt(caesar.Encrypt(message, key), key) << std::endl;
  return 0;
}