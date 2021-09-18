import java.util.ArrayList;

public class PhoneBook {
  ArrayList<Contact> contacts;
  
  public PhoneBook() {
    contacts = new ArrayList<Contact>();
  }
  
  public ArrayList<Contact> getContacts() {
    return contacts;
  }

  public void printAllContacts() {
    for (int i = 0; i < getContacts().size(); i++) {
      System.out.println(String.valueOf(i + 1) + ". " + getContacts().get(i).getInfo());
    }
  }
  
  public void addContact(Contact contact) {
    getContacts().add(contact);
  }
  
  public void removeContact(int index) {
    getContacts().remove(index);
  }
  
  public void updateContact(int index, String newName) {
    getContacts().get(index).setName(newName);
  }
  
  public void deleteContact(int index) {
    removeContact(index);
  }
}
