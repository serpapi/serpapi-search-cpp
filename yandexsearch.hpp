#ifndef SERPAPI_YANDEX_SEARCH
#define SERPAPI_YANDEX_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class YandexSearch : public SerpApiSearch 
{
    public:
    YandexSearch(map<string,string> parameter, string apiKey);
};
}
#endif