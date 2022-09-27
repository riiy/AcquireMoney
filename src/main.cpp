#include "eastmoney.h"
#include <boost/program_options.hpp>
#include <iostream>
using namespace std;
namespace po = boost::program_options;

int main(int argc, const char *argv[]) {
  po::options_description desc("Allowed options");
  desc.add_options()("help,h", "produce help message")(
      "stock,s", po::value<string>(), "查找stock");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help")) {
    cout << desc << "\n";
    return 1;
  }

  if (vm.count("stock")) {
    auto stocks = get_stocks();
    for (auto &[key, value] : stocks.items()) {
      if (vm["stock"].as<string>() == key)
        std::cout << key << " : " << value << "\n";
    }
  } else {
    cout << "Compression level was not set.\n";
  }
  return 0;
}
