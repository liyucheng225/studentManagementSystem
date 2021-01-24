#include "../Include/puh.h"

/*
    �γ���Ϣ����ϵͳ����
    ���ܣ��Կγ���Ϣ����ɾ�Ĳ�
    void diaplayCou(const struct course *cou,const int *couNum); //��ʾ���пγ���Ϣ
    void insertCou(struct course *cou,int *couNum); //���ӿγ�
    void deleteCou(struct course *cou,int *couNum); //ɾ���γ�
    void modifyCou(struct course *cou,int *couNum); //�޸Ŀγ�
    void searchCou(const struct course *cou,const int *couNum); //�鿴�γ�
*/

/*��ʾ�γ���Ϣ*/
void displayCou(const struct course *cou, const int *couNum)
{
    if (*couNum == 0)
    {
        cout << "û�пγ���Ϣ,������ӿγ���Ϣ!" << endl;
        return;
    }
    cout.flags (ios::left);//����Ϊ��������
    cout <<setw(15)<< "�γ̺�"<< setw(20) << "�γ�����" << setw(15) <<"�������" << setw(8) << "ѡ������" << endl;
    for (int i = 0; i < *couNum; i++)
    {
        cout << setw(15) << cou[i].id << setw(20) << cou[i].name << setw(15) << cou[i].maxNum << setw(8) << cou[i].cou_stuNum << endl;
    }
}

/*���ӿγ���Ϣ*/
void insertCou(struct course *cou, int *couNum)
{
    cout << "������γ̺�:" << endl;
    cin >> cou[*couNum].id;
    cout << "������γ���:" << endl;
    cin >> cou[*couNum].name;
    cout << "������ÿγ����ѡ������:" << endl;
    cin >> cou[*couNum].maxNum;
    (*couNum)++;
    cout << "��ӿγ̳ɹ���" << endl;
}

/*ɾ��ѧ����Ϣ*/
void deleteCou(struct course *cou, int *couNum)
{
    int index; //���տγ̵��±�
    int id; //Ҫɾ���γ̵�id
    cout << "������Ҫɾ���Ŀγ̺ţ�" << endl;
    cin >> id;

    /*�жϴ˿γ̺��Ƿ���ڣ������򷵻��±�*/
    index == isCouEmpty(cou, couNum, id);
    if (index == -1)
    {
        cout << "�ÿγ̺Ų����ڣ�" << endl;
        return;
    }

    /*��ѡ��ÿγ̵�ѧ���Ŀγ��б��еĸÿγ��߼���ɾ��*/
    for (int i = 0; i < cou[index].cou_stuNum; i++)
    {
        for(int j=0;j<cou[index].cou_stu[i]->stu_couNum; j++) {
            if(cou[index].cou_stu[i]->stu_cou[j]->id == cou[index].id){
                if(j != cou[index].cou_stu[i]->stu_couNum-1){
                   cou[index].cou_stu[i]->stu_cou[j]=cou[index].cou_stu[i]->stu_cou[j+1];
                }
            }
             cou[index].cou_stu[i]->stu_couNum--;
        }
    }
    /*�߼���ɾ���ÿγ̵�����*/
    for (int i = index; i < *couNum; i++)
    {
        if (i != *couNum - 1)
        {
            cou[i] = cou[i + 1];
        }
    }
    (*couNum)--;
    cout << "ɾ���ɹ���" << endl;
}

/*�޸Ŀγ���Ϣ*/
void modifyCou(struct course *cou, int *couNum)
{
    int index; //���տγ̵��±�
    int id; //Ҫ�޸Ŀγ̵�id
    int inputNum;//�û���������
    cout << "������Ҫ�޸ĵĿγ̺ţ�" << endl;
    cin >> id;

    /*�жϴ˿γ̺��Ƿ���ڣ������򷵻��±�*/
    index = isCouEmpty(cou, couNum, id);
    if (index == -1) {
        cout << "�ÿγ̺Ų����ڣ�" << endl;
        return;
    }
    cout << "������Ҫ�޸����ݵ����(1.�γ̺�,2.�γ���,3.���ѡ������):" << endl;
    cin >> inputNum;
    switch (inputNum)
    {
        case 1:
        {
            cout << "�������µĿγ̺�:" << endl;
            cin >> cou[index].id;
            cout << "�޸Ŀγ̺ųɹ�!" << endl;
            break;
        }
        case 2:
        {
            cout << "�������µĿγ���:" << endl;
            cin >> cou[index].name;
            cout << "�޸Ŀγ����ɹ�!" << endl;
            break;
        }
        case 3:
        {
            cout << "�����������ѡ������:" << endl;
            int num;
            cin >> num;
            if(num < cou[index].cou_stuNum){
                cout <<"��ǰ�ÿγ��Ѿ�ѡ����"<<cou[index].cou_stuNum<<"��"<<"��ʱ�����޸�!" <<endl;
            }else{
                cou[index].maxNum = num;
                cout << "�޸����ѡ�������ɹ�!" << endl;
            }
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
void searchCou(const struct course *cou, const int *couNum)
{
    int index = 0;    //���տγ̵��±�
    long long int id; //ѧ��Ҫ���ҵĿγ�id
    cout << "������Ҫ���ҵĿγ̺ţ�" << endl;
    cin >> id;
    index = isCouEmpty(cou, couNum, id);
    if (index == -1)
    {
        cout << "�ÿγ̺Ų����ڣ�";
        return;
    }
    cout.flags (ios::left);//����Ϊ��������
    cout <<setw(15)<< "�γ̺�"<< setw(20) << "�γ�����" << setw(15) <<"�������" << setw(8) << "ѡ������" << endl;
    cout << setw(15) << cou[index].id << setw(20) << cou[index].name << setw(15) << cou[index].maxNum << setw(8) <<cou[index].cou_stuNum << endl;
}


