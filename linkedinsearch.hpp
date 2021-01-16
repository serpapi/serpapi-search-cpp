#ifndef SERPAPI_LINKEDIN_SEARCH
#define SERPAPI_LINKEDIN_SEARCH

#include <iostream>
#include <string>
#include <map>
#include <serpapisearch.hpp>

namespace serpapi 
{
using namespace std;
class LinkedinSearch : public SerpApiSearch 
{
    public:
    LinkedinSearch(map<string,string> parameter, string apiKey);
};
}
#endif