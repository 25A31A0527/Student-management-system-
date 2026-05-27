#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string course;

    void input() {
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Student Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Course Name: ";
        getline(cin, course);
    }

    void display() {
        cout << "\nStudent ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
        cout << "Course Name: " << course << endl;
    }
};

void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    s.input();

    file << s.id << "|" << s.name << "|" << s.age << "|" << s.course << endl;
    file.close();

    cout << "\nStudent record added successfully!\n";
}

void displayStudents() {
    ifstream file("students.txt");
    string line;

    cout << "\n===== Student Records =====\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchStudent() {
    ifstream file("students.txt");
    string line;
    int searchId;
    bool found = false;

    cout << "Enter Student ID to search: ";
    cin >> searchId;

    while (getline(file, line)) {
        int id = stoi(line.substr(0, line.find("|")));

        if (id == searchId) {
            cout << "\nRecord Found:\n";
            cout << line << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent record not found.\n";
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
