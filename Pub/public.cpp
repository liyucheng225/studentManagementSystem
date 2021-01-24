#include "../Include/puh.h"

/*判断学生是否存在*/
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

/*判断课程是否存在*/
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

