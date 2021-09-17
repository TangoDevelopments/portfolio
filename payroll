import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    payroll();
  }

  public static void payroll() {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter employee's name:");
    String name = scanner.nextLine();
    System.out.println("Enter number of hours worked in a week");
    double hours = scanner.nextInt();
    System.out.println("Enter hourly pay rate:");
    double pay = scanner.nextDouble();
    System.out.println("Enter federal tax withholding rate:");
    double fed = scanner.nextDouble();
    System.out.println("Enter state tax withholding rate:");
    double state = scanner.nextDouble();

    double gross = hours * pay;
    double stateWithhold = gross * (state/100);
    double federalWithhold = gross * (fed/100);
    double deductions = federalWithhold + stateWithhold;
    double net = gross - deductions;

    System.out.println("Employee Name: " + name);
    System.out.println("Hours Worked: " + hours);
    System.out.println("Pay Rate: $" + pay);
    System.out.println("Gross Pay: $" + gross);
    System.out.println("Deductions:");
    System.out.println("\tFederal Withholding ($" + fed + "): " + federalWithhold);
    System.out.println("\tState Withholding ($" + state + "): " + stateWithhold);
    System.out.println("Total Deduction: $" + deductions);
    System.out.println("Net Pay: $" + net);
  }
}
