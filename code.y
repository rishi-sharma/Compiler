%{
#define YYERROR_VERBOSE 1
#include <stdlib.h>
#include <sstream>
#include <string>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#define YYSTYPE node*
using namespace std;
struct symbol{
	string name;
	int val;
	int off;
};
int yylex();
void yyerror(const char*);
vector<symbol> f;
vector<symbol> v;
vector<symbol> g;
int global=0;
struct node{
	string name;
	int val;
};
int find_var(string temp)
{
	for(int i=0;i<v.size();i++)
		if(v[i].name==temp)
			return i;
	return -1;
}
int offset=0;
int para_count=0;
int local_off=0;
int arg_off=0;
int lines=0,chars=0;
string token;
%}

%token ASSIGN EQ NEQ LT GT LTE GTE PLUS MINUS MULTIPLY DIVISION UNKNOWN id integer COLON FUNC BEG END IF FALSE GOTO PARAM CALL PARAMX COMMA RETURN PRINT READ NUL 
%%


DECS : DECS DEC
       |
       DEC 
       ;

IDENTIFIER_LIST:  IDENTIFIER_LIST IDENTIFIER {
			 			symbol s;
						s.name=$2->name;
						s.val=0;
						s.off=offset;
						offset += 4;
						cout << "lw $t0," << 4*(v.size()-g.size()) << "($fp)" << endl;
						cout << "sw $t0," << offset-4 << "($sp)" << endl;
						v.push_back(s);
		 			    }
					    |  
					    ;

DEC :	PRINT FACTOR{
			if($2->name=="")
				cout << "li $a0," << $2->val << endl;
			else
			{
				int i=find_var($2->name);
				if(v[i].val==1)
					cout << "lw $a0," << v[i].name << endl;
				else
					cout << "lw $a0," << v[i].off << "($sp)" << endl;
			}
			cout << "li $v0,1" << endl;
			cout << "syscall" << endl;
			cout << "li $v0,4" << endl;
			cout << "la $a0,__newline" << endl;
			cout << "syscall" << endl;

		    }
	|
	READ FACTOR{
			cout << "li $v0,5" << endl;
			cout << "syscall" << endl;
			int i=find_var($2->name);
			if(v[i].val==0)
			cout << "sw $v0," << v[i].off << "($sp)" << endl;
			else
			cout << "sw $v0," << v[i].name << endl;
		    }
	|
	PARAM IDENTIFIER {
				int i=find_var($2->name);
				if(v[i].val==1)
					cout << "lw $t2," << v[i].name << endl;
				else
					cout << "lw $t2," << v[i].off << "($sp)" << endl;
				cout << "sw $t2," << arg_off << "($sp)" << endl;
				arg_off += 4;
				++para_count;
			 }
	|
	IF FALSE IDENTIFIER GOTO IDENTIFIER {
						int i=find_var($3->name);
						if(v[i].val==1)
							cout << "lw $t2," << v[i].name << endl;
						else
							cout << "lw $t2," << v[i].off << "($sp)" << endl;
						cout << "beqz $t2," << $5->name << endl;
					    }
	|
	GOTO IDENTIFIER {
				cout << "la $t2," << $2->name << endl;
				cout << "jr $t2" << endl;
			}
	|
	IDENTIFIER ASSIGN EXPR {
					int i=find_var($1->name);
					symbol s;
					if(i==-1)
					{
						s.name=$1->name;
						s.val=0;
						s.off=offset;
						offset += 4;
						v.push_back(s);
						i=v.size()-1;
					}
					if(global==0)
					{
						offset -= 4;
						s.val=1;
						v[i].val=1;
						g.push_back(s);
						cout << $1->name << " : .word " << $3->val << endl;
					}
					else
					{
						if(v[i].val==1)
							cout << "sw $t2," << v[i].name << endl;
						else
							cout << "sw $t2," << v[i].off << "($sp)" << endl;
					}
				}
	|

	IDENTIFIER COLON { if(global==0)
				cout << ".text" << endl;
			   global=1;
			   cout << $1->name << ":" << endl;
			   symbol a;
			   a.name=$1->name;
			   f.push_back(a);
			 }
	|

	FUNC BEG INTEGER COMMA INTEGER {
						cout << "addi $sp,$sp,-" << $3->val << endl;
						cout << "addi $t2,$sp,0" << endl;		// Storing the frame pointer pointing to stack start
						offset=$5->val*4+8;
						local_off=offset;
						cout << "sw $fp," << offset-4 <<"($sp)" << endl;
						cout << "sw $ra," << offset-8 << "($sp)" << endl;		// Storing the return address
						f[f.size()-1].val=$3->val;
						f[f.size()-1].off=$5->val;
						v.clear();
						v=g;
				       } PARAMX {			       		
				       		}
					       IDENTIFIER_LIST COMMA DECS FUNC END 
	|
	RETURN FACTOR {
		cout << "lw $fp," << local_off-4 << "($sp)" << endl;
		cout << "lw $ra," << local_off-8 << "($sp)" << endl;
		if($2->name=="")
			cout << "li $v0," << $2->val << endl;
		else
		{
			int i=find_var($2->name);
			cout << "lw $v0," << v[i].off << "($sp)" << endl;
		}
		cout <<	 "addi $sp,$fp,0" << endl;
		cout <<	 "jr $ra" << endl;
		}
	|
	RETURN NUL{
		cout << "lw $fp," << local_off-4 << "($sp)" << endl;
		cout << "lw $ra," << local_off-8 << "($sp)" << endl;
		cout <<	 "addi $sp,$fp,0" << endl;
		cout <<	 "jr $ra" << endl;
		}
	;

EXPR :  FACTOR REL_OP FACTOR {
				if($1->name=="")
					cout << "li $t0," << $1->val << endl;
				else
				{
					int i=find_var($1->name);
					if(v[i].val==1)
						cout << "lw $t0," << v[i].name << endl;
					else
					cout << "lw $t0," << v[i].off << "($sp)" << endl;
				}
				if($3->name=="")
					cout << "li $t1," << $3->val << endl;
				else
				{
					int i=find_var($3->name);
					if(v[i].val==1)
						cout << "lw $t1," << v[i].name << endl;
					else
					cout << "lw $t1," << v[i].off << "($sp)" << endl;
				}
				node *a=new node[1];$$=a;
				switch($2->val)
				{
					case 0: cout << "slt $t2,$t0,$t1" << endl;
						break;
					case 1: cout << "slt $t2,$t1,$t0" << endl;
						break;
					case 2: cout << "slt $t2,$t1,$t0" << endl;
						cout << "not $t2,$t2" << endl;
						cout << "andi $t2,$t2,1" << endl;
						break;
					case 3: cout << "slt $t2,$t0,$t1" << endl;
						cout << "not $t2,$t2" << endl;
						cout << "andi $t2,$t2,1" << endl;
						break;
					case 4: cout << "slt $t2,$t0,$t1" << endl;
						cout << "slt $t3,$t1,$t0" << endl;
						cout << "or $t2,$t2,$t3" << endl;
						cout << "not $t2,$t2 " << endl;
						cout << "andi $t2,$t2,1" << endl;
						break;
					case 5: cout << "slt $t2,$t1,$t0" << endl;
						cout << "slt $t3,$t0,$t1" << endl;
						cout << "or $t2,$t2,$t3" << endl;
						break;
					default: break;
				}
			       }
	|
	FACTOR ARITH_OP FACTOR {
				if($1->name=="")
					cout << "li $t0," << $1->val << endl;
				else
				{
					int i=find_var($1->name);
					if(v[i].val==1)
						cout << "lw $t0," << v[i].name << endl;
					else
					cout << "lw $t0," << v[i].off << "($sp)" << endl;
				}
				if($3->name=="")
					cout << "li $t1," << $3->val << endl;
				else
				{
					int i=find_var($3->name);
					if(v[i].val==1)
						cout << "lw $t1," << v[i].name << endl;
					else
					cout << "lw $t1," << v[i].off << "($sp)" << endl;
				}
				node *a=new node[1];$$=a;
				switch($2->val)
				{
					case 0: cout << "add $t2,$t1,$t0" << endl;
						break;
					case 1: cout << "sub $t2,$t0,$t1" << endl;
						break;
					case 2: cout << "mult $t1,$t0" << endl;
						cout << "mflo $t2" << endl;
						break;
					case 3: cout << "div $t0,$t1" << endl;
						cout << "mflo $t2" << endl;
						break;
					default: break;
				}
			       } 
	|
	MINUS FACTOR {
		     	node *a=new node[1];
			$$=a;
			if($2->name=="")
				cout << "li $t2," << $2->val*-1 << endl;
			else
			{
				int i=find_var($2->name);
					if(v[i].val==1)
						cout << "lw $t0," << v[i].name << endl;
					else
				cout << "lw $t0," << v[i].off << "($sp)" << endl;
				cout << "negu $t2,$t0" << endl;
			}
		     }
	| 
	FACTOR  {
			$$=$1;
			if($1->name=="")
			{
				if(global!=0)
				cout << "li $t2," << $1->val << endl;
			}
			else
			{
				int i=find_var($1->name);
				if(v[i].val==1)
					cout << "lw $t2," << v[i].name << endl;
				else
					cout << "lw $t2," << v[i].off << "($sp)" << endl;

			}
		}
	|
	FUNC_CALL
	;

FUNC_CALL: CALL IDENTIFIER COMMA INTEGER  {
								int i=f.size()-1;
								while(i>=0)
								{
									if(f[i].name==$2->name)
										break;
									--i;
								}
								int shift=4*($4->val);
								arg_off -= shift;
								cout << "addi $fp,$sp,0" << endl;
								cout << "jal " << $2->name << endl;
								cout << "addi $t2,$v0,0" << endl;
					  }

ARITH_OP : PLUS {node *a=new node[1];$$=a;$$->val=0;} 
	   | 
	   MINUS {node *a=new node[1];$$=a;$$->val=1;}
	   | 
	   MULTIPLY {node *a=new node[1];$$=a;$$->val=2;}
	   | 
	   DIVISION {node *a=new node[1];$$=a;$$->val=3;}
	   ;

REL_OP :   LT {node *a=new node[1];$$=a;$$->val=0;} 
	   | 
	   GT {node *a=new node[1];$$=a;$$->val=1;}
	   | 
	   LTE {node *a=new node[1];$$=a;$$->val=2;}
	   | 
	   GTE {node *a=new node[1];$$=a;$$->val=3;}
	   |
	   EQ {node *a=new node[1];$$=a;$$->val=4;}
	   |
	   NEQ {node *a=new node[1];$$=a;$$->val=5;}
	   ;
FACTOR : IDENTIFIER{
			$$=$1;
			int i=find_var($1->name);
			symbol s;
			if(i==-1)
			{
				s.name=$1->name;
				s.val=0;
				s.off=offset;
				offset += 4;
				v.push_back(s);
				i=v.size()-1;
			}
		    } 
	| 
	INTEGER {
			$$=$1;
		 }
	;
IDENTIFIER : id{
	node *a=new node[1];
	$$=a;
	$$->name=token;
};
INTEGER : integer{
	stringstream ss;
	ss << token;
	node *a=new node[1];$$=a;
	ss >> $$->val;
	$$->name="";
};

%%
void yyerror(const char *s)
{
	fprintf(stderr,"error: %s line: %d\n",s,lines);
}
int main()
{
	cout << ".data" << endl;
	cout << "__newline : .ascii \"\\n\"" << endl;
	yyparse();
	cout << "li $v0,10\nsyscall" << endl;
/*	if(val==0)
	{
		dfs(root);
		printf("\n");
	}*/
//	for(int i=0;i<v2.size();i++)
//		cout << v2[i].name << " " << v2[i].scope << " " << endl;
	return 1;
}
