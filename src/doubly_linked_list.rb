class ListNode

    attr_accessor :value, :back, :forward

    def initialize(value, back = nil, forward = nil)
        @value, @back, @forward = value, back, forward
    end

    def head?
        @back.nil?
    end

    def tail?
        @forward.nil?
    end
end

class LinkedList

    attr_reader :head

    def initialize
        @head = nil
    end

    def head=(node)
        node.forward = @head
        @head = node
    end

    def tail=(node)
        tail = tail()
        tail.forward = node
        node.back = tail
    end

    def tail
        node = @head

        loop do
            break if node.nil? or node.tail?
            node = node.forward
        end

        node
    end

    def empty?
        @head.nil?
    end

    def nodes
        nodes, node = Array.new, @head

        loop do
            nodes.push node.value
            break if node.tail?
            node = node.forward
        end

        nodes
    end
end
