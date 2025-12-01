#include <iostream>
#include <vector>
#include <string>

using namespace std;

int partition2(vector<int>& v, int low, int high){
    int p = v[high - 1];
    int i = low;
    int j = high -1; 
    while(1){
        while(v[i] < p ) i++;
        while(v[j] > p) j--;

        if (i>=j) return j;

        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void quick_sort(vector<int>& v, int low, int high){
    if (low < high){
        int b = partition2(v, low, high);
        quick_sort(v, 0, b);
        quick_sort(v, b+1, high);
    }
}

int main(){
    vector<int> v={9,8,7,6,5,4,3,2,1};
    quick_sort(v, 0, v.size());

    for (int x:v) cout<< x << " ";
    cout<< endl;
}