module Algorithms
    module Sorting
        class Insertion
            def sort(array)
                for index in 1..(array.size - 1)
                    value, hole_index = array[index], index

                    puts "Value: #{value}, initial hole position: #{hole_index}"

                    while hole_index > 0 and array[hole_index - 1] > value
                        array[hole_index] = array[hole_index - 1]
                        hole_index -= 1
                    end

                    puts "The hole position was adjusted to #{hole_index}"

                    array[hole_index] = value
                end

                array
            end
        end
    end
end
