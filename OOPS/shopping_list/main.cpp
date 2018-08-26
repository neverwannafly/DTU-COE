#include "shoppingList.hpp"

int main() {

    initSeed();

    ShoppingList list[2];
    list[0].addItem(10, 150);
    list[0].addItem(2, 90);
    list[0].addItem(1, 70);
    list[0].addItem(7, 50);
    std::cout << list[0].getAllItemsCount() << " " << list[1].getAllItemsCount() << "\n";
    list[0].showList();

    list[1].addItem(4, 150);
    list[1].addItem(7, 100);
    list[1].addItem(9, 170);
    list[1].addItem(15, 250);
    std::cout << list[0].getAllItemsCount() << " " << list[1].getAllItemsCount() << "\n";
    list[1].showList();

    return 0;
}