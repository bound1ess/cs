import java.util.Scanner;
import java.util.HashMap;
import java.io.File;
import java.io.FileNotFoundException;

public class decode {

  public static void main(String[] args) {
    Scanner reader;
    File schemeFile = new File("scheme.txt");
    HashMap<String, Character> encoding = new HashMap<>();

    try {
      reader = new Scanner(schemeFile);
    } catch (FileNotFoundException error) {
      System.out.println(error.toString());
      return;
    }

    while (reader.hasNextLine()) {
      String[] line = reader.nextLine().split("\\s");
      encoding.put(line[1], line[0].charAt(0));
    }

    reader.close();
    String message = new Scanner(System.in).nextLine();
    StringBuilder decoded = new StringBuilder();

    while (message.length() > 0) {
      boolean foundMatch = false;

      for (String key: encoding.keySet()) {
        if (key.length() <= message.length()) {
          if (message.substring(0, key.length()).equals(key)) {
            decoded.append(encoding.get(key));
            message = message.substring(key.length());
            foundMatch = true;
            break;
          }
        }
      }

      if ( ! foundMatch) {
        System.out.printf("Unable to decode string %s\n", message);
        return;
      }
    }

    System.out.println(decoded.toString());
  }
}
