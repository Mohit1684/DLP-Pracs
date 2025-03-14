%{
    int no_of_chars = 0;
    int no_of_words = 0;
    int no_of_lines = 0;
%}

%%
[ \t]+ { ++no_of_words; }
. { ++no_of_chars; }
\n { ++no_of_lines; ++no_of_words; }
end {return 0;}
%%

int main(int argc, char **argv) {
    yylex();
    printf("No of characters: %d\n", no_of_chars);
    printf("No of words: %d\n", no_of_words);
    printf("No of lines: %d\n", no_of_lines);
    return 0;
}

int yywrap() {
    return 1;
}
