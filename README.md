# Address Book (C++)

A simple command-line Address Book application written in C++. This program allows users to manage contacts by adding, displaying, updating, sorting, searching, and deleting entries. All contact data is stored in a text file for persistence.

## Features

- Add new contacts (first name, last name, phone number)
- Display all contacts in a formatted table
- Update existing contact information
- Delete contacts by name
- Sort contacts alphabetically by first name
- Search for contacts by first name, last name, or phone number
- Data is saved to and loaded from `filename.txt`

## How to Use

1. **Clone the repository:**
   ```bash
   git clone https://github.com/your-username/your-repo-name.git
   cd your-repo-name
   ```

2. **Compile the program:**
   ```bash
   g++ -o address_book project.cpp
   ```

3. **Run the program:**
   ```bash
   ./address_book
   ```
   or on Windows:
   ```bash
   address_book.exe
   ```

4. **Follow the on-screen menu to manage your contacts.**

## File Structure

- `project.cpp` — Main source code file
- `filename.txt` — Data file for storing contacts (created automatically)

## Example

```text
----- Address Book -----
1. Add Contacts
2. Display All Contacts
3. Update Contact Information
4. Sort Contacts
5. Search Contact
6. Delete Contact
7. Exit
CHOOSE AN OPTION: 1
Enter First Name: John
Enter Last Name: Doe
Enter Contact Number: 1234567890
Contact added: John Doe 1234567890

----- Address Book -----
1. Add Contacts
2. Display All Contacts
3. Update Contact Information
4. Sort Contacts
5. Search Contact
6. Delete Contact
7. Exit
CHOOSE AN OPTION: 2
Entry  FirstName  LastName  ContactNumber
    1       John      Doe      1234567890
```

## Requirements

- C++ compiler (e.g., g++, clang++)
- Standard C++ libraries

## Notes

- The contact list is stored in a simple text file (`filename.txt`) in the same directory as the executable.
- Make sure you have write permissions in the directory to allow saving contacts.

## License

[MIT](LICENSE) 
