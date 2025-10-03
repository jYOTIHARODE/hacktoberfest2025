#include<iostream>
using namespace std;
int main(){
    char arr[9] = {'a','b','c','d','e','f','g','h','i'};
    int top = -1;
    int n;
    char alpha[10];
    cout<<"Enter any number : ";
    cin>>n;
    while(n>0){
        top++;
        alpha[top] = arr[n%10];
        n = n/10;
    }
    cout<<"corresponding alphabat is : "<<endl;
    for(int i =top;i>=0;i--){
        cout<<alpha[i];
    }
    return 0;
}
