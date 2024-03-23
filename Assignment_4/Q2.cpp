#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Subject {
    string name;
    int marks;
};

struct Student {
    string name;
    int rollNumber;
    vector<Subject> subjects;
};

class MarksDatabase {
private:
    vector<Student> students;

public:
    void addStudent(Student student) {
        students.push_back(student);
    }

    void updateMarks(int rollNumber, string subjectName, int newMarks) {
        for (auto& student : students) {
            if (student.rollNumber == rollNumber) {
                for (auto& subject : student.subjects) {
                    if (subject.name == subjectName) {
                        subject.marks = newMarks;
                        cout << "Marks updated successfully!" << endl;
                        return;
                    }
                }
                cout << "Subject not found for the given student!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void displayStudentInfo() {
        cout << "Student Information:" << endl;
        for (const auto& student : students) {
            cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber << endl;
        }
    }

    void displayMarks() {
        cout << "Marks of the students:" << endl;
        for (const auto& student : students) {
            cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber << endl;
            for (const auto& subject : student.subjects) {
                cout << subject.name << ": " << subject.marks << endl;
            }
            cout << endl;
        }
    }

    void sortAndDisplayByTotalMarks() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            int totalMarksA = 0, totalMarksB = 0;
            for (const auto& subject : a.subjects) {
                totalMarksA += subject.marks;
            }
            for (const auto& subject : b.subjects) {
                totalMarksB += subject.marks;
            }
            return totalMarksA > totalMarksB;
        });

        cout << "Students sorted by total marks:" << endl;
        for (const auto& student : students) {
            cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber << ", Total Marks: ";
            int totalMarks = 0;
            for (const auto& subject : student.subjects) {
                totalMarks += subject.marks;
            }
            cout << totalMarks << endl;
        }
    }
};

int main() {
    MarksDatabase database;

    Student student1 {"John", 101, {{"Maths", 80}, {"Physics", 75}, {"Chemistry", 85}, {"Biology", 90}, {"English", 95}}};
    Student student2 {"Alice", 102, {{"Maths", 85}, {"Physics", 90}, {"Chemistry", 88}, {"Biology", 92}, {"English", 80}}};
    Student student3 {"Bob", 103, {{"Maths", 70}, {"Physics", 65}, {"Chemistry", 75}, {"Biology", 80}, {"English", 85}}};

    database.addStudent(student1);
    database.addStudent(student2);
    database.addStudent(student3);

    database.updateMarks(101, "Maths", 85);
    database.updateMarks(103, "Physics", 70);

    database.displayStudentInfo();
    cout << endl;
    database.displayMarks();
    cout << endl;

    database.sortAndDisplayByTotalMarks();

    return 0;
}
