#include <serpapisearch.hpp>
#include <walmartsearch.hpp>

namespace serpapi 
{
using namespace std;
WalmartSearch::WalmartSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "walmart") 
{ 
}
}