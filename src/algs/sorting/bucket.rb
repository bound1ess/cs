module Algorithms
    module Sorting
        class Bucket
            def sort(array)
                # We'll stick with 10 buckets.
                bucket_range = (array.max - array.min) / array.size
                buckets = Array.new (array.max / bucket_range) + 1

                puts "A bucket has values range of #{bucket_range}, there are %s buckets" % \
                    buckets.size

                # Place elements into their respective buckets.
                for value in array
                    bucket_id = value / bucket_range

                    puts "Placing #{value} in bucket ##{bucket_id}..."

                    buckets[bucket_id] = Array.new if buckets[bucket_id].nil?

                    buckets[bucket_id].push(value)
                end

                buckets
            end
        end
    end
end
