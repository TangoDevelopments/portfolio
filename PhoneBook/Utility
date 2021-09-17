import java.util.Arrays;
import java.util.ArrayList;

class Utility{
  public static String letterSorter(String word) {
    char[] letters = word.toCharArray();
    Arrays.sort(letters);
    String sorted = new String(letters);
    return sorted;
  }
  public static String[] wordSorter(String sentence, char letter) {
    String[] words = sentence.split(" ");
    ArrayList<String> matchingWords = new ArrayList<String>();
    for (String word : words) {
      if (word.charAt(0) == letter || word.charAt(0) == Character.toUpperCase(letter) || word.charAt(0) == Character.toLowerCase(letter)) {
        matchingWords.add(word);
      }
    }
    String[] result = new String[matchingWords.size()];
    matchingWords.toArray(result);
    return result;
  }
  
  public static Integer[][] numSorter(int[] nums) {
    ArrayList<Integer> even = new ArrayList<Integer>();
    ArrayList<Integer> odd = new ArrayList<Integer>();
    for (int num : nums) {
      if (num % 2 == 0) {
        even.add(num);
      }
      else {
        odd.add(num);
      }
    }
    Integer[] sortedEven = new Integer[even.size()];
    even.toArray(sortedEven);
    Integer[] sortedOdd = new Integer[odd.size()];
    odd.toArray(sortedOdd);
    Arrays.sort(sortedEven);
    Arrays.sort(sortedOdd);
    Integer[][] result = {sortedEven, sortedOdd};
    return result;
  }
  
  public static boolean phoneNumberValidator(String phoneNumber) {
    return phoneNumber.matches("(\\d{3}-){2}\\d{4}");
  }
}
