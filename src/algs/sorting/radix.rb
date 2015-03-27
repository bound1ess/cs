module Algorithms
    module Sorting
        class Radix
            def sort(array)
                matrix = []

                for number in array
                    matrix.push digits(number)
                end

                matrix
            end

            def digits(number)
                digits = []

                while number > 0
                    digits.push (number % 10)
                    number /= 10
                end

                digits
            end
        end
    end
end
