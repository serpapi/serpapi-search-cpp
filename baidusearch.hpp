#ifndef SERPAPI_BAIDU_SEARCH
#define SERPAPI_BAIDU_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class BaiduSearch : public SerpApiSearch 
{
    public:
    BaiduSearch(map<string,string> parameter, string apiKey);
};
}
#endif