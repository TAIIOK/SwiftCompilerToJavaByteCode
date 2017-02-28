%{

    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
	#include <math.h>
	
    char strconst[1281] = {0};
	int convertOctalToDecimal(int octalNumber);
	int convertBinaryToDecimal(int n);
	
%}

%option noyywrap
%option yylineno
%x COMMENT

%%

"/*" {strcat(strconst," "); strcat(strconst,yytext); BEGIN(COMMENT); }
<COMMENT>"*/" {strcat(strconst,yytext); printf("Found multiple line comment "); BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|. {strcat(strconst,yytext);}
<COMMENT><<EOF>> {printf("Unterminated comment\n");return 0;}

"//".*                        printf("Found single line comment \n");

\"([^\\\"]|\\.)*\"            printf("String %s\n",yytext);

"var"						  printf("Found key word \"var\"\n");
"let"						  printf("Found key word \"let\"\n");
"import"					  printf("Found key word \"import\"\n");
"while"                       printf("Found key word \"while\"\n");
"for"                         printf("Found key word \"for\"\n");
"in"						  printf("Found key word \"in\"\n");
"if"                          printf("Found key word \"if\"\n");
"else if"                     printf("Found key word \"else if\"\n");
"else"                        printf("Found key word \"else\"\n");
"do"                          printf("Found key word \"do\"\n");
"..."						  printf("Found range word  \"...\"\n");
"repeat"                      printf("Found key word \"repeat\"\n");
"return"                      printf("Found key word \"return\"\n");
"nil"                         printf("Found key word \"nil\"\n");
"true"                        printf("Found \"true\" constant\n");
"false"                       printf("Found \"false\" constant\n");
"self"                        printf("Found \"self\" (like this pointer)");
"error"                       printf("Found \"error\" call\n");
"print"                       printf("Found \"print\" call\n");
"readLine"					  printf("Found \"readLine\" call\n");
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

"->"                          printf("Found \"function type arrow\"\n");

"||"                          printf("Found \"or\"\n");
"&&"                          printf("Found \"and\"\n");

"=="						  printf("Found \"is equal\"\n");
"Int"						  printf("Found \"Int type\"\n");
"Character"				      printf("Found \"Char type\"\n");
"String"					  printf("Found \"String type\"\n");
"Bool" 						  printf("Found \"Bool type\"\n");
"Float" 				      printf("Found \"Float type\"\n");
"Double" 					  printf("Found \"Double type\"\n");

"switch"					  printf("Found \"switch\" \n");
"case"						  printf("Found \"case\" \n");
"default"					  printf("Found \"default\"\n");
"break"						  printf("Found \"break\"\n");

("!"[a-zA-Z])+[a-zA-Z0-9_]* 	  printf("Found \"not\" %s\"\n",yytext);
"!"    printf("Found \"adduction type\"\n");


"0b"[01]+                 printf("Found binary: %d\n",convertBinaryToDecimal(atoi(yytext+2)));
"0o"[0-7]+                 printf("Found octal: %d\n",convertOctalToDecimal(atoi(yytext+2)));
"0x"[A-F0-9]+                 printf("Found hexadecimal: %ld\n",strtol(yytext,NULL,16));
[+-]?[0-9]+                   printf("Found decimal: %d\n",atoi(yytext));
([_]|[a-zA-Z])+[a-zA-Z0-9_]*  printf("Found identifier: %s\n",yytext);
[+-]?[0-9]+\.[0-9eE-]+        printf("Found double: %f\n",atof(yytext));

<<EOF>>                       { printf("<<END OF FILE>>\n"); return 0; };

[\n\r\t\f\v ]                ;
".*" 						  printf("Bad string %s\n", yytext);
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

int convertOctalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0;

    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }

    i = 1;

    return decimalNumber;
}

int convertBinaryToDecimal(int n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}


