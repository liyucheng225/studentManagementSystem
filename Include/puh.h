#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#define STU_MAX 1000 //学生的最大数量
#define COU_MAX 1000 //课程的最大数量
#define STU_COU 10 //学生最多能选的课程数
#define COU_STU 10 //课程的最多人数
/*这四个宏还得有一定的逻辑关系，不能乱写，否则会错误一大堆，被这个搞烦了*/
using namespace std;

struct student;
/*课程结构体*/
struct course{
    int id; //课程id
    string name; //课程名称
    int cou_stuNum; //选择该门课程的学生人数
    int maxNum; //该课程最多选择的人数
    struct student *cou_stu[STU_COU]; //选该课程的学生
};

/*学生结构体*/
struct student{
    long long int id; //学生学号
    string name; //学生姓名
    int sex; //学生性别
    long long int tel; //学生电话
    struct course *stu_cou[COU_STU]; //学生所选课程
    int stu_couNum; //学生所选课程的数量
};

/*定义菜单函数*/
void homeShow(); //主菜单
void stuSystemShow(); //学生管理系统菜单        
void couSystemShow(); //课程管理系统菜单
void selectCouSystem(); //选课系统菜单

/*学生函数声明*/
void displayStu(const struct student *stu,const int *stuNum); //显示所有学生信息
void insertStu(struct student *stu,int *stuNum); //增加学生
void deleteStu(struct student *stu,int *stuNum); //删除学生
void modifyStu(struct student *stu,int *stuNum); //修改学生
void searchStu(const struct student *stu,const int *stuNum); //查看学生

/*课程函数声明*/
void displayCou(const struct course *cou,const int *couNum); //显示所有课程信息
void insertCou(struct course *cou,int *couNum); //增加课程
void deleteCou(struct course *cou,int *couNum); //删除课程
void modifyCou(struct course *cou,int *couNum); //修改课程
void searchCou(const struct course *cou,const int *couNum); //查看课程

/*选课函数声明*/
void nameSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum); //以姓名选课
void idSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum); //以学号选课

/*工具类函数声明*/
int isCouEmpty(const struct course *cou,const int *couNum,int id); //判断课程是否存在
int isStuEmpty(const struct student *stu,const int *stuNum,long long int id); //判断学生是否存在
string stuSearchCou(const struct student *stu,int index); //返回学生所选课程的id