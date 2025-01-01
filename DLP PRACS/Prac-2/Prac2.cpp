#include<iostream>
#include<string>

using namespace std;

int main()
{
    int A[] = {1,2,3,4};
    int i=0;
    int f=0;
    int c=0;
    string S;
    cout<<"Enter the Initial State: ";
    cin>>i;
    cout<<"Enter the Final State: ";
    cin>>f;
    cout<<"Enter the String: ";
    cin>>S;
    int n=S.size();

    if(S[0]=='a'){
        c=A[1];
    }
    else if(S[0]=='b'){
        c=A[2];
    }

    else if(S[1]=='a'){
        c=A[0];
    }
    else if(S[1]=='b'){
        c=A[3];
    }

    else if(S[2]=='a'){
        c=A[3];
    }
    else if(S[2]=='b'){
        c=A[0];
    }

    else if(S[3]=='a'){
        c=A[2];
    }
    else if(S[3]=='b'){
        c=A[1];
    }

    if(c==f){
        cout<<"Valid String";
    }
    else{
        cout<<"Invalid String";
    }



    return 0;
}


/*
1 to a = 2
1 to b = 3
2 to a = 1
2 to b = 4
3 to a = 4
3 to b = 1
4 to a = 3
4 to b = 2
  a    b    b    a    b    a    b
(1-2)(2-4)(4-2)(2-1)(1-3)(3-4)(4-2)
*/


