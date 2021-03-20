#include <serpapisearch.hpp>
#include <yandexsearch.hpp>

namespace serpapi 
{
using namespace std;
YandexSearch::YandexSearch(map<string,string> parameter, string apiKey): SerpApiSearch(parameter, apiKey, "yandex") 
{ 
}
}