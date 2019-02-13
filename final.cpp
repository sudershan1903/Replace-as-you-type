#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define size 27
typedef struct trie* trieptr;
struct trie
{
    string letter[size];
    trieptr ptr[size-1];
};
struct trie* getnode()
{
    trieptr node=new trie;
    for(int i=0;i<size-1;i++)
     {
        node->letter[i]="\0";
        node->ptr[i]=NULL;
     }
     return node;
};
void insert(string word,trieptr root)
{
   // struct trie* node;
    string extra;
    int i=0,index;
    while(i!=word.length())
    {
        index=word[i]-'a';
        if(root->letter[index]=="\0"&&root->ptr[index]==NULL)
        {
            root->letter[index]=word;
         //   cout<<"Word Inserted!!\t\t\t"<<word<<endl;
            break;
        }
        else if(root->ptr[index]==NULL)
        {
            extra=root->letter[index];

            root->letter[index]="\0";
            root->ptr[index]=getnode();
            root=root->ptr[index];
         //   cout<<i<<"\t\t\t"<<extra<<endl;
            if(i+1==extra.length())
                root->letter[size-1]=extra;
            else
                root->letter[int(extra[i+1]-'a')]=extra;
            i++;
        }
        else
        {
            root=root->ptr[index];
            i++;
        }
    }
}
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
            //cout<<s1[i];
          //  cout<<endl;

    for(int j=l2+1; j>=0; j--)
        {
            s2[j]=a2[j-1];
            //cout<<s2[j];
        }      // cout<<A[i][j]<<endl;
    s2[0]='-';
    for(int j=0;j<l2;j++)
            //cout<<s2[j];
          //  cout<<endl;



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
          //  cout<<endl;
            for(int j=0; j<l2+1 ; j++)
              {
                //  cout<<A[i][j]<<"\t";
              }
        }
    int y=A[l1][l2];
 //   cout<<endl<<y<<endl;
    return y;
}
int check(trieptr,int,string);
void extra(trieptr node,int i,string word);
int opt=0,a,b;
string choice[35];
void traversal(trieptr root,string word)
{
    int len=word.length(),i=0;
    trieptr node=root;
    int ctr=1;
    char ch;
    trieptr ptrs[2];
    int k=0;
    string *keys;
    while(i<=len)
    {
            if(node->letter[size-1]==word)
            {
                    cout<<"\nSpace";
                    ctr=0;
                    break;
            }
        if(ctr)
        {
        int index=word[i]-'a';
        if(node->ptr[index]!=NULL)
        {
            if(k<2)
                ptrs[k++]=node->ptr[index];
            else
            {
                ptrs[0]=ptrs[1];
                ptrs[1]=node->ptr[index];
            }
            node=node->ptr[index];
            i++;
        }
        else if(node->letter[index]==word)
            {
               // cout<<"Here!!";
                ctr=0;
                break;
            }
        else
            {
                    int k1=0,k2=0,k3;
                    if(k>0)
                    k1=check(ptrs[0],i,word);
                //cout<<endl<<endl;
                    if(k>1)
                    k2=check(ptrs[1],i,word);
                  //  cout<<index<<endl<<ptrs[1]->letter[24];
                 //    k3=
                    extra(ptrs[0],i,word);
                    extra(ptrs[1],i,word);
                    cout<<a++<<")"<<"Insert word";
                    if(!k1&&!k2)
                    {
                        cout<<"\nWord does not exist.\nWant to insert?";
                        cin>>ch;
                        if(ch=='y')
                        insert(word,root);
                    }
                    else
                    {
                        cout<<"\nEnter option:";
                        cin>>opt;
                    }
                break;
            }

        }
          //cout<<i<<endl;
    }
    if(ctr==0)
        cout<<"\nWord exists!!"<<endl;
}
int check(trieptr node,int i,string word)
{
    int k=0;
    for(int j=0;j<size;j++)
        if(j!=i&&((lev(word,node->letter[j])==1)||(lev(word,node->letter[j])==2))&&node->letter[j]!="\0")
            {
                cout<<a++<<")"<<node->letter[j]<<"\t";
                choice[b++]=node->letter[j];
                k=1;
            }
            return k;
}
void extra(trieptr node,int i,string word)
{
    int k=-1;
    trieptr trav;
    while(k<26)
    {
        k++;
        trav=node->ptr[k];
        //if(k!=i)
        if(trav==NULL)
            continue;

            for(int j=0;j<size;j++)
                if(((lev(word,trav->letter[j])==1)||(lev(word,trav->letter[j])==2))&&trav->letter[j]!="\0")
                {
                    cout<<a++<<")"<<trav->letter[j]<<"\t";
                    choice[b++]=trav->letter[j];
                    //k=1;
                    //cout<<endl<<k<<" "<<j<<"\t";
                }
    }
}
int main()
{
    string content;
    ifstream file("dict.txt");
    int k,n=0;
    trieptr root = getnode();
    while(file>>content)
    {
        k=0;
        for(int j=0;j<content.length();j++)
            if(isupper(content[j]))
                content[j]+=32;
            else if(!isalpha(content[j]))
                {
                    k=1;
                    break;
                }
        if(!k)
        {
            //n++;
           // cout<<"main\t\t\t"<<content<<endl;
            insert(content,root);
        }
    }
    string word=" ",s,t;
    for(int i=0;;i++)
    {
        cin>>word;
        if(word==".")
            break;
        a=1;
        b=0;
        opt=0;
        traversal(root,word);
        if(opt!=0&&opt!=a-1)
            word=choice[opt-1];
        if(opt==a-1)
        {
            cout<<word;
            insert(word,root);
            //cout<<"inserted";
        }
        if(!i)
        {
            //s=new char[strlen(x)+1];
            //strcpy(s,x);
            s=word;
        }
        else
        {
            //t=new char[strlen(s)+1];
            //strcpy(t,s);
            t=s;
            if(word!=".")
            t=t+" ";
            //s=new char[strlen(x)+strlen(t)+1];
            //strcpy(s,t);
            s=t;
            //strcat(s,x);
            s=s+word;
        }
        system("cls");
        cout<<s;
    }
   // cout<<"Done";
   return 0;
}
