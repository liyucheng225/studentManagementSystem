#include "../Include/puh.h"

/*
    ѧ��ѡ��ϵͳ����
    ���ܣ��ṩѧ��ѡ�ι���
    void nameSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum); //������ѡ��
    void idSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum); //��ѧ��ѡ��
*/

/*��ѧ��ѡ��*/
void idSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum)
{
    long long int stuId; //ѧ��id
    int stuIndex; //ѧ���±�
    int couIndex; //�γ��±�
    int couId; //�γ�id
    cout <<"������ѧ��ѧ��:"<< endl;
    cin >>stuId;
    stuIndex = isStuEmpty(stu,stuNum,stuId);
    if(stuIndex == -1) {
        cout <<"�������ѧ�Ų�����!"<< endl;
        return;
    }
    cout <<"������γ̺�:"<< endl;
    cin >>couId;
    couIndex =isCouEmpty(cou,couNum,couId);
    if(couIndex == -1) {
        cout <<"������Ŀγ̺Ų�����!"<< endl;
        return;
    }
    if(cou[couIndex].cou_stuNum >= cou[couIndex].maxNum){
        cout <<"�ÿγ�����!"<< endl;
        return;
    }
    /*���ÿγ̷����ѧ���Ŀγ�������*/
    stu[stuIndex].stu_cou[stu[stuIndex].stu_couNum] = &cou[couIndex];
    /*��ѧ����ѡ��γ�����1*/
    stu[stuIndex].stu_couNum++; 

    /*����ѧ������ÿγ̵�ѧ��������*/
    cou[couIndex].cou_stu[cou[couIndex].cou_stuNum] = &stu[stuIndex];
    /*�ÿγ̵���ѡ������1*/
    cou[couIndex].cou_stuNum++;
    // cout <<"ѧ��Ϊ"<<stu[stuIndex].id<<"��ѧ��ѡ�γ̺�Ϊ"<<stu[stuIndex].stu_cou[stu[stuIndex].stu_couNum]->id<<"�Ŀγ̳ɹ�!"<< endl;
    cout <<"ѡ�γɹ�!"<< endl;
}
void nameSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum){
    cout <<"������ͬ���Ժ���ʱ����ʵ��"<< endl;
}
