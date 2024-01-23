#include "flag.h"
#include "level.h"
#include "rand.h"
#include "repo.h"

#include <fstream>
#include <ios>
#include <iostream>
#include <string>

int print_result(const std::string filename);

int main(int argc, char *argv[]) {
  const std::string filename = "result.db";

  if (flag_bool(argc, argv, "-table")) {
    return print_result(filename);
  }

  int max;
  int level = flag_int(argc, argv, "-level", 0);

  if (level) {
    max = max_by_level(level);
  } else {
    max = flag_int(argc, argv, "-max", 100);
  }

  int want = generate_random_number(max);

  std::cout << "Please enter your name: " << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << "Nice to met u user " << name
            << "! Try to guess number between 0 and " << max << std::endl;

  std::string answer;
  int tries = 0;
  while (true) {
    std::cin >> answer;
    int got = std::stoi(answer);

    ++tries;
    if (got == want) {
      break;
    }

    if (got < want) {
      std::cout << "greater than " << got << std::endl;
      continue;
    }

    std ::cout << "less than " << got << std::endl;
  }

  std::cout << "Congrats " << name << "! You'we guessed for " << tries
            << " tries." << std::endl;

  std::ofstream of;
  of.open(filename, std::ios_base::app);

  if (store_result(of, name, tries)) {
    return -1;
  }

  std::cout << "Here is a result table" << std::endl;

  return print_result(filename);
}

int print_result(const std::string filename) {
  std::ifstream file(filename);

  if (print_result_table(file)) {
    return 0;
  }

  return -1;
}
