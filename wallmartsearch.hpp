#ifndef SERPAPI_WALLMART_SEARCH
#define SERPAPI_WALLMART_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class WallmartSearch : public SerpApiSearch 
{
    public:
    WallmartSearch(map<string,string> parameter, string apiKey);
};
}
#endif