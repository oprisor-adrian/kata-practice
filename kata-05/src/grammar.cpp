#include "../include/grammar.h"

#include <algorithm>
#include <cctype>
#include <locale>
#include <codecvt>
#include <stdexcept>

namespace LFCGRI {

std::unordered_map<char, std::wstring> symbol_map;

std::ostream& operator<< (std::ostream& stream, const Grammar& grammar) {
  stream  << "G = (VN, VT, S, P)\nP = {";
  // Prints the production
  const auto& production = grammar.GetProductions();
  for (auto it = production.begin(); it != production.end(); ++it) {
    stream << *it;
    if (std::next(it) != production.end()) {
      stream << "; ";
    }
  }
  stream << "}\nVN = {";
  // Prints the non-terminals
  const auto& non_terminals = grammar.GetNonTerminals();
  for (auto it = non_terminals.begin(); it != non_terminals.end(); ++it) {
    stream << static_cast<std::string>(*it);
    if (std::next(it) != non_terminals.end()) {
      stream << ", ";
    }
  }
  stream << "}\nVT = {";
  // Prints the terminals
  const auto& terminals = grammar.GetTerminals();
  for (auto it = terminals.begin(); it != terminals.end(); ++it) {
    stream << *it;
    if (std::next(it) != terminals.end()) {
      stream << ", ";
    }
  }
  stream << "}\n";
  return stream;
}

void Grammar::AddProduction(const std::string& production) {
  if (production.empty()) {
    throw std::invalid_argument("[eroare]: S-a introdus o producție fără " 
                                "parametrii.");
  }
  ParseSymbol(production);
  std::string l_symbol = production.substr(0, 1);
  if (!std::isalpha(l_symbol[0]) || std::islower(l_symbol[0])) {
    throw std::invalid_argument("[eroare]: Primul simbol din producție trebuie " 
                                "să fie neterminal.");
  }
  std::string r_symbol = MapSymbol(production.substr(1));
  if (r_symbol.empty()) {
    throw std::invalid_argument("[eroare]: Nu s-a introdus partea dreaptă " 
                                "a unei producții.");
  }
  Production prod(l_symbol, r_symbol);
  productions_.push_back(prod);
}

void Grammar::ParseSymbol(const std::string& stream) {
  for (std::size_t index=0; index < stream.size(); index++) {
    std::string temp(1, stream[index]);
    if (std::isupper(temp[0])) {
      if (std::find(non_terminals_.begin(), non_terminals_.end(), 
           temp) == non_terminals_.end()) {
          non_terminals_.push_back(temp);
      }
      continue;
    }
    if (std::find(terminals_.begin(), terminals_.end(), temp) 
        == terminals_.end()) {
      if (symbol_map.find(temp[0]) != symbol_map.end()) {
        terminals_.push_back(WString2UTF8(symbol_map[temp[0]]));
        continue;
      }
      terminals_.push_back(temp);
    }
  }
}

std::string Grammar::WString2UTF8(const std::wstring& unicode) {
  std::wstring_convert<std::codecvt_utf8<wchar_t>> conversion;
  return conversion.to_bytes(unicode);
}

std::string Grammar::MapSymbol(const std::string& input) {
  std::string converted;
  for (char c:input) {
    if (symbol_map.find(c) != symbol_map.end()) {
      converted += WString2UTF8(symbol_map[c]);
      continue;
    }
    converted += c;
  }
  return converted;
}

}  // namespace LFCGRI