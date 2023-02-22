#include <bits/stdc++.h>
using namespace std;
vector<int> v;


void merge(vector<int> &a, int l, int mid, int r) {
 
    int l_sz=mid-l+1;
    int L[l_sz+1];
    int r_sz=r-mid;
    int R[r_sz+1];
    for (int i = 0; i < l_sz; ++i)
    {
        L[i]=a[i+l];
    }
    for (int i = 0; i < r_sz; ++i)
    {
        R[i]=a[i+mid+1];
    }
    L[l_sz]=R[r_sz]=INT_MAX;
    int l_i=0;
    int r_i=0;

    for (int i = l; i <= r; ++i)
    {
        if(L[l_i]<=R[r_i]){
            a[i]=L[l_i];
            l_i++;
        }
        else 
        {
            a[i]=R[r_i];
            r_i++;
        }
    }
}




void mergeSort(vector<int> &a, int l,int r){

    int mid=(l+r)/2;
    if(l==r) return;
   
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,mid,r);
}



void solve(int m, int n, vector<vector<int>> &arr) {


    for(int i = m - 1; i >= 0; i--) {
        for(int j = i, k = 0; j < m && k < n; j++, k++) {
            v.push_back(arr[j][k]);
           // cout<<j<<" "<<k<<"\n";
           
        }

        mergeSort(v, 0, v.size() - 1);
        int c = 0;
        for(int j = i, k = 0; j < m && k < n; j++, k++) {
            arr[j][k] = v[c];
            c++;
        }
        v.clear();
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0, k = i; j < m && k < n; j++, k++) {
            v.push_back(arr[j][k]);
        }
        mergeSort(v, 0, v.size() - 1);
        int c= 0;
        for(int j = 0, k = i; j < m && k < n; j++, k++) {
            arr[j][k] = v[c];
            c++;
        }
        v.clear();
    }
}

int main() {


    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    
    solve(m, n, arr);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}
