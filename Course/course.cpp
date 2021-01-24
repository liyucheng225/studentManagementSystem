#include "../Include/puh.h"

/*
    课程信息管理系统函数
    功能：对课程信息的增删改查
    void diaplayCou(const struct course *cou,const int *couNum); //显示所有课程信息
    void insertCou(struct course *cou,int *couNum); //增加课程
    void deleteCou(struct course *cou,int *couNum); //删除课程
    void modifyCou(struct course *cou,int *couNum); //修改课程
    void searchCou(const struct course *cou,const int *couNum); //查看课程
*/

/*显示课程信息*/
void displayCou(const struct course *cou, const int *couNum)
{
    if (*couNum == 0)
    {
        cout << "没有课程信息,请先添加课程信息!" << endl;
        return;
    }
    cout.flags (ios::left);//设置为左对齐输出
    cout <<setw(15)<< "课程号"<< setw(20) << "课程名名" << setw(15) <<"最多人数" << setw(8) << "选择人数" << endl;
    for (int i = 0; i < *couNum; i++)
    {
        cout << setw(15) << cou[i].id << setw(20) << cou[i].name << setw(15) << cou[i].maxNum << setw(8) << cou[i].cou_stuNum << endl;
    }
}

/*增加课程信息*/
void insertCou(struct course *cou, int *couNum)
{
    cout << "请输入课程号:" << endl;
    cin >> cou[*couNum].id;
    cout << "请输入课程名:" << endl;
    cin >> cou[*couNum].name;
    cout << "请输入该课程最多选择人数:" << endl;
    cin >> cou[*couNum].maxNum;
    (*couNum)++;
    cout << "添加课程成功！" << endl;
}

/*删除学生信息*/
void deleteCou(struct course *cou, int *couNum)
{
    int index; //接收课程的下标
    int id; //要删除课程的id
    cout << "请输入要删除的课程号：" << endl;
    cin >> id;

    /*判断此课程号是否存在，存在则返回下标*/
    index == isCouEmpty(cou, couNum, id);
    if (index == -1)
    {
        cout << "该课程号不存在！" << endl;
        return;
    }

    /*将选择该课程的学生的课程列表中的该课程逻辑上删除*/
    for (int i = 0; i < cou[index].cou_stuNum; i++)
    {
        for(int j=0;j<cou[index].cou_stu[i]->stu_couNum; j++) {
            if(cou[index].cou_stu[i]->stu_cou[j]->id == cou[index].id){
                if(j != cou[index].cou_stu[i]->stu_couNum-1){
                   cou[index].cou_stu[i]->stu_cou[j]=cou[index].cou_stu[i]->stu_cou[j+1];
                }
            }
             cou[index].cou_stu[i]->stu_couNum--;
        }
    }
    /*逻辑上删除该课程的数据*/
    for (int i = index; i < *couNum; i++)
    {
        if (i != *couNum - 1)
        {
            cou[i] = cou[i + 1];
        }
    }
    (*couNum)--;
    cout << "删除成功！" << endl;
}

/*修改课程信息*/
void modifyCou(struct course *cou, int *couNum)
{
    int index; //接收课程的下标
    int id; //要修改课程的id
    int inputNum;//用户输入的序号
    cout << "请输入要修改的课程号：" << endl;
    cin >> id;

    /*判断此课程号是否存在，存在则返回下标*/
    index = isCouEmpty(cou, couNum, id);
    if (index == -1) {
        cout << "该课程号不存在！" << endl;
        return;
    }
    cout << "请输入要修改内容的序号(1.课程号,2.课程名,3.最大选择人数):" << endl;
    cin >> inputNum;
    switch (inputNum)
    {
        case 1:
        {
            cout << "请输入新的课程号:" << endl;
            cin >> cou[index].id;
            cout << "修改课程号成功!" << endl;
            break;
        }
        case 2:
        {
            cout << "请输入新的课程名:" << endl;
            cin >> cou[index].name;
            cout << "修改课程名成功!" << endl;
            break;
        }
        case 3:
        {
            cout << "请输入新最大选择人数:" << endl;
            int num;
            cin >> num;
            if(num < cou[index].cou_stuNum){
                cout <<"当前该课程已经选择了"<<cou[index].cou_stuNum<<"人"<<"暂时不能修改!" <<endl;
            }else{
                cou[index].maxNum = num;
                cout << "修改最大选择人数成功!" << endl;
            }
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
void searchCou(const struct course *cou, const int *couNum)
{
    int index = 0;    //接收课程的下标
    long long int id; //学生要查找的课程id
    cout << "请输入要查找的课程号：" << endl;
    cin >> id;
    index = isCouEmpty(cou, couNum, id);
    if (index == -1)
    {
        cout << "该课程号不存在！";
        return;
    }
    cout.flags (ios::left);//设置为左对齐输出
    cout <<setw(15)<< "课程号"<< setw(20) << "课程名名" << setw(15) <<"最多人数" << setw(8) << "选择人数" << endl;
    cout << setw(15) << cou[index].id << setw(20) << cou[index].name << setw(15) << cou[index].maxNum << setw(8) <<cou[index].cou_stuNum << endl;
}


