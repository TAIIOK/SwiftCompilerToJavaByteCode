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
void generate_class_file();
void generate_stmt_code(NStmt *stmt);
void generate_stmt_list_code(NStmtList *list);
void generate_expr_list_code(NExprList*list);
void generate_for_code(NFor *For);
void generate_while_code(NWhile * While);
void write_byte_code(std::vector<char> & code);
void generate_name_list_code(NExprList*list);
void generate_name_code(NExpr*name);
std::vector<char> all_code;
char* loopVarName;
std::vector<char*> loopVarNames;


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
	signed long int number;
	float flnumber;
	char bytes[2];
};

void code_const_table()
{
	/*
	int i;
	for(i=0;i<table_of_const.size();i++)
	{
		switch(table_of_const[i]->type)
		{
		case CONST_UTF8:
			{
				code_number(1,1);
				code_utf8(table_of_const[i]);
				break;
			}
		case CONST_INT:
			{
				code_number(3,1);
				code_integer(table_of_const[i]);
				break;
			}
		case CONST_FLOAT:
			{
				code_number(4,1);
				code_float(table_of_const[i]);
				break;
			}
		case CONST_CLASS:
			{
				code_number(7,1);
				code_class(table_of_const[i]);
				break;
			}
		case CONST_STRING:
			{
				code_number(8,1);
				code_string(table_of_const[i]);
				break;
			}
		case CONST_METHODREF:
			{
				code_number(10,1);
				code_methodref(table_of_const[i]);
				break;
			}
		case CONST_NAMETYPE:
			{
				code_number(12,1);
				code_name_and_type(table_of_const[i]);
				break;
			}
		}
	}
	*/
}

void code_method_table()
{
	/*
	for (int i = 0; i < parent_class->methods->size(); i++)
	{
		unsigned long int number;
		if (parent_class->methods->size() != code_of_methods.size())
		{
			code_of_methods.insert(code_of_methods.end(), std::vector<char>());
		}

		code_number(0x0001, 2);
		number = parent_class->methods->at(i).name->id;
		code_number(number, 2);
		number = parent_class->methods->at(i).desc->id;
		code_number(number, 2);
		number = 1;
		code_number(number, 2);
		//1000 ���. ����������
		code_method_class(code_of_methods[i], 1000);
	}
	*/
}

void code_to_file(std::vector<char> & byte_code)
{/*
	char* arr;
	std::ofstream classFile ("byteCode.class", std::ios::binary|std::ios::out);

	if (byte_code.size() != 0)
	{
		file_of_class.write(&byte_code[0], byte_code.size());
	}
	*/
}

void code_method_class(std::vector<char> & byte_code, int index)
{
	/*
	unsigned long int number;
	number = table_of_const.at(table_of_const.size()-1)->id;
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
	*/
}



void code_class_table()
{

}

void code_methodref(SemanticalElement* element)
{
	/*
	int number;
	number = element->first->id;
	code_number(number, 2);
	number = element->second->id;
	code_number(number, 2);
	*/
}

void code_float(SemanticalElement* element)
{
	/*
	float number;
	number = element->const_float;
	code_float_number(number, 4);
	*/
}

void code_fieldref(SemanticalElement* element)
{
	/*
	int number;
	number = element->first->id;
	code_number(number, 2);
	number = element->second->id;
	code_number(number, 2);
	*/
}

void code_class(SemanticalElement* element)
{
	/*
	int number;
	number = element->first->id;
	code_number(number, 2);
	*/
}

void code_name_and_type(SemanticalElement* element)
{
	/*
	int number;
	number = element->first->id;
	code_number(number, 2);
	number = element->second->id;
	code_number(number, 2);
	*/
}

void code_string(SemanticalElement* element)
{
	/*
	int number;
	number = element->first->id;
	code_number(number, 2);
	*/
}


void code_integer(SemanticalElement* element)
{
	/*
	int number;
	number = element->const_int;
	code_number(number, 4);
	*/
}

void code_utf8(SemanticalElement* element)
{
	/*
	int number;
	char* bytes = (char*) malloc(element->str.length());
	number = element->str.length();
	code_number(number, 2);
	strcpy(bytes, element->str.c_str());
	for (int i = 0; i < element->str.length(); i++)
	{
		number = bytes[i];
		code_number(number, 1);
	}
	*/
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
	/*
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
	*/
}

void write_code_to_class_file(unsigned long int number, int size)
{
/*
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
	*/
}

void generate_expr_code(NExpr *expr)
{
 bool arrInitializing = false;

	switch (expr->type)
	{
	case EXPR_ID_LIST:
		{
			generate_name_list_code(expr->idlist);
			break;
		}
		/*
	case assign:
		{
			if (loopVarName!=NULL && expr->left->type!=func && strcmp(loopVarName, expr->left->list->first->name) == 0)
			{
				throw ("You can't assign to loop variable");
			}
			else
			{
				std::vector<struct LocalElement> *vars;
				LocalElement * el;
				//��� ��������
				if (expr->left->type == func)
				{
					int i;
					for (i = 0; i < table_of_classes[1].methods->size(); i++)
					{
						if (strcmp(table_of_classes[1].methods->at(i).name->str.c_str(), current_method->name->str.c_str()) == 0)
							vars = table_of_classes[1].methods->at(i).localvars;
					}
					for (i = 0; i < vars->size(); i++)
					{
						if (stricmp(expr->left->call->func, vars->at(i).name.c_str()) == 0 && NVarType::Array)
							break;
					}
					code_number(ALOAD, 1);
					code_number(vars->at(i).id, 1);
					generate_expr_list_code(expr->left->call->arguments);
					generate_expr_code(expr->right);
					if (vars->at(i).elem_type == Integer)
						code_number(IASTORE, 1);
					else if (vars->at(i).elem_type == Float)
						code_number(FASTORE, 1);
					else if (vars->at(i).elem_type == Boolean)
						code_number(IASTORE, 1);
				}
				//��� ���������
				else
				{
					generate_expr_code(expr->right);
					if (expr->left->list->first->type == Integer || expr->left->list->first->type == Boolean || expr->left->list->first->type == ENum || expr->left->list->first->type == Character)
					{
						code_number(ISTORE, 1);
					}
					else if (expr->left->list->first->type == Real || expr->left->list->first->type == Float)
					{
						code_number(FSTORE, 1);
					}
					else
					{
						code_number(ASTORE, 1);
					}
					el = is_in_local_vars(expr->left->list->first->name);
					code_number(el->id, 1);
				}
				break;
			}
		}
	case array_call:
		{

			break;
		}
	case func:
	{
			//���� �� ������ �������� �������
			if (!isArray(current_method->name->str.c_str(),expr->call->func))
			{
				if (((stricmp(expr->call->func, "Float") == 0) || (stricmp(expr->call->func, "Integer") == 0)
					|| (stricmp(expr->call->func, "printInt") == 0) || (stricmp(expr->call->func, "printFloat") == 0) || (stricmp(expr->call->func, "printBoolean") == 0)
					|| (stricmp(expr->call->func, "printChar") == 0) || (stricmp(expr->call->func, "printString") == 0) || (stricmp(expr->call->func, "printLnInt") == 0)
					|| (stricmp(expr->call->func, "printLnFloat") == 0) || (stricmp(expr->call->func, "printLnBoolean") == 0) || (stricmp(expr->call->func, "printLnChar") == 0)
					|| (stricmp(expr->call->func, "printLnString") == 0) || (stricmp(expr->call->func, "scanInt") == 0) || (stricmp(expr->call->func, "scanBoolean") == 0)
					|| (stricmp(expr->call->func, "scanFloat") == 0) || (stricmp(expr->call->func, "scanChar") == 0) || (stricmp(expr->call->func, "scanString") == 0)
					|| (stricmp(expr->call->func, "LENGTH") == 0) || (stricmp(expr->call->func, "FIRST") == 0) || (stricmp(expr->call->func, "LAST") == 0)))
				{
					//�������� �������
					generate_expr_list_code(expr->call->arguments);
					code_number(INVOKESTATIC, 1);
				}
				//������ ���������
				else if(expr->call->type != a_call)
				{
					code_number(ALOAD, 1);
					code_number(0, 1);
					generate_expr_list_code(expr->call->arguments);
					code_number(INVOKEVIRTUAL, 1);
				}
				code_number(findMethodRef(expr->call->func), 2);
			}
			else
			{
				//��� ��� ������ �������� �������
				std::vector<struct LocalElement> *vars;
				int i;
				for (i = 0; i < table_of_classes[1].methods->size(); i++)
				{
					if (strcmp(table_of_classes[1].methods->at(i).name->str.c_str(), current_method->name->str.c_str()) == 0)
						vars = table_of_classes[1].methods->at(i).localvars;
				}
				for (i = 0; i < vars->size(); i++)
				{
					if (stricmp(expr->call->func, vars->at(i).name.c_str()) == 0 && NVarType::Array)
						break;
				}
				code_number(ALOAD, 1);
				code_number(vars->at(i).id, 1);
				generate_expr_list_code(expr->call->arguments);
				if (vars->at(i).elem_type == Integer)
					code_number(IALOAD, 1);
				else if (vars->at(i).elem_type == Float)
					code_number(FALOAD, 1);
				else if (vars->at(i).elem_type == Boolean)
					code_number(IALOAD, 1);
			}
			break;
		}
		*/
	case EXPR_PLUS:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			if(expr->left->vartype->type == INTTy)
				code_number(IADD, 1);
			if (expr->left->vartype->type == DOUBLETy || expr->left->vartype->type == FLOATTy)
				code_number(FADD, 1);
			break;
		}
	case EXPR_MUL:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			if(expr->left->vartype->type == INTTy)
				code_number(IMUL, 1);
			if (expr->left->vartype->type == DOUBLETy || expr->left->vartype->type == FLOATTy)
				code_number(FMUL, 1);
			break;
		}
	case EXPR_DIV:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			if(expr->left->vartype->type == INTTy)
				code_number(IDIV, 1);
			if (expr->left->vartype->type == DOUBLETy || expr->left->vartype->type == FLOATTy)
				code_number(FDIV, 1);
			break;
		}
	case EXPR_MINUS:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			if(expr->left->vartype->type == INTTy)
				code_number(ISUB, 1);
			if (expr->left->vartype->type == DOUBLETy || expr->left->vartype->type == FLOATTy)
				code_number(FSUB, 1);
			break;
		}
	case EXPR_GT:
		{
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);
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
			generate_expr_code(expr->right);
			generate_expr_code(expr->left);
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
		/*
	case xor:
		{
			generate_expr_code(expr->left);
			generate_expr_code(expr->right);
			code_number(IXOR, 1);
			code_number(ICONST_1, 1);
			code_number(IF_ICMPEQ, 1);
			code_number(7, 2);
			code_number(ICONST_0, 1);
			code_number(GO_TO, 1);
			code_number(4, 2);
			code_number(ICONST_1, 1);
			break;
		}
		*/
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
			if (expr->left->vartype->type == INTTy || expr->left->vartype->type == EXPR_INT)
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
	/*
	if(list!=NULL)
	{
		generate_var_code(list->first);
	}
	*/
}

void generate_var_code(NExpr*var)
{
	/*
	if (var->value != NULL)
	{
		generate_expr_code(var->value);
		LocalElement * local = is_in_local_vars(var->var_name);
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
	*/
}

struct NExpr* is_in_local_vars(char*name)
{
	/*
	std::vector<struct LocalElement> *vars = current_method->localvars;
	int i;
	for (i = 0; i < vars->size(); i++)
	{
		if(stricmp(name,vars->at(i).name.c_str())==0)
			return &(vars->at(i));
	}
	*/
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
			code_number(200 + i, 1);
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
			else if (elem->vartype->type == ARRAYTy)
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
	/*
	int size2;
	union s2 temp;
	//1. ������� GenerateCodeForExpression ��� ���������� ��������� ��������� � ��������� ��� ���������� �� ���� (0 � ����);
	generate_expr_code(If->ifExpr);
	//2. ������������� ������� ifeq ��� �������� � ������ ������� �������, ��������� ����� ���� ������� ��� ��������� ����� �������� �����;
	code_number(IFEQ, 1);
	int size = all_code.size();
	code_number(0, 2);
	//3. ������������� ���, ������������� ��� ������ �������, ��������� ������� GenerateCodeForBlock;
	generate_stmt_list_code(If->ifStmt);
	if (If->elseStmt != NULL)
	{
		//4. ���� ������������ ����� "�����", �� ������������� �������� ������������ �������� � ��������� ��� ����� ��� ����������� ��������� �����;
		code_number(GO_TO, 1);
		size2 = all_code.size();
	}
	//5. ��������� ����� ������� �� ������ 2 �� ���������� ���;
	if (If->elseStmt == NULL)
	{
		temp = make_reversed_s2(all_code.size() + 1 - size);
		for (int i = 0; i < 2; i++)
			all_code.at(size + i) = temp.bytes[i];
	}
	else if (If->elseStmt != NULL)
	{
		code_number(0, 2);
		temp = make_reversed_s2(all_code.size() + 1 - size);
		for (int i = 0; i < 2; i++)
			all_code.at(size + i) = temp.bytes[i];
		//6. ���� ������������ ����� "�����", �� ������������� ��� ��� ��� ��������� GenerateCodeForBlock � ��������� ����� �������� �� ������ 4 �� ���������� ���.
		generate_stmt_list_code(If->elseStmt);
		temp = make_reversed_s2(all_code.size() + 1 - size2);
		for (int i = 0; i < 2; i++)
			all_code.at(size2 + i) = temp.bytes[i];
	}
}
	//�������� elseif � else
	/*if(If->elsifList!=NULL)
	{
		size = all_code.size();
		generate_elsif_list_code(If->elsifList);
		union s2 changer = make_reversed_s2(all_code.size() - size);
		for (int i = 0; i < 2; i++)
			all_code.at(size + i) = changer.bytes[i];
	}
	if(If->elseStmt!=NULL)
	{
		size = all_code.size();
		generate_stmt_list_code(If->elseStmt);
		union s2 changer = make_reversed_s2(all_code.size() - size);
		for (int i = 0; i < 2; i++)
			all_code.at(size + i) = changer.bytes[i];
			*/
	}

void generate_elsif_list_code(NIfList *list)
{
	/*
	if(list!=NULL)
		generate_elsif_code(list->first);
		*/
}

void generate_elsif_code(NIf*elsif)
{
	/*
	if(elsif!=NULL)
	{
		generate_expr_code(elsif->elsifExpr);
		code_number(IFEQ, 1);
		int size = all_code.size();
		code_number(0, 2);
		generate_stmt_list_code(elsif->body);
		union s2 temp = make_reversed_s2(all_code.size() - size);
		for (int i = 0; i < 2; i++)
			all_code.at(size + i) = temp.bytes[i];
		generate_elsif_code(elsif->next);
	}
	*/
}
void generate_stmt_list_code(NStmtList *list)
{
	generate_stmt_code(list->first);
}

void generate_stmt_code(NStmt*stmt)
{

	switch (stmt->type)
	{
		/*
	case array_var:
		{
			std::vector<struct LocalElement> *vars;
			int arrId;
			NExpr *arrExpr;
			if (stmt->arr_var->expression != NULL)
				arrExpr = stmt->arr_var->expression->first;
			for (arrId = 0; arrId < table_of_classes[1].methods->size(); arrId++)
			{
				if (strcmp(table_of_classes[1].methods->at(arrId).name->str.c_str(), current_method->name->str.c_str()) == 0)
					vars = table_of_classes[1].methods->at(arrId).localvars;
			}
			for (arrId = 0; arrId < vars->size(); arrId++)
			{
				if (stricmp(stmt->arr_var->arr_name, vars->at(arrId).name.c_str()) == 0 && NVarType::Array)
					break;
			}
			if (stmt->arr_var->elem_type != String)
			{
				code_number(BIPUSH, 1);
				code_number(stmt->arr_var->size, 1);
				code_number(NEWARRAY, 1);
				if (stmt->arr_var->elem_type == Integer || stmt->arr_var->elem_type == Root_Integer || stmt->arr_var->elem_type == Boolean)
					code_number(10, 1);
				else if (stmt->arr_var->elem_type == Real || stmt->arr_var->elem_type == Float)
					code_number(6, 1);
				else if (stmt->arr_var->elem_type == Character)
					code_number(5, 1);
				code_number(ASTORE, 1);
				code_number(vars->at(arrId).id, 1);
				//���� ������� ������������� ��������
				if (stmt->arr_var->expression != NULL)
				{
					arrInitializing = true;
					for (int i = 0; i < stmt->arr_var->size; i++)
					{
						if (arrExpr == NULL)
							throw ("array size is bigger than initializing pool!");
						code_number(ALOAD, 1);
						code_number(vars->at(arrId).id, 1);
						code_number(BIPUSH, 1);
						code_number(i, 1);
						generate_expr_code(arrExpr);
						if (stmt->arr_var->elem_type == Integer || stmt->arr_var->elem_type == Root_Integer)
						code_number(IASTORE, 1);
						else if (stmt->arr_var->elem_type == Real || stmt->arr_var->elem_type == Float)
							code_number(FASTORE, 1);
						else if (stmt->arr_var->elem_type == Boolean)
							code_number(IASTORE, 1);
						//!!!��������
						else if (stmt->arr_var->elem_type == Character)
						{
						}
						if (arrExpr->next != NULL && i == stmt->arr_var->size-1)
							throw ("array size is lower than initializing pool!");
						arrExpr = arrExpr->next;
					}
					arrInitializing = false;
				}
			}
			//else if (stmt->arr_var->elem_type == String)
			//{
			//	SemanticalConst str = CONST_String;
			//	code_number(findType(str), 1);
			//}
			break;
		}
	case array_assign:
		{
			int x = 1;
			break;
		}
		*/
		/*
	case var_list_assign:
		{
			generate_varlist_assign_code(stmt->list);
			break;
		}
		*/
	case STMT_EXPR:
		{
			generate_expr_list_code(stmt->expr->idlist);
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
		/*
	case func_pr:
		{
			for (char el : all_code)
				code_of_methods[methodCounter].push_back(el);
			all_code.clear();
			generate_func_proc_code(stmt->func_proc);
			break;
		}
		*/
		/*
	case en:
		{

			break;
		}
		*/
	}
	if (stmt->next != NULL)
	{
		generate_stmt_code(stmt->next);
	}

}

void generate_varlist_assign_code(NExprList * assign)
{
	/*
	NVariable*var = assign->variables->first;
	while(var!=NULL)
	{
		LocalElement *el;
		if(var->type == Integer && var->value!=NULL)
		{
			generate_expr_code(var->value);
			code_number(ISTORE,1);
			el = is_in_local_vars(var->var_name);
			code_number(el->id,1);
		}
		else if((var->type == Real || var->type == Float) && var->value!=NULL)
		{
			generate_expr_code(var->value);
			code_number(FSTORE,1);
			code_number(is_in_local_vars(var->var_name)->id,1);
		}
		else if(var->type == Boolean&& var->value!=NULL)
		{
			generate_expr_code(var->value);
			code_number(ISTORE, 1);
			el = is_in_local_vars(var->var_name);
			code_number(el->id, 1);
		}
		else if(var->type == Character&& var->value!=NULL)
		{
		}
		else if(var->type == String&& var->value!=NULL)
		{
		}
		else if(var->type == Array&& var->value!=NULL)
		{
		}
		var=var->next;
	}
	*/
}

void generate_while_code(NWhile * While)
{
	/*
	int size;	//����� ������������ ��������
	int size2;
	int startCondition;
	union s2 temp;
	//1. ������������� ��� ��� �������� ������������ �������� � ��������� �� ����� ��� ���������� ����� �������� � ����������;
	if (!While->doWhile)
	{
		code_number(GO_TO, 1);
		code_number(0, 2);
	}
	size = all_code.size();
	//2. ������������� ��� ���� �����, ��������� GenerateCodeForBlock;
	generate_stmt_list_code(While->body);
	size2 = all_code.size();

	//3. ������������� ��� ���������� ��������� ���������, ��������� GenerateCodeForExpression,
	generate_expr_code(While->condition);

	//-----��������� ������� � ������ ���, ����� �� �������� �� ������ ���������� ���������;
	if (!While->doWhile)
	{
		temp = make_reversed_s2(size2 - size + 3);
		for (int i = 0; i < 2; i++)
			all_code.at(size - 2 + i) = temp.bytes[i];
	}
	//4. ������������� ��� �������� ifne ��� �������� � ������ ���� �����.
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
*/
}
void generate_for_code(NFor *For)
{
	/*
	loopVarName = (char*)malloc(sizeof(char) * strlen(For->condition->first->name)+1);
	loopVarName = For->condition->first->name;
	loopVarNames.push_back(loopVarName);
	loopCounter++;
	int size;	//����� ������������ ��������
	int size2;
	int startCondition;
	union s2 temp;
	if (For->inReverse == false)
	{
		//������ � ���������� ����� ����� �������
		generate_expr_code(For->begin);
		code_number(ISTORE, 1);
		code_number(200 + loopCounter, 1);
		// ������������� ��� ��� �������� ������������ �������� � ��������� �� ����� ��� ���������� ����� �������� � ����������;
		code_number(GO_TO, 1);
		code_number(0, 2);
		size = all_code.size();

		//������������� ��� ���� �����, ��������� GenerateCodeForBlock;
		generate_stmt_list_code(For->body);
		code_number(ILOAD, 1);
		code_number(200 + loopCounter, 1);
		code_number(ICONST_1, 1);
		code_number(IADD, 1);
		code_number(ISTORE, 1);
		code_number(200 + loopCounter, 1);

		size2 = all_code.size();

		//3. ������������� ��� ���������� ��������� ���������

		code_number(ILOAD, 1);
		code_number(200 + loopCounter, 1);
		generate_expr_code(For->end);
		code_number(IF_ICMPLE, 1);
		code_number(7, 2);
		code_number(ICONST_0, 1);
		code_number(GO_TO, 1);
		code_number(4, 2);
		code_number(ICONST_1, 1);

		//-----��������� ������� � ������ ���, ����� �� �������� �� ������ ���������� ���������;
		temp = make_reversed_s2(size2 - size + 3);
		for (int i = 0; i < 2; i++)
			all_code.at(size - 2 + i) = temp.bytes[i];



		//4. ������������� ��� �������� ifne ��� �������� � ������ ���� �����.
		code_number(IFNE, 1);
		temp = make_reversed_s2(size + 1 - all_code.size());
		for (int i = 0; i < 2; i++)
			all_code.push_back(temp.bytes[i]);
	}
	else
	{
		//������ � ���������� ����� ������ �������
		generate_expr_code(For->end);
		code_number(ISTORE, 1);
		code_number(200 + loopCounter, 1);
		// ������������� ��� ��� �������� ������������ �������� � ��������� �� ����� ��� ���������� ����� �������� � ����������;
		code_number(GO_TO, 1);
		code_number(0, 2);
		size = all_code.size();

		//������������� ��� ���� �����, ��������� GenerateCodeForBlock;
		generate_stmt_list_code(For->body);
		code_number(ILOAD, 1);
		code_number(200 + loopCounter, 1);
		code_number(ICONST_1, 1);
		code_number(ISUB, 1);
		code_number(ISTORE, 1);
		code_number(200 + loopCounter, 1);

		size2 = all_code.size();

		//3. ������������� ��� ���������� ��������� ���������

		code_number(ILOAD, 1);
		code_number(200 + loopCounter, 1);
		generate_expr_code(For->begin);
		code_number(IF_ICMPGE, 1);
		code_number(7, 2);
		code_number(ICONST_0, 1);
		code_number(GO_TO, 1);
		code_number(4, 2);
		code_number(ICONST_1, 1);

		//-----��������� ������� � ������ ���, ����� �� �������� �� ������ ���������� ���������;
		temp = make_reversed_s2(size2 - size + 3);
		for (int i = 0; i < 2; i++)
			all_code.at(size - 2 + i) = temp.bytes[i];

		//4. ������������� ��� �������� ifne ��� �������� � ������ ���� �����.
		code_number(IFNE, 1);
		temp = make_reversed_s2(size + 1 - all_code.size());
		for (int i = 0; i < 2; i++)
			all_code.push_back(temp.bytes[i]);
	}
	loopVarName = NULL;
	if (loopVarNames.size()>0)
	{
		loopVarName = (char*)malloc(sizeof(char)* strlen(loopVarNames.at(loopVarNames.size()-1) + 1));
		strcpy(loopVarName, loopVarNames.at(loopVarNames.size() - 1));
	}
	loopVarNames.erase(loopVarNames.begin()+loopVarNames.size()-1);
	loopCounter--;
	*/
}


void generate_arr_var_code(NExpr * var)
{
	/*
	if (var!= NULL)
	{
		generate_expr_list_code(var->expression);
		LocalElement * local = is_in_local_vars(var->arr_name);
		if(local != NULL)
		{
			code_number(ASTORE, 1);
			code_number(local->id, 1);
		}
	}
	*/
}
std::vector<char> empty_code;
void generate_func_proc_code(NFunc *func)
{
	/*
	code_of_methods.insert(code_of_methods.end(), empty_code);
	if (methodCounter >= 0)
	{
		for (char el : all_code)
			code_of_methods[methodCounter].push_back(el);
		all_code.clear();
	}
	methodCounter++;
	method1 = current_method;
	current_method = is_in_methods(func->name);

	generate_stmt_list_code(func->localVars);
	if (func->name == "main")
		methodCounter = 0;
	generate_stmt_list_code(func->body);
	if(func->isFunc)
		generate_return_code(func->type);
	else code_number(_RETURN, 1);
	for (char el : all_code)
		code_of_methods[methodCounter].push_back(el);
	all_code.clear();
	current_method = method1;
	*/
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

void generate_enum_code(NExpr * var)
{
	generate_var_code(var);
	//generate_name_list_code(var->idlist);
}

void generate_byte_code()
{
//	table_of_const = constT;
//	table_of_classes = classT;
//	file_name = "Main.class";
	generate_stmt_list_code(root);
	generate_class_file();
}

void generate_class_file()
{
	all_code.clear();
	char file_name [20];
	unsigned long int number;
	strcpy(file_name,"Main_Class");
	strcat(file_name, ".class");
	FILE* file_of_class;
	file_of_class = fopen("Main_Class.class","rb+wb");

	//����������� ��������� �����
	number = 0xCAFEBABE;
	code_number(number, 4);
	number = 0;
	code_number(number, 2);
	number = 52;
	code_number(number, 2);
	number = table.size() + 1;
	code_number(number, 2);
	code_const_table();
	number = 0x01;
	code_number(number, 2);
	number = 2;
	code_number(number, 2);
	//�������� Object
	number = 4;
	code_number(number, 2);
	//����������
	number = 0;
	code_number(number, 2);
	//����������� ���� ������
	number = 0;
	code_number(number, 2);
	//������ ������
	//number = parent_class->methods->size();
	code_number(number, 2);
	code_method_table();
	// �������� � ����
	number = 0;
	code_number(number, 2);
	write_byte_code(all_code);
	fclose(file_of_class);
}

void write_byte_code(std::vector<char> & code)
{
	FILE* output;
	output = fopen("Main_Class.class","rb+wb");

	if (code.size() != 0)
	{
		fwrite(&code[0] , sizeof(char), sizeof(code), output);
	}
}

#endif
