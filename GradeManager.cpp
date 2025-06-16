#include "GradeManager.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// 添加学生
void GradeManager::addStudent(Student student) {
    students.push_back(student);
}

// 按学号查找学生索引
int GradeManager::findStudentIndex(string id) const {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getId() == id) {
            return i;
        }
    }
    return -1; // 未找到
}

// 查询学生
Student* GradeManager::findStudent(string id) {//指针类型
    int index = findStudentIndex(id);
    if (index != -1) {
        return &students[index];
    }
    return nullptr;
}

//比较函数（用于sort）
bool compareById(const Student& a, const Student& b) {
    return a.getId() < b.getId();
}

// 显示所有学生（按学号排序）
void GradeManager::displayAll() const {
    if (students.empty()) {
        cout << "没有学生记录！" << endl;
        return;
    }

    vector<Student> sortedStudents = students;
    sort(sortedStudents.begin(), sortedStudents.end(), compareById);//sort排序

    // 打印表头
    cout << "\n学号        姓名          平时成绩  考试成绩  总评成绩\n";
    cout << "------------------------------------------------------\n";

    // 打印学生信息
    for (Student student : sortedStudents) {
        student.display();
    }
    cout << endl;
}

// 删除学生
bool GradeManager::removeStudent(string id) {
    int index = findStudentIndex(id);
    if (index != -1) {
        students.erase(students.begin() + index);
        return true;
    }
    return false;
}

// 修改学生信息
bool GradeManager::updateStudent(string id) {
    Student* student = findStudent(id);
    if (student) {
        double daily, exam;
        cout << "输入新的平时成绩: ";
        cin >> daily;
        cout << "输入新的考试成绩: ";
        cin >> exam;

        student->updateScores(daily, exam);
        return true;
    }
    return false;
}

// 成绩统计
void GradeManager::analyzeScores() const {
    if (students.empty()) {
        cout << "没有学生记录！" <<endl;
        return;
    }
    vector<pair<string, int>> scoreGroups = {
        {"不及格(0-59)", 0},
        {"及格(60-69)", 0},
        {"中等(70-79)", 0}, 
        {"良好(80-89)", 0},
        {"优秀(90-100)", 0}
    };
    double total = 0;

    // 统计各分数段人数
    for (Student student : students) {
        double score = student.getFinalScore();
        total += score;

        if (score >= 90) {
            scoreGroups[4].second++;  //优秀
        }
        else if (score >= 80) {
            scoreGroups[3].second++;  //良好
        }
        else if (score >= 70) {
            scoreGroups[2].second++;  //中等
        }
        else if (score >= 60) {
            scoreGroups[1].second++;  //及格
        }
        else {
            scoreGroups[0].second++;  //不及格
        }
    }
    double average = total / students.size();

    cout << "\n============== 成绩统计分析 ==============\n";
    cout << "班级平均成绩: " << fixed << setprecision(2) << average << endl;
    cout << "----------------------------------------\n";
    cout << "成绩分段统计:\n";

    for (const auto& group : scoreGroups) {
        double percentage = static_cast<double>(group.second) / students.size() * 100;
        cout << group.first << ": " << group.second << "人 ("
            << fixed << setprecision(1) << percentage << "%)" << endl;
    }
    cout << "========================================\n\n";
}