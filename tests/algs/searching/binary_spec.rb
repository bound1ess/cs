require_relative '../../../src/algs/searching/binary'

RSpec.describe(Algorithms::Searching::Binary) do

    before(:all) do
        @sut = Algorithms::Searching::Binary.new
    end

    it('looks for given value in sorted array') do
        expect(@sut.search(5, [])).to eq(false)
    end
end
