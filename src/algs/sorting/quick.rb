module Algorithms
    module Sorting
        class Quick
            def sort(array, left = 0, right = nil)
                right = array.size - 1 if right.nil?
                index = split(array, left, right)

                array = sort(array, left, index - 1) if left < (index - 1)
                array = sort(array, index, right) if index < right

                array
            end

            def split(array, left, right)
                pivot = array[(left + right) / 2]

                while left <= right
                    left += 1 while array[left] < pivot
                    right -= 1 while array[right] > pivot

                    if left <= right
                        tmp = array[left]
                        array[left] = array[right]
                        array[right] = tmp

                        left += 1
                        right -= 1
                    end
                end

                left
            end
        end
    end
end
