require_relative 'queue'

class TreeNode

    attr_accessor :value, :left, :right

    def initialize(value, left = nil, right = nil)
        @value, @left, @right = value, left, right
    end
end

class BinaryTree
    def initialize(root_node = nil)
        @root = root_node
    end

    def insert(node)
        return @root = node if @root.nil?

        # BFSearch using Queue.
        queue = Queue.new
        queue.queue!(@root)

        while not queue.empty?
            parent = queue.dequeue!

            if parent.left.nil?
                parent.left = node
                break
            else
                queue.queue!(parent.left)
            end

            if parent.right.nil?
                parent.right = node
                break
            else
                queue.queue!(parent.right)
            end
        end

        true
    end

    def traverse
        raise "No block was given." unless block_given?
    end
end
