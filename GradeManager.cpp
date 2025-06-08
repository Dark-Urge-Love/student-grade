#include "GradeManager.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// 添加学生
void GradeManager::addStudent(const Student& student) {
    students.push_back(student);
}

// 按学号查找学生索引
int GradeManager::findStudentIndex(const string& id) const {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getId() == id) {
            return i;
        }
    }
    return -1; // 未找到
}

// 查询学生
Student* GradeManager::findStudent(const string& id) {
    int index = findStudentIndex(id);
    if (index != -1) {
        return &students[index];
    }
    return nullptr;
}

// 显示所有学生（按学号排序）
void GradeManager::displayAll() const {
    if (students.empty()) {
        cout << "没有学生记录！" << endl;
        return;
    }

    // 创建副本进行排序（不修改原顺序）
    vector<Student> sortedStudents = students;
    sort(sortedStudents.begin(), sortedStudents.end(),
        [](const Student& a, const Student& b) {
            return a.getId() < b.getId();
        });

    // 打印表头
    cout << "\n学号        姓名          平时成绩  考试成绩  总评成绩\n";
    cout << "------------------------------------------------------\n";

    // 打印学生信息
    for (const auto& student : sortedStudents) {
        student.display();
    }
    std::cout << std::endl;
}

// 删除学生
bool GradeManager::removeStudent(const std::string& id) {
    int index = findStudentIndex(id);
    if (index != -1) {
        students.erase(students.begin() + index);
        return true;
    }
    return false;
}

// 修改学生信息
bool GradeManager::updateStudent(const std::string& id) {
    Student* student = findStudent(id);
    if (student) {
        double daily, exam;
        std::cout << "输入新的平时成绩: ";
        std::cin >> daily;
        std::cout << "输入新的考试成绩: ";
        std::cin >> exam;

        student->updateScores(daily, exam);
        return true;
    }
    return false;
}

// 成绩统计
void GradeManager::analyzeScores() const {
    if (students.empty()) {
        std::cout << "没有学生记录！" << std::endl;
        return;
    }

    // 成绩分段统计
    std::map<std::string, int> scoreGroups = {
        {"优秀(90-100)", 0},
        {"良好(80-89)", 0},
        {"中等(70-79)", 0},
        {"及格(60-69)", 0},
        {"不及格(0-59)", 0}
    };

    double total = 0;

    // 统计各分数段人数
    for (const auto& student : students) {
        double score = student.getFinalScore();
        total += score;

        if (score >= 90) scoreGroups["优秀(90-100)"]++;
        else if (score >= 80) scoreGroups["良好(80-89)"]++;
        else if (score >= 70) scoreGroups["中等(70-79)"]++;
        else if (score >= 60) scoreGroups["及格(60-69)"]++;
        else scoreGroups["不及格(0-59)"]++;
    }

    // 计算平均分
    double average = total / students.size();

    // 输出统计结果
    std::cout << "\n============== 成绩统计分析 ==============\n";
    std::cout << "班级平均成绩: " << std::fixed << std::setprecision(2) << average << std::endl;
    std::cout << "----------------------------------------\n";
    std::cout << "成绩分段统计:\n";

    for (const auto& group : scoreGroups) {
        double percentage = static_cast<double>(group.second) / students.size() * 100;
        std::cout << group.first << ": " << group.second << "人 ("
            << std::fixed << std::setprecision(1) << percentage << "%)" << std::endl;
    }
    std::cout << "========================================\n\n";
}