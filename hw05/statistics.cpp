#include <cmath>
#include <cstddef>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

class IStatistics {
public:
  virtual ~IStatistics() {}

  virtual void update(double next) = 0;
  virtual double eval() const = 0;
  virtual const char *name() const = 0;
};

class Min : public IStatistics {
public:
  Min() : m_min{std::numeric_limits<double>::max()} {}

  void update(double next) override {
    if (next < m_min) {
      m_min = next;
    }
  }

  double eval() const override { return m_min; }

  const char *name() const override { return "min"; }

private:
  double m_min;
};

class Max : public IStatistics {
public:
  Max() : m_max{-std::numeric_limits<double>::max()} {}

  void update(double next) override {
    if (next > m_max) {
      m_max = next;
    }
  }

  double eval() const override { return m_max; }

  const char *name() const override { return "max"; }

private:
  double m_max;
};

class Mean : public IStatistics {
public:
  void update(double next) override { _values.push_back(next); }

  double eval() const override { return sum() / _values.size(); }

  const char *name() const override { return "mean"; }

private:
  std::vector<double> _values;

  double sum() const {
    double result{0};
    for (const double &i : _values) {
      result += i;
    }
    return result;
  }
};

class Std : public IStatistics {
public:
  void update(double next) override {
    _values.push_back(next);
    _mean.update(next);
  }

  double eval() const override { return std::sqrt(sum() / _values.size()); }

  const char *name() const override { return "std"; }

private:
  std::vector<double> _values;
  Mean _mean;

  double sum() const {
    double _mean_result = _mean.eval();

    double result{0};
    for (const double &i : _values) {
      result += std::pow(i - _mean_result, 2);
    }

    return result;
  }
};

class Perc : public IStatistics {
public:
  Perc(size_t N) {
    if (N < 1 || N > 100) {
      throw std::invalid_argument(
          "percentile N must be a value between 1 and 100");
    }
    _n = N;
    _name = "pct";
    _name.append(std::to_string(N));
  }

  void update(double next) override {
    _values.push_back(next);
    std::sort(_values.begin(), _values.end());
  }

  double eval() const override {
    size_t perc_pos = _values.size() * _n / 100;
    return _values.at(perc_pos);
  }

  const char *name() const override { return _name.c_str(); }

private:
  std::vector<double> _values;
  std::string _name;
  size_t _n;
};

int main() {
  const size_t statistics_count = 6;
  IStatistics *statistics[statistics_count];

  statistics[0] = new Min{};
  statistics[1] = new Max{};
  statistics[2] = new Mean{};
  statistics[3] = new Std{};
  statistics[4] = new Perc(91);
  statistics[5] = new Perc(95);

  double val = 0;
  while (std::cin >> val) {
    for (size_t i = 0; i < statistics_count; ++i) {
      statistics[i]->update(val);
    }
  }

  // Handle invalid input data
  if (!std::cin.eof() && !std::cin.good()) {
    std::cerr << "Invalid input data\n";
    return 1;
  }

  // Print results if any
  for (size_t i = 0; i < statistics_count; ++i) {
    std::cout << statistics[i]->name() << " = " << statistics[i]->eval()
              << std::endl;
  }

  // Clear memory - delete all objects created by new
  for (size_t i = 0; i < statistics_count; ++i) {
    delete statistics[i];
  }

  return 0;
}
