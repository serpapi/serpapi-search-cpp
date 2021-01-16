file_set=$(wildcard *.cpp)
app_name=main

.PHONY: build

all: build run
	
build:
	meson compile -C build -v

run:
	./build/serpapi-search-cpp

# tested on AARCH64 and x86
install_linux:
	sudo apt-get install -f libcurl4-openssl-dev libjsoncpp-dev
	brew curl jsoncpp

# tested on Apple M1 aarch64
install_apple:
	brew install meson pkg-config curl cmake meson ninja rapidjson

reset:
	-rm -rf build/
	meson setup build
