#include <iostream>

#include "rail_cipher.h"

int main() {
  std::cout << RailFenceCipher::Encode("testTEXT", 3);
  return 0;
}