#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For find_if

using namespace std;

// Define the Item structure
struct Item {
    string name;
    int quantity;
    double price;
};

// Function to add an item to the inventory
void addItem(vector<Item>& inventory) {
    Item newItem;
    cout << "Enter item name: ";
    cin >> newItem.name;
    cout << "Enter item quantity: ";
    while (!(cin >> newItem.quantity) || newItem.quantity < 0) {
        cout << "Invalid input. Enter a positive integer for quantity: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter item price: ";
    while (!(cin >> newItem.price) || newItem.price < 0) {
        cout << "Invalid input. Enter a positive number for price: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    inventory.push_back(newItem);
    cout << "Item added successfully!\n";
}

// Function to display the inventory
void displayInventory(const vector<Item>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }
    cout << "\nInventory:\n";
    cout << "Name\t\tQuantity\tPrice\n";
    cout << "----------------------------------------\n";
    for (const auto& item : inventory) {
        cout << item.name << "\t\t" << item.quantity << "\t\t" << item.price << "\n";
    }
}

// Function to remove an item from the inventory
void removeItem(vector<Item>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty. No items to remove.\n";
        return;
    }

    string itemName;
    cout << "Enter the name of the item to remove: ";
    cin >> itemName;
    
    auto it = find_if(inventory.begin(), inventory.end(), [&itemName](const Item& item) {
        return equal(itemName.begin(), itemName.end(), item.name.begin(), item.name.end(), 
                     [](char a, char b) { return tolower(a) == tolower(b); });
    });
    
    if (it != inventory.end()) {
        inventory.erase(it);
        cout << "Item removed successfully!\n";
    } else {
        cout << "Item not found!\n";
    }
}

int main() {
    vector<Item> inventory;
    int choice;

    do {
        cout << "\nInventory System Menu\n";
        cout << "1. Add Item\n";
        cout << "2. Display Inventory\n";
        cout << "3. Remove Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                addItem(inventory);
                break;
            case 2:
                displayInventory(inventory);
                break;
            case 3:
                removeItem(inventory);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                // This case will never be reached due to input validation
                break;
        }
    } while (choice != 4);

    return 0;
}
