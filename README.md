<h1 align="center">Google Search Results in C++</h1>

<div align="center">
   <img src="https://user-images.githubusercontent.com/78694043/234493320-a9b06273-4264-4540-b5e6-4d1d2e6e4339.svg" width="700" alt="serpapi-search-cpp-logo">
</div>


Extension to search on Google, Bing, HomeDepot, Baidu, Yandex and more using SerpApi written in C++.
The backend is powered by serpapi.com and required an account

Current Status: `draft`

## Run with Docker

```bash
env API_KEY=API_KEY docker run --rm -it -e API_KEY --workdir /tmp/serpapi -v $PWD:/tmp/serpapi conanio/gcc10 make install_linux reset all
```

This will use https://hub.docker.com/layers/conanio/gcc10 image instead
of creating our own image for compilation on Linux.

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

https://rapidjson.org/md_doc_tutorial.html