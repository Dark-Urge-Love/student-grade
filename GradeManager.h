#pragma once
#ifndef GRADE_MANAGER_H
#define GRADE_MANAGER_H
#include "Student.h"
#include <vector>
#include <map>
using namespace std;

class GradeManager {
private:
    vector<Student> students;  // �洢����ѧ��

    // ��ѧ�Ų���ѧ������
    int findStudentIndex(string id) const;

public:
    // ���ѧ��
    void addStudent(Student student);

    // ��ѯѧ��
    Student* findStudent(string id);

    // ��ʾ����ѧ������ѧ������
    void displayAll() const;

    // ɾ��ѧ��
    bool removeStudent(string id);

    // �޸�ѧ����Ϣ
    bool updateStudent(string id);

    // �ɼ�ͳ��
    void analyzeScores() const;
};

#endif // GRADE_MANAGER_H
