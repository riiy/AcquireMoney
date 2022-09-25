#include "eastmoney.h"
#include <iostream>
using namespace std;


int main(void) {
  auto stocks = get_stocks();
  for (auto &[key, value] : stocks.items()) {
    std::cout << key << " : " << value << "\n";
  }
  return 0;
}
