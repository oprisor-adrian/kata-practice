#include "../include/application.h"

#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <regex>

#include "../include/grammar.h"

namespace LFCGRI {

Application::Application() {
  //Adds default equivalent symbol.
  AddSymbolEquivalent('@', L"\u03BB");
  AddSymbolEquivalent('!', L"\u03B2");
}

void Application::Run() {
  std::system("clear");
  while (true) {
    std::cout << "> (q - exit; 0 - commands) [?]: ";
    std::string action = "";
    std::cin >> action;
    // Checks if the user wants to exit the application.
    if (action.length() == 1 && std::tolower(action[0]) == 'q') {
      break;
    }
    // Checks if the action is to clear the console.
    if (action == "clear") {
      std::system("clear");
      continue;
    }
    HandleAction(action);
  }
}

void Application::ShowMenu() {
  std::cout << '\n'
            << "[1] Reads grammar from the console.\n"
            << "[2] Reads grammar from the file.\n\n" 
            << std::endl;
}

void Application::HandleAction(const std::string& action) {
  try {
    // Checks if the action isn't a digit or has invalid format.
    if (!std::isdigit(action[0]) || action.length() > 1) {
      std::cerr << "[error] The action could not be recognized.\n" << std::endl;
      return;
    }
    // Handles the action
    const unsigned int temp = std::stoi(action);
    switch (temp){
      case 0:
        ShowMenu();
        break;
      case 1:
        ShowRules();
        ReadGrammar('c');
        break;
      case 2:
        ReadGrammar('f');
        break;
      default:
        std::cerr << "[error] The action could not be recognized..\n" << std::endl;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n\n";
  }
}

void Application::ReadGrammar(const char mode) {
  std::string input;
  // Reads the grammar from file.
  if (mode == 'f') {
    std::ifstream file("../data/grammar.txt");
    if (!file.is_open()) {
        throw std::runtime_error("[error]: Failed to access the file.");
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    input = buffer.str();
    file.close();
  } else if (mode =='c') {
    // Reads the grammar from console.
    std::cout << "\n\tgrammar: ";
    std::cin >> input;
  }
  ProcessGrammar(input);
}

void Application::ShowRules() {
  std::cout << '\n'
            << "1. The first symbol of the first production represents the axiom "
                "(start symbol);\n"
            << "2. The symbol of separation between productions is $;\n"
            << "3. Non-terminal symbols are written in capital letters;\n" 
            << "4. The terminal symbols are written in small letters;\n"
            << "5. The empty sequence will be @;\n"
            << "6. The symbol that marks the end of the grammar is &;" 
            << std::endl;
}

void Application::ProcessGrammar(const std::string& input) {
  // Validate the input format.
  std::regex pattern("([&]{2}|[$]{2}|&\\$|\\$\\$|\\$&)");
  if (std::regex_search(input, pattern) || input.find('&') == std::string::npos) {
    throw std::runtime_error("[error] Invalid formatted input grammar.");
  }
  Grammar g;
  std::size_t start_prod = 0;
  std::size_t end_prod = input.find_first_of("$&");
  std::size_t end_character = input.find("&");
  // Adds the valid productions to the grammar. 
  while (end_prod != std::string::npos) {
    if (end_character < end_prod) { 
      break;
    }
    g.AddProduction(input.substr(start_prod, end_prod-start_prod));
    start_prod = end_prod+1;
    end_prod = input.find_first_of("$&", start_prod);
  }
  // Shows the grammar (terminals, non-terminals and productions).
  std::cout << '\n' << g << std::endl;
}

void Application::AddSymbolEquivalent(const char c, 
                                      const std::wstring& unicode) {
  symbol_map[c] = unicode;
}

}  // namespace LFCGRI