#include <serpapisearch.hpp>
#include <youtubesearch.hpp>

namespace serpapi 
{
using namespace std;
YoutubeSearch::YoutubeSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "youtube") 
{ 
}
}