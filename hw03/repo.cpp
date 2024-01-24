#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> get_best(std::ifstream &file);

bool store_one(std::ofstream &file, const std::string user, const int value) {
  if (!file.is_open()) {
    std::cerr << "Can not store result as file is not opened" << std::endl;
    return false;
  }

  file << user << ' ' << value << std::endl;
  return true;
}

bool recreate_results(std::ofstream &file,
                      std::unordered_map<std::string, int> &data) {
  if (!file.is_open()) {
    std::cerr << "Can not store result as file is not opened" << std::endl;
    return false;
  }

  for (auto i = data.begin(); i != data.end(); ++i) {
    file << i->first << '\t' << i->second << std::endl;
  }
  return true;
}

bool print_result_table(std::ifstream &file) {
  if (!file.is_open()) {
    std::cerr << "Can not print results, can't open file" << std::endl;
    return false;
  }

  std::cout << "USER" << '\t' << "TRIES" << std::endl;

  auto m = get_best(file);

  for (auto i = m.begin(); i != m.end(); ++i) {
    std::cout << i->first << '\t' << i->second << std::endl;
  }

  return true;
}

std::unordered_map<std::string, int> get_best(std::ifstream &file) {
  std::unordered_map<std::string, int> m;
  std::string name;
  int tries;
  while (file >> name >> tries) {
    if (m.count(name) && m[name] < tries) {
      continue;
    }
    m[name] = tries;
  }

  return m;
}
