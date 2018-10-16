#include "rapidjson/document.h"
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace rapidjson;

int main() {
  std::ifstream ifs("bench.json");
  std::istreambuf_iterator<char> it(ifs);
  std::istreambuf_iterator<char> last;
  std::string txt(it, last);
  auto start = std::chrono::system_clock::now();
  for (int i=0; i<1000; i++) {
    Document d;
    d.Parse(txt.c_str());
    // cout << d[0]["_id"].GetString() << endl;
    // cout << d[0]["tags"][0].GetString() << endl;
  }
  auto end = std::chrono::system_clock::now();
  cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;
}
