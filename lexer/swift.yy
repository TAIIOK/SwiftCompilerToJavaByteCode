%{

    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <netinet/in.h>
	  #include <math.h>

    #include "swift.tab.h"
    #include "semantic_tables.h"
    #include "tree_print.h"





    #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

    char strconst[1281] = {0};
	  int convertOctalToDecimal(int octalNumber);
	  int convertBinaryToDecimal(int n);

    extern int yyparse(void);
    extern void update_tree_stmtlist(NStmtList* list,NStmtList* root);
    extern void update_tree_parent_func(struct NStmtList* root);

    /*
    <STRING_A>\\\(([^\)]*)\)        {
                                  yylval.Id = (char *)malloc(sizeof(yytext)+1);
                                  strcpy(yylval.Id, yytext);
                                  return ID;
                                  }
  */
  static int staticplus = 0;
  static int statictoken = 0;
  static char staticstring[1281] = {0};


%}

%option noyywrap
%option yylineno

%x COMMENT
%x STRING_A

%%

  if(statictoken == 1)
  {
  statictoken = 0;
  return '+';
  }

  if(staticplus == 1)
  {
    staticplus = 0;
    statictoken = 1;

    yylval.Id = (char *)malloc(sizeof(staticstring)+1);
    strcpy(yylval.Id, staticstring);
    *staticstring = '\0';
    return ID;

  }

"/*"                          {BEGIN(COMMENT); }
<COMMENT>"*/"                 {BEGIN(INITIAL);}
<COMMENT>([^*]|\n)+|.         {}
<COMMENT><<EOF>>              {printf("Unterminated comment\n");return 0;}

"//".*                        ;

\"                            { BEGIN(STRING_A); strcpy(strconst, ""); }
<STRING_A>\\                    strcat(strconst, "\\");
<STRING_A>\\\"                  strcat(strconst, "\"");
<STRING_A>\\r                   strcat(strconst, "\r");
<STRING_A>\\t                   strcat(strconst, "\t");
<STRING_A>\\n                   strcat(strconst, "\n");
<STRING_A>\\\\                  strcat(strconst, "\\");
<STRING_A>[^\\\n\"]+            strcat(strconst,yytext);
<STRING_A>\\\(([^\)]*)\)        {
                              strcat(staticstring, yytext);
                              statictoken = 1;
                              staticplus = 1;
                              yylval.String = (char *)malloc(strlen(strconst) + 1);
                              strcpy(yylval.String, strconst);
                              *strconst = '\0';
                              return STRING;
                              }
<STRING_A>\"                    {
								              yylval.String = (char *)malloc(strlen(strconst) + 1);
                              strcpy(yylval.String, strconst);
                              BEGIN(INITIAL);
                              return STRING;
                              }
<STRING_A>.|[\n\r\f\t\v]        ;


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
"["                           {printf("[");return '[';}
"]"                           {printf("]");return ']';}
":"                           {printf(":");return ':';}

";"                           return ';';
"\n"						              return ENDL;

"||"                          return OR;
"&&"                          return AND;
"!"    						            return NOT;

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

[^ \f\n\r\t\v]                printf("Unknown symbol: %s\n",yytext);

.|[\r\t\f\v]                  {;};

<<EOF>>                       return 0;
%%
int main(int argc,char* argv[])
{
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");

        yyparse();
        update_tree_parent_func(root);
        update_tree_stmtlist(root,root);
        print_tree(root);

        FILE* output;
        output = fopen("constant_table.csv","w");
        fprintf(output, "%s", ";Constant table:;\n");
        create_table(root);
        st_print_const_file(output);
        printLocalVars_file(output);
        /*
        printf("Constant table:\n");
        fprintf(output, "%s", ";Constant table:;\n");
        st_fill_tables(root);
        st_print_const(st_const_table);
        st_print_const_file(output,st_const_table);
        struct NStmt * current = root->first;
        while (current != NULL)
        {
            if (current->type == STMT_FUNC)
            {
                printf("Function constant table:\n");
                st_print_const(current->func->const_table);
                fprintf(output, "'%s'", ";Function constant table:;\n");
                st_print_const_file(output,current->func->const_table);
            }
            current = current->next;
        }

        printf("Function list:\n");
        fprintf(output, "'%s'", ";Function list:;\n");
        SList * cur = func_list;
        while (cur != NULL)
        {
            printf("function %s\n", ((NFunc *)(cur->data))->name->last->name );
            fprintf(output, ";'%s';",((NFunc *)(cur->data))->name->last->name);
            cur = cur->next;
        }

        printf("Function methodrefs:\n");
        fprintf(output, "%s",";Function methodrefs:;\n");
        st_print_const(st_func_handles);
        st_print_const_file(output,st_func_handles);
        fclose(output);

        cg_generate_bytecode(root);
        */
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
