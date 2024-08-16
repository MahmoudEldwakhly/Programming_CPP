#include <iostream>
#include <string>

using namespace std;

// Define the nested structures
struct Name {
    string first;
    string middle;
    string last;
};

struct Address {
    string address_1;
    string address_2;
    string city;
    string zip_code;
};

struct HiringDate {
    int day;
    int month;
    int year;
};

struct ContactInfo {
    string phone;
    string cell_phone;
    string fax;
    string email;
};

struct Employee {
    Name name;
    Address address;
    HiringDate hiring_date;
    ContactInfo contact_info;
};

// Declare functions
void add_employee(Employee employees[], int& num_employees);
void delete_employee(Employee employees[], int& num_employees);
void display_records(Employee employees[], int num_employees);

int main() {
    // Declare an array of employees
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int num_employees = 0;

    // Read the information for the 100 employees
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        cout << "Enter the information for employee #" << i+1 << ":" << endl;

        Name name;
        cout << "First name: ";
        cin >> name.first;
        cout << "Middle name: ";
        cin >> name.middle;
        cout << "Last name: ";
        cin >> name.last;

        Address address;
        cout << "Address line 1: ";
        cin.ignore();
        getline(cin, address.address_1);
        cout << "Address line 2: ";
        getline(cin, address.address_2);
        cout << "City: ";
        getline(cin, address.city);
        cout << "Zip code: ";
        getline(cin, address.zip_code);

        HiringDate hiring_date;
        cout << "Hiring date (day month year): ";
        cin >> hiring_date.day >> hiring_date.month >> hiring_date.year;

        ContactInfo contact_info;
        cout << "Phone number: ";
        cin.ignore();
        getline(cin, contact_info.phone);
        cout << "Cell phone number: ";
        getline(cin, contact_info.cell_phone);
        cout << "Fax number: ";
        getline(cin, contact_info.fax);
        cout << "Email address: ";
        getline(cin, contact_info.email);

        Employee new_employee = {name, address, hiring_date, contact_info};
        employees[num_employees] = new_employee;
        num_employees++;
    }

    // Display the menu and get the user's choice
    char choice;
    do {
        cout << "MENU" << endl;
        cout << "----" << endl;
        cout << "1. Add an employee" << endl;
        cout << "2. Delete an employee" << endl;
        cout << "3. Display records" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cout << endl;

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case '1':
                add_employee(employees, num_employees);
                break;
            case '2':
                delete_employee(employees, num_employees);
                break;
            case '3':
                display_records(employees, num_employees);
                break;
            case '4':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != '4');

    return 0;
}

// Function to add a new employee
void add_employee(Employee employees[], int& num_employees) {
    if (num_employees >= 100) {
        cout << "Maximum number of employees reached. Cannot add more." << endl;
        return;
    }

    // Get the information for the new employee
    cout << "Enter the following information for the new employee:" << endl;

    Name name;
    cout << "First name: ";
    cin >> name.first;
    cout << "Middle name: ";
    cin >> name.middle;
    cout << "Last name: ";
    cin >> name.last;

    Address address;
    cout << "Address line 1: ";
    cin.ignore();
    getline(cin, address.address_1);
    cout << "Address line 2: ";
    getline(cin, address.address_2);
    cout << "City: ";
    getline(cin, address.city);
    cout << "Zip code: ";
    getline(cin, address.zip_code);

    HiringDate hiring_date;
    cout << "Hiring date (day month year): ";
    cin >> hiring_date.day >> hiring_date.month >> hiring_date.year;

    ContactInfo contact_info;
    cout << "Phone number: ";
    cin.ignore();
    getline(cin, contact_info.phone);
    cout << "Cell phone number: ";
    getline(cin, contact_info.cell_phone);
    cout << "Fax number: ";
    getline(cin, contact_info.fax);
    cout << "Email address: ";
    getline(cin, contact_info.email);

    // Add the new employee to the array
    Employee new_employee = {name, address, hiring_date, contact_info};
    employees[num_employees] = new_employee;
    num_employees++;

    cout << "New employee added successfully." << endl;
}

// Function to delete an employee
void delete_employee(Employee employees[], int& num_employees) {
    if (num_employees == 0) {
        cout << "No employees to delete." << endl;
        return;
    }

    // Get the index of the employee to delete
    int index;
    cout << "Enter the index of the employee to delete (0-" << num_employees-1 << "): ";
    cin >> index;

    if (index < 0 || index >= num_employees) {
        cout << "Invalid index. Please try again." << endl;
        return;
    }

    // Shift the remaining employees in the array to fill the gap
    for (int i = index; i < num_employees-1; i++) {
        employees[i] = employees[i+1];
    }

    num_employees--;

    cout << "Employee deleted successfully." << endl;
}

// Function to display a sorted list of records
void display_records(Employee employees[], int num_employees) {
    if (num_employees == 0) {
        cout << "No employees to display." << endl;
        return;
    }

    // Sort the employees by full name
    for (int i = 0; i < num_employees-1; i++) {
        for (int j = i+1; j < num_employees; j++) {
            string name1 = employees[i].name.first + employees[i].name.middle + employees[i].name.last;
            string name2 = employees[j].name.first + employees[j].name.middle + employees[j].name.last;
            if (name1 > name2) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }

    // Display the sorted list of employees
    cout << "Sorted list of employees:" << endl;
    for (int i = 0; i < num_employees; i++) {
        cout << i+1 << ". " << employees[i].name.first << " " << employees[i].name.middle << " " << employees[i].name.last << endl;
        cout << "   " << employees[i].address.address_1 << endl;
        if (employees[i].address.address_2 != "") {
            cout << "   " << employees[i].address.address_2 << endl;
        }
        cout << "   " << employees[i].address.city << ", " << employees[i].address.zip_code << endl;
        cout << "   Phone: " << employees[i].contact_info.phone << endl;
        cout << "   Cell: " << employees[i].contact_info.cell_phone << endl;
        cout << "   Fax: " << employees[i].contact_info.fax << endl;
        cout << "   Email: " << employees[i].contact_info.email << endl;
    }
}


//This modified function creates two strings for each employee containing their entire name (first, middle, and last names concatenated). The sorting algorithm then compares these strings to determine the order of the employees in the sorted list.
