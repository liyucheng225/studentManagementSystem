#include "../Include/puh.h"
/*
    ѧ����Ϣ����ϵͳ
    ���ܣ���ѧ����Ϣ����ɾ�Ĳ�
    void diaplayStu(const struct student *stu,const int *stuNum); //��ʾ����ѧ����Ϣ
    void insertStu(struct student *stu,int *stuNum); //����ѧ��
    void deleteStu(struct student *stu,int *stuNum); //ɾ��ѧ��
    void modifyStu(struct student *stu,int *stuNum); //�޸�ѧ��
    void searchStu(const struct student *stu,const int *stuNum); //�鿴ѧ��
*/
/*��ʾѧ����Ϣ*/
void displayStu(const struct student *stu, const int *stuNum)
{
    if (*stuNum == 0)
    {
        cout << "û��ѧ����Ϣ,�������ѧ����Ϣ!" << endl;
        return;
    }
    string couList; //ѧ���Ŀγ�idƴ���ַ���
    cout.flags (ios::left);//����Ϊ��������
    cout <<setw(15)<< "ѧ��"<<setw(15)<<"����"<<setw(8)<<"�Ա�"<<setw(15)<<"�绰"<<setw(20)<<"��ѡ�γ�"<<setw(5)<<"��ѡ�γ�����" << endl;
    for (int i = 0; i < *stuNum; i++)
    {
        couList = stuSearchCou(stu, i);
        cout <<setw(15)<< stu[i].id <<setw(15)<< stu[i].name << setw(8) << (stu[i].sex == 1 ? "��" : "Ů") << setw(15)
             << stu[i].tel << setw(20) << couList <<  setw(5)<< stu[i].stu_couNum << endl;
    }
}

/*����ѧ����Ϣ*/
void insertStu(struct student *stu, int *stuNum)
{
    cout << "������ѧ��ѧ��:" << endl;
    cin >> stu[*stuNum].id;
    cout << "������ѧ������:" << endl;
    cin >> stu[*stuNum].name;
    cout << "������ѧ���Ա�(1.������2.Ů��):" << endl;
    cin >> stu[*stuNum].sex;
    cout << "������ѧ���绰����:" << endl;
    cin >> stu[*stuNum].tel;
    (*stuNum)++;
    cout << "���ѧ���ɹ���" << endl;
}

/*ɾ��ѧ����Ϣ*/
void deleteStu(struct student *stu, int *stuNum)
{
    int index;        //����ѧ�����±�
    long long int id; //Ҫɾ��ѧ����id
    cout << "������Ҫɾ����ѧ��ѧ�ţ�" << endl;
    cin >> id;

    /*�жϴ�ѧ���Ƿ���ڣ������򷵻��±�*/
    index = isStuEmpty(stu, stuNum, id);
    if (index == -1)
    {
        cout << "��ѧ�Ų����ڣ�" << endl;
        return;
    }
    /*��Ҫɾ��ѧ��ѡ��γ��е�������1*/
    for (int i = 0; i < stu[index].stu_couNum; i++)
    {
        stu[index].stu_cou[i]->cou_stuNum--;
    }
    /*�߼���ɾ����ѧ��������*/
    for (int i = index; i < *stuNum; i++)
    {
        if (i != *stuNum - 1)
        {
             stu[i] = stu[i + 1];
        }
    }
    (*stuNum)--;
    cout << "ɾ���ɹ���" << endl;
}

/*�޸�ѧ����Ϣ*/
void modifyStu(struct student *stu, int *stuNum)
{
    int index;        //����ѧ�����±�
    long long int id; //Ҫ�޸�ѧ����id
    int inputNum;     //�û���������
    cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�" << endl;
    cin >> id;
    cout <<"id=" <<id << endl;

    /*�жϴ�ѧ���Ƿ���ڣ������򷵻��±�*/
    index = isStuEmpty(stu, stuNum, id);
    if (index == -1) {
        cout << "��ѧ�Ų����ڣ�" << endl;
        return;
    }
    cout << "������Ҫ�޸����ݵ����(1.ѧ��,2.����,3.�Ա�,4.�绰):" << endl;
    cin >> inputNum;
    switch (inputNum)
    {
        case 1:
        {
            cout << "�������µ�ѧ��:" << endl;
            cin >> stu[index].id;
            cout << "�޸�ѧ�ųɹ�!" << endl;
            break;
        }
        case 2:
        {
            cout << "�������µ�����:" << endl;
            cin >> stu[index].name;
            cout << "�޸������ɹ�!" << endl;
            break;
        }
        case 3:
        {
            cout << "�������µ��Ա�(1.��,2.Ů):" << endl;
            cin >> stu[index].sex;
            cout << "�޸��Ա�ɹ�!" << endl;
            break;
        }
        case 4:
        {
            cout << "�������µĵ绰����:" << endl;
            cin >> stu[index].tel;
            cout << "�޸ĵ绰�ɹ�!" << endl;
            break;
        }
        default:
        {
            cout << "����������,���ߴ�������ʱ��֧���޸�!" << endl;
            cin.clear();
            cin.sync();
            break;
        }
    }
}

/*��ѯѧ����Ϣ*/
void searchStu(const struct student *stu, const int *stuNum)
{
    int index = 0;    //����ѧ�����±�
    long long int id; //ѧ��Ҫ���ҵ�ѧ��id
    string couList;   //ѧ���Ŀγ��б�
    cout << "������Ҫ���ҵ�ѧ��ѧ�ţ�" << endl;
    cin >> id;
    index = isStuEmpty(stu, stuNum, id);
    if (index == -1)
    {
        cout << "��ѧ�Ų����ڣ�" << endl;
        return;
    }
    couList = stuSearchCou(stu, index);
    cout.flags (ios::left);//����Ϊ��������
    cout <<setw(15)<< "ѧ��"<<setw(15)<<"����"<<setw(8)<<"�Ա�"<<setw(15)<<"�绰"<<setw(20)<<"��ѡ�γ�"<<setw(5)<<"��ѡ�γ�����" << endl;
    cout <<setw(15)<< stu[index].id <<setw(15)<< stu[index].name << setw(8) << (stu[index].sex == 1 ? "��" : "Ů") 
         << setw(15)<< stu[index].tel << setw(20) << couList <<  setw(5)<< stu[index].stu_couNum << endl;
}

/*����ѧ����ѡ�γ̵�id��ƴ���ַ���*/
string stuSearchCou(const struct student *stu, int index)
{
    stringstream ss;
    for (int i = 0; i < stu[index].stu_couNum; i++)
    {
        ss << stu[index].stu_cou[i]->id;
        if (i != stu[index].stu_couNum - 1)
        {
            ss << " ";
        }
    }
    return ss.str();
}

