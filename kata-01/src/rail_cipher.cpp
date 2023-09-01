#include "rail_cipher.h"

#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstddef>
#include <vector>

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

  std::vector<std::string> SplitInRails(std::string text,
		  			const unsigned int rails_number) {
    std::vector<std::string> rails;
    std::size_t text_length = text.length();
    unsigned int rail_length = text_length / (2*(rails_number-1));
    // Adds the first rail
    rails.push_back(text.substr(0, rail_length));
    std::string last_rail = text.substr(text_length-rail_length);
    text.erase(text_length-rail_length, text_length-1);
    text.erase(0, rail_length);
    // Adds the intermediare rails
    for (unsigned int index=1; index<rails_number-1; index++) {
      if (2*rail_length>text.length()) {
	      rails.push_back(text);
        break;
      }
      rails.push_back(text.substr(0, 2*rail_length));
      text.erase(0, 2*rail_length);
    } 
    // Adds last rail
    rails.push_back(last_rail);
    return rails;
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
    // Splits the encoded text into rails
    std::vector<std::string> rails = SplitInRails(text, rails_number);
    // Adds the first character
    std::string decoded_output;
    decoded_output.push_back(rails[0][0]);
    rails[0].erase(0, 1);
    // Recreates the original text
    int direction = 1;
    while (decoded_output.length()<text.length()) {
      if (direction < 0 ) {
        std::for_each(rails.rbegin()+1, rails.rend(), [&decoded_output](auto& rail) {
          if (rail.length() > 0) {
            decoded_output.push_back(rail[0]);
            rail.erase(0, 1);
          }
	      });
      } else {
	      std::for_each(rails.begin()+1, rails.end(), [&decoded_output](auto& rail) {
          if (rail.length() > 0) {
            decoded_output.push_back(rail[0]);
            rail.erase(0, 1);
          }
 	      });
      }
      direction *= -1;    
    }
    return decoded_output;
  }

}  // namespac RailFenceCipher
