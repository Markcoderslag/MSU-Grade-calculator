#include <iostream>
#include <string>
using namespace std;

// ── Assessment weights ────────────────────────────────────────────────────────
const double QUIZ_WEIGHT       = 0.10;
const double ASSIGNMENT_WEIGHT = 0.20;
const double PROJECT_WEIGHT    = 0.30;
const double EXAM_WEIGHT       = 0.40;

// ── Score limits ──────────────────────────────────────────────────────────────
const double MIN_SCORE = 0.0;
const double MAX_SCORE = 100.0;

// ── Module / semester info ────────────────────────────────────────────────────
const int CREDIT_HOURS_PER_MODULE = 4;
const int MODULES_PER_SEMESTER    = 4;

int main()
{
    // Identifiers for student and module names
    string studentName;
    string moduleName;
    string letterGrade;

    // Loop counters
    int moduleNumber  = 0;
    int studentNumber = 0;

    // Scores for one module
    double quizScore;
    double assignmentScore;
    double projectScore;
    double examScore;

    // Caluclated Values
    double moduleTotal = 0.0;
    double gradePoints = 0.0;
    double semesterGPA = 0.0;

    // True if the student passes the module
    bool isPassed = false;

    cout << "Constants and variables loaded successfully." << endl;

    return 0;
}