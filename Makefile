
all: build run
	
# initialize meson build
init:
	rm -rf build/
	meson setup build

# build application
build:
	meson compile -C build -v
	cd build && ninja

# run application
run:
	./build/serpapi-cpp

# tested on AARCH64 and x86
install_linux:
	sudo apt update -y && sudo apt install -f -y build-essential meson pkg-config curl cmake meson ninja-build libcurl4-openssl-dev rapidjson-dev

# tested on Apple M1 aarch64
install_apple:
	brew install meson pkg-config curl cmake meson ninja rapidjson

# reset build directory
reset: init
