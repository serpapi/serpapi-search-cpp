project('serpapi', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

add_project_arguments(['-Wno-deprecated-declarations', '-funsigned-char'], language : 'cpp')

dep = [
    dependency('libcurl'),
    dependency('RapidJSON')
    ]

executable('serpapi-cpp',
           'serpapi.cpp',
           'callback.cpp',
           'main.cpp',
           install : true,
           dependencies : dep,
           )
