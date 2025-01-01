#include<iostream>
#include<string>
using namespace std;

int main()
{
    string A;
    cin>>A;
    int n=A.size();
    int n2=n-2;
    int i=0;
    int c=0;
    int d=0;

    while(i<n2){
        if(A[i]=='a'){
            i++;
            c++;
        }
        else{
            break;
        }

    }

    while(n2<n){
        if(A[n2]=='b'){
            n2++;
            d++;
        }
        else{
            break;
        }

    }

    if(c==n-2 && d==2){
        cout<<"Valid String";
    }
    else{
        cout<<"Invalid String";
    }



    return 0;
}





