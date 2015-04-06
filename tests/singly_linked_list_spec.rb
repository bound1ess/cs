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
