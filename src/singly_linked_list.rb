class ListNode
    attr_accessor :value, :link

    def initialize(value, link = nil)
        @value, @link = value, link
    end

    def end?
        @link.nil?
    end
end

class LinkedList
    attr_reader :head

    def initialize
        @head = nil
    end

    def head=(node)
        node.link = @head
        @head = node
    end

    def tail=(node)
        tail().link = node
    end

    def tail
        tail = @head

        loop do
            break if tail.nil? or tail.end?
            tail = tail.link
        end

        tail
    end

    def empty?
        @head.nil?
    end

    def to_a
        values, node = Array.new, @head

        loop do
            values.push(node.value)
            break if node.end?
            node = node.link
        end

        values
    end

    def has_loop?
        # Floyd's algorithm.
        slow = fast = @head

        loop do
            slow = slow.link

            if fast.link.nil?
                return false
            else
                fast = fast.link.link
            end

            return false if fast.nil? or slow.nil?
            return true if fast.value == slow.value
        end
    end
end
