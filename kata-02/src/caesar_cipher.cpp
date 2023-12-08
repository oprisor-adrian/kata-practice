#include "caesar_cipher.h"

namespace Cipher {

namespace {

int getRange(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 65;
  }
  return 97;
}

}  // namespace

Caesar::Caesar(const int alphabet_length): alphabet_length_(alphabet_length) {}

std::string Caesar::Encrypt(const std::string& plain_text, const int key) {
  std::string cipher_text;
  for (char c: plain_text) {
    // Checks if the character is a letter from alphabet
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
      // Adds the encrypted character to the string
      int range = getRange(c);
      cipher_text += (c + key - range) % alphabet_length_ + range;
    } else {
      // Adds other characters
      cipher_text += c;
    }
  }
  return cipher_text;
}

std::string Caesar::Decrypt(const std::string& cipher_text, const int key) {
  std::string plain_text;
  for (char c : cipher_text) {
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
      // Adds the encrypted character to the string
      int range = getRange(c);
      plain_text += (c - key + alphabet_length_ - range) % 
                    alphabet_length_ + range;
    } else {
      // Adds other characters
      plain_text += c;
    }
  }
  return plain_text;
}

}  // namespace Cipher