class HashTable
    def initialize(size=128)
        @data, @size = Array.new, size
    end

    def set(key, value)
        @data[hash = hash_key(key)] = value

        hash
    end

    def get(key)
        return nil if @data[hash = hash_key(key)].nil?

        @data[hash]
    end

    private
    def hash_key(key)
        # We use the simple djb2 hashing algorithm (modified).
        hash = 5381

        key.each_byte do |byte|
            hash = (((hash << 5) + hash) + byte) % @size
        end

        hash
    end
end
