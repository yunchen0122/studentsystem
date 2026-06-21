#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
struct Student {
    string id;
    string name;
    int score;
};
// Template function：通用最大值與最小值
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}
template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}
vector<Student> students;
// 功能1：新增學生資料
void addStudent() {
    string id, name;
    int score;
    cout << "請輸入學號: ";
    cin >> id;
    // 檢查學號是否重複
    for (auto& s : students) {
        if (s.id == id) {
            cout << "學號重複！是否覆蓋原資料？(y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                cout << "請輸入姓名: ";
                cin >> name;
                cout << "請輸入成績: ";
                cin >> score;
                s.name = name;
                s.score = score;
                cout << "資料已覆蓋。" << endl;
            } else {
                cout << "已取消新增。" << endl;
            }
            return;
        }
    }
    cout << "請輸入姓名: ";
    cin >> name;
    cout << "請輸入成績: ";
    cin >> score;
    students.push_back({id, name, score});
    cout << "新增成功！" << endl;
}
// 功能2：列出所有學生
void listStudents() {
    if (students.empty()) {
        cout << "目前尚無學生資料。" << endl;
        return;
    }
    cout << "學號\t姓名\t成績" << endl;
    cout << "----------------------" << endl;
    for (auto& s : students) {
        cout << s.id << "\t" << s.name << "\t" << s.score << endl;
    }
}
// 功能3：依成績排序
void sortByScore() {
    if (students.empty()) {
        cout << "目前尚無學生資料。" << endl;
        return;
    }
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });
    cout << "已依成績由高到低排序完成！" << endl;
    listStudents();
}
// 功能4：查詢學生
void searchById() {
    string id;
    cout << "請輸入要查詢的學號: ";
    cin >> id;
    for (auto& s : students) {
        if (s.id == id) {
            cout << "找到學生資料：" << endl;
            cout << "學號: " << s.id << endl;
            cout << "姓名: " << s.name << endl;
            cout << "成績: " << s.score << endl;
            return;
        }
    }
    cout << "找不到該學號的學生資料。" << endl;
}
// 功能5：統計成績（使用 template function getMax / getMin）
void showStatistics() {
    if (students.empty()) {
        cout << "目前尚無學生資料。" << endl;
        return;
    }
    double sum = 0;
    int highest = students[0].score;
    int lowest = students[0].score;
    int passCount = 0;
    int failCount = 0;
    for (auto& s : students) {
        sum += s.score;
        highest = getMax(highest, s.score);   // 使用 template function
        lowest = getMin(lowest, s.score);      // 使用 template function
        if (s.score >= 60) passCount++;
        else failCount++;
    }
    double average = sum / students.size();
    cout << "全班平均: " << average << endl;
    cout << "最高分: " << highest << endl;
    cout << "最低分: " << lowest << endl;
    cout << "及格人數: " << passCount << endl;
    cout << "不及格人數: " << failCount << endl;
}
// 選單介面
void showMenu() {
    cout << "\n========== 學生成績管理系統 ==========" << endl;
    cout << "1. Add student" << endl;
    cout << "2. List all students" << endl;
    cout << "3. Sort by score" << endl;
    cout << "4. Search by id" << endl;
    cout << "5. Show statistics" << endl;
    cout << "0. Exit" << endl;
    cout << "請選擇功能: ";
}
int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: sortByScore(); break;
            case 4: searchById(); break;
            case 5: showStatistics(); break;
            case 0: cout << "再見！" << endl; break;
            default: cout << "無效選項，請重新輸入。" << endl;
        }

    } while (choice != 0);
    return 0;
}