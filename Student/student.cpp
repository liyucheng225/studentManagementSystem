#include "../Include/puh.h"
/*
    学生信息管理系统
    功能：对学生信息的增删改查
    void diaplayStu(const struct student *stu,const int *stuNum); //显示所有学生信息
    void insertStu(struct student *stu,int *stuNum); //增加学生
    void deleteStu(struct student *stu,int *stuNum); //删除学生
    void modifyStu(struct student *stu,int *stuNum); //修改学生
    void searchStu(const struct student *stu,const int *stuNum); //查看学生
*/
/*显示学生信息*/
void displayStu(const struct student *stu, const int *stuNum)
{
    if (*stuNum == 0)
    {
        cout << "没有学生信息,请先添加学生信息!" << endl;
        return;
    }
    string couList; //学生的课程id拼接字符串
    cout.flags (ios::left);//设置为左对齐输出
    cout <<setw(15)<< "学号"<<setw(15)<<"姓名"<<setw(8)<<"性别"<<setw(15)<<"电话"<<setw(20)<<"已选课程"<<setw(5)<<"已选课程总数" << endl;
    for (int i = 0; i < *stuNum; i++)
    {
        couList = stuSearchCou(stu, i);
        cout <<setw(15)<< stu[i].id <<setw(15)<< stu[i].name << setw(8) << (stu[i].sex == 1 ? "男" : "女") << setw(15)
             << stu[i].tel << setw(20) << couList <<  setw(5)<< stu[i].stu_couNum << endl;
    }
}

/*增加学生信息*/
void insertStu(struct student *stu, int *stuNum)
{
    cout << "请输入学生学号:" << endl;
    cin >> stu[*stuNum].id;
    cout << "请输入学生姓名:" << endl;
    cin >> stu[*stuNum].name;
    cout << "请输入学生性别(1.男生，2.女生):" << endl;
    cin >> stu[*stuNum].sex;
    cout << "请输入学生电话号码:" << endl;
    cin >> stu[*stuNum].tel;
    (*stuNum)++;
    cout << "添加学生成功！" << endl;
}

/*删除学生信息*/
void deleteStu(struct student *stu, int *stuNum)
{
    int index;        //接收学生的下标
    long long int id; //要删除学生的id
    cout << "请输入要删除的学生学号：" << endl;
    cin >> id;

    /*判断此学号是否存在，存在则返回下标*/
    index = isStuEmpty(stu, stuNum, id);
    if (index == -1)
    {
        cout << "该学号不存在！" << endl;
        return;
    }
    /*将要删除学生选择课程中的人数减1*/
    for (int i = 0; i < stu[index].stu_couNum; i++)
    {
        stu[index].stu_cou[i]->cou_stuNum--;
    }
    /*逻辑上删除该学生的数据*/
    for (int i = index; i < *stuNum; i++)
    {
        if (i != *stuNum - 1)
        {
             stu[i] = stu[i + 1];
        }
    }
    (*stuNum)--;
    cout << "删除成功！" << endl;
}

/*修改学生信息*/
void modifyStu(struct student *stu, int *stuNum)
{
    int index;        //接收学生的下标
    long long int id; //要修改学生的id
    int inputNum;     //用户输入的序号
    cout << "请输入要修改的学生学号：" << endl;
    cin >> id;
    cout <<"id=" <<id << endl;

    /*判断此学号是否存在，存在则返回下标*/
    index = isStuEmpty(stu, stuNum, id);
    if (index == -1) {
        cout << "该学号不存在！" << endl;
        return;
    }
    cout << "请输入要修改内容的序号(1.学号,2.姓名,3.性别,4.电话):" << endl;
    cin >> inputNum;
    switch (inputNum)
    {
        case 1:
        {
            cout << "请输入新的学号:" << endl;
            cin >> stu[index].id;
            cout << "修改学号成功!" << endl;
            break;
        }
        case 2:
        {
            cout << "请输入新的姓名:" << endl;
            cin >> stu[index].name;
            cout << "修改姓名成功!" << endl;
            break;
        }
        case 3:
        {
            cout << "请输入新的性别(1.男,2.女):" << endl;
            cin >> stu[index].sex;
            cout << "修改性别成功!" << endl;
            break;
        }
        case 4:
        {
            cout << "请输入新的电话号码:" << endl;
            cin >> stu[index].tel;
            cout << "修改电话成功!" << endl;
            break;
        }
        default:
        {
            cout << "您输入有误,或者此内容暂时不支持修改!" << endl;
            cin.clear();
            cin.sync();
            break;
        }
    }
}

/*查询学生信息*/
void searchStu(const struct student *stu, const int *stuNum)
{
    int index = 0;    //接收学生的下标
    long long int id; //学生要查找的学生id
    string couList;   //学生的课程列表
    cout << "请输入要查找的学生学号：" << endl;
    cin >> id;
    index = isStuEmpty(stu, stuNum, id);
    if (index == -1)
    {
        cout << "该学号不存在！" << endl;
        return;
    }
    couList = stuSearchCou(stu, index);
    cout.flags (ios::left);//设置为左对齐输出
    cout <<setw(15)<< "学号"<<setw(15)<<"姓名"<<setw(8)<<"性别"<<setw(15)<<"电话"<<setw(20)<<"已选课程"<<setw(5)<<"已选课程总数" << endl;
    cout <<setw(15)<< stu[index].id <<setw(15)<< stu[index].name << setw(8) << (stu[index].sex == 1 ? "男" : "女") 
         << setw(15)<< stu[index].tel << setw(20) << couList <<  setw(5)<< stu[index].stu_couNum << endl;
}

/*返回学生所选课程的id的拼接字符串*/
string stuSearchCou(const struct student *stu, int index)
{
    stringstream ss;
    for (int i = 0; i < stu[index].stu_couNum; i++)
    {
        ss << stu[index].stu_cou[i]->id;
        if (i != stu[index].stu_couNum - 1)
        {
            ss << " ";
        }
    }
    return ss.str();
}

