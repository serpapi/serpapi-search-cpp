/***
 * Scrape search powered by SerpApi
 */

#include <serpapi.hpp>

namespace serpapi 
{

const static string HOST = "https://serpapi.com";
const static string NAME = "serpapi-cpp";
const static string VERSION = "1.0.0";

using namespace rapidjson;
using namespace std;

struct GetResponse {
   int httpCode;
   string payload;
};

Client::Client(map<string, string> parameter)
{
   this->parameter = parameter;
}

/***
* Get HTML search results
*/
string Client::html(map<string, string> parameter)
{
   GetResponse gr = Client::get("/search", "html", parameter);
   return gr.payload;
}

Document Client::search(map<string, string> parameter) 
{
   return Client::json("/search", parameter);
}

Document Client::searchArchive(string id) 
{
   return Client::json("/searches/" + id + ".json", map<string, string>());
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
   GetResponse gr = get(uri, "json", parameter);
   const char* json = gr.payload.c_str();
   Document d;
   d.Parse(json);
   // if(gr.httpCode != 200 && d.HasMember("error")) {
   //    Value entry(d);
   //    entry.AddMember("httpCode", string(gr.httpCode), d.GetAllocator());
   //    entry.AddMember("error", "serpapi.com did not returned any error message", d.GetAllocator());
   // }
   return d;
}

string encodeUrl(map<string, string> parameter)
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
   return s;
}

string Client::url(string output, map<string, string> parameter)
{
   // encode parameter
   string url = encodeUrl(parameter);
   if(size(this->parameter) > 0) {
      url += "&";
      url += encodeUrl(this->parameter);
   } 
   // append output format
   url += "&output=" + output;
   // append source language
   url += "&source="+NAME+":"+VERSION;
   // cout << url << endl;
   return url;
}

GetResponse Client::get(string uri, string output, map<string, string> parameter)
{
   curl_global_init(CURL_GLOBAL_DEFAULT);
   curl = curl_easy_init();
   const string url = HOST + uri + "?" + this->url(output, parameter);
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

   curl_global_cleanup();
   GetResponse gr;
   gr.httpCode = httpCode;
   gr.payload = *httpData.get();
   return gr;
}

}

