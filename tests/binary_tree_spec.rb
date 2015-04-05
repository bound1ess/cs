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
