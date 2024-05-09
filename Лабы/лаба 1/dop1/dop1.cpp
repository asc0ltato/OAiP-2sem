#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

struct ExamResult {
    string studentName;
    int numOfExams;
    vector<int> grades;
};

bool areAllExamsPassed(const ExamResult& result) {
    for (int grade : result.grades) {
        if (grade < 4) {
            return false;
        }
    }
    return true;
}

int getPassRate(const vector<ExamResult>& results) {
    int passedCount = 0;
    int totalCount = results.size();

    for (const ExamResult& result : results) {
        if (areAllExamsPassed(result)) {
            passedCount++;
        }
    }

    return 100 * passedCount / totalCount;
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<ExamResult> results = {
        {"Марина", 3, {4, 5, 5}},
        {"Даша", 2, {5, 5}},
        {"Аня", 4, {4, 4, 5, 4}}
    };
    int passRate = getPassRate(results);
    cout << "Проценты: " << passRate << "%" << endl;
    return 0;
}