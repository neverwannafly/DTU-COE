#include <iostream>
#include <iomanip>
#include <vector>
#define MAX_DEV 999999
#define MIN_DEV 100000

void initSeed() {
    srand((int)time(0));
}

class Employee {
public:

    class Profile {
    public:
        Profile() {};
        void addHobby(std::string hobby) {
            hobbies.push_back(hobby);
        };
        void addLanguage(std::string language) {
            languages.push_back(language);
        };
        void displayProfile() const;
    private:
        std::vector<std::string> hobbies;
        std::vector<std::string> languages;
    };

    Employee(): name(""), workingHour(0), ratePerHour(0) {
        this->uuid = rand()%((MAX_DEV - MIN_DEV) + 1) + MIN_DEV;
    };
    Employee(std::string name, int workingHour, int ratePerHour): name(name), workingHour(workingHour), ratePerHour(ratePerHour) {
        this->uuid = rand()%((MAX_DEV - MIN_DEV) + 1) + MIN_DEV;
    };
    int grossIncome() const;
    void display() const;
    void addHobby(std::string hobby);
    void addLanguage(std::string language);
private:
    std::string name;
    Profile employeeProfile;
    int workingHour;
    int ratePerHour;
    int uuid;
};

void Employee::Profile::displayProfile() const {
    std::cout << "| Employee Profile -> " << std::setw(40) << "|\n";
    std::cout << "| Languages: ";
    for (std::string language: this->languages) {
        std::cout << language << ", ";
    } 
    std::cout << std::setw(30);
    std::cout << "|\n| Hobbies: ";
    for (std::string hobby: this->hobbies) {
        std::cout << hobby << ", ";
    } 
    std::cout << std::setw(17);
    
    std::cout << "|\n";
}

int Employee::grossIncome() const {
    return this->ratePerHour * this->workingHour;
}

void Employee::addLanguage(std::string language) {
    this->employeeProfile.addLanguage(language);
}

void Employee::addHobby(std::string hobby) {
    this->employeeProfile.addHobby(hobby);
}

void Employee::display() const {
    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "| Uuid: " << std::setw(52) << this->uuid << std::setw(2) << "|\n";
    std::cout << "| Name: " << std::setw(52) << this->name << std::setw(2) << "|\n";
    std::cout << "| Gross: " << std::setw(51) << this->grossIncome() << std::setw(1) << "|\n";
    std::cout << "|-----------------------------------------------------------|\n";
    this->employeeProfile.displayProfile();
    std::cout << "|-----------------------------------------------------------|\n";
}

int main() {

    Employee rakesh("rakesh", 30, 1500);
    Employee vibhor("vibhor", 50, 1700);

    rakesh.addHobby("Cricket");
    rakesh.addHobby("Badminton");
    rakesh.addHobby("Chess");
    vibhor.addHobby("Cricket");
    vibhor.addHobby("Badminton");
    vibhor.addHobby("Swimming");
    vibhor.addHobby("Talking");

    rakesh.addLanguage("C++");
    rakesh.addLanguage("Swift");
    rakesh.addLanguage("Python");
    rakesh.addLanguage("JS");
    vibhor.addLanguage("Java");
    vibhor.addLanguage("C++");
    vibhor.addLanguage("JS");
    vibhor.addLanguage("Kotlin");

    rakesh.display();
    vibhor.display();

    return 0;
}