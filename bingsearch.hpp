#ifndef SERPAPI_BING_SEARCH
#define SERPAPI_BING_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class BingSearch : public SerpApiSearch 
{
    public:
    BingSearch(map<string,string> parameter, string apiKey);
};
}
#endif