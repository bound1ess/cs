module Algorithms
    module Sorting
        class Shell
            def sort(array)
                gap = array.size / 2

                while gap > 0
                    puts "Gap - #{gap}"

                    for index1 in gap..(array.size - 1)
                        tmp = array[index1]
                        index2 = index1

                        while gap <= index2 and tmp < array[index2 - gap]
                            array[index2] = array[index2 - gap]
                            index2 -= gap
                        end

                        puts "Replacing #{array[index2]} with #{tmp}"

                        array[index2] = tmp
                    end

                    gap /= 2
                end

                array
            end
        end
    end
end
