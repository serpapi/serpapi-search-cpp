#include <serpapisearch.hpp>
#include <bingsearch.hpp>

namespace serpapi 
{
using namespace std;
BingSearch::BingSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "bing") 
{ 
};
}