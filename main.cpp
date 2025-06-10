#include "GradeManager.h"
#include <iostream>
#include <limits>

// 显示主菜单
void displayMenu() {
    cout << "\n===== 学生成绩管理系统 =====";
    cout << "\n1. 添加学生";
    cout << "\n2. 查询学生";
    cout << "\n3. 显示成绩单";
    cout << "\n4. 删除学生";
    cout << "\n5. 修改学生信息";
    cout << "\n6. 成绩统计分析";
    cout << "\n0. 退出系统";
    cout << "\n请选择操作: ";
}

// 添加多个学生
void addStudents(GradeManager& manager) {
    char choice;
    do {
        string id, name;
        double daily, exam;

        cout << "\n--- 添加学生 ---" << endl;
        cout << "输入学号: ";
        cin >> id;
        cout << "输入姓名: ";
        cin >> name;
        cout << "输入平时成绩: ";
        cin >> daily;
        cout << "输入考试成绩: ";
        cin >> exam;

        manager.addStudent(Student(id, name, daily, exam));
        cout << "学生添加成功！" << endl;

        cout << "继续添加? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    GradeManager manager;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: // 添加学生
            addStudents(manager);
            break;

        case 2: { // 查询学生
            string id;
            cout << "输入要查询的学号: ";
            cin >> id;

            Student* student = manager.findStudent(id);
            if (student) {
                cout << "\n学号        姓名          平时成绩  考试成绩  总评成绩\n";
                cout << "------------------------------------------------------\n";
                student->display();
            }
            else {
                cout << "未找到该学生！" << endl;
            }
            break;
        }

        case 3: // 显示成绩单
            manager.displayAll();
            break;

        case 4: { // 删除学生
            string id;
            cout << "输入要删除的学号: ";
            cin >> id;

            char confirm;
            cout << "确定删除? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                if (manager.removeStudent(id)) {
                    cout << "删除成功！" << endl;
                }
                else {
                    cout << "未找到该学生！" << endl;
                }
            }
            break;
        }

        case 5: { // 修改学生信息
            string id;
            cout << "输入要修改的学号: ";
            cin >> id;

            if (manager.updateStudent(id)) {
                cout << "修改成功！" << endl;
            }
            else {
                cout << "未找到该学生！" << endl;
            }
            break;
        }

        case 6: // 成绩统计
            manager.analyzeScores();
            break;

        case 0: // 退出
            cout << "感谢使用，再见！" << endl;
            break;

        default:
            cout << "无效选择，请重新输入！" << endl;
        }
    } while (choice != 0);

    return 0;
}