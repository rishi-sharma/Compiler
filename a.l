%{
#include "a.tab.h"
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
extern int chars;
extern int lines;
extern string token;
%}
%%
[\n] {chars=1;lines++;}
[ \t] ;
"if" {chars+=strlen(yytext); return  IF;}
"else" {chars+=strlen(yytext); return  ELSE;}
"while" {chars+=strlen(yytext); return  WHILE;}
"print" {chars+=strlen(yytext); return  PRINT;}
"read" {chars+=strlen(yytext); return  READ;}
"return" {chars+=strlen(yytext); return RETURN;}
"int" {chars+=strlen(yytext); return  INT;}
"bool" {chars+=strlen(yytext); return  BOOL;}
"false" {chars+=strlen(yytext); return  FALSE;}
"true" {chars+=strlen(yytext); return  TRUE;}
"void" {chars+=strlen(yytext); return  VOID;}
[a-zA-Z_][a-zA-Z0-9_]* {string temp(yytext);token=temp;chars+=strlen(yytext); return  id;}
[0-9][0-9]* {string temp(yytext);token=temp;chars+=strlen(yytext); return  integer;}
"=" {chars+=strlen(yytext); return  ASSIGN;}
"+=" {chars+=strlen(yytext); return  SUM_ASSIGN;}
"-=" {chars+=strlen(yytext); return  SUB_ASSIGN;}
"==" {chars+=strlen(yytext); return  EQ;}
"!=" {chars+=strlen(yytext); return  NEQ;}
"<" {chars+=strlen(yytext); return  LT;}
"<=" {chars+=strlen(yytext); return  LTE;}
">" {chars+=strlen(yytext); return  GT;}
">=" {chars+=strlen(yytext); return  GTE;}
"(" {chars+=strlen(yytext); return  LEFTPAR;}
")" {chars+=strlen(yytext); return  RIGHTPAR;}
"+" {chars+=strlen(yytext); return  PLUS;}
"-" {chars+=strlen(yytext); return  MINUS;}
"*" {chars+=strlen(yytext); return  MULTIPLY;}
"/" {chars+=strlen(yytext); return  DIVISION;}
"{" {chars+=strlen(yytext); return  LEFTBRACE;}
"}" {chars+=strlen(yytext); return  RIGHTBRACE;}
";" {chars+=strlen(yytext); return  DELIMITER;}
"," {chars+=strlen(yytext); return  COMMA;}
.   return UNKNOWN;
%%
int yywrap(void)
{
	return 1;
}