#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 100;
struct Student {
    string name;
    string id;
    int age;
    int score;
} student[MAX];

void input_student(int &count) {
    if (count >= MAX) {
        cout << "学生人数已满，无法添加" << endl;
        return;
    }
    cout << "请输入学生信息(姓名 学号 年龄 分数)，输入 end 结束:" << endl;
    while (count < MAX) {
        string name;
        cin >> name;
        if (name == "end") break;
        student[count].name = name;
        cin >> student[count].id >> student[count].age >> student[count].score;
        count++;
    }

}

void output_student(int count) {
    if (count == 0) {
        cout << "没有学生信息" << endl;
        return;
    }
    cout << "学生信息如下：" << endl;
    for (int i = 0; i < count; i++) {
        cout << "姓名:" << student[i].name 
             << " 学号:" << student[i].id 
             << " 年龄:" << student[i].age 
             << " 分数:" << student[i].score
             << endl;
    }
}

void search_by_id(int count) {
    string id;
    cout << "请输入要查找的学生学号：";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (student[i].id == id) {
            cout << "姓名:" << student[i].name 
                 << " 学号:" << student[i].id 
                 << " 年龄:" << student[i].age 
                 << " 分数:" << student[i].score                 
                 << endl;
            return;
        }
    }
    cout << "没有找到该学生信息" << endl;
}

void edit_by_id(int count){
    string id;
    int choice;
    cout<<"请输入学号查找想要修改的信息:"<<endl;
    cin >> id;
    bool found = false; 
    for(int i=0; i < count; i++){
        if(student[i].id == id){
            found = true; 
            cout<<" 1.修改姓名"<<endl;
            cout<<" 2.修改学号"<<endl;
            cout<<" 3.修改年龄"<<endl;            
            cout<<" 4.修改得分"<<endl;
            cout<<"请选择要修改的项目：";
            cin >> choice;
            switch(choice){
                case 1: cout<<"请输入新的姓名：";
                        cin >> student[i].name;break;
                case 2: cout<<"请输入新的学号：";
                        cin >> student[i].id;break;
                case 3: cout<<"请输入新的年龄：";
                        cin >> student[i].age;break;
                case 4: cout<<"请输入新的得分：";
                        cin >> student[i].score;break;
                default: cout<<"无效选项"<<endl;break;                               
        }return;
    }
    }
}

void delete_by_id(int &count) {   
    string id;
    int index = -1;
    cout << "请输入学号查找想要删除的信息:" << endl;
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (student[i].id == id) {
            index = i;   
            break;
        }
    }
    if (index == -1) {
        cout << "想要删除的学生信息不存在" << endl;
        return;
    }
    for (int i = index; i < count - 1; i++) {
        student[i] = student[i + 1];
    }
    count--;   
    cout << "删除成功!" << endl;
}

void sort_by_score(int count) {
    string target_id;
    cout << "请输入要查找的学生学号：" << endl;
    cin >> target_id;
    
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (student[i].id == target_id) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "未找到学号为 " << target_id << " 的学生！" << endl;
        return;
    }

    cout << "找到该学生，开始对全班成绩进行排序..." << endl;
    for (int j = 0; j < count - 1; j++) {
        for (int k = 0; k < count - 1 - j; k++) {
            if (student[k].score > student[k + 1].score) {
                Student temp = student[k];
                student[k] = student[k + 1];
                student[k + 1] = temp;
            }
        }
    }


    int rank = 0;
    for (int i = 0; i < count; i++) {
        if (student[i].id == target_id) {
            rank = i + 1;  // 排名从1开始
            break;
        }
    }

    cout << "排序完毕！" << endl;
    cout << "学号 " << target_id 
         << "，排序后排名：第" << rank << "名（成绩：" << student[rank-1].score << ")" << endl;

    cout << "\n全班成绩排序结果:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "排名" << i+1 << "：学号" << student[i].id << "，成绩" << student[i].score << endl;
    }
}

int main() {
    int count = 0;
    int choice;
    do {
        cout << "\n=== 学生成绩管理系统 ===" << endl;
        cout << "1. 输入学生信息" << endl;
        cout << "2. 输出所有学生" << endl;
        cout << "3. 按学号查找" << endl;
        cout << "4. 按学号修改信息" <<endl;
        cout << "5. 按学号删除信息" <<endl; 
        cout << "6. 按学号排序成绩" <<endl;         
        cout << "0. 退出" << endl;
        cout << "请选择：";
        cin >> choice;

        switch (choice) {
            case 1: input_student(count); break;
            case 2: output_student(count); break;
            case 3: search_by_id(count); break;
            case 4: edit_by_id(count);break;
            case 5: delete_by_id(count);break;
            case 6: sort_by_score(count);break;
            case 0: cout << "再见" << endl; break;
            default: cout << "无效选项，请重新输入" << endl;
        }
    } while (choice != 0);

    return 0;
}