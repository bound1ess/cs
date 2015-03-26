module Algorithms
    module Sorting
        class Bubble
            def initialize
                @swapped = true
            end

            def sort(array)
                while @swapped
                    @swapped = false

                    # Logging...
                    puts "Working with values #{array.join(', ')}..."
                    puts "Scanning indices 0-#{array.size - 1}..."

                    for index in 0..(array.size - 2)
                        if array[index] > array[index + 1]
                            array = swap(array, index, index + 1)
                            @swapped = true
                        end
                    end
                end

                array
            end

            def swap(array, index1, index2)

                # Logging...
                puts "Swapping values #{array[index1]} and #{array[index2]}..."

                tmp = array[index1]
                array[index1] = array[index2]
                array[index2] = tmp

                array
            end
        end
    end
end
