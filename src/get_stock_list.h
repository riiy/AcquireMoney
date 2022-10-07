#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <map>

using stock = std::tuple<std::string, std::string, std::vector<std::string>>;
using stock_map = std::map<std::string, stock>;

stock_map get_stock_list();
