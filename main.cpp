#include "./Include/puh.h"

/*
    主函数
    功能：main函数
*/
int main() {
    struct course couArray[COU_MAX]; //课程数组
    struct student stuArray[STU_MAX]; //学生数组
    int stuNum; //学生总数
    int couNum; //课程总数
    int inputNum; //输入序号
    while(1){
        homeShow();
        cin >>inputNum;
        switch (inputNum)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            return 0;
            break;
        default:
            cout <<"输入错误，请重新输入！"<< endl;
            break;
        }
    }
    system("pause");
    return 0;
}