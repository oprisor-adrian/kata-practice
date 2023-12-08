#ifndef CAESAR_CIPHER_H_
#define CAESAR_CIPHER_H_

#include <string>

namespace Cipher{

class Caesar {
  public:
    Caesar(const int alphabet_length = 26);
    std::string Encrypt(const std::string& plain_text, const int key);
    std::string Decrypt(const std::string& cipher_test, const int key);
    inline const int GetAlphabetLength() const { return alphabet_length_; };
  private:
    int alphabet_length_;
};

}  // namesapce Cipher

#endif  // CAESAR_CIPHER_H_