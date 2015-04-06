require_relative '../src/singly_linked_list'

RSpec.describe(ListNode) do

    before(:all) do
        @sut = ListNode.new(nil)
    end

    it('stores a value') do
        expect(@sut.value).to eq(nil)

        @sut.value = 'foo'

        expect(@sut.value).to eq('foo')
    end

    it('possibly points to another/next ListNode') do
        expect(@sut.link).to eq(nil)
        expect(@sut.end?).to eq(true)

        @sut.link = ListNode.new('foo')

        expect(@sut.link).to be_kind_of(ListNode)
        expect(@sut.end?).to eq(false)
    end
end

RSpec.describe(LinkedList) do

    before(:each) do
        @sut = LinkedList.new
    end

    it('stores a reference to the head node') do
        expect(@sut.head).to eq(nil)
        expect(@sut.empty?).to eq(true)

        ['foo', 'bar', 'baz'].each { |node| @sut.head = ListNode.new(node) }

        expect(@sut.head).to be_kind_of(ListNode)
        expect(@sut.head.value).to eq('baz')
        expect(@sut.empty?).to eq(false)
    end

    it('returns the tail/last node') do
        expect(@sut.tail).to eq(nil)

        ['foo', 'bar', 'baz', 'fizz'].each { |node| @sut.tail = ListNode.new(node) }

        expect(@sut.tail).to be_kind_of(ListNode)
        expect(@sut.tail.value).to eq('fizz')
    end

    it('returns all node values') do
        expect(@sut.to_a).to eq(Array.new)

        ['foo', 'bar', 'baz'].each { |node| @sut.tail = ListNode.new(node) }

        @sut.head = ListNode.new('fizz')

        expect(@sut.to_a).to eq(['fizz', 'foo', 'bar', 'baz'])
    end

    it('checks if the linked list has a loop') do
        expect(@sut.has_loop?).to eq(false)

        ['foo', 'bar', 'baz'].each { |node| @sut.head = ListNode.new(node) }

        expect(@sut.has_loop?).to eq(false)

        @sut.tail = ListNode.new('fizz', @sut.head)

        expect(@sut.has_loop?).to eq(true)
    end
end
