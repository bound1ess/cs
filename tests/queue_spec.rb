require_relative '../src/queue'

RSpec.describe(Queue) do

    before(:each) do
        @sut = Queue.new
    end

    it('queues a value to the queue') do
        [1, 2, 3].each { |item| @sut.queue!(item) }
    end

    it('dequeues a value from the queue') do
        expect(@sut.dequeue!).to be(nil)

        @sut.queue!(1)
        @sut.queue!(2)

        expect(@sut.dequeue!).to be(1)
        expect(@sut.dequeue!).to be(2)
    end

    it('returns the first element in the queue') do
        expect(@sut.peek).to be(nil)

        @sut.queue!(1)
        @sut.queue!(2)

        expect(@sut.peek).to be(1)
    end

    it('checks if the queue is empty') do
        expect(@sut.empty?).to be(true)

        @sut.queue!(1)

        expect(@sut.empty?).to be(false)
    end
end
