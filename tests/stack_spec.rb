require_relative '../src/stack'

RSpec.describe(Stack) do

    before(:each) do
        @sut = Stack.new(3)
    end

    it('pushes a value to the stack') do
        [1, 2, 3].each { |element| @sut.push!(element) }

        expect { @sut.push!(4) }.to raise_error(NoMemoryError, 'Stack overflow.')
    end

    it('pops a value from the stack') do
        expect(@sut.pop!).to eq(nil)

        @sut.push!(1)
        @sut.push!(2)

        expect(@sut.pop!).to eq(2)
        expect(@sut.pop!).to eq(1)
        expect(@sut.pop!).to eq(nil)
    end

    it('returns the top element in the stack') do
        expect(@sut.peek).to eq(nil)

        @sut.push!(1)
        @sut.push!(2)

        expect(@sut.peek).to eq(2)
    end

    it('checks if the stack is full or empty') do
        expect(@sut.empty?).to eq(true)
        expect(@sut.full?).to eq(false)

        @sut.push!(1)

        expect(@sut.empty?).to eq(false)
        expect(@sut.full?).to eq(false)

        @sut.push!(2)
        @sut.push!(3)

        expect(@sut.full?).to eq(true)
    end
end
