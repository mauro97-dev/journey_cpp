#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_PRODUCTS = 5;

struct Product {
    string name;
    int stock;
    double price;
};

// Function declarations
void show_inventory(const Product inventory[]);
float make_sale(int index, int quantity, Product inventory[]);
void restock_product(int index, int quantity, Product inventory[]);
void apply_discount(Product& product, float discount_percentage);

int main() {
    
    Product inventory[NUM_PRODUCTS] = {
        {"Apple", 50, 0.50},
        {"Banana", 30, 0.30},
        {"Orange", 20, 0.80},
        {"Grapes", 15, 2.00},
        {"Mango", 10, 1.50}
    };
    
    float daily_sales = 0.0;
    int option;
    
    do {
        cout << "=== STORE INVENTORY MANAGEMENT SYSTEM ===\n";
        cout << "1. View full inventory\n";
        cout << "2. Sell a product\n";
        cout << "3. Restock a product\n";
        cout << "4. View total sales of the day\n";
        cout << "5. Apply discount to a product\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                show_inventory(inventory);
                break;
                
            case 2: {
                show_inventory(inventory);
                int index, quantity;
                cout << "Enter product number (0-4): ";
                cin >> index;
                cout << "Enter quantity to sell: ";
                cin >> quantity;

                float amount = make_sale(index, quantity, inventory);
                daily_sales += amount;
                break;
            }
                
            case 3: {
                show_inventory(inventory);
                int index, quantity;
                cout << "Enter product number to restock (0-4): ";
                cin >> index;
                cout << "Enter quantity to add: ";
                cin >> quantity;
                
                restock_product(index, quantity, inventory);
                break;
            }
                
            case 4:
                cout << fixed << setprecision(2);
                cout << "\nTotal sales accumulated today: $" << daily_sales << "\n\n";
                break;
                
            case 5: {
                int index;
                float discount;
                cout << "Enter product number to apply discount (0-4): ";
                cin >> index;
                cout << "Enter discount percentage: ";
                cin >> discount;
                    
                if (index >= 0 && index < NUM_PRODUCTS) {
                    apply_discount(inventory[index], discount);
                } else {
                    cout << "Error: Product does not exist. Must be between 0 and 4.\n\n";
                }
                break;
            }
                
            case 6:
                cout << "Goodbye! Thanks for using the system.\n";
                break;

            default:
                cout << "Invalid option. Please choose between 1 and 5.\n\n";
        }
        
    } while (option != 6);
    
    return 0;
}

void show_inventory(const Product inventory[]) {
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
             << setw(15) << inventory[i].name
             << setw(12) << "$" << fixed << setprecision(2) << inventory[i].price
             << setw(8)  << inventory[i].stock << "\n";
    }
    cout << "------------------------------------------------\n\n";
}

float make_sale(int index, int quantity, Product inventory[]) {
    if (index < 0 || index >= NUM_PRODUCTS) {
        cout << "Error: Product does not exist. Must be between 0 and 4.\n\n";
        return 0.0;
    }
    
    if (quantity > inventory[index].stock) {
        cout << "Error: Not enough stock of " << inventory[index].name
             << ". Only " << inventory[index].stock << " units available.\n\n";
        return 0.0;
    }
    
    if (quantity <= 0) {
        cout << "Error: Quantity must be greater than 0.\n\n";
        return 0.0;
    }
    
    inventory[index].stock -= quantity;
    float total = quantity * inventory[index].price;
    
    cout << fixed << setprecision(2);
    cout << "Sale completed!\n";
    cout << quantity << " x " << inventory[index].name << " = $" << total << "\n\n";
    
    return total;
}

void restock_product(int index, int quantity, Product inventory[]) {
    if (index < 0 || index >= NUM_PRODUCTS) {
        cout << "Error: Product does not exist. Must be between 0 and 4.\n\n";
        return;
    }
    
    if (quantity <= 0) {
        cout << "Error: Quantity to restock must be greater than 0.\n\n";
        return;
    }
    
    inventory[index].stock += quantity;
    cout << "Restock successful: +" << quantity 
         << " units of " << inventory[index].name << ".\n";
    cout << "Current stock: " << inventory[index].stock << "\n\n";
}

void apply_discount(Product& product, float discount_percentage) {
    if (discount_percentage < 0 || discount_percentage > 100) {
        cout << "Error: Discount percentage must be between 0 and 100.\n";
        return;
    }
    
    float discount_amount = product.price * (discount_percentage / 100.0);
    product.price -= discount_amount;
    
    cout << fixed << setprecision(2);
    cout << "Discount applied: " << discount_percentage << "% off on " 
         << product.name << ". New price: $" << product.price << "\n";
}