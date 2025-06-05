#include <iostream>
#include <string>
#include <iomanip> //格式化输出
#include <fstream>

using namespace std;

struct Contact 
{
    string firstName;
    string lastName;
    string number;
    Contact* next;
};

Contact* head = nullptr;
Contact* tail = nullptr;
Contact* current = nullptr;

void readFile() {
    ifstream MyReadFile("filename.txt");

    string f_name, l_name, number;
    while (MyReadFile >> f_name >> l_name >> number) {
        Contact* newContact = new Contact{f_name, l_name, number};
        if (!head) {
            head = tail = newContact;
        } else {
            tail -> next = newContact;
            tail = newContact;
        }
    }
    MyReadFile.close();
}

void saveFile() {
    ofstream myFile("filename.txt");

    Contact* temp = head;
    while (temp) {
        myFile << temp->firstName << " " << temp->lastName << " " << temp->number << endl;
        temp = temp->next;
    }
    myFile.close();
}

void addContact() {
    string f_name, l_name, number;

    cout << "Enter First Name: ";
    cin >> f_name;
    cout << "Enter Last Name: ";
    cin >> l_name;
    cout << "Enter Contact Number: ";
    cin >> number;

    Contact* newContact = new Contact{f_name, l_name, number};
    if (!head) {
        head = tail = newContact;
    } else {
        tail -> next = newContact;
        tail = newContact;
    }

    cout << "Contact added: " << f_name << " " << l_name << " " << number << endl;
}

void displayContacts() {
    current = head;
    int entry = 1;

    cout << setw(5) << "Entry" << setw(11) << "FirstName" << setw(10) << "LastName" << setw(15) << "ContactNumber" << endl;
    while (current != nullptr) {
        cout << setw(5) << entry << setw(11) << current->firstName << setw(10) << current->lastName << setw(15) << current->number << endl;
        current = current->next;
        entry++;
    }
}

void updateContact() {
    string first_name, last_name, new_first_name, new_last_name, new_number;
    cout << "Enter First Name of the contact to update: ";
    cin >> first_name;
    cout << "Enter Last Name of the contact to update: ";
    cin >> last_name;

    Contact* temp = head;
    while (temp) {
        if (temp->firstName == first_name && temp->lastName == last_name) {
            cout << "Enter New First Name: ";
            cin >> new_first_name;
            cout << "Enter New Last Name: ";
            cin >> new_last_name;
            cout << "Enter New Contact Number: ";
            cin >> new_number;
            
            temp->firstName = new_first_name;
            temp->lastName = new_last_name;
            temp->number = new_number;
            cout << "Contact updated successfully." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Contact not found." << endl;
}

void deleteContact() {
    string first_name, last_name;
    cout << "Enter First Name of the contact to delete: ";
    cin >> first_name;
    cout << "Enter Last Name of the contact to delete: ";
    cin >> last_name;

    Contact* temp = head;
    Contact* prev = nullptr;

    while (temp) {
        if (temp->firstName == first_name && temp->lastName == last_name) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp;
            cout << "Contact deleted successfully." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Contact not found." << endl;
}

Contact* merge(Contact* left, Contact* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->firstName <= right->firstName) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Contact* mergeSort(Contact* head) {
    if (!head || !head->next) {
        return head;
    }

    Contact* slow = head;
    Contact* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Contact* mid = slow->next;
    slow->next = nullptr;

    Contact* left = mergeSort(head);
    Contact* right = mergeSort(mid);

    return merge(left, right);
}

void sortContacts() {
    head = mergeSort(head);
    cout << "Contacts sorted successfully." << endl;
    
    cout << setw(5) << "Entry" << setw(11) << "FirstName" << setw(10) << "LastName" << setw(15) << "ContactNumber" << endl;

    Contact* current = head;
    int entry = 1;
    
    while (current != nullptr) {
        cout << setw(5) << entry << setw(11) << current->firstName << setw(10) << current->lastName << setw(15) << current->number << endl;
        current = current->next;
        entry++;
    }
}

void searchContact() {
    string query;
    cout << "Enter search query (first name, last name, or contact number): ";
    cin >> query;

    Contact* temp = head;
    int entry = 1;

    cout << setw(5) << "Entry" << setw(11) << "FirstName" << setw(10) << "LastName" << setw(15) << "ContactNumber" << endl;
    while (temp!=nullptr) {
        if (temp->firstName == query || temp->lastName == query || temp->number == query) {
            cout << setw(5) << entry << setw(11) << temp->firstName << setw(10) << temp->lastName << setw(15) << temp->number << endl;
            current = temp;

            return;
        }
        temp = temp->next;
    }
    cout << "No contact found with the given query." << endl;
    
}

int main() {
    readFile();

    int opt;
    while (true) {
        cout << "----- Address Book -----" << endl;
        cout << "1. Add Contacts" << endl;
        cout << "2. Display All Contacts" << endl;
        cout << "3. Update Contact Information" << endl;
        cout << "4. Sort Contacts" << endl;
        cout << "5. Search Contact" << endl;
        cout << "6. Delete Contact" << endl;
        cout << "7. Exit" << endl;

        cout << "CHOOSE AN OPTION: ";
        cin >> opt;

        if (opt == 1) {
            addContact();
            saveFile(); 
        } else if (opt == 2) {
            displayContacts();
        } else if (opt == 3) {
            updateContact();
            saveFile(); 
        } else if (opt == 4) {
            sortContacts();
            saveFile(); 
        } else if (opt == 5) {
            searchContact();
        } else if (opt == 6) {
            deleteContact();
            saveFile();
        } else if (opt == 7) {
            break;
        } else {
            cout << "Invalid option. Please choose again." << endl;
        }
    }
    return 0;
}