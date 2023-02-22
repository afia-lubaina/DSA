# DSA

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int main(){

	cin>>n ; 
	Stack<double>st;
	double x;

	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		st.push(x);
	}

	cout<<st.isempty()<<"\n";
	cout<<st.isfull()<<"\n";

	st.print();
	st.pop(); 
	st.peek();
	cout<<st.size()<<"\n";

}
