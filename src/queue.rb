class Queue
    def initialize
        @queue = Array.new
    end

    def queue!(value)
        @queue.push(value)
        value
    end

    def dequeue!
        @queue.shift
    end

    def peek
        @queue.first
    end

    def empty?
        @queue.size < 1
    end
end
