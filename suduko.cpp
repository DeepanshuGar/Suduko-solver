#include <iostream>
#include <math.h>
using namespace std;

bool canPlace(int suduko[100][100],int i,int j,int n,int number)
{
    for(int x=0;x<n;x++)
    {
        if(suduko[x][j]==number || suduko[i][x]==number)
        {
            return false;
        }
    }
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int m=sx;m<sx+rn;m++)
    {
        for(int n=sy;n<sy+rn;n++)
        {
            if(suduko[m][n]==number)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSuduko(int suduko[100][100],int i,int j,int n)
{
    //base case
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<suduko[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //end of coloumn
    if(j==n)
    {
        return solveSuduko(suduko,i+1,0,n);
    }
    //already filled part
    if(suduko[i][j]!=0)
    {
        return solveSuduko(suduko,i,j+1,n);
    }
    for(int number = 1;number<=n;number++)
    {
        if(canPlace(suduko,i,j,n,number))
        {
            suduko[i][j] = number;
            bool solveFurther = solveSuduko(suduko,i,j+1,n);
            if(solveFurther==true)
            {
                return true;
            }
        }
    }
    suduko[i][j] = 0;
    return false;
}

int main()
{
    int n;
    cin>>n;
    int suduko[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>suduko[i][j];
        }
    }                 
    solveSuduko(suduko,0,0,n); 
    return 0;
}
