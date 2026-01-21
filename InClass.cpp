/*
This is a simple C++ program that asks the user for the number of elements in a secret sequence
*/

#include <iostream>
using namespace std;

int main() {  //Asks for numbers in the secret sequence
   
    //defining variables
    int n1;
    int n2=++n1;

    //inputs and outputs
    cout<<n1<<" "<<n2<<endl;
   
   
    cout<<"How many Numbers are in the Secret Sequence?"<<endl;
    int n;

    cin >> n;

    //receives the number inputs for the secret sequence
    for(int i=0; i<n; i++)
    {
       
        int code;
       
        cout<<"Enter a Code "<<i+1<<": ";
        cin >> code;
    

       // cout<<"Hello"<<endl;
    }

    return 0;
}