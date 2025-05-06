#include <iostream>
#include <cstring>
using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_COURSES = 50;
const int MAX_COURSES_PER_STUDENT = 10;

class Course {
public:
    char name[50];

    Course() {
        name[0] = '\0';
    }

    void setCourse(const char* courseName) {
        strcpy(name, courseName);
    }
};

class Student {
private:
    char username[50];
    char password[50];
    char rollNumber[20];
    Course courses[MAX_COURSES_PER_STUDENT];
    int courseCount;

public:
    Student() {
        username[0] = password[0] = rollNumber[0] = '\0';
        courseCount = 0;
    }

    void registerStudent() {
        cout << "Enter student username: ";
        cin.getline(username, 50);
        cout << "Enter student password: ";
        cin.getline(password, 50);
        cout << "Enter student roll number: ";
        cin.getline(rollNumber, 20);
    }

    bool login(const char* uname, const char* pword) {
        return strcmp(username, uname) == 0 && strcmp(password, pword) == 0;
    }

    bool matchRollNumber(const char* roll) {
        return strcmp(rollNumber, roll) == 0;
    }

    void allocateCourse(const char* courseName) {
        if (courseCount < MAX_COURSES_PER_STUDENT) {
            courses[courseCount].setCourse(courseName);
            courseCount++;
            cout << "Course allocated successfully.\n";
        } else {
            cout << "Cannot allocate more courses.\n";
        }
    }

    void viewCourses() {
        if (courseCount == 0) {
            cout << "No courses allocated.\n";
            return;
        }
        cout << "Courses for Roll No " << rollNumber << ":\n";
        for (int i = 0; i < courseCount; i++) {
            cout << "- " << courses[i].name << endl;
        }
    }

    void showRollNumber() {
        cout << rollNumber << endl;
    }
};

class ProgramCoordinator {
private:
    char username[50];
    char password[50];

public:
    ProgramCoordinator() {
        strcpy(username, "admin");
        strcpy(password, "admin123");
    }

    bool login(const char* uname, const char* pword) {
        return strcmp(username, uname) == 0 && strcmp(password, pword) == 0;
    }
};

class System {
private:
    Student students[MAX_STUDENTS];
    Course courses[MAX_COURSES];
    ProgramCoordinator pc;
    int studentCount;
    int courseCount;

public:
    System() {
        studentCount = 0;
        courseCount = 0;
    }

    void run() {
        int choice;
        do {
            cout << "\n1. Login as Program Coordinator\n2. Login as Student\n3. Exit\nEnter choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                pcLogin();
            } else if (choice == 2) {
                studentLogin();
            } else if (choice == 3) {
                cout << "Exiting system...\n";
            } else {
                cout << "Invalid choice.\n";
            }
        } while (choice != 3);
    }

private:
    void pcLogin() {
        char uname[50], pword[50];
        cout << "Enter PC username: ";
        cin.getline(uname, 50);
        cout << "Enter PC password: ";
        cin.getline(pword, 50);

        if (pc.login(uname, pword)) {
            int pcChoice;
            do {
                cout << "\n--- PC Menu ---\n";
                cout << "1. Create Course\n2. Register Student\n3. Allocate Course to Student\n";
                cout << "4. View All Students\n5. Search Student by Roll Number\n6. Logout\nEnter choice: ";
                cin >> pcChoice;
                cin.ignore();

                if (pcChoice == 1) {
                    createCourse();
                } else if (pcChoice == 2) {
                    registerStudent();
                } else if (pcChoice == 3) {
                    allocateCourse();
                } else if (pcChoice == 4) {
                    viewAllStudents();
                } else if (pcChoice == 5) {
                    searchStudent();
                } else if (pcChoice != 6) {
                    cout << "Invalid choice.\n";
                }
            } while (pcChoice != 6);
        } else {
            cout << "Login failed.\n";
        }
    }

    void studentLogin() {
        char uname[50], pword[50];
        cout << "Enter student username: ";
        cin.getline(uname, 50);
        cout << "Enter student password: ";
        cin.getline(pword, 50);

        for (int i = 0; i < studentCount; i++) {
            if (students[i].login(uname, pword)) {
                cout << "Student login successful.\n";
                students[i].viewCourses();
                return;
            }
        }
        cout << "Login failed.\n";
    }

    void createCourse() {
        if (courseCount >= MAX_COURSES) {
            cout << "Course limit reached.\n";
            return;
        }
        char cname[50];
        cout << "Enter course name: ";
        cin.getline(cname, 50);
        courses[courseCount].setCourse(cname);
        courseCount++;
        cout << "Course created successfully.\n";
    }

    void registerStudent() {
        if (studentCount >= MAX_STUDENTS) {
            cout << "Student limit reached.\n";
            return;
        }
        students[studentCount].registerStudent();
        studentCount++;
        cout << "Student registered successfully.\n";
    }

    void allocateCourse() {
        char roll[20], cname[50];
        cout << "Enter student roll number: ";
        cin.getline(roll, 20);
        cout << "Enter course name: ";
        cin.getline(cname, 50);

        for (int i = 0; i < studentCount; i++) {
            if (students[i].matchRollNumber(roll)) {
                students[i].allocateCourse(cname);
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void viewAllStudents() {
        if (studentCount == 0) {
            cout << "No students registered.\n";
            return;
        }
        cout << "Registered Students Roll Numbers:\n";
        for (int i = 0; i < studentCount; i++) {
            students[i].showRollNumber();
        }
    }

    void searchStudent() {
        char roll[20];
        cout << "Enter roll number to search: ";
        cin.getline(roll, 20);
        for (int i = 0; i < studentCount; i++) {
            if (students[i].matchRollNumber(roll)) {
                cout << "Student found with Roll No: " << roll << endl;
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

int main() {
    System sys;
    sys.run();
    return 0;
}
