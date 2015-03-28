module Algorithms
    module Searching
        class Binary
            def search(value, array)
                middle = array.size / 2

                # Essential check.
                return true if array[middle] == value

                # Base (or "exit") condition.
                return value == array.first if array.size == 1

                if array[middle] > value
                    # Left.
                    subset = array.slice(0, middle)
                else
                    # Right.
                    subset = array.slice(middle + 1, array.size - middle)
                end

                puts "Chosen subset: [#{subset.join(', ')}]"

                search(value, subset)
            end
        end
    end
end
