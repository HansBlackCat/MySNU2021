#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <range/v3/all.hpp>
#include <chrono>
#include <locale>
#include <algorithm>
#include <iomanip>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include "matplotlibcpp.h"
#include "includes/csv.hpp"
#include "includes/date.h"

namespace plt = matplotlibcpp;
using namespace Eigen;

int main() {
  fmt::print("== Init ==\n");

  csv::CSVFormat format;
  format.header_row(1);

  csv::CSVReader reader("../KODC_2019.csv", format);

  std::vector<int> column_flag {7,8,9,11,13,16,17,18,19,21,22};
  int column_flag_counter = 0;
  int row = 0, column = 0;


  for (csv::CSVRow& row: reader) {
    column_flag_counter = 0;
    for (csv::CSVField& field: row) {
      ++column_flag_counter;
      if (std::find(column_flag.begin(), column_flag.end(), column_flag_counter) != column_flag.end()) {
        fmt::print(fmt::format("{}: {}\n",column_flag_counter, field.get<>()));
      }
    }
  std::cout << '\n';
  }

}
