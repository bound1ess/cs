require_relative '../../../src/algs/searching/binary'

RSpec.describe(Algorithms::Searching::Binary) do

    before(:all) do
        @sut = Algorithms::Searching::Binary.new
    end

    it('looks for given value in sorted array') do
        expect(@sut.search(5, [])).to eq(false)

        expect(@sut.search(5, [3, 5, 7])).to eq(true)
        expect(@sut.search(5, [5, 6, 7])).to eq(true)
        expect(@sut.search(5, [3, 4, 5])).to eq(true)

        expect(@sut.search(1, [3, 5, 7])).to eq(false)
        expect(@sut.search(8, [3, 5, 7])).to eq(false)
    end
end
