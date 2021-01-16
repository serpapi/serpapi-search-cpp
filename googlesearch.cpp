#include <serpapisearch.hpp>
#include <googlesearch.hpp>

namespace serpapi 
{
using namespace std;
GoogleSearch::GoogleSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "google") 
{ 
};
}