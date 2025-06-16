#include "GradeManager.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// ���ѧ��
void GradeManager::addStudent(Student student) {
    students.push_back(student);
}

// ��ѧ�Ų���ѧ������
int GradeManager::findStudentIndex(string id) const {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getId() == id) {
            return i;
        }
    }
    return -1; // δ�ҵ�
}

// ��ѯѧ��
Student* GradeManager::findStudent(string id) {//ָ������
    int index = findStudentIndex(id);
    if (index != -1) {
        return &students[index];
    }
    return nullptr;
}

//�ȽϺ���������sort��
bool compareById(const Student& a, const Student& b) {
    return a.getId() < b.getId();
}

// ��ʾ����ѧ������ѧ������
void GradeManager::displayAll() const {
    if (students.empty()) {
        cout << "û��ѧ����¼��" << endl;
        return;
    }

    vector<Student> sortedStudents = students;
    sort(sortedStudents.begin(), sortedStudents.end(), compareById);//sort����

    // ��ӡ��ͷ
    cout << "\nѧ��        ����          ƽʱ�ɼ�  ���Գɼ�  �����ɼ�\n";
    cout << "------------------------------------------------------\n";

    // ��ӡѧ����Ϣ
    for (Student student : sortedStudents) {
        student.display();
    }
    cout << endl;
}

// ɾ��ѧ��
bool GradeManager::removeStudent(string id) {
    int index = findStudentIndex(id);
    if (index != -1) {
        students.erase(students.begin() + index);
        return true;
    }
    return false;
}

// �޸�ѧ����Ϣ
bool GradeManager::updateStudent(string id) {
    Student* student = findStudent(id);
    if (student) {
        double daily, exam;
        cout << "�����µ�ƽʱ�ɼ�: ";
        cin >> daily;
        cout << "�����µĿ��Գɼ�: ";
        cin >> exam;

        student->updateScores(daily, exam);
        return true;
    }
    return false;
}

// �ɼ�ͳ��
void GradeManager::analyzeScores() const {
    if (students.empty()) {
        cout << "û��ѧ����¼��" <<endl;
        return;
    }
    vector<pair<string, int>> scoreGroups = {
        {"������(0-59)", 0},
        {"����(60-69)", 0},
        {"�е�(70-79)", 0}, 
        {"����(80-89)", 0},
        {"����(90-100)", 0}
    };
    double total = 0;

    // ͳ�Ƹ�����������
    for (Student student : students) {
        double score = student.getFinalScore();
        total += score;

        if (score >= 90) {
            scoreGroups[4].second++;  //����
        }
        else if (score >= 80) {
            scoreGroups[3].second++;  //����
        }
        else if (score >= 70) {
            scoreGroups[2].second++;  //�е�
        }
        else if (score >= 60) {
            scoreGroups[1].second++;  //����
        }
        else {
            scoreGroups[0].second++;  //������
        }
    }
    double average = total / students.size();

    cout << "\n============== �ɼ�ͳ�Ʒ��� ==============\n";
    cout << "�༶ƽ���ɼ�: " << fixed << setprecision(2) << average << endl;
    cout << "----------------------------------------\n";
    cout << "�ɼ��ֶ�ͳ��:\n";

    for (const auto& group : scoreGroups) {
        double percentage = static_cast<double>(group.second) / students.size() * 100;
        cout << group.first << ": " << group.second << "�� ("
            << fixed << setprecision(1) << percentage << "%)" << endl;
    }
    cout << "========================================\n\n";
}