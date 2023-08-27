#include <algorithm>
#include <any>
#include <ios>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

void printAnyType(const std::any& value) {
  try {
    if (value.type() == typeid(bool)) {
      std::cout << std::any_cast<bool>(value) << ' ';
      return;
    }
    if (value.type() == typeid(int)) {
      std::cout << std::any_cast<int>(value) << ' ';
      return;
    }
    if (value.type() == typeid(std::string)) {
      std::cout << std::any_cast<std::string>(value) << ' ';
      return;
    }
  } catch (const std::bad_any_cast& e) {
    std::cout << e.what() << std::endl;
  }
}

void moveZeroToEnd(std::vector<std::any>& array, const unsigned int pos) {
  for (unsigned int index=pos; index < array.size()-1; index++) {
    std::swap(array[index], array[index+1]);
  }
}

void moveZeros(std::vector<std::any>& array) {
  try {
    // Move each '0' element at the end of the array
    for (unsigned int index = 0; index < array.size(); index++) {
      std::any elem = array[index];
      if (elem.type() == typeid(int)) {
        int temp = std::any_cast<int>(elem);
	if (temp == 0) {
          moveZeroToEnd(array, index);
	}
      }
    }
  } catch (const std::bad_any_cast& e) {
    std::cout << e.what() << std::endl;
  }
}

int main() {
  std::vector<std::any> array = {0, true, 0, std::string("test"), 0, std::string("me"), 0, 5};
  std::cout << std::boolalpha;
  // Prints array before processing
  for (std::any temp : array) {
    printAnyType(temp);
  }
  std::cout << std::endl;
  // Moves all the '0' to the end
  moveZeros(array);
  // Prints array after processing
  for (std::any temp : array) {
    printAnyType(temp);
  }
  std::cout << std::endl;
  return 0;
}
