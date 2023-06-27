/*Micro project :Phonebook Directory using file that can perform the following function
		1.Add contact detail.
		2.Search contact detail.
		3.Modify contact detail.
		4.List contact detail.
		5.Delete contact detail.
		Group:
				226020307199 : Saurabh Sonagara
				226020307201 : Spandan.H.Parikh
				226020307204 : Tirth Tankaria
				226020307205 : Herit Tanna
				226020307211 : Hitarth Upadhyay*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct PhoneBookRecord {
    string name;
    string phoneNumber;
    string email;
    string address;
};

void addRecord() {
    ofstream file("phonebook.txt", ios::app);

    PhoneBookRecord record;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, record.name);
    cout << "Enter phone number: ";
    getline(cin, record.phoneNumber);
    cout << "Enter email id: ";
    getline(cin, record.email);
    cout << "Enter address: ";
    getline(cin, record.address);

    file << record.name << "," << record.phoneNumber << "," << record.email << "," << record.address << endl;

    cout << "Record added successfully!" << endl;

    file.close();
}

void searchRecord() {
    ifstream file("phonebook.txt");

    string name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        string recordName = line.substr(0, pos1);
        size_t pos2 = line.find(",", pos1 + 1);
        string phoneNumber = line.substr(pos1 + 1, pos2 - pos1 - 1);
        size_t pos3 = line.find(",", pos2 + 1);
        string email = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string address = line.substr(pos3 + 1);

        if (recordName == name) {
            cout << "Name: " << recordName << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "Email: " << email << endl;
            cout << "Address: " << address << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }

    file.close();
}

void modifyRecord() {
    string name;
    cout << "Enter name to modify: ";
    cin.ignore();
    getline(cin, name);

    fstream file("phonebook.txt", ios::in | ios::out);

    bool found = false;
    string line;
    streampos modifyPos;
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        string recordName = line.substr(0, pos1);
        size_t pos2 = line.find(",", pos1 + 1);
        string phoneNumber = line.substr(pos1 + 1, pos2 - pos1 - 1);
        size_t pos3 = line.find(",", pos2 + 1);
        string email = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string address = line.substr(pos3 + 1);

        if (recordName == name) {
            cout << "Enter new phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter new email id: ";
            getline(cin, email);
            cout << "Enter new address: ";
            getline(cin, address);

            modifyPos = file.tellg() - line.length() - 1;
            file.seekp(modifyPos);

            file << recordName << "," << phoneNumber << "," << email << "," << address << endl;

            cout << "Record modified successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }

    file.close();
}

void listRecords() {
    ifstream file("phonebook.txt");

    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        string recordName = line.substr(0, pos1);
        size_t pos2 = line.find(",", pos1 + 1);
        string phoneNumber = line.substr(pos1 + 1, pos2 - pos1 - 1);
        size_t pos3 = line.find(",", pos2 + 1);
        string email = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string address = line.substr(pos3 + 1);

        cout << "Name: " << recordName << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
        cout << "-------------------------" << endl;
    }

    file.close();
}

void deleteRecord() {
    string name;
    cout << "Enter name to delete: ";
    cin.ignore();
    getline(cin, name);

    ifstream inputFile("phonebook.txt");
    ofstream outputFile("temp.txt");

    bool found = false;
    string line;
    while (getline(inputFile, line)) {
        size_t pos1 = line.find(",");
        string recordName = line.substr(0, pos1);

        if (recordName != name) {
            outputFile << line << endl;
        } else {
            found = true;
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("phonebook.txt");
        rename("temp.txt", "phonebook.txt");
        cout << "Record deleted successfully!" << endl;
    } else {
        remove("temp.txt");
        cout << "Record not found!" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "Phone Book Management System" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Search Record" << endl;
        cout << "3. Modify Record" << endl;
        cout << "4. List Records" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                modifyRecord();
                break;
            case 4:
                listRecords();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 6);

    return 0;
}
