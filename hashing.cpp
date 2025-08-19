#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
   /* int n; 
    cin >> n;
    int arr[n];
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }

    int hash[13] = {0};
    for(int i=0; i<n;i++){
        hash[arr[i]] +=1;
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }*/

   /*string s;
    cin >> s;


    int hash[26] = {0};
    for(int i=0;i<s.size(); i++){
        hash[s[i]-'a']++;
    }
    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c-'a'] << endl;
    }*/

    // using map
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    unordered_map<int, int> mpp;
    for(int i=0; i< n; i++){
        //O(1)
        mpp[arr[i]]++;
    }
    
    for(auto it : mpp){
        cout << it.first << "-> " << it.second << endl;
    }
    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }

}