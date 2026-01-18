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

struct People {
    string full_name;
    string civil_status;
    int age;
    string rol;
    License l;
};

void enter_person(People &p);
void enter_person_details(People &p);
void show_person_data(const People &p);

int main() {
    People p;

    cout << "Learning structures and pointers" << endl;
    cout << "=========================" << endl;

    enter_person(p);
    enter_person_details(p);
    show_person_data(p);

    return 0;
}

void enter_person(People &p) {
    cout << "--- Enter person details ---" << endl;
    cout << "Enter a full name: ";
    getline(cin >> ws, p.full_name);

    cout << "Enter the status civil: ";
    cin >> p.civil_status;
    cout << "Enter age: ";
    cin >> p.age;
    cout << "Enter the rol: ";
    cin >> p.rol;
}

void enter_person_details(People &p) {
    cout << "\n--- Driver's license information ---" << endl;
    cout << "Enter the birthdate: ";
    cin >> p.l.birthdate;
    cout << "Enter the address: ";
    cin >> p.l.address;

    cout << "--- Additional details ---" << endl;
    cout << "License number: ";
    cin >> p.l.d.license_number;
    cout << "License type: ";
    cin >> p.l.d.type_license;
    cout << "State: ";
    cin >> p.l.d.state;
}

void show_person_data(const People &p) {
    cout << "\n=========================" << endl;
    cout << "Name: " << p.full_name << endl;
    cout << "Age: " << p.age << endl;
    cout << "License N#: " << p.l.d.license_number << endl;
    cout << "=========================" << endl; 
}