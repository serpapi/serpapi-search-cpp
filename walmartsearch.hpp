#ifndef SERPAPI_WALMART_SEARCH
#define SERPAPI_WALMART_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class WalmartSearch : public SerpApiSearch 
{
    public:
    WalmartSearch(map<string,string> parameter, string apiKey);
};
}
#endif