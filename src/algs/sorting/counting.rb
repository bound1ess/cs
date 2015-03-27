module Algorithms
    module Sorting
        class Counting
            def sort(array)
                count = Array.new(array.max + 1, 0)

                for value in array
                    count[value] += 1
                end

                for index in 1..array.max
                    count[index] += count[index - 1]
                end

                result = Array.new(array.size + 1, 0)

                for value in array
                    result[count[value]] = value
                    count[value] = count[value] - 1
                end

                result
            end
        end
    end
end
