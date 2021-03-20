#include <serpapisearch.hpp>
#include <homedepotsearch.hpp>

namespace serpapi 
{
using namespace std;
HomedepotSearch::HomedepotSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "homedepot") 
{ 
}
}