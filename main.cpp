#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_TESTS = 10;
int readData(ifstream &file, string names[], double scores[][MAX_TESTS], int &numTests);
void calculateAverages(const double scores[][MAX_TESTS], double averages[], int numStudents, int numTests);
char getLetterGrade(double average);
void printReport(const string names[], const double averages[], int numStudents);
int main() {
    ifstream inputFile("StudentGrades.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file.\n";
        return 1;
    }
    string names[MAX_STUDENTS];
    double scores[MAX_STUDENTS][MAX_TESTS];
    double averages[MAX_STUDENTS];
    int numStudents = 0;
    int numTests = 0;
        numStudents = readData(inputFile, names, scores, numTests);
        inputFile.close();
        calculateAverages(scores, averages, numStudents, numTests);
        printReport(names, averages, numStudents);
        return 0;
    }
    int readData(ifstream &file, string names[], double scores[][MAX_TESTS], int &numTests) {
        int studentCount = 0;
        while (file >> names[studentCount]) { 
            int testCount = 0;
            while (testCount < MAX_TESTS && file >> scores[studentCount][testCount]) {
                testCount++;
                if (file.peek() == '\n' || file.peek() == EOF) break;
            }
            if (studentCount == 0) {
                numTests = testCount;
            }
            studentCount++;
            if (studentCount >= MAX_STUDENTS) break;
        }
        return studentCount;
    }
    void calculateAverages(const double scores[][MAX_TESTS], double averages[], int numStudents, int numTests) {
        for (int i = 0; i < numStudents; i++) {
            double total = 0;
            for (int j = 0; j < numTests; j++) {
                total += scores[i][j];
            }
            averages[i] = total / numTests;
        }
    }
    char getLetterGrade(double average) {
        if (average >= 90) return 'A';
        else if (average >= 80) return 'B';
        else if (average >= 70) return 'C';
        else if (average >= 60) return 'D';
        return 'F';
    }
    void printReport(const string names[], const double averages[], int numStudents) {
        cout << "\nStudent Report\n";
        cout << "--------------------------------------\n";
        cout << left << setw(15) << "Name" << setw(10) << "Average" << setw(10) << "Grade" << endl;
        cout << "--------------------------------------\n";

        for (int i = 0; i < numStudents; i++) {
            cout << left << setw(15) << names[i]
                 << setw(10) << fixed << setprecision(2) << averages[i]
                 << setw(10) << getLetterGrade(averages[i]) << endl;
        }
    }