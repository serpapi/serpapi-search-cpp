#ifndef SERPAPI_YAHOO_SEARCH
#define SERPAPI_YAHOO_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class YahooSearch : public SerpApiSearch 
{
    public:
    YahooSearch(map<string,string> parameter, string apiKey);
};
}
#endif