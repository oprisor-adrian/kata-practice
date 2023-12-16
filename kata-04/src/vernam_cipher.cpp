#include "../include/vernam_cipher.h"

#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>

namespace Cipher {

std::vector<bool> Vernam::Ascii2Bites(std::uint8_t character) {
  std::vector<bool> row;
  // Converts the characters in binary
  do {
    bool rest = character%2;
    row.push_back(rest);
    character /= 2;
    if (character == 1) {
      row.push_back(1);
    }
  } while (character != 1);
  // Completes with `0` if needed
  while (row.size() < 8) {
    row.push_back(0);
  }
  std::reverse(row.begin(), row.end());
  return row;
}

std::uint8_t Vernam::Bites2Ascii(std::vector<bool> bites) {
  std::uint8_t character;
  std::reverse(bites.begin(), bites.end());
  for (std::size_t index = 0; index < bites.size(); index++) {
    if (bites[index] == 1) {
      character += std::pow(2, index);
    }
  }
  return character;
}

std::vector<std::vector<bool>> Vernam::GetBitsMatrix(
    const std::string& stream) {
  std::vector<std::vector<bool>> matrix;
  for (auto chr : stream) {
    matrix.push_back(Ascii2Bites(chr));
  }
  return matrix;
}

std::string Vernam::Encrypt(const std::string& plain_text, 
                            const std::string& key) {
  if (plain_text.length() != key.length()) {
    throw std::runtime_error("[error] The plain text and the key must " 
                             "be the same legth.");
  }
  std::vector<std::vector<bool>> plain_matrix = GetBitsMatrix(plain_text);
  std::vector<std::vector<bool>> key_matrix = GetBitsMatrix(key);
  std::vector<std::vector<bool>> cipher_matrix = XorMatrix(plain_matrix, 
                                                           key_matrix);
  std::string cipher;
  for (std::size_t index=0; index < cipher_matrix.size(); index++) {
    cipher += Bites2Ascii(cipher_matrix[index]);
  }
  return cipher;
}

std::string Vernam::Decrypt(const std::string& cipher_text, 
                            const std::string& key) {
  if (cipher_text.length() != key.length()) {
    throw std::runtime_error("[error] The plain text and the key must "
                             "be the same legth.");
  }
  // Equivalent with Encrypt(Encrypt("abc", "123"), "123");
  // XOR(XOR(m)) = m
  std::vector<std::vector<bool>> cipher_matrix = GetBitsMatrix(cipher_text);
  std::vector<std::vector<bool>> key_matrix = GetBitsMatrix(key);
  std::vector<std::vector<bool>> plain_matrix = XorMatrix(cipher_matrix, 
                                                          key_matrix);
  std::string plain_text;
  for (std::size_t index=0; index < plain_matrix.size(); index++) {
    plain_text += Bites2Ascii(plain_matrix[index]);
  }
  return plain_text;
}

std::vector<std::vector<bool>> Vernam::XorMatrix(
    std::vector<std::vector<bool>> plain_matrix,
    std::vector<std::vector<bool>> key_matrix) {
  std::vector<std::vector<bool>> result;
  // Performs XOR
  for (std::size_t index=0; index<plain_matrix.size(); index++) {
    std::vector<bool> b_result;
    for (std::size_t b_index = 0; b_index<8; b_index++) {
      b_result.push_back((plain_matrix[index][b_index] + 
                          key_matrix[index][b_index]) % 2);
    }
    result.push_back(b_result);
  }
  return result;
}

void Vernam::ShowMatrix(std::vector<std::vector<bool>> matrix) {
  for (std::size_t r = 0; r<matrix.size(); r++) {
    for (std::size_t c = 0; c<8; c++) {
      std::cout << matrix[r][c] << " ";
    }
    std::cout << std::endl;
  }
}

}  // namespace Cipher