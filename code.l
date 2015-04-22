%{
#include "code.tab.h"
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
"func" {chars+=strlen(yytext); return  FUNC;}
"null" {chars+=strlen(yytext); return  NUL;}
"read" {chars+=strlen(yytext); return  READ;}
"return" {chars+=strlen(yytext); return  RETURN;}
"print" {chars+=strlen(yytext); return  PRINT;}
"paramx" {chars+=strlen(yytext); return  PARAMX;}
"begin " {chars+=strlen(yytext); return  BEG;}   
"end"  {chars+=strlen(yytext); return  END;}
"if" {chars+=strlen(yytext); return  IF;}
"FALSE" {chars+=strlen(yytext); return  FALSE;}
"goto" {chars+=strlen(yytext); return  GOTO;}
"param" {chars+=strlen(yytext); return  PARAM;}
"call" {chars+=strlen(yytext); return  CALL;}
"=" {chars+=strlen(yytext); return  ASSIGN;}
"==" {chars+=strlen(yytext); return  EQ;}
"!=" {chars+=strlen(yytext); return  NEQ;}
"<" {chars+=strlen(yytext); return  LT;}
"<=" {chars+=strlen(yytext); return  LTE;}
">" {chars+=strlen(yytext); return  GT;}
">=" {chars+=strlen(yytext); return  GTE;}
"+" {chars+=strlen(yytext); return  PLUS;}
"-" {chars+=strlen(yytext); return  MINUS;}
"*" {chars+=strlen(yytext); return  MULTIPLY;}
"," {chars+=strlen(yytext); return  COMMA;}
"/" {chars+=strlen(yytext); return  DIVISION;}
":" {chars+=strlen(yytext); return  COLON;}
[a-zA-Z_][a-zA-Z0-9_]* {string temp(yytext);token=temp;chars+=strlen(yytext); return  id;}
[0-9][0-9]* {string temp(yytext);token=temp;chars+=strlen(yytext); return  integer;}
.   return UNKNOWN;
%%
int yywrap(void)
{
	return 1;
}
