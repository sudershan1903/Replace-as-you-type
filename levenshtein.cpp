#include<iostream>
#include<string.h>
using namespace std;

int lev(string s1,string s2);
int min(int a,int b, int c)
{
    if(a<=b && b<=c)
        return a;
    if(b<=a && a<=c)
        return b;
    if(c<=b && b<=a)
        return c;
}
int main()
{
    string s1,s2;
    //cout<<"Enter the first word: \n";
    //cin>>s1;
    //cout<<s1;
    s1="adithya";
    //cout<<"Enter the second word: \n";
    //cin>>s2;
    //cout<<s2;
    s2="aditya";
    int x=lev(s1,s2);
    cout<<"The min number of changes needed to make '"<<s1<<"' into '"<<s2<<"' is:"<<x;
}
int lev(string a1,string a2)
{
    int l1=a1.length();
    int l2=a2.length();

    int s1[l1+1];
    int s2[l2+1];

    int A[l1+1][l2+1];


    for(int i=0; i<l1+1 ; i++)
        for(int j=0; j<l2+1 ; j++)
            if(i+j==i || i+j==j)
                A[i][j]=i+j;


    for(int i=l1+1; i>0; i--)
        {
            s1[i]=a1[i-1];
            //cout<<s1[i];
        }
    s1[0]='-';
    for(int i=0;i<l1;i++)
            cout<<s1[i];
            cout<<endl;

    for(int j=l2+1; j>=0; j--)
        {
            s2[j]=a2[j-1];
            //cout<<s2[j];
        }      // cout<<A[i][j]<<endl;
    s2[0]='-';
    for(int j=0;j<l2;j++)
            cout<<s2[j];
            cout<<endl;



    for(int j=1; j<l2+1 ; j++)
        {
            for(int i=1; i<l1+1 ; i++)
            {
                if(s1[i]==s2[j])
                    A[i][j]=A[i-1][j-1];
                else
                    A[i][j]=min(A[i-1][j],A[i-1][j-1],A[i][j-1])+1;
            }
        }
    for(int i=0; i<l1+1 ; i++)
        {
            cout<<endl;
            for(int j=0; j<l2+1 ; j++)
              {
                  cout<<A[i][j]<<"\t";
              }
        }
    int y=A[l1][l2];
    cout<<endl<<y<<endl;
    return y;
}
