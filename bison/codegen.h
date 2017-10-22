/**
 * @file codegen.h
 * Provides functions to generate java bytecode.
 */

#ifndef _H_CODEGEN_
#define _H_CODEGEN_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "semantic_tables.h"
#include "codegenconst.h"

void generate_var_code(NExpr *var);
void generate_expr_code(NExpr *expr);
void generate_class_file();
void generate_stmt_code(NStmt *stmt);
void generate_stmt_list_code(NStmtList *list);
void generate_expr_list_code(NExprList*list);
void generate_for_code(NFor *For);
void generate_while_code(NWhile * While);
void write_byte_code(std::vector<char> & code);
void generate_name_list_code(NExprList*list);
void generate_name_code(NExpr*name);
void code_number(unsigned long int number, int size);
void code_utf8(char* bytes);
void code_integer(int number);
void code_float(float number);
void code_class(int number);
void code_string(int number);
void code_methodref(int first , int second);
void code_name_and_type(int first , int second);
void code_float_number(float number, int size);
struct NExpr* is_in_local_vars(char*name);
void generate_expr_assign(NStmt *expr);
void generate_elsif_code(NIf*elsif);

std::vector<char> all_code;
std::vector<char> byte_code;
char* loopVarName;
std::vector<char*> loopVarNames;
std::vector<char> empty_code;
int loopCounter = 0;


std::ofstream file_of_class ("Main.class", std::ios::out | std::ios::binary);

union u4
{
	unsigned long int number;
	char bytes[4];
};

union u2
{
	unsigned long int number;
	char bytes[2];
};

union s4
{
	signed long int number;
	float flnumber;
	char bytes[4];
};

union s2
{
	signed short number;
	float flnumber;
	char bytes[2];
};

void code_const_table()
{
	int i;
	for (auto c : table) {
					if(c.type != CONST_NULL) {

					}
					switch (c.type) {
					case CONST_UTF8:
					code_number(1,1);
					code_utf8(c.value.utf8);
					break;
					case CONST_INT:
					code_number(3,1);
					code_integer(c.value.val_int);
					break;
					case CONST_FLOAT:
					code_number(4,1);
					code_float(c.value.val_float);
					break;
					case CONST_DOUBLE:
					code_number(4,1);
					code_float(c.value.val_double);
					break;
					case CONST_CLASS:
					code_number(7,1);
					code_class(c.value.val_int);
					break;
					case CONST_STRING:
					code_number(8,1);
					code_string(c.value.args.arg1);
					break;
					case CONST_NULL:      break;
					case CONST_FIELDREF:/*
					code_number(9,1);
					code_fieldref(c.value.args.arg1, c.value.args.arg2);
					*/
					 break;
					case CONST_METHODREF:
					code_number(10,1);
					code_methodref(c.value.args.arg1, c.value.args.arg2);
					break;
					case CONST_NAMETYPE:
					code_number(12,1);
					code_name_and_type(c.value.args.arg1, c.value.args.arg2);
					break;

					default:   break;
					}
	}
}

void code_method_table()
{

code_number(0x0001 | 0x0008, 2);//  флаги доступа метода

code_number(4, 2);//имя метода

code_number(5, 2);//дескриптор метода

code_number(1, 2);//количество атрибутов метода

code_number(1, 2);//имя атрибута

code_number(byte_code.size() + 13, 4);//длинна атрибута

code_number(2048, 2);//стек

code_number(Main_varubles.size() + 1 + loopCounter, 2);//количество локальных переменных

code_number(byte_code.size() + 1, 4);//длинна байт кода

all_code.insert(all_code.end(), byte_code.begin(), byte_code.end()); // байт код

all_code.insert(all_code.end(),0xb1);

int number = 0;
code_number(number, 2);

number = 0;
code_number(number, 2);

}

void code_method_class(std::vector<char> & byte_code, int index)
{

	unsigned long int number;
	number = table.size()-1;
	code_number(number, 2);
	number = 12 + byte_code.size();
	code_number(number, 4);
	number = 1000;
	code_number(number, 2);
	number = index;
	code_number(number, 2);
	number = byte_code.size();
	code_number(number, 4);
	for(int i=0;i<byte_code.size();i++)
	{
		all_code.insert(all_code.end(), byte_code[i]);
	}
	number = 0;
	code_number(number, 2);
	code_number(number, 2);

}



void code_class_table()
{

}

void code_methodref(int first , int second)
{
	code_number(first, 2);
	code_number(second, 2);
}

void code_float(float number)
{
	code_float_number(number, 4);
}

void code_fieldref(int first , int second)
{
	code_number(first, 2);
	code_number(second, 2);
}

void code_class(int number)
{
	code_number(number, 2);
}

void code_name_and_type(int first , int second)
{
	code_number(first, 2);
	code_number(second, 2);
}

void code_string(int number)
{
	code_number(number, 2);
}


void code_integer(int number)
{
	code_number(number, 4);
}

void code_utf8(char* bytes)
{
	int number;
	char* inbytes = (char*)malloc(strlen(bytes));
	number = strlen(bytes);
	code_number(number, 2);
	strcpy(inbytes, bytes);
	for (int i = 0; i < strlen(inbytes); i++)
	{
		number = inbytes[i];
		code_number(number, 1);
	}

}


void reverse_bytes(char* bytes, int size)
{
	char temp;
	for(int i = 0; i < size/2; i++)
    {
		temp = bytes[i];
        bytes[i] = bytes[size - 1 - i];
        bytes[size - 1 - i] = temp;
    }
}

union u2 make_reversed_u2(unsigned long int number)
{
	union u2 changer;
	changer.number = number;
	reverse_bytes(changer.bytes, 2);
	return changer;
}

union u4 make_reversed_u4(unsigned long int number)
{
	union u4 changer;
	changer.number = number;
	reverse_bytes(changer.bytes, 4);
	return changer;
}

union s2 make_reversed_s2(signed long int number)
{
	union s2 changer;
	changer.number = number;
	reverse_bytes(changer.bytes, 2);
	return changer;
}

union s2 make_reversed_float_s2(float number)
{
	union s2 changer;
	changer.flnumber = number;
	reverse_bytes(changer.bytes, 2);
	return changer;
}

union s4 make_reversed_s4(signed long int number)
{
	union s4 changer;
	changer.number = number;
	reverse_bytes(changer.bytes, 4);
	return changer;
}

union s4 make_reversed_float_s4(float number)
{
	union s4 changer;
	changer.flnumber = number;
	reverse_bytes(changer.bytes, 4);
	return changer;
}

void code_number(unsigned long int number, int size)
{

	int i;
	if (size == 1)
	{
		all_code.insert(all_code.end(), (char)number);
	}
	else if (size == 2)
	{
		union u2 temp = make_reversed_u2(number);
		for (i = 0; i < 2; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}
	else if (size == 4)
	{
		union u4 temp = make_reversed_u4(number);
		for (i = 0; i < 4; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}

}

void code_float_number(float number, int size)
{

	int i;
	if (size == 1)
	{
		all_code.insert(all_code.end(), (char)number);
	}
	else if (size == 2)
	{
		union s2 temp = make_reversed_float_s2(number);
		for (i = 0; i < 2; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}
	else if (size == 4)
	{
		union s4 temp = make_reversed_float_s4(number);
		for (i = 0; i < 4; i++)
		{
			all_code.insert(all_code.end(), temp.bytes[i]);
		}
	}

}

void write_code_to_class_file(unsigned long int number, int size)
{

	int i;
	if (size == 1)
	{
		char temp = (char)number;

		file_of_class.write(&temp, 4);
	}
	else if (size == 2)
	{
		union u2 temp = make_reversed_u2(number);

		file_of_class.write(&temp.bytes[0], 2);
	}
	else if (size == 4)
	{
		union u4 temp = make_reversed_u4(number);

		file_of_class.write(&temp.bytes[0], 4);
	}

}

void generate_expr_assign(NStmt *expr)
{
			std::vector<NExpr> *vars;
			NExpr * el;

				if(expr->var->type != EXPR_MAS)
				generate_expr_code(expr->expr);
				if( expr->var->type == EXPR_ID_LIST)
				{	if(!expr->var->isArray){
					switch (update_varuble(globalroot,expr->var)[0]) {
					case 'I':    code_number(ISTORE, 1);     break;
					case 'F':    code_number(FSTORE, 1);   break;
					case 'D':    code_number(FSTORE, 1);  break;
					case 'S':    code_number(ASTORE, 1);  break;
					case 'A':    code_number(ASTORE, 1);  break;
					default:          printf("==WTF?== IN generate_expr_assign\n");  code_number(ISTORE, 1);     break;
					}
				}else{
					code_number(ASTORE, 1);
				}

				}
				else if (expr->var->type == EXPR_MAS)
				{
					code_number(ALOAD, 1);
					el =  is_in_local_vars(expr->var->left->idlist->first->name);
					code_number(el->id, 1);
					generate_expr_code(expr->var->right);
					generate_expr_code(expr->expr);

						switch (update_varuble(globalroot,el)[0]) {
						case 'I':    code_number(IASTORE, 1);     break;
						case 'F':    code_number(FASTORE, 1);   break;
						case 'D':    code_number(FASTORE, 1);  break;
						case 'S':    code_number(AASTORE, 1);  break;
						case 'A':    code_number(AASTORE, 1);  break;
						default:          printf("==WTF?== generate_expr_assign MASS\n"); code_number(IASTORE, 1);       break;
						}

						return;

				}
				else if (expr->var->vartype->type == INTTy || expr->var->vartype->type== BOOLTy)
					{
						code_number(ISTORE, 1);
					}
					else if (expr->var->vartype->type == FLOATTy)
					{
						code_number(FSTORE, 1);
					}
					else
					{
						code_number(ASTORE, 1);
					}
					el = is_in_local_vars(expr->var->idlist->first->name);
					code_number(el->id, 1);
}

 int findMethodRef(enum NVarEnumType type , bool Print)
{
	switch(type)
{
case INTTy:
		if(Print)
		return 13;

		return 39;
		break;
case FLOATTy:
		if(Print)
		return  17;

		return  43;
		break;
case BOOLTy:
		if(Print)
		return  25;

		return  51;
		break;
case STRINGTy:
		if(Print)
		return  29;

		return  55;
		break;
default:
		if(Print)
		return  33;
		break;
}
	return 33;
}
void generate_expr_code(NExpr *expr)
{
 bool arrInitializing = false;

	switch (expr->type)
	{
	case EXPR_MAS:
	{
		NExpr * el;
		el =  is_in_local_vars(expr->left->idlist->first->name);

		code_number(ALOAD, 1);
		code_number(el->id, 1);


		generate_expr_code(expr->right);


		switch (update_varuble(globalroot,el)[0]) {
		case 'I':    code_number(IALOAD, 1);     break;
		case 'F':    code_number(FALOAD, 1);   break;
		case 'D':    code_number(FALOAD, 1);  break;
		case 'S':    code_number(AALOAD, 1);  break;
		case 'A':    code_number(AALOAD, 1);  break;
		default:          printf("==WTF?== IN FUNCTION CALL\n");       break;
		}
		break;
	}
	case EXPR_ID_LIST:
		{
			generate_name_list_code(expr->idlist);
			break;
		}

	case EXPR_TABLE:
	{

		if (expr->vartype->type != STRINGTy )
		{
			int size = 0;
			code_number(SIPUSH, 1);
			 struct NTblElem * currentElem = expr->table->first;
			  	while (currentElem != NULL)
			 {
				 size = size + 1;
				 currentElem = currentElem->next;
			 }
			  currentElem = expr->table->first;
			code_number(size,2);   // размер массива
			code_number(NEWARRAY, 1);
			if (expr->vartype->type == INTTy || expr->vartype->type == BOOLTy){
				code_number(10, 1);
			}
			else if (expr->vartype->type == DOUBLETy || expr->vartype->type == FLOATTy)
				code_number(6, 1);



			if (currentElem != NULL)
			{
				for (int i = 0; i < size; i++)
				{

					code_number(DUP, 1);
					code_number(SIPUSH, 1);
					code_number(i, 2);
					generate_expr_code(currentElem->value);
					if (expr->vartype->type == INTTy)
					code_number(IASTORE, 1);
					else if (expr->vartype->type == DOUBLETy || expr->vartype->type  == FLOATTy)
						code_number(FASTORE, 1);
					else if (expr->vartype->type == BOOLTy)
						code_number(IASTORE, 1);

					currentElem = currentElem->next;
				}
			}


		}


		break;
	}

	case EXPR_MET:
	{
		if(expr->left->idlist->first->next != NULL)
		{
			if(strcmp(expr->left->idlist->first->next->name,"count") == 0)
			{

				NExpr * el;
				el =  is_in_local_vars(expr->left->idlist->first->name);

				code_number(ALOAD, 1);
				code_number(el->id, 1);

				code_number(ARRAYLENGTH,1);
				return;
			}
		}
		else if(strcmp(expr->left->idlist->first->name,"toInt") == 0)
		{
			generate_expr_list_code(expr->right->idlist);
			code_number(INVOKESTATIC, 1);
			code_number(findMethodRef(INTTy,false), 2);
		}
		else if(strcmp(expr->left->idlist->first->name,"toFloat") == 0)
		{
			generate_expr_list_code(expr->right->idlist);
			code_number(INVOKESTATIC, 1);
			code_number(findMethodRef(FLOATTy,false), 2);
		}
		else if(strcmp(expr->left->idlist->first->name,"readLine") == 0)
		{
			code_number(INVOKESTATIC, 1);
			code_number(findMethodRef(STRINGTy,false), 2);
		}
		else if(strcmp(expr->left->idlist->first->name,"print") == 0)
		{
			generate_expr_list_code(expr->right->idlist);
			code_number(INVOKESTATIC, 1);

  	char * str = (char*)malloc(sizeof(char)*33);

			if(expr->right->idlist->first->type == EXPR_ID_LIST) {
							strcpy(str,update_varuble(globalroot,expr->right->idlist->first));
			}
			else{
							strcpy(str,check_stack_operation(create_stack_operation(expr->right->idlist->first)));
			}
			switch (str[0]) {
			case 'I':    code_number(findMethodRef(INTTy,true), 2);     break;
			case 'F':    code_number(findMethodRef(FLOATTy,true), 2);   break;
			case 'D':    code_number(findMethodRef(DOUBLETy,true), 2);  break;
			case 'B':    code_number(findMethodRef(BOOLTy,true), 2);    break;
			case 'S':    code_number(findMethodRef(STRINGTy,true), 2);  break;
			case 'A':    code_number(findMethodRef(ARRAYTy,true), 2);   break;
			default:          printf("==WTF?== IN FUNCTION CALL\n");   code_number(findMethodRef(INTTy,true), 2);    break;
			}


		}
			break;
		}

	case EXPR_PLUS:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			switch (check_stack_operation(create_stack_operation(expr))[0]) {
			case 'I':    code_number(IADD, 1);     break;
			case 'F':    code_number(FADD, 1);   break;
			case 'D':    code_number(FADD, 1);  break;
			case 'S':			code_number(INVOKESTATIC, 1);
										code_number(61,2);break;
			default:          printf("==WTF?== IN EXPR_PLUS\n");       break;
			}
			break;
		}
	case EXPR_MUL:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			switch (check_stack_operation(create_stack_operation(expr))[0]) {
			case 'I':    code_number(IMUL, 1);     break;
			case 'F':    code_number(FMUL, 1);   break;
			case 'D':    code_number(FMUL, 1);  break;
			default:          printf("==WTF?== IN EXPR_MUL\n");       break;
			}
			break;
		}
	case EXPR_DIV:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			switch (check_stack_operation(create_stack_operation(expr))[0]) {
			case 'I':    code_number(IDIV, 1);     break;
			case 'F':    code_number(FDIV, 1);   break;
			case 'D':    code_number(FDIV, 1);  break;
			default:          printf("==WTF?== EXPR_DIV\n");       break;
			}
			break;
		}
	case EXPR_MINUS:
		{

			generate_expr_code(expr->left);
			generate_expr_code(expr->right);


switch (check_stack_operation(create_stack_operation(expr))[0]) {
case 'I':    code_number(ISUB, 1);     break;
case 'F':    code_number(FSUB, 1);   break;
case 'D':    code_number(FSUB, 1);  break;
default:          printf("==WTF?== IN EXPR_MINUS\n");       break;
}

			break;
		}
	case EXPR_GT:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			code_number(IF_ICMPGT, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case EXPR_EQ:
		{
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);
			code_number(IF_ICMPEQ, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case EXPR_LT:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			code_number(IF_ICMPLT, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case EXPR_NOT:
		{
			generate_expr_code(expr->left);
			code_number(ICONST_0, 1);
			code_number(IF_ICMPEQ, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case EXPR_NQ:
		{
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);
			code_number(IF_ICMPNE, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case EXPR_GE:
		{
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);
			code_number(IF_ICMPGE, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case EXPR_LE:
		{
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);
			code_number(IF_ICMPLE, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case EXPR_AND:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			code_number(IMUL, 1);
			code_number(ICONST_1, 1);
			code_number(IF_ICMPEQ, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
	case EXPR_OR:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			code_number(IADD, 1);
			code_number(ICONST_1, 1);
			code_number(IF_ICMPEQ, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}

	case EXPR_UMIN:
		{
			if (expr->type == INTTy || expr->type == EXPR_INT)
			{
				code_number(BIPUSH, 1);
				code_number(0, 1);
				generate_expr_code(expr->left);
				code_number(ISUB, 1);
			}
			else
			{
				code_number(FCONST_0, 1);
				generate_expr_code(expr->left);
				code_number(FSUB, 1);
			}
			break;
		}
	case EXPR_INT:
		{
			code_number(LDC, 1);
			code_number(expr->id, 1);
			break;
		}
	case EXPR_DOUBLE:
		{
			code_number(LDC2_W, 1);
			code_number(expr->id, 2);
			break;
		}
		case EXPR_FLOAT:
			{
				code_number(LDC_W, 1);
				code_number(expr->id, 2);
				break;
			}
	case EXPR_STR:
		{
			code_number(LDC, 1);
			code_number(expr->id, 1);
			break;
		}
	case EXPR_BOOL:
		{
			if (expr->Int)
				code_number(ICONST_1, 1);
			else
				code_number(ICONST_0, 1);
			break;
		}

	}

	if (expr->next != NULL && !arrInitializing)
	{
		generate_expr_code(expr->next);
	}

}

void generate_expr_list_code(NExprList *list)
{

	if(list!=NULL)
	{
		generate_expr_code(list->first);
	}

}

void generate_varlist_code(NExprList*list)
{

	if(list!=NULL)
	{
		generate_var_code(list->first);
	}

}

void generate_var_code(NExpr*var)
{

	if (var != NULL)
	{
		generate_expr_code(var);
		NExpr * local = is_in_local_vars(var->name);
		if(local != NULL)
		{
			code_number(ASTORE, 1);
			code_number(local->id, 1);
		}
	}
	if(var->next != NULL)
	{
		generate_var_code(var->next);
	}

}

struct NExpr* is_in_local_vars(char*name)
{
	int i=0;
	for (auto c: Main_varubles){
		if(strcmp(name,c->idlist->first->name)==0){
			return c;
		}
		i++;
	}
	return NULL;
}


void generate_name_code(NExpr*name)
{
	if(name!=NULL)
	{
		int i;
		for (i = 0; i < loopVarNames.size(); i++)
		{
				if (loopVarName != NULL && strcmp(name->name, loopVarNames[i]) == 0)
				break;
		}
		if (loopVarName!=NULL && i<loopVarNames.size() && strcmp(name->name, loopVarNames[i]) == 0)
		{
			code_number(ILOAD, 1);
			code_number(Main_varubles.size() + i + loopCounter , 1);
		}
		else
		{

			NExpr *elem = is_in_local_vars(name->name);

			if (elem->vartype->type == INTTy )
			{
				code_number(ILOAD, 1);
				code_number(elem->id, 1);
			}
			else if (elem->vartype->type == BOOLTy)
			{
				code_number(ILOAD, 1);
				code_number(elem->id, 1);
			}
			else if (elem->vartype->type == DOUBLETy || elem->vartype->type == FLOATTy)
			{
				code_number(FLOAD, 1);
				code_number(elem->id, 1);
			}
			else if (elem->vartype->type == STRINGTy)
			{
				code_number(ALOAD, 1);
				code_number(elem->id, 1);
			}
			else if (elem->vartype->type == ARRAYTy || elem->isArray)
			{
				code_number(ALOAD, 1);
				code_number(elem->id, 1);
			}
		}
		generate_name_code(name->next);
	}

}


void generate_name_list_code(NExprList*list)
{
	if(list!=NULL)
	{
		generate_name_code(list->first);
	}

}

void generate_if_code(NIf * If)
{

	int size2;
	union s2 temp;

	generate_expr_code(If->condition);

	code_number(IFEQ, 1);
	int size = all_code.size();
	code_number(0, 2);

	generate_stmt_list_code(If->body);
	if (If->elsebody != NULL)
	{

		code_number(GO_TO, 1);
		size2 = all_code.size();
	}

	if (If->elsebody == NULL)
	{
		temp = make_reversed_s2(all_code.size() + 1 - size);
		for (int i = 0; i < 2; i++)
			all_code.at(size + i) = temp.bytes[i];
	}
	else if (If->elsebody != NULL)
	{
		code_number(0, 2);
		temp = make_reversed_s2(all_code.size() + 1 - size);
		for (int i = 0; i < 2; i++)
			all_code.at(size + i) = temp.bytes[i];

		generate_stmt_list_code(If->elsebody);
		temp = make_reversed_s2(all_code.size() + 1 - size2);
		for (int i = 0; i < 2; i++)
			all_code.at(size2 + i) = temp.bytes[i];
	}

}

void generate_elsif_list_code(NIfList *list)
{

	if(list!=NULL)
		generate_elsif_code(list->first);

}

void generate_elsif_code(NIf*elsif)
{

	if(elsif!=NULL)
	{
		generate_expr_code(elsif->condition);
		code_number(IFEQ, 1);
		int size = all_code.size();
		code_number(0, 2);
		generate_stmt_list_code(elsif->body);
		union s2 temp = make_reversed_s2(all_code.size() - size);
		for (int i = 0; i < 2; i++)
			all_code.at(size + i) = temp.bytes[i];
		generate_elsif_code(elsif->next);
	}

}
void generate_stmt_list_code(NStmtList *list)
{
	if(list->first != NULL){
	generate_stmt_code(list->first);
	}
}

void generate_stmt_code(NStmt*stmt)
{
	switch (stmt->type)
	{

	case STMT_ASSIGN:

	generate_expr_assign(stmt);

		break;
	case STMT_EXPR:
		{
			generate_expr_code(stmt->expr);

			break;
		}

	case STMT_FUNC:
		{
			break;
		}
	case STMT_IF:
		{
			generate_if_code(stmt->if_tree);
			break;
		}
	case STMT_FOR:
		{
			generate_for_code(stmt->for_loop);
			break;
		}
	case STMT_WHILE:
		{
			generate_while_code(stmt->while_loop);
			break;
		}

	}
	if (stmt->next != NULL)
	{
		generate_stmt_code(stmt->next);
	}

}

void generate_while_code(NWhile * While)
{

	int size;
	int size2;
	int startCondition;
	union s2 temp;

	if (!While->doWhile)
	{
		code_number(GO_TO, 1);
		code_number(0, 2);
	}
	size = all_code.size();

	generate_stmt_list_code(While->body);
	size2 = all_code.size();


	generate_expr_code(While->condition);


	if (!While->doWhile)
	{
		temp = make_reversed_s2(size2 - size + 3);
		for (int i = 0; i < 2; i++)
			all_code.at(size - 2 + i) = temp.bytes[i];
	}

	if (!While->doWhile)
	{
		code_number(IFNE, 1);
		temp = make_reversed_s2(size + 1 - all_code.size());
		for (int i = 0; i < 2; i++)
			all_code.push_back(temp.bytes[i]);
	}
	else
	{
		code_number(IFEQ, 1);
		temp = make_reversed_s2(size + 1 - all_code.size());
		for (int i = 0; i < 2; i++)
			all_code.push_back(temp.bytes[i]);
	}

}
void generate_for_code(NFor *For)
{

	loopVarName = (char*)malloc(sizeof(char) * strlen(For->name->name)+1);
	loopVarName = For->name->name;
	loopVarNames.push_back(loopVarName);
	loopCounter++;
	int size;
	int size2;
	int startCondition;
	union s2 temp;


		generate_expr_code(For->start->left );
		code_number(ISTORE, 1);
		code_number(Main_varubles.size() + loopCounter, 1);

		code_number(GO_TO, 1);
		code_number(0, 2);
		size = all_code.size();


		generate_stmt_list_code(For->body );
		code_number(ILOAD, 1);
		code_number(Main_varubles.size() + loopCounter, 1);
		code_number(ICONST_1, 1);
		code_number(IADD, 1);
		code_number(ISTORE, 1);
		code_number(Main_varubles.size() + loopCounter, 1);

		size2 = all_code.size();



		code_number(ILOAD, 1);
		code_number(Main_varubles.size() + loopCounter, 1);
		generate_expr_code(For->start->right);
		code_number(IF_ICMPLT, 1);
		code_number(7, 2);
		code_number(ICONST_0, 1);
		code_number(GO_TO, 1);
		code_number(4, 2);
		code_number(ICONST_1, 1);


		temp = make_reversed_s2(size2 - size + 3);
		for (int i = 0; i < 2; i++)
			all_code.at(size - 2 + i) = temp.bytes[i];



		code_number(IFNE, 1);
		temp = make_reversed_s2(size + 1 - all_code.size());
		for (int i = 0; i < 2; i++)
			all_code.push_back(temp.bytes[i]);


	loopVarName = NULL;
	if (loopVarNames.size()>0)
	{
		loopVarName = (char*)malloc(sizeof(char)* strlen(loopVarNames.at(loopVarNames.size()-1) + 1));
		strcpy(loopVarName, loopVarNames.at(loopVarNames.size() - 1));
	}
	loopVarNames.erase(loopVarNames.begin()+loopVarNames.size()-1);

}


void generate_arr_var_code(NExpr * var)
{

	if (var!= NULL)
	{
		generate_expr_list_code(var->idlist);
		NExpr * local = is_in_local_vars(var->name);
		if(local != NULL)
		{
			code_number(ASTORE, 1);
			code_number(local->id, 1);
		}
	}

}

void generate_return_code(NVarEnumType type)
{
	if (type == STRINGTy || type == ARRAYTy)
	{
		code_number(ARETURN, 1);
	}
	else if (type == INTTy || type == CHARACTERTy || type == BOOLTy)
	{
		code_number(IRETURN, 1);
	}
	else if (type == DOUBLETy || type == FLOATTy)
	{
		code_number(FRETURN, 1);
	}
}

void generate_byte_code()
{

printf("count of Main_varubles: %d\n", Main_varubles.size());
for (auto c : Main_varubles) {
	printf("name -> %s , id -> %d\n",c->idlist->first->name, c->id);
}

generate_stmt_list_code(root);
byte_code = all_code;
	generate_class_file();
}

void generate_class_file()
{
	all_code.clear();
	char file_name [20];
	unsigned long int number;
	strcpy(file_name,"Main");
	strcat(file_name, ".class");

	number = 0xCAFEBABE;
	code_number(number, 4);
	number = 0x0000;
	code_number(number, 2);
	number = 0x0030;
	code_number(number, 2);
	number = table.size();
	code_number(number, 2);

	code_const_table();

	number = 0x0001;
	code_number(0x0001 | 0x0002, 2);
	number = 3; //parent_class->classname->id;
	code_number(number, 2);

	number = 8; // parent_class->parentname->id;
	code_number(number, 2);

	number = 0;
	code_number(number, 2);

	number = 0;
	code_number(number, 2);

	number = 1;  // parent_class->methods->size();
	code_number(number, 2);


	code_method_table();

	number = 0;
	code_number(number, 2);

	write_byte_code(all_code);


	file_of_class.close();
}

void write_byte_code(std::vector<char> & code)
{
	if (code.size() != 0)
	{

		file_of_class.write(code.begin().base(), code.size());


	}

}

#endif
