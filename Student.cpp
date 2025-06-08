#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

// 构造函数
Student::Student(const std::string& id, const std::string& name,
    double dailyScore, double examScore)
    : id(id), name(name), dailyScore(dailyScore), examScore(examScore) {
    // 计算总评成绩（平时40% + 考试60%）
    finalScore = dailyScore * 0.4 + examScore * 0.6;
}

// Getter方法实现
string Student::getId() const { return id; }
string Student::getName() const { return name; }
double Student::getDailyScore() const { return dailyScore; }
double Student::getExamScore() const { return examScore; }
double Student::getFinalScore() const { return finalScore; }

// 更新成绩
void Student::updateScores(double newDailyScore, double newExamScore) {
    dailyScore = newDailyScore;
    examScore = newExamScore;
    finalScore = dailyScore * 0.4 + examScore * 0.6;
}

// 显示学生信息
void Student::display() const {
    cout << left << setw(12) << id
        << setw(15) << name
        << setw(10) << fixed << setprecision(2) << dailyScore
        << setw(10) << examScore
        << setw(10) << finalScore <<endl;
}