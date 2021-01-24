#include <iostream>
#include <string>
#define STU_MAX 1000  //学生的最大数量
#define COU_MAX 100 //课程的最大数量
#define STU_COU 5 //学生选课的最大数
#define COU_STU 10 //课程最多的学生人数
using namespace std;

/*学生结构体*/
struct student{
    long long int id; //学生学号
    string name; //学生姓名
    int sex; //学生性别
    long long int tel; //学生电话
    struct course stu_cou[STU_COU]; //学生所选课程
    int stu_cou_num; //学生所选课程的数量
};

/*课程结构体*/
struct course{
    int id; //课程id
    string name; //课程名称
    int cou_stu_num; //选择该门课程的学生人数
    struct student cou_stu[COU_STU]; //选择该门课程的学生
};

void homeShow(); //主菜单

/*学生函数声明*/
void diaplayStu(const struct stuednt stu,const int stuNum); //显示所有学生信息
void insertStu(struct stuednt stu,int stuNum); //增加学生
void deleteStu(struct stuednt stu,int stuNum); //删除学生
void modifyStu(struct stuednt stu,int stuNum); //修改学生
void searchStu(const struct stuednt stu,const int stuNum); //查看学生

/*课程函数声明*/
void diaplayCou(const struct course cou,const int couNum); //显示所有课程信息
void insertCou(struct course cou,int couNum); //增加课程
void deleteCou(struct course cou,int couNum); //删除课程
void modifyCou(struct course cou,int couNum); //修改课程
void searchCou(const struct course cou,const int couNum); //查看课程

/*选课函数声明*/
void nameSelectCou(struct stuednt stu,int stuNum,struct course cou,int couNum); //以姓名选课
void idSelectCou(struct stuednt stu,int stuNum,struct course cou,int couNum); //以学号选课

/*工具类函数声明*/
void isCouEmpty(const struct course cou,const int couNum); //判断课程是否存在
void isStuEmpty(const struct stuednt stu,const int stuNum); //判断学生是否存在