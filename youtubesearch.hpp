#ifndef SERPAPI_YOUTUBE_SEARCH
#define SERPAPI_YOUTUBE_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class YoutubeSearch : public SerpApiSearch 
{
    public:
    YoutubeSearch(map<string,string> parameter, string apiKey);
};
}
#endif