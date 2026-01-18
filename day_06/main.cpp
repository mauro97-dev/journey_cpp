#include<iostream>
#include<string>
using namespace std;

void increment(int* p);
void swap_values(int* a, int* b);

int main() {
    // int nums[] = {1, 2, 3, 4, 5};
    const int SIZE = 5;
    int nums[SIZE];
    cout << "====================================\n";
    cout << "Pointer manipulation with arrays\n";
    cout << "====================================\n";
    cout << "Enter 5 integers: \n";

    for (int i = 0; i < SIZE; i++) {
        cin >> nums[i];
    }

    cout << "\n";

    cout << "Original array: \n";

    for (int i = 0; i < SIZE; i++) {
        cout << nums[i] << " ";
    }

    cout << "\n\n";

    for (int i = 0; i < SIZE; i++) {
        increment(&nums[i]);
    }

    cout << "Array after incrementing each element by 1: \n";
    for (int i = 0; i < SIZE; i++) {
        cout << nums[i] << " ";
    }

    cout << "\n\n";

    for (int i = 0; i < SIZE / 2; i++) {
        swap_values(&nums[i], &nums[SIZE -1 - i]);
    }

    cout << "Array after swapping elements: \n";
    for (int i = 0; i < SIZE; i++) {
        cout << nums[i] << " ";
    }
    
    cout << "\n====================================\n";
    return 0;
}

void increment(int* p){
    (*p)++;
}

void swap_values(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}