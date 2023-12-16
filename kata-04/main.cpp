#include <iostream>

#include "include/vernam_cipher.h"

int main() {
  Cipher::Vernam vernam;
  std::cout << "Encrypt: " 
            << vernam.Encrypt("abcd", "1234") 
            << std::endl;
  std::cout << "Decrypt: " 
            << vernam.Decrypt(vernam.Encrypt("abcd", "1234"), "1234") 
            << std::endl;
  return 0;
}