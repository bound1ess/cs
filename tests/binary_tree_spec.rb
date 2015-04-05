require_relative '../src/binary_tree'

RSpec.describe(TreeNode) do

    before(:all) do
        @sut = TreeNode.new('foo')
    end

    it('stores a value') do
        expect(@sut.value).to eq('foo')

        @sut.value = 'bar'

        expect(@sut.value).to eq('bar')
    end

    it('has left child') do
        expect(@sut.left).to eq(nil)

        @sut.left = 'left'

        expect(@sut.left).to eq('left')
    end

    it('has right child') do
        expect(@sut.right).to eq(nil)

        @sut.right = 'right'

        expect(@sut.right).to eq('right')
    end
end

RSpec.describe(BinaryTree) do

    before(:each) do
        @sut = BinaryTree.new
    end

    it('returns the root node') do
        expect(@sut.root).to eq(nil)
    end

    it('inserts a TreeNode') do
        expect(@sut.insert(TreeNode.new('foo'))).to eq(true)

        expect(@sut.root).to be_kind_of(TreeNode)

        ['bar', 'baz', 'fizz'].each { |item| @sut.insert TreeNode.new(item) }
    end

    it('returns all TreeNode values') do
        node = TreeNode.new('foo', TreeNode.new('bar'), TreeNode.new('baz'))

        @sut.insert(node)

        expect(@sut.all).to eq(['foo', 'bar', 'baz'])
    end

    it('checks if the root node is present') do
        expect(@sut.empty?).to eq(true)

        @sut.insert(TreeNode.new('foo'))

        expect(@sut.empty?).to eq(false)
    end
end
