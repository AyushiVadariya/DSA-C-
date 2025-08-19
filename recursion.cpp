#include<iostream>
using namespace std;
void fun(int i, int n){
    if(i>n){
        return ;
    }
    cout << "Ayushi"<< endl;
    fun(i+1, n);
}//Time complexity O(n), Space complexity O(n), using stack space
void print1toN(int N, int i){
    if(N<1){return ;}
        print1toN(N-1,i);
        cout << N<< endl;   
}
void printNto1(int i, int n){
    if(i<1) return;
    cout << i<< endl;
    printNto1(i-1,n);
}
int sum(int n){
    if(n==0) return 0;
    return n+ sum(n-1);
}
int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}

void swaparray(int i, int arr[], int n){
    if(i==n/2) return;
    swap(arr[i], arr[n-1-i]);
    swaparray(i+1, arr, n);
}



int main(){
    int a[6] = {1,2,3,4,5,6};
    swaparray(0,a ,6);
    for(int i=0; i<6; i++)
    cout << a[i]<< endl;
    return 0;
}