#include<iostream>
using namespace std;
void print(int n)
{
    for(int i=0; i<n; i++)
    {
        int inis=0;
        for(int j=1; j<=n-1; j++)
        {
            cout<<"*";
        }
        for(int j=0; j<inis; j++){
            cout<<" ";
        }
        for(int j =1; j<=n-1; j++){
            cout<<"*";
        }
        inis+=2;
        cout<<endl;
    
    }
   
}
int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
       
        print(t);
    }
    return 0;
}