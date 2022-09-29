#pragma once
#include <bits/stdc++.h>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>
#include <tuple>
#include <vector>
using stock = std::tuple<std::string, std::string, std::vector<std::string>>;
using stock_map = std::map<std::string, stock>;
using json = nlohmann::json;

stock_map get_stock_list();
