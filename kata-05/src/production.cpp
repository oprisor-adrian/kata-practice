#include "../include/production.h"

namespace LFCGRI {

Production::Production(const std::string& l_symbol, const std::string& r_symbol)
    : l_symbol_(l_symbol), r_symbol_(r_symbol) {}

std::ostream& operator<< (std::ostream& stream, const Production& prod) {
  stream << prod.GetLSymbol();
  stream << " → ";
  stream << prod.GetRSymbol();
  return stream;
}

}  // namespace LFCGRI