#ifndef LFC_GRI_PRODUCTION_H_
#define LFC_GRI_PRODUCTION_H_

#include <ostream>
#include <string>

namespace LFCGRI{

class Production {
  public:
    Production(const std::string& l_symbol, const std::string& r_symbol);
    Production(const Production& other) = default;
    Production(Production&& other) = default;
    ~Production() = default;
    Production& operator=(const Production& other) = default;
    Production& operator=(Production&& other) = default;
    friend std::ostream& operator<< (std::ostream& stream, 
                                     const Production& prod);
    inline const std::string GetRSymbol() const { return r_symbol_; }
    inline const std::string GetLSymbol() const { return l_symbol_; }
    inline void SetRSymbol(const std::string& symbol) { r_symbol_ = symbol; }
    inline void SetLSymbol(const std::string& symbol) { l_symbol_ = symbol; }
  private:
    std::string l_symbol_;
    std::string r_symbol_;
};

}  // namespace LFCGRI

#endif  // LFC_GRI_PRODUCTION_H_