require_relative 'queue'

class TreeNode
    attr_accessor :value, :left, :right

    def initialize(value, left = nil, right = nil)
        @value, @left, @right = value, left, right
    end
end

class BinaryTree
    attr_reader :root

    def initialize(root = nil)
        @root = root
    end

    def empty?
        @root.nil?
    end

    def insert(node)
        if @root.nil?
            @root = node

            return true
        end

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

    def all
        return [] if empty?

        do_traverse(@root).map { |node| node.value }
    end

    private
    def do_traverse(node)
        nodes = Array.new

        nodes.push(node)

        if not node.left.nil?
            nodes = nodes.concat do_traverse(node.left)
        end

        if not node.right.nil?
            nodes = nodes.concat do_traverse(node.right)
        end

        nodes
    end
end
