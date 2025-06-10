#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string id;        // 学号
    string name;      // 姓名
    double dailyScore;     // 平时成绩
    double examScore;      // 考试成绩
    double finalScore;     // 总评成绩

public:
    Student(const string id, const string name,
        double dailyScore, double examScore);

    string getId() const;
    string getName() const;
    double getDailyScore() const;
    double getExamScore() const;
    double getFinalScore() const;

    // 更新成绩
    void updateScores(double newDailyScore, double newExamScore);

    // 显示学生信息
    void display() const;
};

#endif // STUDENT_H