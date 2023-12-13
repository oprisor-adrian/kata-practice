#include "../include/afile_cipher.h"

#include <iostream>
#include <stdexcept>
#include <cctype>

namespace Cipher {

namespace {

int getRange(char c) {
  if (std::isupper(c)) {
    return 65;
  }
  return 97;
}

}  // namespace 

Afile::Afile(const int length): length_(length) {}

std::string Afile::Encrypt(const std::string& plain_text, const Key key) {
  if (!IsPrim(key.key_1)) {
    throw std::invalid_argument("Prima cheie trebuie sa fie prim in lung. mult. 26");
  }
  std::string cipher_text;
  for (char c : plain_text) {
    if (std::isalpha(c)) {
      int range = getRange(c);
      cipher_text += (key.key_1 * (c-range) + key.key_2) % length_ + range;
    } else {
      cipher_text += c;
    }
  }
  return cipher_text;
}

std::string Afile::Decrypt(const std::string& cipher_text, const Key key) {
  if (!IsPrim(key.key_1)) {
    throw std::invalid_argument("Prima cheie trebuie sa fie prim in lungimea "
                                "multimii alfabetului.");
  }
  int inv_key = KeyInverse(key.key_1);
  std::string plain_text;
  for (char c:cipher_text) {
    if (std::isalpha(c)) {
      int range = getRange(c);
      int temp = inv_key*(c-key.key_2-range);
      if (temp < 0) {
        temp = (temp+length_)%length_;
      } else {
        temp = temp%length_;
      }
      plain_text += temp + range;
    } else {
      plain_text += c;
    }
  }
  return plain_text;
}

bool Afile::IsPrim(const int key) {
  if (key < 2 || key > 26)
    return false;
  if (key == 2 || key == 3)
    return true;
  if (key % 2 == 0)
    return false;
  for (int index=4; index<26; index++) {
    if (key % index==0) 
      return false;
  }
  return true;
}

int Afile::KeyInverse(const int key) {
  int index = 1;
  while (index*key%length_!=1) {
    index ++;
  }
  return index;
}

}  // namespace Cipher