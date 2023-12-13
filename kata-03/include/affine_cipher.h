#ifndef CIPHER_AFILE_CIPHER_H_
#define CIPHER_AFILE_CIPHER_H_

#include <string>

namespace Cipher {

struct Key {
  int key_1;
  int key_2;
};

class Affine{
  public:
    Affine(const int length_);
    std::string Encrypt(const std::string& plain_text, const Key key);
    std::string Decrypt(const std::string& cipher_text, const Key key);
  private:
    bool IsPrim(const int key);
    int KeyInverse(const int key);
    int length_;
};

}  // namespace Cipher

#endif  // CIPHER_AFILE_CIPHER_H_