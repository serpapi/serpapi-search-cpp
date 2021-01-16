#ifndef SERPAPI_GOOGLE_SEARCH
#define SERPAPI_GOOGLE_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class GoogleSearch : public SerpApiSearch 
{
    public:
    GoogleSearch(map<string,string> parameter, string apiKey);
};
}
#endif