#include <serpapisearch.hpp>
#include <baidusearch.hpp>

namespace serpapi 
{
using namespace std;
BaiduSearch::BaiduSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "baidu") 
{ 
};
}