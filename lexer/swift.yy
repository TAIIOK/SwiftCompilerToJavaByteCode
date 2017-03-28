%{

    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
	  #include <math.h>

    #include "swift.tab.h"

    /*
    #include "semantic_tables.h"
    #include "codegen.h"
    */
    #include "tree_print.h"

    #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

    char strconst[1281] = {0};
	  int convertOctalToDecimal(int octalNumber);
	  int convertBinaryToDecimal(int n);

    extern int yyparse(void);
    extern void update_tree_stmtlist(NStmtList* list,NStmtList* root);
    extern void update_tree_parent_func(struct NStmtList* root);
%}

%option noyywrap
%option yylineno

%x COMMENT
%x STRING
%%

"/*"                          {BEGIN(COMMENT); }
<COMMENT>"*/"                 {BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|.         {}
<COMMENT><<EOF>>              {printf("Unterminated comment\n");return 0;}

"//".*                        ;

\"                            { BEGIN(STRING); strcpy(strconst, ""); }
<STRING>\\                    strcat(strconst, "\\");
<STRING>\\\"                  strcat(strconst, "\"");
<STRING>\\r                   strcat(strconst, "\r");
<STRING>\\t                   strcat(strconst, "\t");
<STRING>\\n                   strcat(strconst, "\n");
<STRING>\\\\                  strcat(strconst, "\\");
<STRING>[^\\\n\"]+            strcat(strconst,yytext);

<STRING>\"                    {
								              yylval.String = (char *)malloc(strlen(strconst) + 1);
                              strcpy(yylval.String, strconst);
                              BEGIN(INITIAL);
                              return STRING;
                              }
<STRING>\\\(([^\)]*)\)        {
                              yylval.Id = (char *)malloc(sizeof(yytext)+1);
                              strcpy(yylval.Id, yytext);
                              return ID;
                              }
<STRING>.|[\n\r\f\t\v]        ;


"import"					            return IMPORT;

"var"						              return VAR;
"let"						              return LET;

"Int"						              return INTT;
"Character"				            return CHARACTERT;
"String"					            return STRINGT;
"Bool" 						            return BOOLT;
"Float" 				              return FLOATT;
"Double" 					            return DOUBLET;

"true"                        return TRUE;
"false"                       return FALSE;

"repeat"                      return REPEAT;
"while"                       return WHILE;

"for"                         return FOR;
"in"						              return IN;

"if"                          return IF;
"else if"                     return ELSEIF;
"else"                        return ELSE;

"switch"					            return SWITCH;
"case"						            return CASE;
"default"					            return DEFAULT;
"break"						            return BREAK;


"func"                        return FUNCTION;
"->"                          return FUNCTIONARROW;

"do"                          return DO;
"..."						              return RANGE;

"return"                      return RETURN;
"nil"                         return NIL;

"."                           return '.';
"self"                        return SELF;
"error"                       return ERROR;

"-"                           return '-';
"\*"                          return '*';
"/"                           return '/';
"%"                           return '%';
"+"                           return '+';
"="                           return '=';

">"                           return '>';
"<"                           return '<';
"=="                          return EQ;
">="                          return GE;
"<="                          return LE;
"!="                          return NE;

","                           return ',';

"("                           return '(';
")"                           return ')';
"{"                           return '{';
"}"                           return '}';
"["                           return '[';
"]"                           return ']';
":"                           return ':';

";"                           return ';';
"\n"						              return ENDL;

"||"                          return OR;
"&&"                          return AND;
"!"    						            return '!';

"0b"[01]+                     {
                                  yylval.Int = convertBinaryToDecimal(atoi(yytext+2));
                                  return INT;
                              }
"0o"[0-7]+                    {
                                  yylval.Int = convertOctalToDecimal(atoi(yytext+2));
                                  return INT;
                              }
"0x"[A-F0-9]+                 {
                                  yylval.Int = strtol(yytext,NULL,16);
                                  return INT;
                              }
[+-]?[0-9]+                   {
                                  yylval.Int = atoi(yytext);
                                  return INT;
                              }
([_]|[$a-zA-Z])+[a-zA-Z0-9_]* {
                                  yylval.Id = (char *)malloc(sizeof(yytext)+1);
                                  strcpy(yylval.Id, yytext);
                                  return ID;
                              }
[+-]?[0-9]+\.[0-9eE-]+        {
                                  yylval.Double = atof(yytext);
                                  return DOUBLE;
                              }

<<EOF>>                       return 0;

[\n\r\t\f\v ]                 ;

. 						                printf("Bad symbol %s\n", yytext);
%%
int main(int argc,char* argv[])
{
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        yyparse();
        //update_tree_parent_func(root);
        //update_tree_stmtlist(root,root);
        //print_tree(root);
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
