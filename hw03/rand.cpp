#include <cstdlib>
#include <ctime>

int generate_random_number(int max) {
  std::srand(std::time(nullptr));

  return std::rand() % max;
}
