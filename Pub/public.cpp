#include "../Include/puh.h"

/*�ж�ѧ���Ƿ����*/
int isStuEmpty(const struct student *stu, const int *stuNum, long long int id)
{
    for (int i = 0; i < *stuNum; i++)
    {
        if (stu[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

/*�жϿγ��Ƿ����*/
int isCouEmpty(const struct course *cou, const int *couNum, int id)
{
    for (int i = 0; i < *couNum; i++)
    {
        if (cou[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

