#include <iostream>

struct Student {
	// Member functions
	int age;
	std::string name;
	float *marks;

	// Member Functions
	void init(std::string name, int age, float *marks) {
		this->age = age;
		this->name = name;
		this->marks = marks;
	}

	void profile() {
		std::cout << "-------------------------------------------\n";
		std::cout << "Name: " << this->name << "\n";
		std::cout << "Age: " << this->age << "\n";
		std::cout << "Grade: " << this->getGrade() << "\n";
		std::cout << "--------------------------------------------\n";
	}
	
	int normalise(int expression) {
		if (expression>6) {
			return 6;
		}
		return expression;
	}  

	char getGrade() {
		float total = 0;
		for (int i=0; i<5; i++) {
			total += this->marks[i];
		}
		char grades[] = {'O', 'A', 'B', 'C', 'D', 'E', 'F'};
		int gpa = (int)total/50;
		return grades[this->normalise(10-gpa)];
	}
};	

int main() {
	
	int num, total;

	std::cout << "No. of students to Enter: ";
	std::cin >> num;
	total = num;

	Student *students[num];

	while (num) {
		Student *student = new Student;
		int age;
		float marks[5];
		std::string name;
		std::cout << "Enter Student Name: ";
		std::cin >> name;
		std::cout << "Enter Student Age: ";
		std::cin >> age;
		std::cout << "Enter your marks->\n";
		for (int i=0; i<5; i++) {
			std::cin >> marks[i];
		}
		student->init(name, age, marks);
		students[total-num] = student;
		num--;
	}

	students[0]->profile();

	return 0;
}
