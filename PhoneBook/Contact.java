public class Contact {
  String name;
  String number;
  
  public Contact(String name, String number) {
    this.name = name;
    this.number = number;
  }
  
  public String getName() {
    return name;
  }
  
  public String getNumber() {
    return number;
  }
  
  public void setName(String name) {
    this.name = name;
  }
  
  public void setNumber(String number) {
    if (Utility.phoneNumberValidator(number) == true) {
      this.number = number;
    } else {
      System.out.println("Invalid Phone Number");
      this.number = null;
    }
  }
  
  public String getInfo() {
    return "Name: " + getName() + "\tNumber: " + getNumber();
  }
}
