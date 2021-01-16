/***
 * Run search engine powered by SerpApi
 */
#ifndef SERPAPI_SEARCH
#define SERPAPI_SEARCH

#include <iostream>
#include <map>
#include <string>
#include <curl/curl.h>
#include <callback.hpp>
#include "rapidjson/document.h"

namespace serpapi 
{
using namespace rapidjson;
using namespace std;

class SerpApiSearch {

    string apiKey;
    string engine;
    map<string, string> parameter;
    CURL *curl;
    int timeout = 60;
    
    public:

    SerpApiSearch(map<string, string> searchParameter, string searchApiKey, string searchEngine);

    void setParameter(map<string, string> searchParameter);

    map<string, string> getParameter();

    Document GetJson();

    string GetHtml();

    Document GetAccount();

    Document GetSearchArchive(string searchID);    
   
    string GetParameter(bool jsonEnabled);

    Document getJsonResult(string uri, string parameter);

    string getRawResult(string uri, string parameter);

    void setup(map<string, string> searchParameter, string searchApiKey, string searchEngine);

};
}

#endif