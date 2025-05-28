#include "OrderList.h"
#include <iostream>
#include <string>

using namespace std;

void showMenu();

int main() {
    OrderList orders;
    string ch;
    while (true) {
        showMenu();
        getline(cin, ch);
        if (ch == "0") break;
        else if (ch == "1") orders.addOrder();
        else if (ch == "2") orders.displayOrders();
        else if (ch == "3") orders.deleteOrder();
        else if (ch == "4") orders.updateOrder();
        else if (ch == "5") orders.searchOrderById();
        else if (ch == "6") orders.sortOrdersByTime();
        else cout << "Invalid.\n";
    }
    return 0;
}
