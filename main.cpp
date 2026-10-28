#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
const double QUIZ_WEIGHT       = 0.10;
const double ASSIGNMENT_WEIGHT = 0.20;
const double PROJECT_WEIGHT    = 0.30;
const double EXAM_WEIGHT       = 0.40;
const double MIN_SCORE = 0.0;
const double MAX_SCORE = 100.0;
const int    CREDIT_HOURS_PER_MODULE = 4;
const int    MODULES_PER_SEMESTER    = 4;
const double PASS_MARK               = 40.0;
const double EXAM_MINIMUM            = 40.0;
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
double calculateModuleTotal(double quiz, double assignment, double project, double exam)
{
    return (quiz * QUIZ_WEIGHT)
         + (assignment * ASSIGNMENT_WEIGHT)
         + (project * PROJECT_WEIGHT)
         + (exam * EXAM_WEIGHT);
}

string getLetterGrade(double total)
{
    if (total >= 80)      return "A";
    else if (total >= 75) return "A-";
    else if (total >= 70) return "B+";
    else if (total >= 65) return "B";
    else if (total >= 60) return "B-";
    else if (total >= 55) return "C+";
    else if (total >= 50) return "C";
    else if (total >= 46) return "C-";
    else if (total >= 43) return "D+";
    else if (total >= 40) return "D";
    else                  return "F";
}

double getGradePoints(const string& grade)
{
    if (grade == "A")       return 4.00;
    else if (grade == "A-") return 3.67;
    else if (grade == "B+") return 3.33;
    else if (grade == "B")  return 3.00;
    else if (grade == "B-") return 2.67;
    else if (grade == "C+") return 2.33;
    else if (grade == "C")  return 2.00;
    else if (grade == "C-") return 1.67;
    else if (grade == "D+") return 1.33;
    else if (grade == "D")  return 1.00;
    else                    return 0.00;
}
bool askToContinue()
{
    char answer;

    while (true)
    {
        cout << "\nAdd another student? (y/n): ";
        cin >> answer;
        cin.ignore(1000, '\n');

        if (answer == 'y' || answer == 'Y')
            return true;
        else if (answer == 'n' || answer == 'N')
            return false;
        else
            cout << "Please type y or n.\n";
    }
}
int main()
{
    string studentName;
    string moduleName;
    double quizScore, assignmentScore, projectScore, examScore;
    double moduleTotal;
    string letterGrade;
    double gradePoints;
    bool   isPassed = false;
    bool   addAnother = true;
    int    studentNumber = 0;

    cout << fixed << setprecision(2);

    cout << "=== MSU Semester GPA Calculator ===\n";

    while (addAnother)
    {
        studentNumber++;

        
        double weightedPointsSum = 0.0;
        int    totalCreditHours  = 0;

        cout << "\n########## Student " << studentNumber << " ##########\n";
        cout << "Enter student name: ";
        getline(cin, studentName);

        for (int moduleNumber = 1; moduleNumber <= MODULES_PER_SEMESTER; moduleNumber++)
        {
            cout << "\n== Module " << moduleNumber << " of " << MODULES_PER_SEMESTER << " ==\n";
            cout << "Enter module name: ";
            getline(cin, moduleName);

            cout << "-- Scores for " << moduleName << " --\n";
            quizScore       = readScore("Quiz");
            assignmentScore = readScore("Assignment");
            projectScore    = readScore("Project");
            examScore       = readScore("Exam");

            
            cin.ignore(1000, '\n');

            moduleTotal = calculateModuleTotal(quizScore, assignmentScore, projectScore, examScore);
            moduleTotal = round(moduleTotal * 100) / 100;
            letterGrade = getLetterGrade(moduleTotal);
            gradePoints = getGradePoints(letterGrade);

            if (moduleTotal >= PASS_MARK && examScore >= EXAM_MINIMUM)
            {
                isPassed = true;
            }
            else
            {
                isPassed = false;
            }

            cout << "\n-- Result for " << moduleName << " --\n";
            cout << "  Weighted total : " << moduleTotal << "\n";
            cout << "  Letter grade   : " << letterGrade << "\n";
            cout << "  Grade points   : " << gradePoints << "\n";
            cout << "  Status         : " << (isPassed ? "Passed" : "Failed") << "\n";

            weightedPointsSum += gradePoints * CREDIT_HOURS_PER_MODULE;
            totalCreditHours  += CREDIT_HOURS_PER_MODULE;
        }

        double semesterGPA = weightedPointsSum / totalCreditHours;

        cout << "\n==============================\n";
        cout << "Student      : " << studentName << "\n";
        cout << "Semester GPA : " << semesterGPA << "\n";
        cout << "==============================\n";

        addAnother = askToContinue();
    }

    cout << "\nThank you. Processed " << studentNumber << " student(s). Goodbye!\n";
    return 0;
}