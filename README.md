# serpapi-search-cpp

Extension to search on Google, Bing, HomeDepot, Baidu, Yandex and more using SerpApi written in C++.
The backend is powered by serpapi.com and required an account

Current Status: `draft`

## Get started.
 - Set an environment API_KEY=<secret>
 - Install dependency either apple or linux tested.
    - `make install_apple`
    - `make install_linux`
- Initialize the project: `make reset`
- Compile `make` or `make build run`
- Edit main.cpp for testing.

#### To modify the *Search classes
 - edit sooglesearch.cpp/hpp
 - update all files using  `rake`

## TODO

 - [ ] Add unit test
 - [ ] Customize classes
 - [ ] Package as a library 
 - [ ] Create OOBT test
 - [ ] Publish library online
 - [ ] Add REPL.it example
 - [ ] Add integration documentation on serpapi.com
 - [ ] Write a full README to match  serpapi-search-results-dotnet
