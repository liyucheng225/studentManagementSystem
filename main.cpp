#include "./Include/puh.h"

/*
    ������
    ���ܣ�main����
*/
int main() {
    struct course couArray[COU_MAX]; //�γ�����
    struct student stuArray[STU_MAX]; //ѧ������
    int stuNum; //ѧ������
    int couNum; //�γ�����
    int inputNum; //�������
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
            cout <<"����������������룡"<< endl;
            break;
        }
    }
    system("pause");
    return 0;
}