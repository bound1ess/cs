module Algorithms
    module Sorting
        class Bucket
            def sort(array)
                # We'll stick with 10 buckets.
                bucket_range = (array.max - array.min) / array.size
                buckets = Array.new (array.max / bucket_range) + 1

                puts "Bucket values are within range of %s and there are %s buckets" % \
                    [bucket_range, buckets.size]

                # Place elements into their respective buckets.
                for value in array
                    bucket_id = value / bucket_range

                    puts "Placing #{value} in bucket ##{bucket_id}..."

                    buckets[bucket_id] = Array.new if buckets[bucket_id].nil?

                    buckets[bucket_id].push(value)
                end

                # Now sort elements in the buckets individually.
                buckets.each_with_index do |bucket, bucket_index|
                    next if bucket.nil?

                    buckets[bucket_index].sort!

                    puts "Sorted bucket ##{bucket_index}: [#{bucket.join(', ')}]"
                end

                # And put the elements back.
                result = []

                for bucket in buckets
                    next if bucket.nil?

                    result = result.concat(bucket)
                end

                result
            end
        end
    end
end
