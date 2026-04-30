#include <iostream>
#include <vector>
using namespace std;

class Contact {
public:
    string name;
    string phone;
  
    void input() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone: ";
        cin >> phone;
    }

    void display() {
        cout << "Name: " << name << ", Phone: " << phone << endl;
    }
};

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\n--- Contact Book ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Contact c;
            c.input();
            contacts.push_back(c);
            cout << "Contact Added!\n";
        }

        else if (choice == 2) {
            if (contacts.empty()) {
                cout << "No contacts available.\n";
            } else {
                for (int i = 0; i < contacts.size(); i++) {
                    contacts[i].display();
                }
            }
        }

        else if (choice == 3) {
            string searchName;
            cout << "Enter name to search: ";
            cin >> searchName;

            bool found = false;
            for (int i = 0; i < contacts.size(); i++) {
                if (contacts[i].name == searchName) {
                    contacts[i].display();
                    found = true;
                }
            }

            if (!found) {
                cout << "Contact not found.\n";
            }
        }

        else if (choice == 4) {
            string deleteName;
            cout << "Enter name to delete: ";
            cin >> deleteName;
            bool found = false;

        for (int i = 0; i < contacts.size(); i++) {
           if (contacts[i].name == deleteName) {
              contacts.erase(contacts.begin() + i);
              i--; // adjust index after deletion
              found = true;
    }
}

       if (found) {
          cout << "All matching contacts deleted!\n";
}


            if (!found) {
                cout << "Contact not found.\n";
            }
        }

    } while (choice != 5);

    cout << "Exiting...\n";
    return 0;
}
