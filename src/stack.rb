class Stack
    def initialize(size=128)
        @stack, @size = Array.new, size
    end

    def push!(value)
        raise NoMemoryError, "Stack overflow." unless @stack.size < @size

        @stack.push(value)
        value
    end

    def pop!
        @stack.pop
    end

    def peek
        @stack.last
    end

    def empty?
        @stack.size < 1
    end

    def full?
        @stack.size == @size
    end
end
