%{
    # include <stdbool.h>
    int length = 0;
    bool lowercase = false, uppercase = false, digit = false, symbols = false;
    bool wrong_input = false;
%}

%%
[0-9] {digit = true; ++length;}
[a-z] {lowercase = true; ++length;}
[A-Z] {uppercase = true; ++length;}
[*|;|#|$|@|,] {symbols = true; ++length;}
. {wrong_input = true; ++length;}
\n return 0;
%%

int yywrap(){}
int main(int argc, char **argv){
    yylex();
    if(wrong_input) {
        printf("Invalid Password");
    }
    else{
        if(length>=9 && length<=15){
            if(lowercase && uppercase && digit && symbols){
                printf("Password is valid");
            }
            else{
                printf("Invalid Password");
            }
        }
        else{
            printf("Invalid Password");
        }
    }
    return 0;
}