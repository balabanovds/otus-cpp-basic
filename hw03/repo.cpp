#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

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

  std::cout << "USER" << '\t' << "TRIES" << std::endl;

  std::unordered_map<std::string, int> m;
  std::string name;
  int tries;
  while (file >> name >> tries) {
    if (m.count(name) && m[name] < tries) {
      continue;
    }
    m[name] = tries;
  }

  for (auto i = m.begin(); i != m.end(); ++i) {
    std::cout << i->first << '\t' << i->second << std::endl;
  }

  return true;
}
