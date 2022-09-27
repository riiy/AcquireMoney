#include "get_stock_his.h"

using json = nlohmann::json;
using namespace std;

json get_stock_his() {
  json ret;
  ret["ret"] = true;
  return ret;
}
