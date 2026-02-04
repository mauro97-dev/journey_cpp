#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;

    Product(const string& n, double p, int q) : name(n), price(p), quantity(q) {

    }
};

void display_product(const Product& product);
double calculate_total_price(const Product& product);
void display_inventory(const vector<Product>& inventory);
void show_inventory(const vector<Product>& inventory);
void add_product(vector<Product>& inventory, const Product& product);
void remove_product(vector<Product>& inventory, const string& product_name);
void sell_product(vector<Product>&  inventory, const string& product_name, int quantity);
void search_product(const vector<Product>& inventory, const string& product_name);
void update_product_price(vector<Product>& inventory, const string& product_name, double new_price);
void update_product_quantity(vector<Product>& inventory, const string& product_name, int new_quantity);
void sort_inventory_by_name(vector<Product>& inventory);
void sort_inventory_by_price(vector<Product>& inventory);
void sort_inventory_by_quantity(vector<Product>& inventory);

int main() {

    vector<Product> inventory;

    return 0;
}

void display_product(const Product& product){
    cout << "Product Name: " << product.name << "\n"
    << "Price: $" << product.price << "\n"
    << "Quantity: " << product.quantity << "\n";
}

void display_inventory(const vector<Product>& inventory) {
    if (inventory.empty()) {
        cout << "Error. Inventory is empty.\n";
        return;
    }

    for(const auto& product: inventory) {
        display_product(product);
        cout << "------------------------------\n";
    }
}

void add_product(vector<Product>& inventory, const Product& product) {
    inventory.push_back(product);
    cout << "Product " << product.name << " added to inventory.\n";

}

void search_product(const vector<Product>& inventory, const string& product_name) {
    bool product_found = false;
    for(const auto& product : inventory) {
        if (product.name == product_name) {
            cout << "Product found: \n";
            display_product(product);
            product_found = true;
            break;
        }
    }

    if (!product_found) {
        cout << "Product " << product_name << " not found in inventory.\n";
    }
}

void show_inventory(const vector<Product>& inventory) {
    display_inventory(inventory);
}

void remove_product(vector<Product>& inventory, const string& product_name) {
    for(auto& product : inventory) {
        if (product.name == product_name) {
            product.quantity = 0;
            cout << "Product " << product_name << " marked as removed (quantity set to 0).\n";
            return;
        }
    }

    cout << "Product " << product_name << " not found in inventory.\n";
}

double calculate_total_price(const Product& product) {
    return product.price * product.quantity;
}

void sell_product(vector<Product>& inventory, const string& product_name, int quantity) {
    for(auto& product : inventory) {
        if(product.name == product_name) {
            if(product.quantity >= quantity) {
                product.quantity -= quantity;
                cout << "Sold " << quantity << " units of product " << product_name << ".\n";
                return;
            } else {
                cout << "Insufficient quantity for product " << product_name << ".\n";
                return;
            }
        }
    }
    cout << "Product " << product_name << " not found in inventory.\n";
}

void update_product_price(vector<Product>& inventory, const string& product_name, double new_price) {
    for(auto& product : inventory) {
        if(product.name == product_name) {
            product.price = new_price;
            cout << "Updated price of product " << product_name << " to $" << new_price << ".\n";
            return;
        }
    }
    cout << "Product " << product_name << " not found in inventory.\n";
}

void update_product_quantity(vector<Product>& inventory, const string& product_name, int new_quantity) {
    for(auto& product : inventory) {
        if(product.name == product_name) {
            product.quantity = new_quantity;
            cout << "Updated quantity of product " << product_name << " to " << new_quantity << ".\n";
            return;
        }
    }
    cout << "Product " << product_name << " not found in inventory.\n";
}

void sort_inventory_by_name(vector<Product>& inventory) {
    sort(inventory.begin(), inventory.end(), [](const Product& a, const Product& b) {
        return a.name < b.name;
    });
    cout << "Inventory sorted by product name.\n";
}

void sort_inventory_by_price(vector<Product>& inventory) {
    sort(inventory.begin(), inventory.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });
    cout << "Inventory sorted by product price.\n";
}

void sort_inventory_by_quantity(vector<Product>& inventory) {
    sort(inventory.begin(), inventory.end(), [](const Product& a, const Product& b) {
        return a.quantity < b.quantity;
    });
    cout << "Inventory sorted by product quantity.\n";
}