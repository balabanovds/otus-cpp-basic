#include <fstream>
#include <unordered_map>

// store result to file.
bool store_one(std::ofstream &file, const std::string user, const int value);

// print all results.
bool print_result_table(std::ifstream &file);

// get best results from db.
std::unordered_map<std::string, int> get_best(std::ifstream &file);

// rewrite db data.
bool recreate_results(std::ofstream &file,
                      std::unordered_map<std::string, int> &data);
