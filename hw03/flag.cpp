#include <cstring>
#include <string>

int flag_int(int argc, char *argv[], std::string key, int defaultValue) {
  for (int i = 1; i < argc; ++i) {
    if (std::strcmp(argv[i], key.c_str()) == 0 && i < argc - 1) {
      return std::stoi(argv[i + 1]);
    }
  }

  return defaultValue;
}

bool flag_bool(int argc, char *argv[], std::string key) {
  for (int i = 1; i < argc; ++i) {
    if (std::strcmp(argv[i], key.c_str()) == 0) {
      return true;
    }
  }

  return false;
}
