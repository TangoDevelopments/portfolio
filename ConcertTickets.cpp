/* Andrew Tang
   CS 2A
*/

#include <iostream>
using namespace std;

void printPurchase(int purchasedAmount, int ticketsLeft) {
  cout << "You have purchased " << purchasedAmount << " tickets, and there are " << ticketsLeft << " remaining." << endl; 
}

void sellTickets(string name, int max_tickets) {
  int ticketsLeft = max_tickets;
  while (ticketsLeft > 0) {
    int numTickets = 0;
    cout << "Welcome to ticket sales for the " << name << " concert." << endl;
    cout << endl;
    while (numTickets >= 0) {
      cout << "How many tickets would you like to buy?" << endl;
      cin >> numTickets;
      if (numTickets < 0) {
        cout << endl;
        cout << "Please choose a positive number of tickets." << endl;
        cout << endl;
        numTickets = 0;
        continue;
      }
      else if (numTickets > ticketsLeft) {
        string answer;
        cout << endl;
        cout << "Would you like a partial order? (y or Y for yes)" << endl;
        cin >> answer;
        if (answer == "y" || answer == "Y") {
          cout << endl;
          printPurchase(ticketsLeft, 0);
          cout << endl;
          cout << "The tickets are sold out!" << endl;
          ticketsLeft = 0;
          break;
        }
      }
      else {
        ticketsLeft -= numTickets;
        cout << endl;
        printPurchase(numTickets, ticketsLeft);
      }
      cout << endl;
      cout << "Next customer, please." << endl;
      cout << endl;
      break;
    }
  } 
}

int main(int argc, const char * argv[]) {
    sellTickets("Cats and Dogs", 3000);
    return 0;
}
