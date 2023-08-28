#include <algorithm>
#include <any>
#include <ios>
#include <iostream>
#include <string>
#include <typeinfo>

void printElement(const std::any& element) {
  try {
    if (element.type() == typeid(bool)) {
      std::cout << std::any_cast<bool>(element) << ' ';
      return;
    }
    if (element.type() == typeid(int)) {
      std::cout << std::any_cast<int>(element) << ' ';
      return;
    }
    if (element.type() == typeid(std::string)) {
      std::cout << std::any_cast<std::string>(element) << ' ';
    }
  } catch (const std::bad_any_cast& e) {
    std::cout << "printElement: " << e.what() << std::endl;
  }
}

std::vector<std::any> moveZeros(const std::vector<std::any>& array) {
  try {
    unsigned int zeros_counter = 0;
    std::vector<std::any> temp_array;
    for (const auto elem : array) {
      if (elem.type() == typeid(int)) {
        int temp = std::any_cast<int>(elem);
	if (temp == 0 ) {
          zeros_counter++;
	  continue;
	}
      }
      temp_array.push_back(elem);
    }
    for (unsigned int index=0; index<zeros_counter; index++) {
      temp_array.push_back(0);
    }
    return temp_array;
  } catch (const std::bad_any_cast& e) {
    std::cout << "moveZeros: " << e.what() << std::endl;
    return std::vector<std::any>();
  }
}

int main() {
  std::vector<std::any> array = {0, true, 0, std::string("text"), 0, 5};
  std::cout << std::boolalpha;
  // Prints arddray before processing
  for (const auto temp : array) {
    printElement(temp);
  }
  std::cout << std::endl;
  // Moves all the '0' to the end
  array = moveZeros(array);
  // Prints array after processing
  for (const auto temp : array) {
    printElement(temp);
  }
  std::cout << std::endl;
  return 0;
}
