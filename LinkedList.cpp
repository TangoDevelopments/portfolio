// rec12.cpp
// Andrew Tang
// Practice with Doubly Linked Lists

#include <cstdlib>
#include <iostream>
using namespace std;

class List {
    friend ostream& operator<<(ostream& os, const List& list) {
        Node* cursor = list.head->next;
        while(cursor->next != nullptr) {
            os << cursor->data << " ";
            cursor = cursor->next;
        }
        cout << endl;
        return os;
    }
private:
    struct Node {
        Node(int data = 0, Node* prior = nullptr, Node* next = nullptr) : data(data), prior(prior), next(next) {}
        int data;
        Node* prior;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t theSize = 0;

public:
    class iterator {
        friend class List;
        friend bool operator==(const iterator& lhs, const iterator& rhs)  {
            return (lhs.where == rhs.where);
        }

        friend bool operator!=(const iterator& lhs, const iterator& rhs)  {
            return (lhs.where != rhs.where);
        }
    public:
        iterator(Node* where) : where(where){}

        iterator& operator++() {
            where = where->next;
            return *this;
        }

        iterator& operator--() {
            where = where->prior;
            return *this;
        }

        int& operator*() {
            return where->data;
        }
    private:
        Node* where;
    };

    List() {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prior = head;
    }
    void push_back(int data) {
        if (theSize == 0) {
            head->next = new Node(data, head, tail);
            tail->prior = head->next;
        }
        else {
            Node* oldTail = tail->prior;
            tail->prior = new Node(data, oldTail, tail);
            oldTail->next = tail->prior;
        }
        ++theSize;
    }

    void pop_back() {
        if (tail->prior != nullptr) {
            Node* oldTail = tail->prior;
            tail->prior = tail->prior->prior;
            if (tail->prior != nullptr) {
                tail->prior->next = tail;
            }
            else {
                head->next = tail;
            }
            delete oldTail;
            --theSize;
        }
    }

    int front() const {
        return head->next->data;
    }

    int& front() {
        return head->next->data;
    }

    int back() const {
        return tail->prior->data;
    }

    int& back() {
        return tail->prior->data;
    }

    size_t size() const{
        return theSize;
    }

    void push_front(int data) {
        if (theSize == 0) {
            head->next = new Node(data, head, tail);
            tail->prior = head->next;
        }
        else {
            Node* oldHead = head->next;
            head->next = new Node(data, head, oldHead);
            oldHead->prior = head->next;
        }
        ++theSize;
    }

    void pop_front() {
        if (head->next != nullptr) {
            Node* oldHead = head->next;
            head->next = head->next->next;
            if (head->next != nullptr) {
                head->next->prior = head;
            }
            else {
                tail->prior = head;
            }
            delete oldHead;
            --theSize;
        }
    }

    void clear() {
        while (head->next != tail) {
            Node* temp = head->next->next;
            delete head->next;
            temp->prior = head;
            head->next = temp;
            --theSize;
        }
    }

    int& operator[](size_t ind) const{
        if (ind >= theSize) {
            exit(0);
        }
        else {
            int count = 0;
            Node* cursor = head->next;
            while (count != ind) {
                cursor = cursor->next;
                ++count;
            }
            return cursor->data;
        }
    }

    iterator begin() {
        iterator iter(head->next);
        return iter;
    }

    iterator end() {
        iterator iter(tail);
        return iter;
    }

    iterator insert(iterator iter, int data) {
        Node* newNode = new Node(data, iter.where->prior, iter.where);
        iter.where->prior = newNode;
        newNode->prior->next = newNode;
        iterator result(newNode);
        ++theSize;
        return result;
    }

    iterator erase(iterator iter) {
        Node* result = iter.where->next;
        result->prior = iter.where->prior;
        iter.where->prior->next = result;
        delete iter.where;
        --theSize;
        return result;
    }
};

// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}

//// Task 8
//void doNothing(List aList) {
//    cout << "In doNothing\n";
//    printListInfo(aList);
//    cout << endl;
//    cout << "Leaving doNothing\n";
//}

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";

    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);

    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
//    // ***Need test for erase other than begin/end***
//    cout << "===================\n";
//
//    // Task 8
//    cout << "\n------Task Eight------\n";
//    cout << "Copy control\n";
//    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
//    printListInfo(myList);
//    cout << "Calling doNothing(myList)\n";
//    doNothing(myList);
//    cout << "Back from doNothing(myList)\n";
//    printListInfo(myList);
//
//    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
//    List listTwo;
//    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
//    printListInfo(listTwo);
//    cout << "listTwo = myList\n";
//    listTwo = myList;
//    cout << "myList: ";
//    printListInfo(myList);
//    cout << "listTwo: ";
//    printListInfo(listTwo);
//    cout << "===================\n";
}
