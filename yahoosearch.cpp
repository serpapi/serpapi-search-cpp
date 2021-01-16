#include <serpapisearch.hpp>
#include <yahoosearch.hpp>

namespace serpapi 
{
using namespace std;
YahooSearch::YahooSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "yahoo") 
{ 
};
}