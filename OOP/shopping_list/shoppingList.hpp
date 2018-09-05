#ifndef shoppingList_HPP
#define shoppingList_HPP

// Item class

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#define MAX_DEV 999999
#define MIN_DEV 100000

void initSeed() {
    srand((int)time(0));
}

class Item {
public:
    Item(int quantity, int price);
    void printItem(int sno) const;
    int getTotal() const;
    int getId() const;
private:
    int uuid;
    int quantity;
    int price;
};

Item::Item(int quantity, int price) {
    this->uuid = rand()%((MAX_DEV - MIN_DEV) + 1) + MIN_DEV;
    this->quantity = quantity;
    this->price = price;
}

void Item::printItem(int sno) const {
    std::cout << "|" << std::setw(4) << sno << "  |  " << std::setw(7) << this->getId() << "  |  "  << std::setw(5) << this->getTotal() << "  |\n";
}

int Item::getId() const {
    return this->uuid;
}

int Item::getTotal() const {
    return this->price * this->quantity;
}

// List class that holds multiple items

class ShoppingList {
public:
    ShoppingList();
    void showList() const;
    int returnTotal() const;
    void addItem(int quantity, int price);
    void deleteItem(int uuid);
    static int getAllItemsCount() {
        return allItemsCount;
    }
private:
    static int allItemsCount;
    static void incrementCount() {
        allItemsCount += 1;
    }
    std::vector<Item> items;
};

ShoppingList::ShoppingList() {}

int ShoppingList::allItemsCount = 0;

void ShoppingList::showList() const {
    std::cout << "______________________________\n";
    std::cout << std::setw(5) << "|  SNO" << " |  " << std::setw(7) << "UUID" << "  |  " << std::setw(5) << "TOTAL" << "  |\n";
    std::cout << "|______|___________|_________|\n";
    for (int i=0; i<this->items.size(); i++) {
        items[i].printItem(i+1); 
    }
    std::cout << "|______|___________|_________|\n";
    std::cout << "|  TOTAL : " << std::setw(16) << this->returnTotal() << "  |\n";
    std::cout << "|____________________________|\n";
}

int ShoppingList::returnTotal() const {
    int total = 0;
    for (int i=0; i<this->items.size(); i++) {
        total += items[i].getTotal();
    }
    return total;
}

void ShoppingList::addItem(int quantity, int price) {
    Item newItem = Item(quantity, price);
    this->items.push_back(newItem);
    ShoppingList::incrementCount();
}

void ShoppingList::deleteItem(int uuid) {
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        if (it->getId() == uuid) {
            this->items.erase(it);
            break;
        }
    }
}

#endif