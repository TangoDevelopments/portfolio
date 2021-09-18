import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    PhoneBook phoneBook = new PhoneBook();
    Scanner scanner = new Scanner(System.in);
    //Driver code
    int menu_choice = 0;
    while (menu_choice != 5) {
      printMenu();
      String input = scanner.next();
      menu_choice = Integer.parseInt(input);
      if (menu_choice == 1) {
        phoneBook.printAllContacts();
      } else if (menu_choice == 2) {
        phoneBook.addContact(getValidContact(scanner));
      } else if (menu_choice == 3) {
        if (phoneBook.getContacts().size() > 0) {
          int index = getValidIndex(phoneBook.getContacts(), scanner);
          System.out.println("\nEnter the contact's new name.");
          String name = scanner.next();
          phoneBook.updateContact(index, name);
          } else {
            System.out.println("\nThere are no contacts to update.");
          }
      } else if (menu_choice == 4) {
        if (phoneBook.getContacts().size() > 0) {
          int index = getValidIndex(phoneBook.getContacts(), scanner);
          phoneBook.deleteContact(index);
        } else {
          System.out.println("\nThere are no contacts to delete. Try creating some contacts first!");
        }
      } else if (menu_choice == 5) {
        break;
      } else {
        System.out.println("Invalid Input. Please enter a valid menu choice.");
      }
    }
  }
  

  
  
  
  private static void printMenu() {
    System.out.println("\n1. View all contacts\n2. Add a contact\n3. Update a contact\n4. Delete a contact\n5. Quit");
  }
  
  private static int getValidIndex(ArrayList<Contact> arrayList, Scanner scanner) {
    while (true) {
      System.out.println("\nPlease enter the slot number of the contact.");
      String input = scanner.next();
      if (input.matches("\\d+")) {
        int num = Integer.parseInt(input);
        if (num >= 1 && num <= arrayList.size()) {
          return num - 1;
        }
      }
      System.out.println("\nInvalid Answer! Please enter a number between 1 and " + arrayList.size() + ".");
    }
  }
  
  private static Contact getValidContact(Scanner scanner) {
    System.out.println("\nEnter the name of the contact.");
    String name = scanner.next();
    
    String number = "";
    boolean valid = false;
    while (!valid) {
      System.out.println("\nEnter the phone number of the contact.");
      number = scanner.next();
      if (Utility.phoneNumberValidator(number)) {
        valid = true;
      } else {
        System.out.println("\nInvalid phone number.");
      }
    }
    Contact contact = new Contact(name, number);
    return contact;
  }
}
