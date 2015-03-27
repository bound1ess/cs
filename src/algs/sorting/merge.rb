module Algorithms
    module Sorting
        class Merge
            def sort(array)
                # Otherwise it's sorted (0 elements or only 1 element).
                return array if array.size < 2

                middle = array.size / 2
                left, right = array.slice(0, middle), array.slice(middle, array.size - middle)

                merge sort(left), sort(right)
            end

            def merge(left, right)
                merged = []

                puts "Working with subsets [#{left.join(', ')}] and [#{right.join(', ')}]..."

                # Keep merging until we run out of elements in either left or right subset(s).
                while left.size > 0 or right.size > 0
                    # If both subsets are not empty, we'll need to compare two values.
                    if left.size > 0 and right.size > 0
                        # Merge the correct value depending on outcome of the comparison.
                        if left.first <= right.first
                            merged.push(left.shift)
                        else
                            merged.push(right.shift)
                        end
                    # As described below, but for the left subset.
                    elsif left.size > 0
                        merged.push(left.shift)
                    # If the right subset is not empty, merge and delete its first element.
                    elsif right.size > 0
                        merged.push(right.shift)
                    end
                end

                puts "After merging: [#{merged.join(', ')}]"

                merged
            end
        end
    end
end
