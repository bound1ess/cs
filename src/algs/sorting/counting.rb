module Algorithms
    module Sorting
        class Counting
            def sort(array)
                count = Array.new(array.max + 1, 0)

                puts "Created a new array for #{array.max + 1} elements"

                for value in array
                    count[value] += 1
                end

                puts "#count is [#{count.join(', ')}]"

                for index in 1..array.max
                    count[index] += count[index - 1]
                end

                puts "#count is [#{count.join(', ')}]"

                result = Array.new(array.size + 1, 0)

                for value in array
                    result[count[value]] = value
                    count[value] = count[value] - 1
                end

                result.slice(1, result.size - 1)
            end
        end
    end
end
