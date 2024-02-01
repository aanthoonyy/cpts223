#include "redBlackTree2.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

int main(void){

    fstream inventory("inventory.csv");
    string grab;
    string grab2;
    string grab3;
    RBTree<inventoryRecord> tree;


    while (!inventory.eof()){
    getline(inventory, grab, ',');
    getline(inventory, grab2, ',');
    getline(inventory, grab3, '\n');
        if (grab != "" && grab2 != "")
        {
            inventoryRecord data(stoi(grab), grab2, stoi(grab3));
            tree.insert(data);
        }
    }

    int choice;
    cout << "Please select an option from the menu:\n";
    cout << "1. Option 1\n";
    cout << "2. Option 2\n";
    cout << "3. Option 3\n";
    cout << "4. Option 4\n";
    cout << "5. Option 5\n";
    cin >> choice;
    string type;
    vector<inventoryRecord> vec;
    switch (choice) {
        case 1:
            cout << "insert a ID, Type, and Quantity" << endl;
            cout << "ID: " << endl;
            int id;
            cin >> id;
            cout << "Type: " << endl;
            
            cin >> type;
            cout << "Quantity: " << endl;
            int quantity;
            cin >> quantity;
            inventory << to_string(id) << "," <<type << "," << to_string(quantity) << "\n";
            break;
        case 2:
        // updating invetory
        tree.clear();
        // insert into tree

        while (!inventory.eof()){
        getline(inventory, grab, ',');
        getline(inventory, grab2, ',');
        getline(inventory, grab3, '\n');
        if (grab != "" && grab2 != "")
        {
            inventoryRecord data(stoi(grab), grab2, stoi(grab3));
            tree.insert(data);
        }
        }

        break;
        case 3:
        //dispaly invitory, sorted by ID
        
        while (!inventory.eof()){
        getline(inventory, grab, ',');
        getline(inventory, grab2, ',');
        getline(inventory, grab3, '\n');
        if (grab != "" && grab2 != "")
        {
            inventoryRecord data(stoi(grab), grab2, stoi(grab3));
            vec.push_back(data);
        }
        
        }
        break;
        case 4:
            // Code for Option 4
            tree.printTree();
            break;
        case 5:
            // I should call the destructor
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }


    return 0;
}