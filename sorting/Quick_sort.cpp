#include<iostream>
#include<vector>
using namespace std;

// time complexity O(nlogn) in base 2 space complexity O(1)

int partition(vector<int> &arr,int low, int high){
    int pivot = arr[low];
    int i= low; 
    int j= high;
    while(i<j){
        while(arr[i]<= pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low +1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void qs(vector<int> &arr, int low, int high){
    if(low<high){
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex-1);
        qs(arr, pIndex+1, high);
    }
}

int main(){
    vector<int> arr = { 6,2,3,7,2,4,8,12,3,65,41,95,100,23};
    qs(arr, 0, arr.size());
    for(int i=0 ;i<arr.size(); i++){
        cout << arr[i] << endl;
    }
}
