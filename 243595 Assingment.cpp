#include <iostream>
#include <string>

using namespace std;

struct Student {
    int student_id;
    string name;
    int age;
    int grades[10];
    int num_courses;
};

void initializeStudent(Student &s) {
    cout << "Enter student ID: ";
    cin >> s.student_id;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter student age: ";
    cin >> s.age;

    cout << "Enter number of courses enrolled: ";
    cin >> s.num_courses;

    cout << "Enter grades for each course:\n";
    for (int i = 0; i < s.num_courses; i++) {
        cout << "Grade for course " << i + 1 << ": ";
        cin >> s.grades[i];
    }
}

void displayStudent(const Student &s) {
    cout << "\nStudent ID: " << s.student_id << endl;
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Number of Courses: " << s.num_courses << endl;
    cout << "Grades: ";
    for (int i = 0; i < s.num_courses; i++) {
        cout << s.grades[i] << " ";
    }
    cout << endl;
}

float calculateAverageGrade(const int *grades, int num_courses) {
    int sum = 0;
    for (int i = 0; i < num_courses; i++) {
        sum += grades[i];
    }
    return static_cast<float>(sum) / num_courses;
}

void addGrade(int *grades, int *num_courses, int new_grade) {
    if (*num_courses < 10) {
        grades[*num_courses] = new_grade;
        (*num_courses)++;
    } else {
        cout << "Cannot add more grades. Maximum limit reached.\n";
    }
}

int main() {
    Student student;
	Student student2(student);
    initializeStudent(student);
    displayStudent(student);

    float average_grade = calculateAverageGrade(student.grades, student.num_courses);
    cout << "Average Grade: " << average_grade << endl;

    int new_grade;
    cout << "Enter a new grade: ";
    cin >> new_grade;
    addGrade(student.grades, &student.num_courses, new_grade);

    cout << "\nStudent details after adding new grade:\n";
    displayStudent(student);

    return 0;
}