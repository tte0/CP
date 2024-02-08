/*
MIT License

Copyright (c) 2024 tte0 (teomana,teoata17)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <bits/stdc++.h>
#define int int_fast64_t
#define ff first
#define ss second
#define endl '\n'
#define spc ' '
#define pb push_back
#define N (200005)
#define MOD (int(1e9)+7)
#define MOD2 (998244353)
#define MODL (int(1e9)+21)
#define INF (int(4e18))
#define e2(x) (1LL<<(x))
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x*y)/gcd(x,y))
#define smrt(i) (double(sqrt(8*(i)+1)-1)/2)
#define ssum(x) ((x)*((x)+1)/2)
#define isint(x) (ceil((x))==floor((x)))
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define cendl cout<<endl
#define mset(x,y) memset(x,y,sizeof(x))
#define sort(x) sort(all(x));
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<fixed<<setprecision(2)
using namespace std;
typedef long long ll;
typedef long double ldouble;
typedef string str;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<pair<char,int>> vci;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<char> stc;
typedef set<str> sts;
typedef multiset<int> msti;
typedef multiset<char> mstc;
typedef multiset<str> msts;
/////////////////////////////////////////////////////////////
int n,m,k,t,q,x,y,ans;
double bubble_time,selection_time,insertion_time,merge_time,merge_it_time,quick_time,heap_time,radix_time,gcc_time;

inline void bubble_sort(int n,vi v){
    clock_t start=clock();

    for(int i=1;i<n;i++){
        bool ok=true;
        for(int j=0;j<n-i;j++){
            if(v[j]>v[j+1]){
                ok&=0;
                swap(v[j],v[j+1]);
            }
        }
        if(ok)break;
    }

    clock_t end=clock();
    bubble_time+=(double(start-end))/(double(CLOCKS_PER_SEC)/1000.0);
}

inline void selection_sort(int n,vi v){
    clock_t start=clock();

    for(int i=n-1;i>0;i--){
        int mx=0;
        for(int j=1;j<=i;j++){
            if(v[mx]<v[j])mx=j;
        }
        swap(v[mx],v[i]);
    }

    clock_t end=clock();
    selection_time+=(double(start-end))/(double(CLOCKS_PER_SEC)/1000.0);
}

inline void insertion_sort(int n,vi v){
    clock_t start=clock();

    for(int i=1;i<n;i++){
        for(int j=i;j>0 && v[j-1]>v[j];j--)swap(v[j-1],v[j]);
    }

    clock_t end=clock();
    insertion_time+=(double(start-end))/(double(CLOCKS_PER_SEC)/1000.0);
}

inline void r_merge(vi& arr, int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}
inline void recursiveMergeSort(vi& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    recursiveMergeSort(arr, left, mid);
    recursiveMergeSort(arr, mid + 1, right);
    int leftArr[mid - left + 1], rightArr[right - mid];
    for (int i = 0; i <= mid - left; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < right - mid; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    r_merge(arr, leftArr, mid - left + 1, rightArr, right - mid);
}
inline void merge_sort(int n,vi v){
    clock_t start=clock();
    recursiveMergeSort(v,0,n-1);
    clock_t end=clock();
    merge_time+=(double(start-end))/(double(CLOCKS_PER_SEC)/1000.0);
}

inline void merge(vi& arr, int l, int m, int r){
    int i, j, k, n1 = m - l + 1, n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)L[i] = arr[l + i];
    for (j = 0; j < n2; j++)R[j] = arr[m + 1+ j];
    i = j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
inline void merge_sort_it(int n,vi arr){
    clock_t start=clock();

    for (int curr_size=1; curr_size<=n-1; curr_size = 2*curr_size){
        for (int left_start=0; left_start<n-1; left_start += 2*curr_size){
            int mid = min(left_start + curr_size - 1, n-1);
            int right_end = min(left_start + 2*curr_size - 1, n-1);
            merge(arr, left_start, mid, right_end);
        }
    }

    clock_t end=clock();
    merge_it_time+=(double(start-end))/(double(CLOCKS_PER_SEC)/1000.0);
}

inline int partition(vi& arr, int start, int end){
    int pivot = arr[start],count = 0;
    for (int i = start + 1; i <= end; i++)if (arr[i] <= pivot)count++;
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot)i++;
        while (arr[j] > pivot)j--;
        if (i < pivotIndex && j > pivotIndex)swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}
inline void recursivequickSort(vi& arr, int start, int end){
    if (start >= end)return;
    int p = partition(arr, start, end);
    recursivequickSort(arr, start, p - 1);
    recursivequickSort(arr, p + 1, end);
}
inline void quick_sort(int n,vi v){
    clock_t start=clock();
    recursivequickSort(v,0,n-1);
    clock_t end=clock();
    quick_time+=(double(start-end))/(double(CLOCKS_PER_SEC)/1000.0);
}

inline void heap_sort(int n,vi v){
    clock_t start=clock();

    make_heap(v.begin(), v.end());
    sort_heap(v.begin(), v.end());

    clock_t end=clock();
    heap_time+=(double(start-end))/(double(CLOCKS_PER_SEC)/1000.0);
}

inline void countSort(vi& arr, int n, int exp){
    int output[n],i, count[10] = { 0 };
    for (i = 0; i < n; i++)count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)arr[i] = output[i];
}
inline void radix_sort(int n,vi arr){
    clock_t start=clock();

    int m = *max_element(all(arr));
    for (int exp = 1; m / exp > 0; exp *= 10)countSort(arr, n, exp);

    clock_t end=clock();
    radix_time+=(double(start-end))/(double(CLOCKS_PER_SEC)/1000.0);
}

inline void gcc_sort(int n,vi v){
    clock_t start=clock();
    sort(v);
    clock_t end=clock();
    gcc_time+=(double(start-end))/(double(CLOCKS_PER_SEC)/1000.0);
}

int32_t main(void){
    srand(time(NULL));
    fastio;
    cin>>t>>n;
    int a=t;
    while(t--){
        cerr<<t<<endl;
        vi v(n);

        for(int i=0;i<n;i++)v[i]=RAND_MAX-i*(RAND_MAX/n);

        bubble_sort(n,v);
        selection_sort(n,v);
        insertion_sort(n,v);
        merge_sort(n,v);
        merge_sort_it(n,v);
        quick_sort(n,v);
        heap_sort(n,v);
        radix_sort(n,v);
        gcc_sort(n,v);
    }

    cout<<"Bubble Sort: "<<bubble_time/a<<"ms\n";
    cout<<"Selection Sort: "<<selection_time/a<<"ms\n";
    cout<<"Insertion Sort: "<<insertion_time/a<<"ms\n";
    cout<<"Merge Sort: "<<merge_time/a<<"ms\n";
    cout<<"Merge Sort (it): "<<merge_it_time/a<<"ms\n";
    cout<<"Quick Sort: "<<quick_time/a<<"ms\n";
    cout<<"Heap Sort: "<<heap_time/a<<"ms\n";
    cout<<"Radix Sort: "<<radix_time/a<<"ms\n";
    cout<<"GCC Sort: "<<gcc_time/a<<"ms\n";
}
