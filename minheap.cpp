#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)
#define pi (2*acos(0.0))
#define debug(x) cerr << (#x) << ' ' << x << endl;

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10;

class MinHeap{
private:
    int* arr;
    int size;
    int capacity;
public:
    MinHeap(int capacity){
        arr = new int[capacity];
        this->size=0;
        this->capacity = capacity;
    }

    int parent(int key) { return (key-1)/2; }
    int left(int key) { 
        return 2*key+1; 
    }
    int right(int key) { 
        return 2*key+2; 
    }

    void insert(int key){
        if(size==capacity) { cout<<"Overflow\n"; return; }

        this->size++;
        int index = size-1;
        arr[index]=key;

        while(index!=0 && arr[parent(index)] > arr[index]){
            swap(arr[parent(index)], arr[index]);
            index = parent(index);
        }
    }

    void decreaseKey(int index, int val){
        arr[index]=val;

         while(index!=0 && arr[parent(index)] > arr[index]){
            swap(arr[parent(index)], arr[index]);
            index = parent(index);
        }
    }


    int extractMin(){
        if(size==0) return INT_MAX;
        if(size==1) { size--; return arr[0]; }

        int root=  arr[0];
        arr[0] = arr[size-1];
        size--;

        minHeapify(0);

        return root;

    }

    void deleteKey(int index){
        decreaseKey(index, INT_MIN);
        extractMin();
    }

    void minHeapify(int index){
        int l = left(index);
        int r = right(index);

        int smallest = index;

        if(l<size && arr[l]< arr[index])
            smallest = l;
        if(r<size && arr[r]<arr[index])
            smallest = r;

        if(smallest != index){
            swap(arr[smallest],arr[index]);
            minHeapify(smallest);
        } 

    }

    void buildHeap(int arr2[]){
        
        for (int i = 0; i < capacity; i++)
        {
            arr[i]=arr2[i];
            debug(arr[i]);
        }
        
        for (int i = (capacity/2)-1; i >= 0 ; i--)
        { 
            minHeapify(i);
        }
        
    }

     void print(){
        debug(size);
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<'\n';
        
    }
    
};

int main(){

    
    int capacity;
    cin >> capacity;
    int arr[capacity]={1,2,3,4,5,8};

    MinHeap a(capacity);
    
    for (int i = 0; i < capacity; ++i)
    {
        a.insert(arr[i]);
    }
    a.print(); // Print the initial heap
}
