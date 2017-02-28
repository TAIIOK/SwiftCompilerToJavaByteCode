%{

    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>

    char strconst[1281] = {0};

%}

%option noyywrap
%option yylineno
%x COMMENT

%%

"/*" {strcat(strconst," "); strcat(strconst,yytext); BEGIN(COMMENT); }
<COMMENT>"*/" {strcat(strconst,yytext); printf("Found multiple line comment %s",strconst); BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|. {strcat(strconst,yytext);}
<COMMENT><<EOF>> {printf("Unterminated comment\n");return 0;}

"//".*                        printf("Found single line comment %s\n",yytext);

\"([^\\\"]|\\.)*\"            printf("String %s\n",yytext);

"var"						  printf("Found \"var\"\n");
"let"						  printf("Found \"let\"\n");
"import"					  printf("Found \"import\"\n");
"while"                       printf("Found \"while\"\n");
"for"                         printf("Found \"for\"\n");
"in"						  printf("Found \"in\"\n");
"if"                          printf("Found \"if\"\n");
"else if"                     printf("Found \"else if\"\n");
"else"                        printf("Found \"else\"\n");
"do"                          printf("Found \"do\"\n");
"..."						  printf("Found \"...\"\n");
"repeat"                      printf("Found \"repeat\"\n");
"return"                      printf("Found \"return\"\n");
"nil"                         printf("Found \"nil\"\n");
"true"                        printf("Found \"true\" constant\n");
"false"                       printf("Found \"false\" constant\n");
"self"                        printf("Found \"self\" (like this pointer)");
"error"                       printf("Found \"error\" call\n");
"print"                       printf("Found \"print\" call\n");
"local"                       printf("Found \"local\" (variable declaration)\n");
"func"                        printf("Found \"function\" (function declaration)\n");
">"                           printf("Found \">\"\n");
"<"                           printf("Found \"<\"\n");
"-"                           printf("Found \"-\"\n");
"\*"                          printf("Found \"*\"\n");
"/"                           printf("Found \"/\"\n");
"%"                           printf("Found \"%\"\n");
"=="                          printf("Found \"==\"\n");
">="                          printf("Found \"=>\"\n");
"<="                          printf("Found \"<=\"\n");
"="                           printf("Found \"=\"\n");
","                           printf("Found \",\"\n");
"+"                           printf("Found \"+\"\n");
"."                           printf("Found \".\"\n");
"("                           printf("Found \"(\"\n");
")"                           printf("Found \")\"\n");
"{"                           printf("Found \"{\"\n");
"}"                           printf("Found \"}\"\n");
"["                           printf("Found \"[\"\n");
"]"                           printf("Found \"]\"\n");
";"                           printf("Found \";\"\n");
"\n"						  printf("Found \"find new line symbol\"\n");
":"                           printf("Found \":\"\n");

"->"                           printf("Found \"function type arrow\"\n");


"||"                           printf("Found \"or\"\n");
"&&"                           printf("Found \"&&\"\n");

"Int"						  printf("Found \"Int type\"\n");
"Character"				      printf("Found \"Char type\"\n");
"String"					  printf("Found \"String type\"\n");
"Bool" 						  printf("Found \"Bool type\"\n");
"Float" 				      printf("Found \"Float type\"\n");
"Double" 					  printf("Found \"Double type\"\n");

"switch"						  printf("Found \"switch\" \n");
"case"						  printf("Found \"case\" \n");
"default"						  printf("Found \"default\"\n");
"break"						  printf("Found \"break\"\n");

"0x"[A-F0-9]+                 printf("Found hexadecimal: %ld\n",strtol(yytext,NULL,16));
[+-]?[0-9]+                   printf("Found decimal: %d\n",atoi(yytext));
([_]|[a-zA-Z])+[a-zA-Z0-9_]*     printf("Found identifier: %s\n",yytext);
[+-]?[0-9]+\.[0-9eE-]+        printf("Found double: %f\n",atof(yytext));

<<EOF>>                       { printf("<<END OF FILE>>\n"); return 0; }
%%
int main(int argc,char* argv[])
{
    if (argc > 1) 
    {
        yyin = fopen(argv[1], "r");
        yylex();
    }
    return 0;
}


