#include "shoppingList.hpp"

int main() {

    initSeed();

    ShoppingList list[2];
    std::cout << "List 1\n";
    list[0].addItem(10, 150);
    list[0].addItem(2, 690);
    list[0].addItem(1, 370);
    list[0].addItem(7, 500);
    list[0].showList();
    std::cout << "Total Items in all lists : " << list[0].getAllItemsCount() << "\n\n";

    std::cout << "List 2\n";
    list[1].addItem(4, 150);
    list[1].addItem(7, 100);
    list[1].addItem(9, 170);
    list[1].addItem(15, 250);
    list[1].addItem(7, 100);
    list[1].addItem(6, 800);
    list[1].showList();
    std::cout << "Total Items in all lists : " << list[0].getAllItemsCount() << "\n";

    return 0;
}