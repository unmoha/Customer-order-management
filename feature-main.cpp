#include <iostream>
#include "OrderUI.cpp"

using namespace std;

void showMainMenu() {
    cout << "\n=== Selam Restaurant ===\n"
         << "1. Add Order\n2. Display Orders\n3. Delete Order\n"
         << "4. Sort by Time\n0. Exit\nChoose: ";
}

int main() {
    OrderService orders;
    string choice;

    while (true) {
        showMainMenu();
        getline(cin, choice);

        if (choice == "0") break;
        else if (choice == "1") {
            displayMenu(orders.getRepo());
            string name, input;
            int menuNum, qty;
            double payment;

            cout << "Customer Name: "; getline(cin, name);
            cout << "Menu Number: "; getline(cin, input); menuNum = stoi(input);
            cout << "Quantity: "; getline(cin, input); qty = stoi(input);
            cout << "Payment: "; getline(cin, input); payment = stod(input);

            try {
                orders.addOrder(name, menuNum, qty, payment);
                cout << "Order added.\n";
            } catch (const exception& e) {
                cout << "Error: " << e.what() << "\n";
            }

        } else if (choice == "2") {
            showOrders(orders.getHead());
        } else if (choice == "3") {
            cout << "Enter Order ID to delete: ";
            string input; getline(cin, input);
            try {
                orders.deleteOrder(stoi(input));
                cout << "Deleted.\n";
            } catch (...) {
                cout << "Error deleting.\n";
            }
        } else if (choice == "4") {
            auto sorted = orders.getSortedOrdersByTime();
            for (Order* tmp : sorted) {
                cout << tmp->id << " - " << tmp->customer << " - " << tmp->orderTime << "\n";
            }
        } else {
            cout << "Invalid.\n";
        }
    }

    return 0;
}
