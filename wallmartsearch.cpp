#include <serpapisearch.hpp>
#include <wallmartsearch.hpp>

namespace serpapi 
{
using namespace std;
WallmartSearch::WallmartSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "wallmart") 
{ 
};
}