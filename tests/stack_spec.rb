require_relative '../src/stack'

RSpec.describe(Stack) do

    before(:all) do
        @sut = Stack.new(3)
    end

    it('pushes a value to the stack') do
        [1, 2, 3].each { |element| @sut.push!(element) }

        expect { @sut.push!(4) }.to raise_error(NoMemoryError, 'Stack overflow.')
    end
end
