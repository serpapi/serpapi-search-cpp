executable('oobt',
           'main.cpp',
           install : true,
           link_with : [libserpapi],
           include_directories : incdirs,
           dependencies : [
            dependency('libcurl'),
            dependency('RapidJSON')
           ]
           )
