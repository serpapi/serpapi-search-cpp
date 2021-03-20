project('serpapi-search-cpp', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

dep = [
    dependency('libcurl'),
    dependency('RapidJSON')
    ]

executable('serpapi-search-cpp',
           'serpapisearch.cpp',
           'callback.cpp',
           'main.cpp',
           install : true,
           dependencies : dep,
           )
