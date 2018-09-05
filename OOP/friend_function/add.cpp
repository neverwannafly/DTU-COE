#include <iostream>
#include <vector>

class __W__;

class __M__ {
public:
    __M__(std::vector<int> values) {
        this->values = values;
    }
    friend int add(__W__ w, __M__ m);
private:
    std::vector<int> values;
};

class __W__ {
public:
    __W__(std::vector<int> values) {
        this->values = values;
    }
    friend int add(__W__ w, __M__ m);
private:
    std::vector<int> values;
};

int add(__W__ w, __M__ m) {
    int sum = 0;
    for (auto it = w.values.begin(); it != w.values.end(); it++) {
        sum += *it;
    }
    for (auto it = m.values.begin(); it != m.values.end(); it++) {
        sum += *it;
    }
    return sum;
}

int main() {

    std::vector<int> valuesW(10, 10);
    std::vector<int> valuesM(20, 10);

    __W__ w(valuesW);
    __M__ m(valuesM);

    std::cout << add(w, m) << "\n";

    return 0;
}