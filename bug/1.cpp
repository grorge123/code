#include <stdio.h>
void print(const int data[], int size)
{
    for (int i=0; i<size; i+=1)
        printf("%d ", data[i]);
}
void print(const int (*data)[3], int row)
{
    for (int i=0; i<row; i+=1)
    {
        print(data[i], 3);
        printf("\n");
    }
}
void print(const int (*data)[2], int row)
{
    for (int i=0; i<row; i+=1)
    {
        print(data[i], 2);
        printf("\n");
    }
}
int main()
{
    int a[2][3] = {}, b[4][2] = {};
    for (int i=0; i<2; i+=1)
    {
        for (int j=0; j<3; j+=1)
        {
            scanf("%d", &a[i][j]);
        }
    }
    print(a,2);
    for (int i=0; i<4; i+=1)
    {
        for (int j=0; j<2; j+=1)
        {
            scanf("%d", &b[i][j]);
        }
    }
    print(b,4);
    return 0;
}
