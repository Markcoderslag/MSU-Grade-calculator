#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
const double Qz_weight = 0.10;
const double Assing_weight = 0.20;
const double prj_Weight = 0.30;
const double Exm_Weight = 0.40;
const double Min_score = 0.0;
const double Max_score = 100.0;
const int crd_hrs_module = 4;
const int  Mdls_one_sem = 4;
const double Pass_mrk = 40.0;
const double Exm_minim  = 40.0;
double readScore(const string& label)
{
    double score;
    bool validInput = false;

    while (!validInput)
    {
        cout << "  Enter " << label << " score (" << Min_score
             << " - " << Max_score << "): ";

        if (!(cin >> score))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  Invalid input. Please enter a number.\n";
        }
        else if (score < Min_score || score > Max_score)
        {
            cout << "  Score must be between " << Min_score
                 << " and " << Max_score << ". Try again.\n";
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
    return (quiz * Qz_weight)
         + (assignment * Assing_weight)
         + (project * prj_Weight)
         + (exam * Exm_Weight);
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
    string stdnname;
    string mdlname;
    double qzscore, assngscore, prjscore, exmscore;
    double moduleTotal;
    string letterGrade;
    double gradePoints;
    bool isPassed = false;
    bool addAnother = true;
    int stdnum = 0;

    cout << fixed << setprecision(2);

    cout << "=== MSU Semester GPA Calculator ===\n";

    while (addAnother)
    {
        stdnum++;

        
        double weighpoin = 0.0;
        int    ttlcrdhour  = 0;

        cout << "\n########## Student " << stdnum << " ##########\n";
        cout << "Enter student name: ";
        getline(cin, stdnname);

        for (int moduleNumber = 1; moduleNumber <= Mdls_one_sem; moduleNumber++)
        {
            cout << "\n== Module " << moduleNumber << " of " << Mdls_one_sem << " ==\n";
            cout << "Enter module name: ";
            getline(cin, mdlname);

            cout << "-- Scores for " << mdlname << " --\n";
            qzscore       = readScore("Quiz");
            assngscore = readScore("Assignment");
            prjscore    = readScore("Project");
            exmscore       = readScore("Exam");

            
            cin.ignore(1000, '\n');

            moduleTotal = calculateModuleTotal(qzscore, assngscore, prjscore, exmscore);
            moduleTotal = round(moduleTotal * 100) / 100;
            letterGrade = getLetterGrade(moduleTotal);
            gradePoints = getGradePoints(letterGrade);

            if (moduleTotal >= Pass_mrk && exmscore >= Exm_minim)
            {
                isPassed = true;
            }
            else
            {
                isPassed = false;
            }

            cout << "\n-- Result for " << mdlname << " --\n";
            cout << "  Weighted total : " << moduleTotal << "\n";
            cout << "  Letter grade   : " << letterGrade << "\n";
            cout << "  Grade points   : " << gradePoints << "\n";
            cout << "  Status         : " << (isPassed ? "Passed" : "Failed") << "\n";

            weighpoin += gradePoints * crd_hrs_module;
            ttlcrdhour  += crd_hrs_module;
        }

        double semesterGPA = weighpoin / ttlcrdhour;

        cout << "\n==============================\n";
        cout << "Student      : " << stdnname << "\n";
        cout << "Semester GPA : " << semesterGPA << "\n";
        cout << "==============================\n";

        addAnother = askToContinue();
    }

    cout << "\nThank you. Processed " << stdnum << " student(s). Goodbye!\n";
    return 0;
}
