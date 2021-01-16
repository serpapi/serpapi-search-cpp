#ifndef SERPAPI_HOMEDEPOT_SEARCH
#define SERPAPI_HOMEDEPOT_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class HomedepotSearch : public SerpApiSearch 
{
    public:
    HomedepotSearch(map<string,string> parameter, string apiKey);
};
}
#endif