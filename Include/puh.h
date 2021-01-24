#include <iostream>
#include <string>
#define STU_MAX 1000  //ѧ�����������
#define COU_MAX 100 //�γ̵��������
#define STU_COU 5 //ѧ��ѡ�ε������
#define COU_STU 10 //�γ�����ѧ������
using namespace std;

/*ѧ���ṹ��*/
struct student{
    long long int id; //ѧ��ѧ��
    string name; //ѧ������
    int sex; //ѧ���Ա�
    long long int tel; //ѧ���绰
    struct course stu_cou[STU_COU]; //ѧ����ѡ�γ�
    int stu_cou_num; //ѧ����ѡ�γ̵�����
};

/*�γ̽ṹ��*/
struct course{
    int id; //�γ�id
    string name; //�γ�����
    int cou_stu_num; //ѡ����ſγ̵�ѧ������
    struct student cou_stu[COU_STU]; //ѡ����ſγ̵�ѧ��
};

void homeShow(); //���˵�

/*ѧ����������*/
void diaplayStu(const struct stuednt stu,const int stuNum); //��ʾ����ѧ����Ϣ
void insertStu(struct stuednt stu,int stuNum); //����ѧ��
void deleteStu(struct stuednt stu,int stuNum); //ɾ��ѧ��
void modifyStu(struct stuednt stu,int stuNum); //�޸�ѧ��
void searchStu(const struct stuednt stu,const int stuNum); //�鿴ѧ��

/*�γ̺�������*/
void diaplayCou(const struct course cou,const int couNum); //��ʾ���пγ���Ϣ
void insertCou(struct course cou,int couNum); //���ӿγ�
void deleteCou(struct course cou,int couNum); //ɾ���γ�
void modifyCou(struct course cou,int couNum); //�޸Ŀγ�
void searchCou(const struct course cou,const int couNum); //�鿴�γ�

/*ѡ�κ�������*/
void nameSelectCou(struct stuednt stu,int stuNum,struct course cou,int couNum); //������ѡ��
void idSelectCou(struct stuednt stu,int stuNum,struct course cou,int couNum); //��ѧ��ѡ��

/*�����ຯ������*/
void isCouEmpty(const struct course cou,const int couNum); //�жϿγ��Ƿ����
void isStuEmpty(const struct stuednt stu,const int stuNum); //�ж�ѧ���Ƿ����