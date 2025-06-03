#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Course {
    string course_code;
    string course_name;
};

struct Grade {
    int mark;
    char the_grade;
    bool calculated; // Flag to check if grade is already calculated

 Grade() : mark(0), the_grade('E'), calculated(false) {}
};

struct Student {
    string registration_number;
    string name;
    int age;
    Course course;
    Grade grade;
};

const int MAX_STUDENTS = 40;
Student students[MAX_STUDENTS];
int studentCount = 0;

char calculateGrade(int mark) {
    if (mark > 69) return 'A';
    if (mark > 59) return 'B';
    if (mark > 49) return 'C';
    if (mark > 39) return 'D';
    return 'E';
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Maximum number of students reached (40).\n";
        return;
    }

    Student newStudent;
    
    cout << "Enter registration number: ";
    getline(cin, newStudent.registration_number);
    
    cout << "Enter name: ";
    getline(cin, newStudent.name);
    
    cout << "Enter age: ";
    cin >> newStudent.age;
    cin.ignore(); 
    
    cout << "Enter course code: ";
    getline(cin, newStudent.course.course_code);
    
    cout << "Enter course name: ";
    getline(cin, newStudent.course.course_name);
  
    newStudent.grade.mark = 0;
    newStudent.grade.the_grade = 'E';
    newStudent.grade.calculated = false;
    
    students[studentCount++] = newStudent;
    cout << "Student added successfully.\n";
}

void editStudent() {
    if (studentCount == 0) {
        cout << "No students available to edit.\n";
        return;
    }

    string regNum;
    cout << "Enter registration number of student to edit: ";
    getline(cin, regNum);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].registration_number == regNum) {
            cout << "Editing student: " << students[i].name << endl;
            
            cout << "Enter new name (current: " << students[i].name << "): ";
            getline(cin, students[i].name);
            
            cout << "Enter new age (current: " << students[i].age << "): ";
            cin >> students[i].age;
            cin.ignore();
            
            cout << "Enter new course code (current: " << students[i].course.course_code << "): ";
            getline(cin, students[i].course.course_code);
            
            cout << "Enter new course name (current: " << students[i].course.course_name << "): ";
            getline(cin, students[i].course.course_name);
            
            cout << "Student details updated successfully.\n";
            return;
        }
    }

    cout << "Student with registration number " << regNum << " not found.\n";
}

void addMarks() {
    if (studentCount == 0) {
        cout << "No students available to add marks.\n";
        return;
    }

    string regNum;
    cout << "Enter registration number of student: ";
    getline(cin, regNum);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].registration_number == regNum) {
            if (students[i].grade.calculated) {
                cout << "Grades for this student have already been calculated and cannot be altered.\n";
                return;
            }

            cout << "Enter mark for " << students[i].name << " (0-100): ";
            cin >> students[i].grade.mark;
            cin.ignore();

            if (students[i].grade.mark < 0 || students[i].grade.mark > 100) {
                cout << "Invalid mark. Must be between 0 and 100.\n";
                students[i].grade.mark = 0;
                return;
            }
            students[i].grade.the_grade = calculateGrade(students[i].grade.mark);
            students[i].grade.calculated = true;
            
            cout << "Grade calculated: " << students[i].grade.the_grade << endl;
            return;
        }
    }

    cout << "Student with registration number " << regNum << " not found.\n";
}
void displayStudents() {
    if (studentCount == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\nList of Students:\n";
    cout << "---------------------------\n";
    cout << "Reg No.       Name                      Age  Course Code  Course Name          Mark  Grade\n";
    cout << "---------------------------\n";

    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(14) << students[i].registration_number.substr(0, 13)
             << setw(26) << students[i].name.substr(0, 25)
             << setw(5) << students[i].age
             << setw(13) << students[i].course.course_code.substr(0, 12)
             << setw(20) << students[i].course.course_name.substr(0, 19)
             << setw(7) << students[i].grade.mark
             << students[i].grade.the_grade << endl;
    }
}

void displayMenu() {
    cout << "\nStudent Management System\n";
    cout << "1. Add a new student\n";
    cout << "2. Edit student details\n";
    cout << "3. Add marks and calculate grades\n";
    cout << "4. Display all students\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                editStudent();
                break;
            case 3:
                addMarks();
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}