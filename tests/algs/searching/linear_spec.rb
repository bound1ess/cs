require_relative '../../../src/algs/searching/linear'

RSpec.describe(Algorithms::Searching::Linear) do

    before(:all) do
        @sut = Algorithms::Searching::Linear.new
    end

    it('looks for given value in sorted array') do
        expect(@sut.search(3, [])).to eq(false)

        expect(@sut.search(3, [3])).to eq(true)
        expect(@sut.search(5, [3, 4, 5])).to eq(true)
    end
end
