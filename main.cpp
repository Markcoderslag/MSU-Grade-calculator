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

// ── Input validation function ─────────────────────────────────────────────────
// Keeps asking until the user enters a valid number between MIN_SCORE and MAX_SCORE
double readScore(const string& label)
{
    double score;
    bool validInput = false;

    while (!validInput)
    {
        cout << "  Enter " << label << " score (" << MIN_SCORE
             << " - " << MAX_SCORE << "): ";

        if (!(cin >> score))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  Invalid input. Please enter a number.\n";
        }
        else if (score < MIN_SCORE || score > MAX_SCORE)
        {
            cout << "  Score must be between " << MIN_SCORE
                 << " and " << MAX_SCORE << ". Try again.\n";
        }
        else
        {
            validInput = true;
        }
    }
    return score;
}

// ─────────────────────────────────────────────────────────────────────────────
int main()
{
    string studentName;
    string moduleName;
    string letterGrade;

    int moduleNumber  = 0;
    int studentNumber = 0;

    double quizScore;
    double assignmentScore;
    double projectScore;
    double examScore;

    double moduleTotal = 0.0;
    double gradePoints = 0.0;
    double semesterGPA = 0.0;

    bool isPassed = false;

    cout << "\nEnter module name: ";
    getline(cin, moduleName);

    cout << "\n-- Scores for " << moduleName << " --\n";
    quizScore       = readScore("Quiz");
    assignmentScore = readScore("Assignment");
    projectScore    = readScore("Project");
    examScore       = readScore("Exam");

    cout << "\nScores recorded successfully for " << moduleName << ".\n";

    return 0;
}