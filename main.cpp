#include <iostream>
#include <string>

using namespace std;

void readScores(double& s1, double& s2, double& s3);
void getGrade(const double s1, const double s2, const double s3, double& avg, char& grade);
double getAverage(const double s1, const double s2, const double s3, double& average);
void print(const double s1, const double s2, const double s3, const double average, const char grade);

int main() {
    double s1, s2, s3, average;
    char grade = 0;
    readScores(s1, s2, s3);
    getGrade(s1, s2, s3, average, grade);
    getAverage(s1, s2, s3, average);
    print(s1, s2, s3, average, grade);
    return 0;
}
void readScores(double& s1, double& s2, double& s3) {
    cout << "Enter three grades: ";
    cin >> s1 >> s2 >> s3;
    while (s1 < 0 || s1 > 100)
      {
        cout << "Enter a grade from 0 to 100: ";
        cin >> s1;
        break;
      }
    while (s2 < 0 || s2 > 100)
      {
        cout << "Enter a grade from 0 to 100: ";
        cin >> s2;
        break;
      }
    while (s3 < 0 || s3 > 100)
      {
        cout << "Enter a grade from 0 to 100: ";
        cin >> s3;
        break;
      }
    }
    double getAverage(double s1, double s2, double s3) { 
    double average = (s1 + s2 + s3) / 3.0;
    return average;
  }
    void getGrade(double average, char& grade) {
      cout << "Average: " << average << endl;
      if (90 < average && average <= 100) {
        cout << "Grade: A" << endl;
      }
      else if (80 < average && average < 89) {
        cout << "Grade: B" << endl;
      }
       else if (70 < average && average < 79) {
        cout << "Grade: C" << endl;
      }
        else if (60 < average && average < 69) {
        cout << "Grade: D" << endl;
      }
        else if (0 < average && average < 59) {
        cout << "Grade: F" << endl;
      }
    } 
    void print(double s1, double s2, double s3, double average, char grade) {
      cout << "Score 1: " << s1 << endl;
      cout << "Score 2: " << s2 << endl;
      cout << "Score 3: " << s3 << endl;
      cout << "Average: " << average << endl;
      cout << "Grade: " << grade << endl;
    }
