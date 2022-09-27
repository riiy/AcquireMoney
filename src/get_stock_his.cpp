#include "get_stock_his.h"

using json = nlohmann::json;
using namespace std;

json get_stock_his(std::string stock) {
  json ret;
  ret["ret"] = stock;
  return ret;
}
