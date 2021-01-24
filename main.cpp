#include "./Include/puh.h"

/*
    主函数
    功能：main函数
*/

int main() {
    struct course couArray[COU_MAX]; //课程数组
    struct student stuArray[STU_MAX]; //学生数组
    int stuNum = 0; //学生总数
    int couNum = 0; //课程总数
    int inputNum; //输入序号
    while(1){
        homeShow();
        cin >>inputNum;
        switch (inputNum)
        {
            case 1: //学生信息管理系统
            {
                while(1){
                    stuSystemShow(); //学生信息管理系统菜单函数
                    cin >>inputNum;
                    switch(inputNum)
                    {
                        case 1: //显示学生信息
                        {
                            displayStu(stuArray,&stuNum);
                            break;           
                        }
                        case 2: //增加学生
                        {
                            insertStu(stuArray,&stuNum);
                            break;           
                        }
                        case 3://删除学生
                        {
                            deleteStu(stuArray,&stuNum);
                            break;           
                        }
                        case 4://修改学生
                        {
                            modifyStu(stuArray,&stuNum);
                            break;           
                        }
                        case 5://查询学生
                        {
                            searchStu(stuArray,&stuNum);
                            break;           
                        }
                        case 6://退出
                        {
                            cout <<"退出成功！"<< endl; 
                            break;           
                        }
                        default:
                        {
                            cout <<"输入错误！"<< endl;
                            cin.clear();
                            cin.sync();
                            break;
                        }
                    }
                    if(inputNum == 6) {break;} //退出循环
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 2://课程信息管理系统
            {
                while(1){
                    couSystemShow(); //课程信息管理系统菜单函数
                    cin >>inputNum;
                    switch(inputNum)
                    {
                        case 1: //显示课程信息
                        {
                            displayCou(couArray,&couNum);
                            break;           
                        }
                        case 2: //增加课程
                        {
                            insertCou(couArray,&couNum);
                            break;           
                        }
                        case 3://删除课程
                        {
                            deleteCou(couArray,&couNum);
                            break;           
                        }
                        case 4://修改课程
                        {
                            modifyCou(couArray,&couNum);
                            break;           
                        }
                        case 5://查询课程
                        {
                            searchCou(couArray,&couNum);
                            break;           
                        }
                        case 6://退出
                        {
                            cout <<"退出成功！"<< endl; 
                            break;           
                        }
                        default:
                        {
                            cout <<"输入错误！"<< endl;
                            cin.clear();
                            cin.sync();
                            break;
                        }
                    }
                    if(inputNum == 6){break;} //退出循环
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 3: //选课系统
            {
                while(1){
                    int isExit = 0; 
                    selectCouSystem(); //选课系统
                    cin >>inputNum;
                    switch(inputNum)
                    {
                        case 1: //以学号选课
                        {
                            idSelectCou(stuArray,&stuNum,couArray,&couNum);
                            break;           
                        }
                        case 2: //以姓名选课
                        {
                            nameSelectCou(stuArray,&stuNum,couArray,&couNum);
                            break;           
                        }
                        case 3://退出
                        {
                            cout <<"退出成功！"<< endl;
                            break;           
                        }
                        default:
                        {
                            cout <<"输入错误！"<< endl;
                            cin.clear();
                            cin.sync();
                            break;
                        }
                    }
                    if(inputNum == 3) {break;} //退出循环
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 4:
                break;
            default:
            {
                cout <<"输入错误！"<< endl;
                cin.clear();
                cin.sync();
                break;
            }
        }
        if(inputNum == 4){break;}
        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}