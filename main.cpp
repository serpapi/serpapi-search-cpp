#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include <serpapi.hpp>

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
    // initialize a client
    const char* env_p = std::getenv("API_KEY");
    std::string apiKey(env_p);
    std::map<string, string> default_parameter;
    default_parameter["api_key"] = apiKey;
    default_parameter["engine"] = "google";
    
    // using namespace serpapi;
    serpapi::Client client(default_parameter);

    // execute search 
    std::map<string, string> parameter;
    parameter["q"] = "coffee";
    parameter["location"] = "Austin,TX";
    //  using namespace rapidjson;
    rapidjson::Document d = client.search(parameter);
    info("document loaded");
    assert(d.HasMember("search_metadata"));
    assert(d["search_metadata"]["status"] == "Success");
    assert(d["search_metadata"]["id"].IsString());

    string id = d["search_metadata"]["id"].GetString();
    client.searchArchive(id);
    assert(d["search_metadata"]["status"] == "Success");
    info(d);
}
