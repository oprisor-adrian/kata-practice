#include "rail_cipher.h"

namespace RailFenceCipher {

namespace {
  std::string GetEncodedRail(const std::string& text, 
                             const unsigned int railes_number) {
    return text;
  }

  std::string GetDecodedRail(const std::string& text,
                             const unsigned int railes_number) {
    return text;
  }
}  // namespace

  std::string Encode(const std::string& text, const unsigned int railes_number) {
    return GetEncodedRail("somethig", railes_number);
  }

  std::string Decode(const std::string& text, const unsigned int railes_number) {
    return GetDecodedRail("somethig", railes_number);
  }

}  // namespace RailFenceCipher