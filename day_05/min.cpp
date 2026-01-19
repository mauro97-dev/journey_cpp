#include <iostream>
#include <string>

using namespace std;

struct Details {
    float height;
    float weight;
    string issue_date;
    string expiration_date;
    string state;
    char type_license;
    int license_number;
};

struct License {
    string birthdate;
    string address;
    Details d;
};

struct Person {
    string full_name;
    string civil_status;
    int age;
    string rol;
    License l;
};

void print_person(Person &p);
void enter_person(Person &p);
void enter_person_details(Person &p);

int main() {
    Person p;
    char choice = 'y';
    do {

        cout << "------------------------------\n";
        cout << "Enter person details:\n";
        cout << "------------------------------\n";

        enter_person(p);
        enter_person_details(p);

        cout << "Do you want to enter details for another person? (y/n): ";
        cin >> choice;
        cin.ignore();
        if (choice != 'y' && choice != 'Y') {
            break;
        }

    } while (true);

    return 0;
}

void enter_person(Person &p) {
    cout << "Enter full name: ";
    getline(cin, p.full_name);
    cout << "Enter civil status: ";
    getline(cin, p.civil_status);
    cout << "Enter age: ";
    cin >> p.age;
    cin.ignore();
    cout << "Enter rol: ";
    getline(cin, p.rol);
    cout << "Enter birthdate: ";
    getline(cin, p.l.birthdate);
    cout << "Enter address: ";
    getline(cin, p.l.address);
}

void enter_person_details(Person &p) {
    cout << "Enter license number: ";
    cin >> p.l.d.license_number;
    cin.ignore();
    cout << "Enter license type (A, B, C, etc.): ";
    cin >> p.l.d.type_license;
    cin.ignore();
    cout << "Enter state: ";
    getline(cin, p.l.d.state);
    cout << "Enter issue date: ";
    getline(cin, p.l.d.issue_date);
    cout << "Enter expiration date: ";
    getline(cin, p.l.d.expiration_date);
    cout << "Enter height: ";
    cin >> p.l.d.height;
    cout << "Enter weight: ";
    cin >> p.l.d.weight;

    cout << "\nPerson Details Entered:\n";
    cout << "=========================\n";
    print_person(p);
}

void print_person(Person &p) {
    cout << "Full name: " << p.full_name << endl;
    cout << "Civil status: " << p.civil_status << endl;
    cout << "Age: " << p.age << endl;
    cout << "Rol: " << p.rol << endl;
    cout << "Birthdate: " << p.l.birthdate << endl;
    cout << "Address: " << p.l.address << endl;
    cout << "License number: " << p.l.d.license_number << endl;
    cout << "License type: " << p.l.d.type_license << endl;
    cout << "State: " << p.l.d.state << endl;
    cout << "Issue date: " << p.l.d.issue_date << endl;
    cout << "Expiration date: " << p.l.d.expiration_date << endl;
    cout << "Height: " << p.l.d.height << endl;
    cout << "Weight: " << p.l.d.weight << endl;
}