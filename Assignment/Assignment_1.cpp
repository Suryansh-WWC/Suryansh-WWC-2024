#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Class to represent an inventory item
class Item {
public:
    string itemID;
    string name;
    string category;
    int quantity;
    int reorderLevel;

    Item(string id, string n, string cat, int qty, int reorder)
        : itemID(id), name(n), category(cat), quantity(qty), reorderLevel(reorder) {}

    void display() {
        cout << "ID: " << itemID << ", Name: " << name
             << ", Category: " << category << ", Quantity: " << quantity
             << ", Reorder Level: " << reorderLevel << endl;
    }

    bool needsReorder() {
        return quantity < reorderLevel;
    }
};

// Class to manage the inventory
class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const Item& item) {
        items.push_back(item);
        cout << "Item added successfully!" << endl;
    }

    void updateStock(const string& id, int newQuantity) {
        for (auto& item : items) {
            if (item.itemID == id) {
                item.quantity = newQuantity;
                cout << "Stock updated for item: " << id << endl;
                return;
            }
        }
        cout << "Item ID not found!" << endl;
    }

    void viewInventory() {
        cout << "\nCurrent Inventory:" << endl;
        for (const auto& item : items) {
            item.display();
            if (item.needsReorder()) {
                cout << "  --> Alert: Stock below reorder level!" << endl;
            }
        }
    }

    void searchByNameOrCategory(const string& searchQuery) {
        bool found = false;
        for (const auto& item : items) {
            if (item.name == searchQuery || item.category == searchQuery) {
                item.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No items found matching: " << searchQuery << endl;
        }
    }

    void exportToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& item : items) {
                file << item.itemID << "," << item.name << ","
                     << item.category << "," << item.quantity << ","
                     << item.reorderLevel << endl;
            }
            file.close();
            cout << "Inventory exported to " << filename << endl;
        } else {
            cout << "Failed to open file for writing!" << endl;
        }
    }
};

// Main function with menu
int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\nWarehouse Inventory Management System" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Update Stock" << endl;
        cout << "3. View Inventory" << endl;
        cout << "4. Search Item by Name/Category" << endl;
        cout << "5. Export Inventory to File" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string id, name, category;
                int quantity, reorder;
                cout << "Enter Item ID: ";
                cin >> id;
                cout << "Enter Item Name: ";
                cin >> name;
                cout << "Enter Category: ";
                cin >> category;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Reorder Level: ";
                cin >> reorder;
                Item newItem(id, name, category, quantity, reorder);
                inventory.addItem(newItem);
                break;
            }
            case 2: {
                string id;
                int newQuantity;
                cout << "Enter Item ID: ";
                cin >> id;
                cout << "Enter New Quantity: ";
                cin >> newQuantity;
                inventory.updateStock(id, newQuantity);
                break;
            }
            case 3:
                inventory.viewInventory();
                break;
            case 4: {
                string query;
                cout << "Enter Name or Category to Search: ";
                cin >> query;
                inventory.searchByNameOrCategory(query);
                break;
            }
            case 5: {
                string filename;
                cout << "Enter filename to export: ";
                cin >> filename;
                inventory.exportToFile(filename);
                break;
            }
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    } while (choice != 6);

    return 0;
}
