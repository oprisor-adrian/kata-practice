#ifndef LFC_GRI_GRAMMAR_H_
#define LFC_GRI_GRAMMAR_H_

#include <ostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "production.h"

namespace LFCGRI {

extern std::unordered_map<char, std::wstring> symbol_map;

class Grammar {
  public:
    Grammar() = default;
    friend std::ostream& operator<< (std::ostream& stream, 
                                     const Grammar& grammar);
    void AddProduction(const std::string& production);
    inline const std::vector<Production>& GetProductions() const { 
      return productions_; 
    }
    inline const std::vector<std::string>& GetTerminals() const { 
      return terminals_; 
    }
    inline const std::vector<std::string>& GetNonTerminals() const { 
      return non_terminals_; 
    }
  private:  
    void ParseSymbol(const std::string& sttream);
    std::string WString2UTF8(const std::wstring& unicode);
    std::string MapSymbol(const std::string& input);
    std::vector<Production> productions_;
    std::vector<std::string> non_terminals_;
    std::vector<std::string> terminals_;
};

}  // namespace LFCGRI

#endif  // LFC_GRI_GRAMMAR_H_