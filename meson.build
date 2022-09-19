project('serpapi', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

compiler = meson.get_compiler('cpp')
add_project_arguments(['-Wno-deprecated-declarations', '-funsigned-char'], language : 'cpp')

incdirs = include_directories('src')

libserpapi = static_library('serpapi', 
                        [
                          'src/serpapi.cpp', 
                          'src/callback.cpp'
                        ],
                        dependencies : [
                          dependency('libcurl'),
                          dependency('RapidJSON')
                        ],
                        include_directories : incdirs)

libserpapi_dep = declare_dependency(include_directories : incdirs, link_with : 
libserpapi)

subdir('oobt')
subdir('example')
