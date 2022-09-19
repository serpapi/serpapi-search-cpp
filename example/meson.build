
executable('google_example',
           'google_example.cpp',
           'helper.cpp',
           install : true,
           link_with : [libserpapi],
           include_directories : incdirs,
           dependencies : [
            dependency('libcurl'),
            dependency('RapidJSON')
           ]
           )
