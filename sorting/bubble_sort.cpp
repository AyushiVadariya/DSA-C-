#include<iostream>
using namespace std;
// time complexity O(n^2)  best O(n)
void bubble_sort(int arr[], int n){
    for(int i= n-1; i>=0; i--){
        int didswap =0;
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
                didswap =1;
            }
        }
        if(didswap==0){
            break;
        }
        cout << "runs" << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }
    bubble_sort(arr, n);
    for(int i=0; i< n;i++){
        cout << arr[i] << endl;
    }
}