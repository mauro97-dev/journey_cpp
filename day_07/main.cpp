#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main() {
    // Dynamic memory allocation.

    // The "new" operator allocates a block of memory with the data type.-
    // The "delete" operator frees the memory allocated by "new".
    int max_size = 0;
    int *memory_address;
    cout << "==========================================================\n"; 
    cout << "The script allocates memory for an array of integers.\n";
    cout << "Enter an integer: ";
    cin >> max_size;

    if (max_size > 0) {
        memory_address = new int[max_size]; // Allocates memory for an array of integers.-
        
        cout << "\nIncrease the value by 2.\n";

        for (int i = 0; i < max_size; i++) {
            memory_address[i] = i + 2;
        }

        cout << "\nThe values are: \n";
        cout << "Address\t\tIndex\tIndex + 2\n";
        for (int i = 0; i < max_size; i++) {
            cout << &memory_address[i] << "\t" << i << "\t" << memory_address[i] << "\n";
        }

        delete[] memory_address; // Frees the allocated memory.-

    } else {
        cout << "Error. Size must be greater than 0.\n";
    }

    return 0;
}