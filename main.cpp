#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int a[10][10];
int b[10][10][10];
int minx,miny;
int ff = 0;
int fff = 0;
void print(int x[10][10])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int getxx(int t)
{
    int xx;
    if (t == 1)
    {
        xx = 0;
    }
    if (t == 2)
    {
        xx = 3;
    }
    if (t == 3)
    {
        xx = 6;
    }
    if (t == 4)
    {
        xx = 0;
    }
    if (t == 5)
    {
        xx = 3;
    }
    if (t == 6)
    {
        xx = 6;
    }
    if (t == 7)
    {
        xx = 0;
    }
    if (t == 8)
    {
        xx = 3;
    }
    if (t == 9)
    {
        xx = 6;
    }
    return xx;
}
int getyy(int t)
{
    int yy;
    if (t == 1)
    {
        yy = 0;
    }
    if (t == 2)
    {
        yy = 0;
    }
    if (t == 3)
    {
        yy = 0;
    }
    if (t == 4)
    {
        yy = 3;
    }
    if (t == 5)
    {
        yy = 3;
    }
    if (t == 6)
    {
        yy = 3;
    }
    if (t == 7)
    {
        yy = 6;
    }
    if (t == 8)
    {
        yy = 6;
    }
    if (t == 9)
    {
        yy = 6;
    }
    return yy;
}
bool test (int x,int y, int t,int xx[10][10])
{
    for (int i = 0; i < 9; i++) {
        if ((i != x) && (xx[i][y] == t))
        {
            return false;
        }
        if ((i != y) && (xx[x][i] == t))
        {
            return false;
        }

    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((((i+(x/3)*3) != x) && ((j+(y/3)*3) != y)) && (xx[i+(x/3)*3][j+(y/3)*3] == t))
            {
                return false;
            }
        }
    }
    return true;
}
int finishtest(int x[10][10])
{
    int s1,s2;
    s1 = 1;
    s2 = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (b[i][j][0] != 0)
            {
                s1 = 0;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (x[i][j] == 0)
            {
                s2 = 0;
            }
        }
    }
    if (s1 == 0)
    {
        if (s2 == 0)
        {
            return 1;
        }
    }
    else
    {
        if (s2 == 0)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}
void region(int xxx[10][10],int t)
{
    int xx,yy;
    xx = getxx(t);
    yy = getyy(t);
    for (int l = 1; l < 10; ++l) {
        int sum=0;
        int aa,bb;
        aa = 0;
        bb = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (b[i+xx][j+yy][l] == 1)
                {
                    aa = i;
                    bb = j;
                }
                sum += b[i+xx][j+yy][l];
            }
        }
        if ((sum == 1) && (test(aa+xx,bb+yy,l,xxx)))
        {
            xxx[aa+xx][bb+yy] = l;
            b[aa+xx][bb+yy][l] = 0;
            b[aa+xx][bb+yy][0]--;
        }
    }
}
void rowandcol(int xxx[10][10],int t)
{
    int aar,bbr,aac,bbc;
    int sumrow;
    int sumcol;
    for (int i = 0; i < 9; ++i) {
        sumcol = 0;
        sumrow = 0;
        aar = 0;
        bbr = 0;
        aac = 0;
        bbc = 0;
        for (int j = 0; j < 9; ++j) {
            if (b[i][j][t] == 1)
            {
                aar = i;
                bbr = j;
            }
            if (b[j][i][t] == 1)
            {
                aac = j;
                bbc = i;
            }
            sumrow += b[i][j][t];
            sumcol += b[j][i][t];
        }
        if ((sumcol == 1)&&(test(aac,bbc,t,xxx)))
        {
            xxx[aac][bbc] = t;
            b[aac][bbc][t] = 0;
            b[aac][bbc][0]--;
        }
        if ((sumrow == 1)&&(test(aar,bbr,t,xxx)))
        {
            xxx[aar][bbr] = t;
            b[aar][bbr][t] = 0;
            b[aar][bbr][0]--;
        }
    }
}
void fill(int x[10][10])
{
    int f = 0;
    int xx[10][10];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            xx[i][j] = x[i][j];
            for (int k = 0; k < 10; ++k) {
                b[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (xx[i][j] == 0)
            {
                for (int k = 1; k < 10; ++k) {
                    if (test(i,j,k,xx))
                    {
                        b[i][j][0]++;
                        b[i][j][k] = 1;
                    }
                }
                if (b[i][j][0] == 1)
                {
                    int t = 0;
                    for (int k = 1 ; k < 10; ++k) {
                        if (b[i][j][k] == 1) {t = k;break;}
                    }
                    xx[i][j] = t;
                    b[i][j][0]=0;
                    b[i][j][t]=0;
                }
            }
        }
    }

    for (int i = 1; i < 10; ++i) {
        region(xx,i);
    }
    for (int i = 1; i < 10; ++i) {
        rowandcol(xx,i);
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (xx[i][j] == 0)
            {
                f = 1;
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (xx[i][j] != x[i][j])
            {
                f = 1;
            }
            else{
                f = 2;
            }
        }
    }

    if (f == 1) {fill(xx);}
    else if ((f == 2)&&(ff < 10))
    {
        ff++;
        fill(xx);
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            x[i][j] = xx[i][j];
        }
    }
}
void dfs(int x[10][10])
{
    int minb = 20;
    int xx,yy;
    xx = 0;
    yy = 0;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if ((b[i][j][0]<minb)&&(b[i][j][0]>0))
            {
                minb = b[i][j][0];
                xx = i;
                yy = j;
            }
        }
    }
    for (int i = 1; i < 10; ++i)
    {
        if (fff == 1)
        {
           // cout<<1<<endl;
            if (b[xx][yy][i] == 1)
            {
                int backupb[10][10][10];
                for ( int l = 0; l < 9; ++l )
                {
                    for ( int j = 0; j < 9; ++j )
                    {
                        for ( int k = 0; k < 10; ++k )
                        {
                            backupb[l][j][k] = b[l][j][k];
                        }
                    }
                }
                b[xx][yy][i] = 0;
                b[xx][yy][0]--;
                int backup[10][10];
                for ( int l = 0; l < 9; ++l )
                {
                    for ( int j = 0; j < 9; ++j )
                    {
                        backup[l][j] = x[l][j];
                    }
                }
                x[xx][yy] = i;
                ff = 0;
                fill (x);
                int state = finishtest (x);
                if (state == 3)
                {
                    print (x);
                    fff = 0;
                }
                else
                {
                    if (state == 1)
                    {
                        dfs (x);
                    }
                    for ( int l = 0; l < 9; ++l )
                    {
                        for ( int j = 0; j < 9; ++j )
                        {
                            x[l][j] = backup[l][j];
                        }
                    }
                    for ( int l = 0; l < 9; ++l )
                    {
                        for ( int j = 0; j < 9; ++j )
                        {
                            for ( int k = 0; k < 10; ++k )
                            {
                                b[l][j][k] = backupb[l][j][k];
                            }
                        }
                    }
                }

            }
        }
    }
}
int main() {
    freopen("/Users/sny/ClionProjects/sudoku_solve/1.in","r",stdin);
    freopen("/Users/sny/ClionProjects/sudoku_solve/1.out","w",stdout);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin>>a[i][j];
        }
    }
    ff = 0;
    fill(a);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
           // cout<<a[i][j]<<" ";
            if (b[i][j][0] !=0)
            {
                fff = 1;
            }
        }
    }
   // cout<<fff<<endl;
   // print(a);
    if (fff == 1)
    {
        dfs(a);
    }
    else
    {
        print(a);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
