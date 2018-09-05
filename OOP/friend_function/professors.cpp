#include <iostream>
#include <vector>
#include <cstdlib>
#define MAX_DEV 999999
#define MIN_DEV 100000

void initSeed() {
    srand((int)time(0));
}

class DataRow;
class AssistantProfessor;
class AssociativeProfessor;
class Professor;

class DataNode {
    friend class DataRow;
    friend std::ostream &operator <<(std::ostream &stream, const DataRow &row);
    friend void maximumPublishesByYear(AssistantProfessor ap, AssociativeProfessor assp, Professor p);
public:
    DataNode(int booksPublished, int publishedBy) {
        this->booksPublished = booksPublished;
        this->publishedBy = publishedBy;
    }
private:
    int booksPublished;
    int publishedBy;
};

class DataRow {
public:
    DataRow() {};
    void addRecord(int publicationYear, int booksPublished, int publishedBy) {
        if (publicationYear<2000 && publicationYear>2018) {
            return;
        }
        if (this->records[publicationYear+1] == nullptr) {
            DataNode *node = new DataNode(booksPublished, publishedBy);
            records[publicationYear+1] = node;
        }
        else {
            this->records[publicationYear+1]->booksPublished += booksPublished;
        }
    }
    friend std::ostream &operator <<(std::ostream &stream, const DataRow &row);
    friend void maximumPublishesByYear(AssistantProfessor ap, AssociativeProfessor assp, Professor p);
    std::vector<DataNode *> returnRecords() {
        return this->records;
    }
private:
    std::vector<DataNode *> records = std::vector<DataNode *>(3000, nullptr);
};

std::ostream &operator <<(std::ostream &stream, const DataRow &row) {
    for (int i=2000; i <= 2018; i++) {
        if (row.records[i] != nullptr) {
            stream << "|| Year : " << i << " | Publishes: " << row.records[i]->booksPublished << " ";
        }
    }
    return stream;
}

class BaseProfessor {
public:
    BaseProfessor(std::string name);
    friend void maximumPublishesByYear(AssistantProfessor ap, AssociativeProfessor assp, Professor p);
    void displayData();
    void addRecord(int publicationYear, int booksPublished) {
        this->publicationData.addRecord(publicationYear, booksPublished, this->uuid);
    }
protected:
    std::string label;
    std::string name;
    DataRow publicationData;
    int uuid;
};

BaseProfessor::BaseProfessor(std::string name) {
    this->name = name;
    this->label = "base";
    this->uuid = rand()%((MAX_DEV - MIN_DEV) + 1) + MIN_DEV;
}

void BaseProfessor::displayData() {
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "name: " << this->name << "\n";
    std::cout << "label: " << this->label << "\n";
    std::cout << "uuid: " << this->uuid << "\n";
    std::cout << "publicationData: " << this->publicationData << "\n";
    std::cout << "----------------------------------------------------------------\n";
}

class Professor: public BaseProfessor {
public:
    Professor(std::string name) : BaseProfessor(name) {
        this->label = "professor";
    };
};

class AssistantProfessor: public BaseProfessor {
public:
    AssistantProfessor(std::string name) : BaseProfessor(name) {
        this->label = "assistant professor";
    };
};

class AssociativeProfessor: public BaseProfessor {
public:
    AssociativeProfessor(std::string name) : BaseProfessor(name) {
        this->label = "associative professor";
    };
};

void maximumPublishesByYear(AssistantProfessor ap, AssociativeProfessor assp, Professor p) {
    BaseProfessor *max = nullptr;
    for (int i=2000; i<=2018; i++) {
        max = nullptr;
        int maxPublish = 0;
        if (ap.publicationData.returnRecords()[i] != nullptr) {
            if (ap.publicationData.returnRecords()[i]->booksPublished > maxPublish) {
                maxPublish = ap.publicationData.returnRecords()[i]->booksPublished;
                max = &ap;
            }
        }
        if (assp.publicationData.returnRecords()[i] != nullptr) {
            if (assp.publicationData.returnRecords()[i]->booksPublished > maxPublish) {
                maxPublish = assp.publicationData.returnRecords()[i]->booksPublished;
                max = &assp;
            }
        }
        if (p.publicationData.returnRecords()[i] != nullptr) {
            if (p.publicationData.returnRecords()[i]->booksPublished > maxPublish) {
                maxPublish = p.publicationData.returnRecords()[i]->booksPublished;
                max = &p;
            }
        }

        if (max != nullptr) {
            max->displayData();
        }
    }
}

int main() {

    initSeed();
    Professor p("shubham");

    p.addRecord(2013, 56);
    p.displayData();

    AssociativeProfessor assp("shivang");
    assp.addRecord(2015, 35);
    assp.addRecord(2015, 45);
    assp.addRecord(2012, 20);

    assp.displayData();

    AssistantProfessor ap("vibhor");
    ap.addRecord(2012, 800);
    ap.displayData();

    maximumPublishesByYear(ap, assp, p);

    return 0;
}