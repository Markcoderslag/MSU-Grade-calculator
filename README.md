# MSU Semester GPA Calculator

A console-based C++ program that calculates module grades and a credit-weighted
semester GPA for one or more students. Built for the CCS20203 Introduction to
Programming mid-semester project at MSU Colombo.

## Features

- Enter one or more students, each with four modules in a semester
- Each module is scored on quiz (10%), assignment (20%), project (30%) and exam (40%)
- Scores are validated to be between 0 and 100
- Module totals are converted to letter grades and grade points
- A module passes only if the total is at least 40 and the exam score is at least 40
- Semester GPA is calculated using credit hours (4 per module)

## Requirements

- A C++ compiler that supports C++11 or later (for example `g++`)
- A terminal or command prompt

## Build and run

```bash
g++ main.cpp -o gpa_calculator
./gpa_calculator
```

On Windows, run `gpa_calculator.exe` instead of `./gpa_calculator`.

## Sample run

```
=== MSU Semester GPA Calculator ===

########## Student 1 ##########
Enter student name: Test Student

== Module 1 of 4 ==
Enter module name: Introduction to programming
-- Scores for Introduction to programming --
  Enter Quiz score (0.00 - 100.00): 45
  ...
-- Result for Introduction to programming --
  Weighted total : 76.10
  Letter grade   : A-
  Grade points   : 3.67
  Status         : Passed

...

==============================
Student      : Test Student
Semester GPA : 2.17
==============================

Add another student? (y/n): n

Thank you. Processed 1 student(s). Goodbye!
```

## Grading rules

| Marks   | Grade | Grade points |
|---------|-------|--------------|
| 80-100  | A     | 4.00         |
| 75-79   | A-    | 3.67         |
| 70-74   | B+    | 3.33         |
| 65-69   | B     | 3.00         |
| 60-64   | B-    | 2.67         |
| 55-59   | C+    | 2.33         |
| 50-54   | C     | 2.00         |
| 46-49   | C-    | 1.67         |
| 43-45   | D+    | 1.33         |
| 40-42   | D     | 1.00         |
| 0-39    | F     | 0.00         |

Totals are rounded to two decimal places before the grade is looked up.

## Project structure

```
msu-gpa-calculator/
├── main.cpp      # Full program source
├── README.md     # This file
└── .gitignore    # Excludes compiled binaries
```

## Known limitations

- Module names are not checked for duplicates.
- Data is not saved; results exist only while the program runs.
- The letter grade labels other than A and the exam minimum of 40 are assumptions to be confirmed against the MSU handbook.
- The program uses console input only and has no GUI.

## Author

<Anjana Prabath>