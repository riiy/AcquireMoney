#include "eastmoney.h"
#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
using json = nlohmann::json;
using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

int main(void) {
  auto stocks = get_stocks();
  for (auto &[key, value] : stocks.items()) {
    std::cout << key << " : " << value << "\n";
  }
  return 0;
}
