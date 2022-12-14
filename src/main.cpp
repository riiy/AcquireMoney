#include "get_stock_his.h"
#include "get_stock_list.h"
#include <boost/program_options.hpp>
#include <iostream>
using namespace std;
namespace po = boost::program_options;

int main(int argc, const char *argv[]) {
  po::options_description desc("Allowed options");
  desc.add_options()("help,h", "produce help message")(
      "stock,s", po::value<string>(), "查找stock")("ta,t", po::value<string>(),
                                                   "查找stock的ta数据");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help")) {
    cout << desc << "\n";
    return 1;
  }

  if (vm.count("stock")) {
    auto stocks = get_stock_list();

    auto &st = stocks[vm["stock"].as<string>()];
    auto chanel = std::get<2>(st);
    cout << std::get<0>(st) << ": ";
    for (unsigned j = 0; j < chanel.size(); j++) {
      cout << chanel[j] << " ";
    }
    cout << endl;
  }
  if (vm.count("ta")) {
    auto stocks = get_stock_his(vm["ta"].as<string>());
    for (auto &[key, value] : stocks.items()) {
      std::cout << key << " : " << value << "\n";
    }
  }
  return 0;
}
