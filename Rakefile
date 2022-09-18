# automatic class generations
# 

task :default => [:init, :build, :run]

# initialize meson build
task :init do
	sh('rm -rf build/')
	sh('meson setup build')
end

# build application
task :build => FileList['*.hpp', '*.cpp'] do
	sh('meson compile -C build -v')
	sh('cd build && ninja')
end

# run application
task :run do
	sh('./build/serpapi-cpp')
end

# tested on AARCH64 and x86
task :install_linux do
	sh('sudo apt update -y && sudo apt install -f -y build-essential meson pkg-config curl cmake meson ninja-build libcurl4-openssl-dev rapidjson-dev')
end

# tested on Apple M1 aarch64
task :install_apple do
	sh('brew install meson pkg-config curl cmake meson ninja rapidjson')
end
