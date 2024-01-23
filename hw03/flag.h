#include <string>

// checks for int flag by key in provided args, returning value of next arg or
// defaultValue if not found. If value can not be parsed, returns defaultValue.
int flag_int(int argc, char *argv[], std::string key, int defaultValue);

// checks for bool flag by key presents in provided args, returning false
// instead.
bool flag_bool(int argc, char *argv[], std::string key);
