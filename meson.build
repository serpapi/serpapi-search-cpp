project('serpapi-search-cpp', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

dep = [
    dependency('curl'),
    dependency('rapidjson')
    ]

executable('serpapi-search-cpp',
           'serpapisearch.cpp',
           'callback.cpp',
           'main.cpp',
           install : true,
           dependencies : dep,
           )
