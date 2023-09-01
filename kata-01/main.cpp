#include <iostream>

#include "rail_cipher.h"

int main() {
  std::cout << "Decoding process:\n" << RailFenceCipher::Decode("TMOETYNLGSKA", 3) << std::endl;
  return 0;
}
