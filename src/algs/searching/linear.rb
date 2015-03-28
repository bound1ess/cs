module Algorithms
    module Searching
        class Linear
            def search(value, array)
                array.each { |element| return true if element == value }

                false
            end
        end
    end
end
