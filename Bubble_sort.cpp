#include <iostream>
using namespace std;

void print_ouput(int* a, int len){
        for (int i=0; i<len;i++){
            cout << a[i];
            
        }
    }

int main(){
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    int len = sizeof(a)/sizeof(a[0]);
    int count=0;
    int temp=0;
    for(int i=0; i< len-1; i++){
        for (int j=0; j<len-1-i; j++){
            if (a[j]>a[j+1]){
                 temp = a[j+1];
                 a[j+1] = a[j];
                 a[j] = temp;
                 count++;
            }        
        }
    }

    print_ouput(a,len);
    printf("\n");
    cout<< "count:" << count << endl;
    
    double d= 0.5*(10 * (10-1));        
    cout<< "d:" << d << endl;
    return 0;
}

