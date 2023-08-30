#include <iostream>

#include "rail_cipher.h"

int main() {
  std::cout << "encoding: " << RailFenceCipher::Encode("TEST", 2) << std::endl;
  std::cout << "decoding: " << RailFenceCipher::Decode("TSET", 2) << std::endl;
  return 0;
}
