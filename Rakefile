# automatic class generations
# 
task :default do
    puts 'automatic class creation'
    files = [
        'googlesearch.cpp',
        'googlesearch.hpp',
    ]
    source = 'google'
    names = %w(bing baidu homedepot yahoo yandex walmart youtube linkedin)
    names.each do |name|
        files.each do |fn|
            buf = File.read(fn)
            buf.gsub!(source, name)
            buf.gsub!(source.capitalize, name.capitalize)
            buf.gsub!(source.upcase, name.upcase)
            fout = fn.gsub(source, name)
            puts "save: " + fout
            File.write(fout, buf)
        end
    end

    puts 'usage:'
    names.each do |name|
        puts "#include <#{name}search.cpp>"
    end
    names.each do |name|
        puts "serpapi::#{name.capitalize}Search search(parameter, apiKey);"
    end
end
