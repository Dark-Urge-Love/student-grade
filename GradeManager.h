#pragma once
#ifndef GRADE_MANAGER_H
#define GRADE_MANAGER_H
#include "Student.h"
#include <vector>
#include <map>
using namespace std;

class GradeManager {
private:
    vector<Student> students;  // 存储所有学生

    // 按学号查找学生索引
    int findStudentIndex(string id) const;

public:
    // 添加学生
    void addStudent(Student student);

    // 查询学生
    Student* findStudent(string id);

    // 显示所有学生（按学号排序）
    void displayAll() const;

    // 删除学生
    bool removeStudent(string id);

    // 修改学生信息
    bool updateStudent(string id);

    // 成绩统计
    void analyzeScores() const;
};

#endif // GRADE_MANAGER_H
