require_relative '../src/hash_table'

RSpec.describe(HashTable) do

    before(:each) do
        @sut = HashTable.new
    end

    it('sets a key-value pair') do
        @sut.set('foo', 'fizz')
    end

    it('finds a value by given key') do
        expect(@sut.get('foo')).to eq(nil)

        @sut.set('foo', 'bar')

        expect(@sut.get('foo')).to eq('bar')
    end
end
