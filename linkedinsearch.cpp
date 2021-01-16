#include <serpapisearch.hpp>
#include <linkedinsearch.hpp>

namespace serpapi 
{
using namespace std;
LinkedinSearch::LinkedinSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "linkedin") 
{ 
};
}