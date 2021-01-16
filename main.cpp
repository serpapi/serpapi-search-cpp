#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include <serpapisearch.hpp>
#include <googlesearch.cpp>
#include <bingsearch.cpp>
#include <baidusearch.cpp>
#include <homedepotsearch.cpp>
#include <yahoosearch.cpp>
#include <yandexsearch.cpp>
#include <wallmartsearch.cpp>
#include <youtubesearch.cpp>
#include <linkedinsearch.cpp>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/pointer.h"

using namespace rapidjson;
using namespace std;

void info(string msg) {
    cout << "\nINFO: " << msg << endl;
}
void info(double msg) {
    cout << "\nINFO: " << msg << endl;
}

void info(const Document& document) {
    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    document.Accept(writer);
    cout << "\nINFO: " << buffer.GetString();
}

// RapidJSON parser documentation is available: https://rapidjson.org
int main()
{
    std::map<string, string> parameter;
    parameter["q"] = "coffee";
    parameter["location"] = "Austin,TX";
    char* env_p = std::getenv("API_KEY");
    std::string apiKey(env_p);
    std::string engine = "google";
    
    // using namespace serpapi;
    //serpapi::GoogleSearch search(parameter, apiKey);
    serpapi::BingSearch search(parameter, apiKey);
    // serpapi::BaiduSearch search(parameter, apiKey);
    // serpapi::HomedepotSearch search(parameter, apiKey);
    // serpapi::YahooSearch search(parameter, apiKey);
    // serpapi::YandexSearch search(parameter, apiKey);
    // serpapi::WallmartSearch search(parameter, apiKey);
    // serpapi::YoutubeSearch search(parameter, apiKey);
    // serpapi::LinkedinSearch search(parameter, apiKey);

    // search on any search engine available from serpapi
    //serpapi::SerpApiSearch search(parameter, apiKey, "bing");

    // using namespace rapidjson;
    rapidjson::Document d = search.GetJson();
    info("document loaded");
    assert(d.HasMember("search_metadata"));
    assert(d["search_metadata"]["status"] == "Success");
    assert(d["search_metadata"]["id"].IsString());
    string id = d["search_metadata"]["id"].GetString();
    search.GetSearchArchive(id);
    assert(d["search_metadata"]["status"] == "Success");
    //info(d["search_information"]["total_results"].GetDouble());
    info(d);
}
