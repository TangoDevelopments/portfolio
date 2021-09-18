import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    int data;
    int sum = 0;

    Scanner input = new Scanner(System.in);

    do {
      System.out.println("Enter an integer (the input ends if it is 0): ");
      data = input.nextInt();
      sum += data;
    } while (data != 0);

    System.out.println("The sum is " + sum);

    System.out.println("\n----------------------------------\n");

    System.out.println("Please input a string, and I will reverse it: ");
    String word = input.next();
    System.out.println(forLoop(word));
  }

  public static String forLoop(String word) {
    StringBuilder result = new StringBuilder(word.length());
    for (int i = word.length() - 1; i >= 0; i--) {
      result.append(word.charAt(i));
    }
    return result.toString();
  }
}
