module Algorithms
    module Sorting
        class Selection
            def sort(array)
                for index in 0..(array.size - 2)
                    min_index = array.find_index(array.slice(index, array.size - index).min)

                    array = swap(array, index, min_index) unless min_index == index
                end

                array
            end

            def swap(array, index1, index2)

                # Logging events...
                puts "Swapping values #{array[index1]} (curr) and #{array[index2]} (min)..."

                tmp = array[index1]
                array[index1] = array[index2]
                array[index2] = tmp

                array
            end
        end
    end
end
