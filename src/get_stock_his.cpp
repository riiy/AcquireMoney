#include "get_stock_his.h"
#include <bits/stdc++.h>
#include <cpr/cpr.h>

using json = nlohmann::json;
using namespace std;

vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

json get_stock_his(std::string stock_code = "sz300760") {
  json ret;
  string url = "http://web.ifzq.gtimg.cn/appstock/app/fqkline/"
               "get?_var=kline_dayqfq2022&param=" +
               stock_code +
               ",day,2022-01-01,2023-12-31,640,qfq&r=0.52745640804514204";
  auto r = cpr::Get(cpr::Url{url});

  auto s = r.text;
  std::string delimiter = "=";
  regex re(",\\{\"nd.*?\\}");
  auto result = regex_replace(s, re, "$1");
  vector<string> v = split(result, delimiter);
  auto d = json::parse(v[1]);

  ret = d["data"][stock_code]["qfqday"];
  return ret;
}
