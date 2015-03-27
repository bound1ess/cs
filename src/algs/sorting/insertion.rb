module Algorithms
    module Sorting
        class Insertion
            def sort(array)
                for index in 1..(array.size - 1)
                    value, hole = array[index], index

                    while hole > 0 and array[hole - 1] > value
                        array[hole] = array[hole - 1]
                        hole -= 1
                    end

                    array[hole] = value
                end

                array
            end
        end
    end
end
