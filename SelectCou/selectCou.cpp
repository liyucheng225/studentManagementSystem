#include "../Include/puh.h"

/*
    学生选课系统函数
    功能：提供学生选课功能
    void nameSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum); //以姓名选课
    void idSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum); //以学号选课
*/

/*以学号选课*/
void idSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum)
{
    long long int stuId; //学生id
    int stuIndex; //学生下标
    int couIndex; //课程下标
    int couId; //课程id
    cout <<"请输入学生学号:"<< endl;
    cin >>stuId;
    stuIndex = isStuEmpty(stu,stuNum,stuId);
    if(stuIndex == -1) {
        cout <<"您输入的学号不存在!"<< endl;
        return;
    }
    cout <<"请输入课程号:"<< endl;
    cin >>couId;
    couIndex =isCouEmpty(cou,couNum,couId);
    if(couIndex == -1) {
        cout <<"您输入的课程号不存在!"<< endl;
        return;
    }
    if(cou[couIndex].cou_stuNum >= cou[couIndex].maxNum){
        cout <<"该课程已满!"<< endl;
        return;
    }
    /*将该课程放入该学生的课程数组中*/
    stu[stuIndex].stu_cou[stu[stuIndex].stu_couNum] = &cou[couIndex];
    /*该学生的选择课程数加1*/
    stu[stuIndex].stu_couNum++; 

    /*将该学生放入该课程的学生数组中*/
    cou[couIndex].cou_stu[cou[couIndex].cou_stuNum] = &stu[stuIndex];
    /*该课程的所选人数加1*/
    cou[couIndex].cou_stuNum++;
    // cout <<"学号为"<<stu[stuIndex].id<<"的学生选课程号为"<<stu[stuIndex].stu_cou[stu[stuIndex].stu_couNum]->id<<"的课程成功!"<< endl;
    cout <<"选课成功!"<< endl;
}
void nameSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum){
    cout <<"功能相同，以后有时间再实现"<< endl;
}
