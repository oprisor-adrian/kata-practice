#include <iostream>

#include "rail_cipher.h"

int main() {
  std::cout << "encoding: " << RailFenceCipher::Encode("WEAREDISCOVEREDRUNATONCE", 6) << std::endl;
  return 0;
}
