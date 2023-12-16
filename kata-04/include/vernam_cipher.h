#ifndef VERMAN_CIPHER_H_
#define VERMAN_CIPHER_H_

#include <cstdint>
#include <string>
#include <vector>

namespace Cipher {

class Vernam {
  public:
    Vernam() = default;
    std::string Encrypt(const std::string& plain_text, const std::string& key);
    std::string Decrypt(const std::string& cipher_text, const std::string& key);
  private:    
    void ShowMatrix(std::vector<std::vector<bool>> matrix);
    std::vector<bool> Ascii2Bites(std::uint8_t character);
    std::uint8_t Bites2Ascii(std::vector<bool> bites);
    std::vector<std::vector<bool>> GetBitsMatrix(const std::string& stream);
    std::vector<std::vector<bool>> XorMatrix(
        std::vector<std::vector<bool>> plain_matrix,
        std::vector<std::vector<bool>> key_matrix);
};

}  // namesapce Cipher

#endif  // VERMAN_CIPHER_H_