%%
charusat {printf("university");}
. {printf("%s",yytext);}
\n {return 0;}
%%

int yywrap(){}
int main(int argc, char **argv){
    yylex();
    return 0;
}