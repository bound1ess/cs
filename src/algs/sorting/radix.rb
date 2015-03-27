module Algorithms
    module Sorting
        class Radix
            # O(matrix.first.length * matrix.size)
            def sort(array)
                matrix = []

                for number in array
                    matrix.push digits(number)
                end

                offset = -1

                matrix.first.length.times do
                    offset += 1

                    matrix.sort! do |one, another|
                        one[offset] <=> another[offset]
                    end
                end

                matrix.map do |digits|
                    # Notice that this approach is very different from what I did in #digits.
                    digits.reverse.join('').to_i
                end
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
