#include<bits/stdc++.h>
using namespace std;


// D Dependency Inversion Principle

// Class should depend on interfaces rather than concrete classes.



// Abstraction
class Database {
public:
    virtual void saveData(string data) = 0;
    virtual ~Database() {}
};

// Low-level implementation: MySQL
class MySQLDatabase : public Database {
public:
    void saveData(string data) override {
        cout << "Saving '" << data << "' to MySQL Database\n";
    }
};

// Low-level implementation: File
class FileDatabase : public Database {
public:
    void saveData(string data) override {
        cout << "Saving '" << data << "' to File\n";
    }
};

// High-level module: Report
class Report {
    Database* db;   // depends on abstraction, not on details

public:
    Report(Database* db) : db(db) {}

    void save(string content) {
        db->saveData(content);   // works with any Database implementation
    }
};

int main() {
    MySQLDatabase mysql;
    FileDatabase file;

    Report report1(&mysql);
    report1.save("Annual Report");

    Report report2(&file);
    report2.save("Financial Report");

    return 0;
}
