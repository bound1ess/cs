task :test do
    sh 'rspec tests/ --color --format documentation --require ./tests/helper.rb'
end

task :default => :test

task :server do
    sh 'thin start --adapter file --address localhost --port 8000'
end
