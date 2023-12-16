#include <iostream>

#include "include/vernam_cipher.h"

int main() {
  Cipher::Vernam vernam;
  std::cout << "Encrypt: " 
            << vernam.Encrypt("Crypto is cool!", "123411:51:23126") 
            << std::endl;
  std::cout << "Decrypt: " 
            << vernam.Decrypt(vernam.Encrypt("Crypto is cool!", 
                              "123411:51:23126"), "123411:51:23126")
            << std::endl;
  return 0;
}