import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.HashMap;

class HuffmanTree implements Comparable<HuffmanTree> {
  public int frequency;

  public HuffmanTree(int frequency) {
    this.frequency = frequency;
  }

  public int compareTo(HuffmanTree tree) {
    return Integer.signum(this.frequency - tree.frequency);
  }
}

class HuffmanLeaf extends HuffmanTree {
  public char encodedSymbol;

  public HuffmanLeaf(int frequency, char encodedSymbol) {
    super(frequency);
    this.encodedSymbol = encodedSymbol;
  }
}

class HuffmanNode extends HuffmanTree {
  public HuffmanTree left, right;

  public HuffmanNode(HuffmanTree left, HuffmanTree right) {
    super(left.frequency + right.frequency);
    this.left = left;
    this.right = right;
  }
}

public class encode {
  private static final int ALPHABET_SIZE = 256;
  private static HashMap<Character, String> encoding = new HashMap<>();

  public static void main(String[] args) {
    String message = new Scanner(System.in).nextLine();
    int[] frequencyTable = new int[ALPHABET_SIZE];
    PriorityQueue<HuffmanTree> queue = new PriorityQueue<>();

    for (char symbol: message.toCharArray()) {
      ++frequencyTable[(int) symbol];
    }

    for (int i = 0; i < frequencyTable.length; ++i) {
      if (frequencyTable[i] > 0) {
        queue.offer(new HuffmanLeaf(frequencyTable[i], (char) i));
      }
    }

    while (queue.size() > 1) {
      HuffmanTree left = queue.poll(), right = queue.poll();
      queue.offer(new HuffmanNode(left, right));
    }

    HuffmanTree tree = queue.poll();
    report(tree, new StringBuilder());

    try {
      encodeMessage(message, tree);
    } catch (Exception error) {
      System.out.println(error.toString());
    }
  }

  private static void report(HuffmanTree tree, StringBuilder prefix) {
    if (tree instanceof HuffmanLeaf) {
      HuffmanLeaf leaf = (HuffmanLeaf) tree;
      String format = "Char %c with frequency %d is encoded as %s\n";
      System.out.printf(format, leaf.encodedSymbol, leaf.frequency, prefix);
      encoding.put(leaf.encodedSymbol, prefix.toString());
    } else {
      HuffmanNode node = (HuffmanNode) tree;

      prefix.append('0');
      report(node.left, prefix);
      prefix.deleteCharAt(prefix.length() - 1);

      prefix.append('1');
      report(node.right, prefix);
      prefix.deleteCharAt(prefix.length() - 1);
    }
  }

  private static void encodeMessage(String message, HuffmanTree tree) throws Exception {
    StringBuilder encoded = new StringBuilder();

    for (char symbol: message.toCharArray()) {
      if ( ! encoding.containsKey(symbol)) {
        throw new Exception(String.format("Unable to find encoding for %c", symbol));
      }

      encoded.append(encoding.get(symbol));
    }

    System.out.println(encoded.toString());
  }
}
