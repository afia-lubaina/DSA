#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first;
#define ss second;
#define debug(x) cerr << (#x) << ' ' << x << endl;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
const int N=1e6+5;

    int freq[N];

class priorityQueue{

    private:
    int* arr;
    int size;
    int capacity;

    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i+1);}
    int right(int i){return (2*i+2);}

    void maxHeapify(int index){
        int l=left(index);
        int r=right(index);
        int largest=index;
      //  debug(index);

        if(l<size && arr[largest]<arr[l])
            largest=l;
        if(r<size && arr[largest]<arr[r])
            largest=r;
        if( largest!=index)
            {
                swap(arr[largest],arr[index]);
                maxHeapify(largest);
            }
    }


    public:

    priorityQueue() {
        
         this->capacity=N;
         size=0;
         arr =new int[N];
    }

    priorityQueue(int capacity) {
         this->capacity=capacity;
         size=0;
         arr =new int[capacity];
    }

    void push(int key){

        if(size==capacity)return;
        size++;
        arr[size-1]=key;
        debug(arr[size-1]);
        
        int index=size-1; 
        while(index!=0 && arr[parent(index)]<arr[index]){
            swap(arr[parent(index)],arr[index]);
            index=parent(index);
        }
    }

    void pop(){

        if(size==0)return;
        debug(arr[0]);
        arr[0]=arr[size-1];
        size--;
        maxHeapify(0);

    }

    int top(){
        return arr[0];
    }


};



int main() {

    priorityQueue pq;

    // int n; cin>>n; 
    int n=4;
    int arr[n]={1,2,3,4};
   
  //  int arr[n];

    for(int i=0; i<n; i++) {
     //   cin>>arr[i];
        freq[arr[i]]++;
        pq.push(arr[i]);
    }
    int k ; cin>>k;
    solve(pq,k,n);
}
