#ifndef LFC_GRI_APPLICATION_H_
#define LFC_GRI_APPLICATION_H_

#include <string>

namespace LFCGRI {

class Application {
  public:
    Application();
    void Run();
  private:
    void ShowMenu();
    void ShowRules();
    void HandleAction(const std::string& action);
    void ReadGrammar(const char mode);
    void ProcessGrammar(const std::string& input);
    void AddSymbolEquivalent(const char c, const std::wstring& unicode);
};

}  // namespace LFCGRI

#endif  // LFC_GRI_APPLICATION_H_