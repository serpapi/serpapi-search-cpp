/***
 * Run search engine powered by SerpApi
 */

#include <serpapisearch.hpp>

namespace serpapi 
{
const static string GOOGLE = "google";
const static string BAIDU = "baidu";
const static string BING = "bing";
const static string YAHOO = "yahoo";
const static string YANDEX = "yandex";
const static string HOMEDEPOT = "homedepot";
const static string JSON_FORMAT = "json";
const static string HTML_FORMAT = "html";
const static string HOST = "https://serpapi.com";

using namespace rapidjson;
using namespace std;

SerpApiSearch::SerpApiSearch(map<string, string> searchParameter, string searchApiKey, string searchEngine)
{
   setup(searchParameter, searchApiKey, searchEngine);
}

void SerpApiSearch::setup(map<string, string> searchParameter, string searchApiKey, string searchEngine) {
   parameter = searchParameter;
   apiKey = searchApiKey;
   engine = searchEngine;
}

string SerpApiSearch::GetParameter(const bool jsonEnabled)
{
   map<string, string> param(parameter);
   if (!engine.empty()) {
      param.insert(pair<string,string>("engine", engine));
   }
   // append api_key
   if (!apiKey.empty())
   {  
      param.insert(pair<string,string>("api_key", apiKey));
   }

   string s = "";

   map<string,string>::iterator it;
   for (it = param.begin(); it != param.end(); ++it)
   {
      if (s != "")
      {
         s += "&";
      }
      // encode each value in case of special character
      s += it->first + "=" + it->second;
   }

   // append output format
   s += "&output=" + (jsonEnabled ? JSON_FORMAT : HTML_FORMAT);

   // append source language
   s += "&source=cpp";

   return s;
}

/***
* Get search HTML results
*/
string SerpApiSearch::GetHtml()
{
   return getRawResult("/search", GetParameter(false));
}

string SerpApiSearch::getRawResult(string uri, string parameter) 
{
   curl_global_init(CURL_GLOBAL_DEFAULT);
   curl = curl_easy_init();
   const string url = HOST + uri + "?" + parameter;
   cout << "url: " + url << endl;
   curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
   curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
   curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
   curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
   curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
   curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

   long httpCode(0);
   unique_ptr<string> httpData(new string());
   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

   // execute search
   curl_easy_perform(curl);
   curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
   curl_easy_cleanup(curl);

   if(httpCode != 200) {
      // TODO what is the best solution in C++
      return nullptr;
   }
   curl_global_cleanup();
   return *httpData.get();
}

Document SerpApiSearch::GetJson() 
{
   return SerpApiSearch::getJsonResult("/search", GetParameter(true));
}

Document SerpApiSearch::getJsonResult(string uri, string parameter)
{
   string buf = getRawResult(uri, parameter);
   const char* json = buf.c_str();
   Document d;
   d.Parse(json);
   return d;
}

Document SerpApiSearch::GetSearchArchive(string searchID) 
{
   return SerpApiSearch::getJsonResult("/searches/" + searchID + ".json", SerpApiSearch::GetParameter(true));
};
};