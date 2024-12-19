/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int number(int N)
{
  return N*(N+1)/2;
}
int main(){
    int N;
    cout<<"Enter positive number(N): ";
    cin>> N;
    if(N>0){
        int result = number(N);
    cout<<"The sum of natural number up to "<<N<<"is: " <<result<<endl;    }
    else{
        cout<<"Enter  positive integer"<<endl;
    }
    return 0;
}