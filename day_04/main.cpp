#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_PRODUCTS = 5;

// Function declarations
void show_inventory(const string products[], const int stock[], const float prices[]);
float make_sale(int index, int quantity, int stock[], const float prices[], const string products[]);
void restock_product(int index, int quantity, int stock[], const string products[]);

int main() {
    string products[NUM_PRODUCTS] = {"Apples", "Bread", "Milk", "Eggs", "Rice"};
    int stock[NUM_PRODUCTS] = {10, 20, 15, 30, 8};
    float prices[NUM_PRODUCTS] = {0.50, 1.20, 1.80, 0.30, 2.50};
    
    float daily_sales = 0.0;
    int option;
    
    do {
        cout << "=== STORE INVENTORY MANAGEMENT SYSTEM ===\n";
        cout << "1. View full inventory\n";
        cout << "2. Sell a product\n";
        cout << "3. Restock a product\n";
        cout << "4. View total sales of the day\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                show_inventory(products, stock, prices);
                break;
                
            case 2: {
                show_inventory(products, stock, prices);
                int index, quantity;
                cout << "Enter product number (0-4): ";
                cin >> index;
                cout << "Enter quantity to sell: ";
                cin >> quantity;
                
                float amount = make_sale(index, quantity, stock, prices, products);
                daily_sales += amount;
                break;
            }
                
            case 3: {
                show_inventory(products, stock, prices);
                int index, quantity;
                cout << "Enter product number to restock (0-4): ";
                cin >> index;
                cout << "Enter quantity to add: ";
                cin >> quantity;
                
                restock_product(index, quantity, stock, products);
                break;
            }
                
            case 4:
                cout << fixed << setprecision(2);
                cout << "\nTotal sales accumulated today: $" << daily_sales << "\n\n";
                break;
                
            case 5:
                cout << "Goodbye! Thanks for using the system.\n";
                break;
                
            default:
                cout << "Invalid option. Please choose between 1 and 5.\n\n";
        }
        
    } while (option != 5);
    
    return 0;
}

void show_inventory(const string products[], const int stock[], const float prices[]) {
    cout << "\n=== CURRENT INVENTORY ===\n";
    cout << left
         << setw(8)  << "Index"
         << setw(15) << "Product"
         << setw(12) << "Price"
         << setw(8)  << "Stock" << "\n";
    cout << "------------------------------------------------\n";
    
    cout << fixed << setprecision(2);
    
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        cout << left
             << setw(8)  << i
             << setw(15) << products[i]
             << setw(12) << ("$" + to_string(prices[i]))
             << setw(8)  << stock[i] << "\n";
    }
    cout << "------------------------------------------------\n\n";
}

float make_sale(int index, int quantity, int stock[], const float prices[], const string products[]) {
    if (index < 0 || index >= NUM_PRODUCTS) {
        cout << "Error: Product does not exist. Must be between 0 and 4.\n\n";
        return 0.0;
    }
    
    if (quantity > stock[index]) {
        cout << "Error: Not enough stock of " << products[index]
             << ". Only " << stock[index] << " units available.\n\n";
        return 0.0;
    }
    
    if (quantity <= 0) {
        cout << "Error: Quantity must be greater than 0.\n\n";
        return 0.0;
    }
    
    stock[index] -= quantity;
    float total = quantity * prices[index];
    
    cout << fixed << setprecision(2);
    cout << "Sale completed!\n";
    cout << quantity << " x " << products[index] << " = $" << total << "\n\n";
    
    return total;
}

void restock_product(int index, int quantity, int stock[], const string products[]) {
    if (index < 0 || index >= NUM_PRODUCTS) {
        cout << "Error: Product does not exist. Must be between 0 and 4.\n\n";
        return;
    }
    
    if (quantity <= 0) {
        cout << "Error: Quantity to restock must be greater than 0.\n\n";
        return;
    }
    
    stock[index] += quantity;
    cout << "Restock successful: +" << quantity 
         << " units of " << products[index] << ".\n";
    cout << "Current stock: " << stock[index] << "\n\n";
}