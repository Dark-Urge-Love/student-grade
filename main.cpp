#include "GradeManager.h"
#include <iostream>
#include <limits>

// 显示主菜单
void displayMenu() {
    std::cout << "\n===== 学生成绩管理系统 =====";
    std::cout << "\n1. 添加学生";
    std::cout << "\n2. 查询学生";
    std::cout << "\n3. 显示成绩单";
    std::cout << "\n4. 删除学生";
    std::cout << "\n5. 修改学生信息";
    std::cout << "\n6. 成绩统计分析";
    std::cout << "\n0. 退出系统";
    std::cout << "\n请选择操作: ";
}

// 添加多个学生
void addStudents(GradeManager& manager) {
    char choice;
    do {
        std::string id, name;
        double daily, exam;

        std::cout << "\n--- 添加学生 ---" << std::endl;
        std::cout << "输入学号: ";
        std::cin >> id;
        std::cout << "输入姓名: ";
        std::cin >> name;
        std::cout << "输入平时成绩: ";
        std::cin >> daily;
        std::cout << "输入考试成绩: ";
        std::cin >> exam;

        manager.addStudent(Student(id, name, daily, exam));
        std::cout << "学生添加成功！" << std::endl;

        std::cout << "继续添加? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    GradeManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        // 清除输入缓冲区
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: // 添加学生
            addStudents(manager);
            break;

        case 2: { // 查询学生
            std::string id;
            std::cout << "输入要查询的学号: ";
            std::cin >> id;

            Student* student = manager.findStudent(id);
            if (student) {
                std::cout << "\n学号        姓名          平时成绩  考试成绩  总评成绩\n";
                std::cout << "------------------------------------------------------\n";
                student->display();
            }
            else {
                std::cout << "未找到该学生！" << std::endl;
            }
            break;
        }

        case 3: // 显示成绩单
            manager.displayAll();
            break;

        case 4: { // 删除学生
            std::string id;
            std::cout << "输入要删除的学号: ";
            std::cin >> id;

            char confirm;
            std::cout << "确定删除? (y/n): ";
            std::cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                if (manager.removeStudent(id)) {
                    std::cout << "删除成功！" << std::endl;
                }
                else {
                    std::cout << "未找到该学生！" << std::endl;
                }
            }
            break;
        }

        case 5: { // 修改学生信息
            std::string id;
            std::cout << "输入要修改的学号: ";
            std::cin >> id;

            if (manager.updateStudent(id)) {
                std::cout << "修改成功！" << std::endl;
            }
            else {
                std::cout << "未找到该学生！" << std::endl;
            }
            break;
        }

        case 6: // 成绩统计
            manager.analyzeScores();
            break;

        case 0: // 退出
            std::cout << "感谢使用，再见！" << std::endl;
            break;

        default:
            std::cout << "无效选择，请重新输入！" << std::endl;
        }
    } while (choice != 0);

    return 0;
}