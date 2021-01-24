#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#define STU_MAX 1000 //ѧ�����������
#define COU_MAX 1000 //�γ̵��������
#define STU_COU 10 //ѧ�������ѡ�Ŀγ���
#define COU_STU 10 //�γ̵��������
/*���ĸ��껹����һ�����߼���ϵ��������д����������һ��ѣ�������㷳��*/
using namespace std;

struct student;
/*�γ̽ṹ��*/
struct course{
    int id; //�γ�id
    string name; //�γ�����
    int cou_stuNum; //ѡ����ſγ̵�ѧ������
    int maxNum; //�ÿγ����ѡ�������
    struct student *cou_stu[STU_COU]; //ѡ�ÿγ̵�ѧ��
};

/*ѧ���ṹ��*/
struct student{
    long long int id; //ѧ��ѧ��
    string name; //ѧ������
    int sex; //ѧ���Ա�
    long long int tel; //ѧ���绰
    struct course *stu_cou[COU_STU]; //ѧ����ѡ�γ�
    int stu_couNum; //ѧ����ѡ�γ̵�����
};

/*����˵�����*/
void homeShow(); //���˵�
void stuSystemShow(); //ѧ������ϵͳ�˵�        
void couSystemShow(); //�γ̹���ϵͳ�˵�
void selectCouSystem(); //ѡ��ϵͳ�˵�

/*ѧ����������*/
void displayStu(const struct student *stu,const int *stuNum); //��ʾ����ѧ����Ϣ
void insertStu(struct student *stu,int *stuNum); //����ѧ��
void deleteStu(struct student *stu,int *stuNum); //ɾ��ѧ��
void modifyStu(struct student *stu,int *stuNum); //�޸�ѧ��
void searchStu(const struct student *stu,const int *stuNum); //�鿴ѧ��

/*�γ̺�������*/
void displayCou(const struct course *cou,const int *couNum); //��ʾ���пγ���Ϣ
void insertCou(struct course *cou,int *couNum); //���ӿγ�
void deleteCou(struct course *cou,int *couNum); //ɾ���γ�
void modifyCou(struct course *cou,int *couNum); //�޸Ŀγ�
void searchCou(const struct course *cou,const int *couNum); //�鿴�γ�

/*ѡ�κ�������*/
void nameSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum); //������ѡ��
void idSelectCou(struct student *stu,int *stuNum,struct course *cou,int *couNum); //��ѧ��ѡ��

/*�����ຯ������*/
int isCouEmpty(const struct course *cou,const int *couNum,int id); //�жϿγ��Ƿ����
int isStuEmpty(const struct student *stu,const int *stuNum,long long int id); //�ж�ѧ���Ƿ����
string stuSearchCou(const struct student *stu,int index); //����ѧ����ѡ�γ̵�id