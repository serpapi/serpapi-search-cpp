/***
 * Run search engine powered by SerpApi
 */

#include <serpapi.hpp>

namespace serpapi 
{

const static string JSON_FORMAT = "json";
const static string HTML_FORMAT = "html";
const static string HOST = "https://serpapi.com";

using namespace rapidjson;
using namespace std;

Client::Client(map<string, string> parameter)
{
   this->parameter = parameter;
}

/***
* Get HTML search results
*/
string Client::html(map<string, string> parameter)
{
   return Client::get("/search", HTML_FORMAT, parameter);
}

Document Client::search(map<string, string> parameter) 
{
   return Client::json("/search", parameter);
}

Document Client::searchArchive(string searchID) 
{
   return Client::json("/searches/" + searchID + ".json", map<string, string>());
}

Document Client::account(map<string, string> parameter) 
{
   return Client::json("/account.json", parameter);
}

Document Client::location(map<string, string> parameter) 
{
   return Client::json("/locations.json", parameter);
}

Document Client::json(string uri, map<string, string> parameter)
{
   string buf = get(uri, JSON_FORMAT, parameter);
   const char* json = buf.c_str();
   Document d;
   d.Parse(json);
   return d;
}

string Client::url(string output, map<string, string> parameter)
{
   map<string, string> param(parameter);
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
   s += "&output=" + output;

   // append source language
   s += "&source=serpapi-cpp:1.0.0";

   return s;
}

string Client::get(string uri, string output, map<string, string> parameter)
{
   curl_global_init(CURL_GLOBAL_DEFAULT);
   curl = curl_easy_init();
   const string url = HOST + uri + "?" + this->url(output, parameter);
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

}

