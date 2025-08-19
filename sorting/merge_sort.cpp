#include<iostream>
#include<vector>
using namespace std;

// time complexity O(n*log n base2)space complexity O(n)

void merge(vector<int> &arr,int low, int mid, int high){
    vector<int> temp;
    // low to mid
    // mid+1 to high
    int left = low; 
    int right = mid+1;
    while(left<=mid && right<= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<= high; i++){
        arr[i] = temp[i-low];
    }
}
void merge_sort(vector<int> &arr, int low, int high){
    if(low==high) return;
    int mid =(low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid , high);
}

int main(){
    vector<int> arr = {3,6,1,9,12,56,21,4,7,6,3,1};
    merge_sort(arr, 0, arr.size() -1 );
    cout << "sorted array :" << endl;

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
}