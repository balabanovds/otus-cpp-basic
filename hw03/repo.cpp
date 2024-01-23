#include <fstream>
#include <iostream>
#include <string>

bool store_result(std::ofstream &file, const std::string user,
                  const int value) {
  if (!file.is_open()) {
    std::cerr << "Can not store result as file is not opened" << std::endl;
    return false;
  }

  file << user << ' ' << value << std::endl;
  return true;
}

bool print_result_table(std::ifstream &file) {
  if (!file.is_open()) {
    std::cerr << "Can not print results, can't open file" << std::endl;
    return false;
  }

  std::cout << "USER" << '\t' << "RESULT" << std::endl;

  int line_num = 1;
  std::string name;
  int tries;
  while (file >> name >> tries) {
    std::cout << name << '\t' << tries << std::endl;
  }

  return true;
}
