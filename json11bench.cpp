#include "json11.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int main() {
  std::ifstream ifs("bench.json");
  std::istreambuf_iterator<char> it(ifs);
  std::istreambuf_iterator<char> last;
  std::string txt(it, last);
  auto start = std::chrono::system_clock::now();
  for (int i=0; i<1000; i++) {
    string err;
    json11::Json v = json11::Json::parse(txt, err);
    // cout << v.array_items()[0]["_id"].string_value() << endl;
    // cout << v.array_items()[0]["tags"].array_items()[0].string_value() << endl;
  }
  auto end = std::chrono::system_clock::now();
  cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
}
