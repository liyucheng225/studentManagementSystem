#include "./Include/puh.h"

/*
    ������
    ���ܣ�main����
*/

int main() {
    struct course couArray[COU_MAX]; //�γ�����
    struct student stuArray[STU_MAX]; //ѧ������
    int stuNum = 0; //ѧ������
    int couNum = 0; //�γ�����
    int inputNum; //�������
    while(1){
        homeShow();
        cin >>inputNum;
        switch (inputNum)
        {
            case 1: //ѧ����Ϣ����ϵͳ
            {
                while(1){
                    stuSystemShow(); //ѧ����Ϣ����ϵͳ�˵�����
                    cin >>inputNum;
                    switch(inputNum)
                    {
                        case 1: //��ʾѧ����Ϣ
                        {
                            displayStu(stuArray,&stuNum);
                            break;           
                        }
                        case 2: //����ѧ��
                        {
                            insertStu(stuArray,&stuNum);
                            break;           
                        }
                        case 3://ɾ��ѧ��
                        {
                            deleteStu(stuArray,&stuNum);
                            break;           
                        }
                        case 4://�޸�ѧ��
                        {
                            modifyStu(stuArray,&stuNum);
                            break;           
                        }
                        case 5://��ѯѧ��
                        {
                            searchStu(stuArray,&stuNum);
                            break;           
                        }
                        case 6://�˳�
                        {
                            cout <<"�˳��ɹ���"<< endl; 
                            break;           
                        }
                        default:
                        {
                            cout <<"�������"<< endl;
                            cin.clear();
                            cin.sync();
                            break;
                        }
                    }
                    if(inputNum == 6) {break;} //�˳�ѭ��
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 2://�γ���Ϣ����ϵͳ
            {
                while(1){
                    couSystemShow(); //�γ���Ϣ����ϵͳ�˵�����
                    cin >>inputNum;
                    switch(inputNum)
                    {
                        case 1: //��ʾ�γ���Ϣ
                        {
                            displayCou(couArray,&couNum);
                            break;           
                        }
                        case 2: //���ӿγ�
                        {
                            insertCou(couArray,&couNum);
                            break;           
                        }
                        case 3://ɾ���γ�
                        {
                            deleteCou(couArray,&couNum);
                            break;           
                        }
                        case 4://�޸Ŀγ�
                        {
                            modifyCou(couArray,&couNum);
                            break;           
                        }
                        case 5://��ѯ�γ�
                        {
                            searchCou(couArray,&couNum);
                            break;           
                        }
                        case 6://�˳�
                        {
                            cout <<"�˳��ɹ���"<< endl; 
                            break;           
                        }
                        default:
                        {
                            cout <<"�������"<< endl;
                            cin.clear();
                            cin.sync();
                            break;
                        }
                    }
                    if(inputNum == 6){break;} //�˳�ѭ��
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 3: //ѡ��ϵͳ
            {
                while(1){
                    int isExit = 0; 
                    selectCouSystem(); //ѡ��ϵͳ
                    cin >>inputNum;
                    switch(inputNum)
                    {
                        case 1: //��ѧ��ѡ��
                        {
                            idSelectCou(stuArray,&stuNum,couArray,&couNum);
                            break;           
                        }
                        case 2: //������ѡ��
                        {
                            nameSelectCou(stuArray,&stuNum,couArray,&couNum);
                            break;           
                        }
                        case 3://�˳�
                        {
                            cout <<"�˳��ɹ���"<< endl;
                            break;           
                        }
                        default:
                        {
                            cout <<"�������"<< endl;
                            cin.clear();
                            cin.sync();
                            break;
                        }
                    }
                    if(inputNum == 3) {break;} //�˳�ѭ��
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 4:
                break;
            default:
            {
                cout <<"�������"<< endl;
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