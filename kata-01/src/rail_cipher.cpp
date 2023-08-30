#include "rail_cipher.h"

#include <cassert>

namespace RailFenceCipher {

namespace {
  
  unsigned int CalculateDepth(const unsigned int rails_number, 
		  	      const unsigned int start_position) {
    if (start_position == rails_number-1) {
      return 2*(rails_number-1);
    }
    return 2*(rails_number-1-start_position);
  }
  
  std::string Rail(const std::string& text, 
		   const unsigned int depth,
		   const unsigned int start_position) {
    std::string rail;
    unsigned int current_position = start_position;
    while (current_position <= text.length()) {
      rail += text[current_position];
      current_position += depth;
    }
    return rail;
  }

}  // namespace

  std::string Encode(const std::string& text, const unsigned int rails_number) {
    assert(rails_number>=2);
    std::string encoded_output;
    for (unsigned int index = 0; index<rails_number; index++) {
      unsigned int depth = CalculateDepth(rails_number, index);
      std::string encoded_rail = Rail(text, depth, index);
      encoded_output += encoded_rail.c_str();
    }
    return encoded_output;
  }

  std::string Decode(const std::string& text, const unsigned int rails_number) {
    assert(rails_number>=2);
    std::string decoded_output;
    for (unsigned int index=0; index<rails_number; index++) {
      unsigned int depth = CalculateDepth(rails_number, index);
      std::string decoded_rail = Rail(text, depth, index);
      decoded_output += decoded_rail;
    }
    return decoded_output;
  }

}  // namespac RailFenceCipher
