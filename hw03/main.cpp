#include "flag.h"
#include "level.h"
#include "rand.h"
#include "repo.h"

#include <fstream>
#include <ios>
#include <iostream>
#include <string>

int print_result(const std::string filename);
int store_result(const std::string filename, std::string name, int tries);

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

  std::cout << "Hey! Let's start game. Pls enter your name: " << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << "Nice to met ya, " << name
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

  std::cout << "Congrats, " << name << "! You'we guessed for " << tries
            << " tries." << std::endl;

  if (!store_result(filename, name, tries)) {
    return -1;
  }

  return print_result(filename);
}

int print_result(const std::string filename) {
  std::cout << "Here is a result table" << std::endl;
  std::ifstream file(filename);

  if (print_result_table(file)) {
    file.close();
    return 0;
  }

  file.close();
  return -1;
}

int store_result(const std::string filename, std::string name, int tries) {
  std::ifstream ifd(filename);
  auto best = get_best(ifd);
  ifd.close();

  if (best.count(name) && best[name] < tries) {
    return 0;
  }

  best[name] = tries;

  std::ofstream ofd;
  ofd.open(filename, std::ios_base::trunc);

  if (recreate_results(ofd, best)) {
    return 0;
  }

  return -1;
}
