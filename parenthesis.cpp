# DSA
#include<bits/stdc++.h>

using namespace std;


const int N=1e5;
int n ; 

template <class T>
class Stack 
{   
  public:

    T a[N];
    int top=-1;

    void push(T x){

        if(top==N-1)
            cout<<"Stack full"<<"\n";
        else 
          {
            top++; 
            a[top]=x;
          }
    }

    void pop(){

        if(top==-1)
            cout<<"Stack empty"<<"\n";
        else 
        {
            a[top]='\0';
            top--;

        }
    }

    void peek(){

        if(top==-1)
            {cout<<"Stack empty"<<"\n";
            
            }
        else
        {
            cout<<a[top]<<"\n";
        }

    }

    void print(){

        if(top==-1)
            cout<<"Stack empty"<<"\n";

        else{

        for (int i = 0; i <=top; ++i)
        {
            cout<<a[i]<<" ";
        }

        cout<<"\n";
        }
    }

    int size(){
        return top+1;
    }

    bool isempty(){
        if(top==-1)
            return 1; 
        else 
            return 0;
    }

    bool isfull(){
        if(top==n-1)
            return 1;
        else 
            return 0;
    }


    
};


bool ispair(char op, char close){

    if(op=='(' && close==')') return true;
    else if(op=='{' && close=='}') return true;
    else if(op=='[' && close==']') return true;
    return false;
}


bool isok(string s){
 
    stack<char>st;

    for (int i = 0; i < s.size(); ++i)
     {
        if(s[i]=='{' ||s[i]=='(' ||s[i]=='[' )
           st.push(s[i]);
        else if(s[i]=='}' ||s[i]==')' ||s[i]==']' )
        {
           if(st.empty() || !ispair(st.top(),s[i]))
              return false;
           else 
              st.pop();
        }
        
     }

  if(st.empty())
    return true;
  else 
    return false;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t; 
    cin>>t;
    string null;
    getline(cin,null);
    while(t--){

    string s;
    getline(cin,s);
    if (s.size()==0)
      cout<<"Yes\n";
    else if(isok(s))
      cout<<"Yes\n";
    else 
      cout<<"No\n";
    }
  return 0;
}
