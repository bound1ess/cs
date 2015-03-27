module Algorithms
    module Sorting
        class Merge
            def sort(array)
                return array if array.size < 2

                middle = array.size / 2
                left, right = array.slice(0, middle), array.slice(middle, array.size - middle)

                merge sort(left), sort(right)
            end

            def merge(left, right)
                merged = []

                while left.size > 0 or right.size > 0
                    if left.size > 0 and right.size > 0
                        if left.first <= right.first
                            merged.push(left.shift)
                        else
                            merged.push(right.shift)
                        end
                    elsif left.size > 0
                        merged.push(left.shift)
                    elsif right.size > 0
                        merged.push(right.shift)
                    end
                end

                merged
            end
        end
    end
end
