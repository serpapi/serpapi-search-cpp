#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace serpapi
{
 size_t callback(const char* in, size_t size, size_t num, string* out);
}
