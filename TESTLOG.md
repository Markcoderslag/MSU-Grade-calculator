# Testing and Debugging Log

Program: MSU Semester GPA Calculator (`main.cpp`)
Compiler: g++
Platform: Windows (VS Code terminal)

## 1. Test plan

Each test enters one module with the given scores. Expected values are calculated by hand using the weights (quiz 10%, assignment 20%, project 30%, exam 40%) and the grade table.

### 1.1 Module calculation and boundaries

| ID | Quiz | Assignment | Project | Exam | Expected total | Expected grade | Expected points | Result status |
|----|------|------------|---------|------|----------------|----------------|-----------------|-----------------|
| M1 | 0 | 0 | 0 | 0 | 0.00 | F | 0.00 | Failed |
| M2 | 40 | 40 | 40 | 40 | 40.00 | D | 1.00 | Passed |
| M3 | 100 | 100 | 100 | 39 | 75.60 | A- | 3.67 | Failed (exam under 40) |
| M4 | 100 | 100 | 100 | 100 | 100.00 | A | 4.00 | Passed |
| M5 | 45 | 67 | 78 | 87 | 76.10 | A- | 3.67 | Passed |
| M6 | 100 | 100 | 100 | 30 | 72.00 | B+ | 3.33 | Failed (exam under 40) |

### 1.2 Grade boundaries

Each boundary is tested by entering the same value for all four scores. Because the weights add up to 1, the weighted total equals that value.

| ID | Scores (all four) | Expected total | Expected grade | Expected points |
|----|-------------------|----------------|----------------|-----------------|
| B1 | 80 | 80.00 | A | 4.00 |
| B2 | 79.99 | 79.99 | A- | 3.67 |
| B3 | 74.99 | 74.99 | B+ | 3.33 |
| B4 | 45 | 45.00 | D+ | 1.33 |
| B5 | 39.99 | 39.99 | F | 0.00 |

### 1.3 Input validation

| ID | Input | Expected behaviour |
|----|-------|--------------------|
| V1 | `-5` | Re-prompts with "Score must be between..." |
| V2 | `101` | Re-prompts |
| V3 | `abc` | Re-prompts with "Invalid input..." |
| V4 | `0` | Accepted |
| V5 | `100` | Accepted |
| V6 | `75.5` | Accepted |
| V7 | Empty line (just Enter) | Re-prompts |

### 1.4 Program flow

| ID | Action | Expected behaviour |
|----|--------|--------------------|
| F1 | Module name with spaces (`Introduction to programming`) | Full name shown in results |
| F2 | Student name with spaces | Full name shown in summary |
| F3 | Two students, second has all 100s, same modules as first | Second GPA is 4.00 (no carry-over) |
| F4 | Continue prompt: `x` | Asks again |
| F5 | Continue prompt: `y` | Starts next student |
| F6 | Continue prompt: `n` | Goodbye message, exits |
| F7 | Semester GPA for modules A-, A, F, D | 2.17 |

### 1.5 Semester GPA check

Modules: A- (3.67), A (4.00), F (0.00), D (1.00). Each has 4 credit hours.

(3.67 × 4 + 4.00 × 4 + 0.00 × 4 + 1.00 × 4) / 16 = 34.68 / 16 = 2.1675, which prints as **2.17**.

Note: the grade points sum to 8.67, and the GPA is the total of grade points × credits divided by total credits.

## 2. Debugging log

Each issue below was found during development, with its cause and fix.

| # | Problem found | Cause | Fix | Branch |
|---|---------------|-------|-----|--------|
| D1 | Module name stored only the first word (`Introduction`) | `cin >>` stops reading at whitespace | Read names with `getline(cin, ...)` | feature/module-input |
| D2 | Total of 40/40/40/40 could print as 39.99... and return F | Floating-point rounding in the weighted sum | Round to two decimals before the grade lookup: `round(total * 100) / 100` | feature/module-calculation |
| D3 | Student name came back empty after a score was entered | Newline left in the input buffer by `cin >>` was read by the next `getline` | Added `cin.ignore(1000, '\n')` after the last score | feature/semester-gpa |
| D4 | Bad input such as `abc` caused an endless error loop | A failed `cin >>` leaves the stream in an error state | `cin.clear()` then `cin.ignore(1000, '\n')` inside `readScore` | feature/module-input |
| D5 | Second student's GPA included the first student's modules | Running totals were declared outside the student loop | Moved `weightedPointsSum` and `totalCreditHours` inside the loop | feature/student-loop |
| D6 | Compiled `gpa_calculator.exe` was committed to GitHub | `.gitignore` did not include the Windows binary name | Added `gpa_calculator.exe` to `.gitignore`, then `git rm --cached` | feature/module-input |
| D7 | Pass check used only the total, so the `&&` check was redundant | Any total of 40 or more already has a grade of at least D | Added an exam minimum (40) so the pass check combines two real conditions | feature/semester-gpa |
| D8 | Test expectation for the 45/67/78/87 module was wrong (73.9, B+) | Arithmetic error when checking by hand | Recalculated: 4.5 + 13.4 + 23.4 + 34.8 = 76.1 (A-) | Test planning |
| D9 | README author line did not show on GitHub | Last lines were inside a code block, or Markdown merged the lines | Moved the author into normal text with a blank line between entries | docs/readme |

## 3. Known limitations found during testing

- Module names are not checked for duplicates.
- The continue prompt reads only the first character, so `yes` is accepted as `y`.
- Data is not saved between runs.
- Grade labels other than A and the exam minimum of 40 are assumptions pending confirmation from the MSU handbook.
- Two-decimal formatting is applied to every number, so the score range prints as `0.00 - 100.00`.

## 4. Conclusion

All module boundary cases, validation cases and flow cases were run. Results are recorded in the Result columns above. Any failures are listed in the debugging log with their fixes.