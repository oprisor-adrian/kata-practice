#ifndef KATA_01_RAIL_CIPHER_H_
#define KATA_01_RAIL_CIPHER_H_

#include <string>

namespace RailFenceCipher {

  std::string Encode(const std::string& text, const unsigned int rails_number);
  std::string Decode(const std::string& text, const unsigned int rails_number);

}  // namespace RailFenceCipher

#endif  // KATA_01_RAIL_CIPHER_H_