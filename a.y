%{
#define YYERROR_VERBOSE 1
#include <stdlib.h>
#include <sstream>
#include <string>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>	
#define YYSTYPE node*
using namespace std;
set<string> mah;
int chars = 1;
int arg_no;
int func_index;
int set_arg=0;
int set_param=0;
int iterat;
int semantic_error=0;
int lines = 1;
string token;
extern char *yytext;
int val=0;
struct symbol{
	string name;
	string type;
	int verify;
	int scope;
};
typedef struct symbol symbol;
struct func_defn{
	string name;
	string type;
	vector<symbol> params;
};
typedef struct func_defn func_defn;
symbol sym;
vector<symbol> v;
vector<func_defn> f;
vector<symbol> v2;
void yyerror (const char *);
int yylex(void);
int scope=1;
struct node{
	string nt;
	string val;
	string typ;
	int scope;
	int np;
	struct node **nptr;
};
bool chec_dec(node *a, node *b)
{
	if(b->typ=="")
		return true;
	else if(b->typ==a->typ)
		return true;
	else 
		return false;
}
void check_symbol(string type)
{
	int i=v.size()-1;
	while(v[i].verify==0 && i>=0)
	{
		if(v[i].type=="scope")
		{}
		else if(v[i].type==type)
			v[i].verify=0;
		else if (v[i].type=="")
		{
			v[i].type=type;
			v[i].verify=0;
		}
		else
		{
			semantic_error=1;
			v[i].verify=0;
			cout << "error: semantic error, Invalid assignment of '" << v[i].type << "' value to '" << type << "' variable line: " << lines   << endl;
			v[i].type=type;
		}
		--i;
	}
	i=v.size()-1;
	while(v[i].verify==0 && i>=0)
	{
		if(v[i].type=="scope")
		{}
		else
		{
			string temp=v[i].name;
			for(int j=i-1;j>=0 && v[j].type!="scope";j--)
				if(v[j].name==v[i].name)
				{
					semantic_error=1;
					cout << "error: semantic error, Multiple definitions of variable '" << v[i].name << "' line : " << lines << endl;
					break;
				}
			v[i].verify=1;
		}
		--i;
	}

}

void clear_scope()
{
	--scope;
	int i=v.size()-1;
	while(v[i].type!="scope")
	{
		v.erase(v.end());
		--i;
	}
}

string get_type(string name)
{
	int i=v.size()-1;
	while(i>=0 && v[i].name!=name)
		--i;
	if(i==-1)
		return "undefined";
	else
		return v[i].type;
}
typedef struct node node;

node* mkleaf(string det)
{
	node *a=new node[1];
	a->nt=det;
	a->np=0;
	a->nptr=NULL;
	return a;
}

node* mknode(string det,int n, ...)
{
	node *a=new node[1];
	a->nt=det;
	a->np=n;
	va_list vl;
	va_start(vl,n);
	a->nptr=(node**)malloc(n*sizeof(node*));
	int i;
	for(i=0;i<n;i++)
		a->nptr[i]=va_arg(vl,node*);
	return a;
}
node *root;
int ret_present=0;
%}
%token IF ELSE WHILE RETURN INT BOOL FALSE TRUE EQ NEQ LT LTE GT GTE LEFTPAR RIGHTPAR LEFTBRACE RIGHTBRACE  DELIMITER UNKNOWN VOID COMMA integer id PRINT READ 
%left MINUS PLUS
%right ASSIGN SUM_ASSIGN SUB_ASSIGN
%left MULTIPLY DIVISION

%%
CODE : DECLARATIONS {$$=$1;root=$$;};

DECLARATIONS : DECLARATIONS DECLARATION {$$=mknode("DEC",2,$1,$2);} 
	     | DECLARATION {$$=$1;}
	     ;

DECLARATION : VARIABLE_DEFINITION {$$=$1;}
	    | FUNCTION_DEFINITION {$$=$1;}
	    | error DELIMITER { val=1; yyclearin; }
	    ;

VARIABLE_DEFINITION : TYPE VARIABLES DELIMITER  {
							$$=mknode("VAR_DEF",3,$1,$2,mkleaf(";"));
							/*bool chec=chec_dec($1,$2);
							if(chec==false)
								cout << "Line no. " << lines << ": Invalid variable initialization\n";*/
						        check_symbol($1->typ);
						}
		    | TYPE error {val=1;}
		    ;

VARIABLES : VARIABLES COMMA VARIABLE_INITIALIZE {
							$$=mknode("VARS",3,$1,mkleaf(","),$3);
						/*	if($1->typ=="")
								$$->typ=$3->typ;
							else if($3->typ=="")
								$$->typ=$1->typ;
							else if($1->typ==$3->typ)
								$$->typ=$1->typ;
							else
								cout << "Line no. " << lines << ": Invalid varibale initialization\n";*/
						}
     	  | VARIABLE_INITIALIZE {
		  			$$=$1;
				}
	  ;

VARIABLE_INITIALIZE : IDENTIFIER {
					$$=$1;
					$$->scope=scope;
					symbol s;
					s.name=$1->val;
					s.type="";
					s.verify=0;
					s.scope=scope;
					v.push_back(s);v2.push_back(s);
				 }
		    | IDENTIFIER  ASSIGN SIMPLE_EXPRESSION {
			    					$$=mknode("VAR_INIT",3,$1,mkleaf("="),$3);
								$$->typ=$3->typ;
								$1->scope=scope;
								symbol s;
								s.name=$1->val;
								s.type=$3->typ;
								s.verify=0;
								s.scope=scope;
								v.push_back(s);v2.push_back(s);
							   }
		    ;

TYPE :	INT {$$=mkleaf("int");$$->typ="int";} 
     | BOOL {$$=mkleaf("bool");$$->typ="bool";}
     ;

FUNCTION_DEFINITION : TYPE IDENTIFIER LEFTPAR {func_defn fun;
						fun.name=$2->val;
						fun.type=$1->nt;
						f.push_back(fun);
						++scope;symbol s; 
						s.name="{";
						s.type="scope";
						s.scope=scope;
						v.push_back(s);
						v2.push_back(s);
						} 
			PARAMS RIGHTPAR LEFTBRACE STATEMENT_LIST RIGHTBRACE {clear_scope();}  {
			$$=mknode("FUNC_DEF",4,$1,$2,$5,$8);};


STATEMENT_LIST: STATEMENTS {$$=$1;} | ;

PARAMS : PARAMETERS {$$=$1;}
       | {$$=mkleaf("");}
       ;

PARAMETERS : PARAMETERS DELIMITER PARAMETER {$$=mknode("PARAMS",3,$1,mkleaf(";"),$3);}
           | PARAMETER {$$=$1;}
	   ;

PARAMETER : TYPE PARAMETER_IDS {
	$$=mknode("PARAM",2,$1,$2);
	$$->typ=$1->typ;
	int i=v.size()-1;
	while(i>=0 && v[i].verify==0)
	{
		symbol temp=v[i];
		temp.type=$1->typ;
		f[f.size()-1].params.push_back(temp);
		--i;
	}
	check_symbol($1->typ);
	}
	  ;

PARAMETER_IDS : PARAMETER_IDS COMMA IDENTIFIER {$$=mknode("PARAM_IDS",3,$1,mkleaf(","),$3);$3->scope=scope;symbol s;s.name=$3->val;s.type="";s.verify=0;s.scope=scope;v.push_back(s);v2.push_back(s);}
	      | IDENTIFIER {$$=$1;$$->scope=scope;symbol s;s.name=$1->val;s.type="";s.verify=0;s.scope=scope;v.push_back(s);v2.push_back(s);}
	      ;

STATEMENT : VARIABLE_DEFINITION{$$=$1;} 
	  | EXP {$$=$1;}
	  | CONDITIONAL {$$=$1;}
	  | LOOP 
	  | PRINT_STATEMENT {$$=$1;}
	  | READ_STATEMENT {$$=$1;}
	  | RETURN_STATEMENT {$$=$1;} 
	  ;

STATEMENTS : STATEMENT STATEMENTS {$$=mknode("STMNTS",2,$1,$2);}
	   | leftbrace STATEMENT_LIST RIGHTBRACE {clear_scope();} STATEMENTS {$$=mknode("STMNTS",2,$2,$5);} 
	   | STATEMENT {$$=$1;} 
	   ;

PRINT_STATEMENT : PRINT IDENTIFIER {$$=mknode("PRINT_STMNT",2,mkleaf("print"),$2);}
		| PRINT LITERALS {$$=mknode("PRINT_STMNT",2,mkleaf("print"),$2);};

READ_STATEMENT : READ IDENTIFIER {$$=mknode("READ_STMNT",2,mkleaf("read"),$2);};

EXP : EXPRESSION DELIMITER {$$=mknode("EXP",2,$1,mkleaf(";"));}
    | DELIMITER {$$=mkleaf(";");}
    ;

CONDITIONAL : IF LEFTPAR SIMPLE_EXPRESSION RIGHTPAR leftbrace  STATEMENT_LIST RIGHTBRACE {clear_scope();$$=mknode("COND",3,mkleaf("if"),$3,$6);}
	    | IF LEFTPAR SIMPLE_EXPRESSION RIGHTPAR leftbrace  STATEMENT_LIST RIGHTBRACE {clear_scope();} ELSE leftbrace  STATEMENT_LIST RIGHTBRACE {clear_scope();$$=mknode("COND",5,mkleaf("if"),$3,$6,mkleaf("else"),$11);}
	    ;

LOOP : WHILE LEFTPAR SIMPLE_EXPRESSION RIGHTPAR leftbrace  STATEMENT_LIST RIGHTBRACE {clear_scope();$$=mknode("LOOP",3,mkleaf("while"),$3,$6);};

RETURN_STATEMENT : RETURN DELIMITER {$$=mknode("RET",2,mkleaf("return"),mkleaf(";"));}
		 | RETURN EXPRESSION DELIMITER {$$=mknode("RET",3,mkleaf("return"),$2,mkleaf(";"));
		 if($2->typ!=f[f.size()-1].type)
			 cout << "error: semantic error, return type does not match with function definition line: " << lines << endl;
		 }
		 ;

EXPRESSION : IDENTIFIER ASSIGN EXPRESSION {
	$$=mknode("EXPR",3,$1,mkleaf("="),$3);
	if(get_type($1->val)=="undefined")
	{
		semantic_error=1;
		cout << "error: semantic error, variable '" << $1->val << "' undefined line: " << lines << endl;
	}
	else if(get_type($1->val)!=$3->typ)
	{
		semantic_error=1;
		cout << "error: semantic error, Invalid assignment of '" << $3->typ << "' value to '" << get_type($1->val) << "' variable line: " << lines <<  endl;
	}
	}
	   | IDENTIFIER SUM_ASSIGN EXPRESSION {$$=mknode("EXPR",3,$1,mkleaf("+="),$3);
	if(get_type($1->val)=="undefined")
	{
		semantic_error=1;
		cout << "error: semantic error, variable '" << $1->val << "' undefined line: " << lines << endl;
	}
	else if(get_type($1->val)!=$3->typ)
	{
		semantic_error=1;
		cout << "error: semantic error, Invalid assignment of '" << $3->typ << "' value to '" << get_type($1->val) << "' variable line: " << lines <<  endl;
	}
}
	   | IDENTIFIER SUB_ASSIGN EXPRESSION {$$=mknode("EXPR",3,$1,mkleaf("-="),$3);
	if(get_type($1->val)=="undefined")
		cout << "error: semantic error, variable '" << $1->val << "' undefined line: " << lines << endl;
	else if(get_type($1->val)!=$3->typ)
		cout << "error: semantic error, Invalid assignment of '" << $3->typ << "' value to '" << get_type($1->val) << "' variable line: " << lines <<  endl;
}
	   | SIMPLE_EXPRESSION {$$=$1;}
	   ;

SIMPLE_EXPRESSION : SUM RELATIONAL_OPERATORS SUM {
	$$=mknode("SIMPL_EXPR",3,$1,$2,$3);
	if($1->typ==$3->typ)
		$$->typ="bool";
	else
		cout << "error: semantic error, Comparison of '" << $1->typ << "' with '" << $3->typ << " line :" << lines << endl;

	}
		  | SUM {$$=$1;}
		  ;

RELATIONAL_OPERATORS : LTE {$$=mkleaf("<=");$$->typ="bool";}
		     | LT {$$=mkleaf("<");$$->typ="bool";}
		     | GT {$$=mkleaf(">");$$->typ="bool";}
		     | GTE {$$=mkleaf(">=");$$->typ="bool";}
		     | EQ {$$=mkleaf("==");$$->typ="bool";}
		     | NEQ {$$=mkleaf("!=");$$->typ="bool";}
		     ;

SUM : SUM ARITHMETIC_OPERATORS TERM {
	$$=mknode("SUM",3,$1,$2,$3);
	$$->typ="int";
	if($1->typ=="bool" || $3->typ=="bool")
		cout << "error: semantic error, boolean value given as operand to arithmetic opertor '" << $2->val << "' line: " << lines << endl;
	}
    | TERM {$$=$1;}
    ;

ARITHMETIC_OPERATORS : PLUS {$$=mkleaf("+");$$->val="+";}
   		     | MINUS {$$=mkleaf("-");$$->val="-";}
		     ;

TERM : TERM MUL_DIV_OPERATORS UNARY_EXPRESSION {$$=mknode("TERM",3,$1,$2,$3);$$->typ="int";
	if($1->typ=="bool" || $3->typ=="bool")
		cout << "error: semantic error, boolean value given as operand to arithmetic opertor '" << $2->val << "' line: " << lines << endl;
}
     | UNARY_EXPRESSION {$$=$1;}
     ;

MUL_DIV_OPERATORS : MULTIPLY {$$=mkleaf("*");$$->val="*";}
		  | DIVISION {$$=mkleaf("/");$$->val="/";}
		  ;

UNARY_EXPRESSION : UNARY_OPERATOR UNARY_EXPRESSION {$$=mknode("UN_EXP",2,$1,$2);$$->typ="int";
	if($2->typ=="bool")
		cout << "error: semantic error, boolean value given as operand to unary operator '" << $2->val << "' line: " << lines << endl;
}
		 | FACTOR {$$=$1;}
		 ;

UNARY_OPERATOR : MINUS {$$=mkleaf("-");$$->val="-";}
	       ;

FACTOR : L_VALUE {$$=$1;}
       | IDENTIFIER {
	       $$=$1;
	       $$->typ=get_type($$->val);
	       if($$->typ=="undefined")
		       cout << "error: semantic error, variable '" << $$->val << "' undefined line: " << lines << endl;
       		}
       ;

L_VALUE : LEFTPAR EXPRESSION RIGHTPAR {$$=$2;}
	| FUNCTION_CALL {$$=$1;}
	| LITERALS {$$=$1;}
	;

FUNCTION_CALL : IDENTIFIER LEFTPAR {
	int i=f.size()-1;
	 while(i>=0 && f[i].name!=$1->val)
		 --i;
	 if(i<0)
	 {
		cout << "error: semantic error, function '" << $1->val << "' is not defined line: " << lines << endl;
		iterat=-1;
	 }
         else
	 { 
		arg_no=f[i].params.size();
		 iterat=0;
		 func_index=i;
	 }
} ARGUMENT RIGHTPAR {
	$$=mknode("FUNC_CALL",2,$1,$4);
	int i=0;
	while(f[i].name!=$1->val)
		++i;
	$$->typ=f[i].type;
	stringstream ss;
	ss << arg_no;
	$$->val=ss.str();
	if(iterat>=0 && iterat!=arg_no)
		cout << "error: semantic error, insufficient number of arguments line: " << lines << endl;
}
	      ;

ARGUMENT : ARGUMENTS {$$=$1;}
	 | {$$=mkleaf("");}
	 ;

ARGUMENTS : ARGUMENTS COMMA EXPRESSION {$$=mknode("ARGS",3,$1,mkleaf(","),$3);
		  if(iterat>=0 && iterat<arg_no)
		  {
			  if(f[func_index].params[iterat].type!=$3->typ)
				  cout << "error: semantic error, passed '" << $3->typ << "' argument to '" << f[func_index].params[iterat].type << "' parameter while calling function '" << f[func_index].name << "' line: " << lines << endl;
			  ++iterat;
		  }
		  else if(iterat>=0)
			  cout << "error: semantic error, extra arguments are passed to function '" << f[func_index].name << "' line: " << lines << endl;
}
	  | EXPRESSION {
		  $$=$1;
		  if(iterat>=0 && iterat<arg_no)
		  {
			  if(f[func_index].params[iterat].type!=$1->typ)
				  cout << "error: semantic error, passed '" << $1->typ << "' argument to '" << f[func_index].params[iterat].type << "' parameter while calling function '" << f[func_index].name << "' line: " << lines << endl;
			  ++iterat;
		  }
		  else if(iterat>=0)
			  cout << "error: semantic error, extra arguments are passed to function '" << f[func_index].name << "' line: " << lines << endl;
		  }
	  ;

LITERALS : INTEGERS {$$=$1;}
	 | TRUE {$$=mkleaf("BOOLEAN");$$->typ="bool";$$->val="true";}
 	 | FALSE {$$=mkleaf("BOOLEAN");$$->typ="bool";$$->val="false";}
	 ;
IDENTIFIER : id 
	    {
		    $$=mkleaf("IDENTIFIER");
		    $$->val=token;
		    for(int i=v.size()-1;i>=0;i--)
			    if(v[i].name==token)
			    {
				    $$->scope=v[i].scope;
				    break;
			    }
			    else
				    $$->scope=scope;
		    $$->typ="";
	    }
	    ;

INTEGERS : integer
	  {
		  $$=mkleaf("INTEGERS");
		  $$->val=token;
		  $$->typ="int";
	  }
leftbrace : LEFTBRACE {++scope;symbol s; s.name="{";s.type="scope";v.push_back(s);v2.push_back(s);};

%%
void yyerror(const char *s)
{
	fprintf(stderr,"error: %s line: %d column : %d\n",s,lines,chars);
}
void dfs(node *p)
{
	if(p->np==0)
	{
		cout << "'" << p->nt << "' ";
	}
	else
	{
		int i;
		for(i=0;i<p->np;i++)
			dfs(p->nptr[i]);
		cout << p->nt << " ";
	}
}
string get_new_reg(){
	static int coun=0;
	stringstream ss;
	ss << "r" << coun ;
	coun++;
	return ss.str();
}
string get_new_var(node *p){
	stringstream ss;
	ss << p->val << p->scope;
	return ss.str();
}
int check_label(string temp)
{
	for(int i=0;i<f.size();i++)
		if(f[i].name==temp)
			return -1;
	return 0;
}
string get_new_label(){
	static int num=0;
	stringstream ss;
	do{
	ss.str("");
	ss << "label" << num;
	num++;
	}
	while(check_label(ss.str())!=0);
	return ss.str();
}
int get_max_para(node *root)
{
	string c=root->nt;
	node** p=root->nptr;
	int count=0;
	if(c=="FUNC_CALL")
	{
		int i=0;
		while(f[i].name!=p[0]->val)
			++i;
		count=(f[i].params.size());
	}
	else
	{
		for(int i=0;i<root->np;i++)
			count = max(count,get_max_para(p[i]));
	}
	return count;
}
int get_var_count(node *root)
{
	string c=root->nt;
	node** p=root->nptr;
	int count=0;
	if(c=="VAR_INIT")
	{
		count += get_var_count(p[0]);
		count += get_var_count(p[2]);
	}
	else if(c=="SUM")
	{
		if(set_arg==1)
			set_arg=0;
		count =1;
		count += get_var_count(p[0]);
		count += get_var_count(p[2]);
	}
	else if(c=="TERM")
	{
		count = 1;
		count +=  get_var_count(p[0]);
		count += get_var_count(p[2]);
	}
	else if(c=="IDENTIFIER")
	{
		string temp=get_new_var(root);
		if(mah.find(temp)==mah.end())
		{
			count=1;
			mah.insert(temp);
		}
		if(set_arg==1)
			++count;
	}
	else if(c=="INTEGERS")
	{
		if(set_arg==1)
			count=1;
	}
	else if(c=="BOOLEAN")
	{
		count=1;
	}
	else if(c=="EXPR")
	{
			count += get_var_count(p[0]);
			count += get_var_count(p[2]);
	}
	else if(c=="SIMPL_EXPR")
	{
		if(set_arg==1)
			set_arg=0;
		count=1;
		count += get_var_count(p[0]);
		count += get_var_count(p[2]);
	}
	else if(c=="COND")
	{
		if(root->np==3)	
		{
			count += get_var_count(p[1]); 
			count += get_var_count(p[2]);
		}
		else
		{
			count += get_var_count(p[1]);
			count += get_var_count(p[2]);
			count += get_var_count(p[4]);
		}
	}
	else if(c=="LOOP")
	{
		count +=  get_var_count(p[1]);
		count += get_var_count(p[2]);
	}
	else if(c=="FUNC_DEF")
	{
		count += get_var_count(p[2]);
		count += get_var_count(p[3]);
	}
	else if(c=="RET")
	{
		if(root->np==3)
			count += get_var_count(p[1]);
	}
	else if(c=="FUNC_CALL")
	{
		set_arg=1;
		count=1;
		count += get_var_count(p[1]);
		set_arg=0;
	}
	else if(c=="PRINT_STMNT")
	{
		count += get_var_count(p[1]);
	}
	else if(c=="UN_EXP")
	{
		count=1;
		count +=get_var_count(p[1]);
	}
	else
	{
		for(int i=0;i<root->np;i++)
			count += get_var_count(p[i]);
	}
	return count;
}
string three_addr_code(node *root)
{
	string c=root->nt;
	//cout << c << endl;
	node** p=root->nptr;
	if(c=="VAR_INIT")
	{
		cout << three_addr_code(p[0]) << "=" << three_addr_code(p[2]) << endl;
		return "";
	}
	else if(c=="SUM")
	{
		int temp=set_arg;
		set_arg=0;
		string reg=get_new_reg();
		cout << reg << "=" << three_addr_code(p[0]) << p[1]->val << three_addr_code(p[2]) << endl;
		if(temp==1)
		{
			cout << "param " << reg << endl;
			set_arg=1;
		}
		return reg;
	}
	else if(c=="TERM")
	{
		int temp=set_arg;
		set_arg=0;
		string reg=get_new_reg();
		cout << reg << "=" << three_addr_code(p[0])<< p[1]->val << three_addr_code(p[2]) << endl;
		if(temp==1)
		{
			cout << "param " << reg << endl;
			set_arg=1;
		}
		return reg;
	}
	else if(c=="IDENTIFIER")
	{
		int temp=set_arg;
		if(set_param==1)
			cout << get_new_var(root) << " " ;
		string r1=get_new_var(root);
		if(temp==1)
		{
			string r2=get_new_reg();
			cout << r2 << "=" << r1 << endl;
			cout << "param " << r2 << endl;
			return r2 ;
		}
		return r1;
	}
	
	else if(c=="PRINT_STMNT")
	{
		cout << "print " << three_addr_code(p[1]) << endl;
	}
	else if(c=="READ_STMNT")
	{
		cout << "read " << three_addr_code(p[1]) << endl;
	}
	else if(c=="INTEGERS")
	{
		int temp=set_arg;
		if(temp==1)
		{
			string r1=get_new_reg();
			cout << r1 << "=" << root->val << endl;
			cout << "param " << r1 << endl;
			return r1;
		}
		return root->val;
	}
	else if(c=="BOOLEAN")
	{
		int temp=set_arg;
		string r1=get_new_reg();
		cout << r1 << "=" ;
		if(root->val=="true")
			cout << "1" << endl;
		else
			cout << "0" << endl;
		if(temp==1)
			cout << "param " << r1 << endl;
		return r1;
	}
	else if(c=="EXPR")
	{
		int temp=set_arg;
		set_arg=0;
		if(p[1]->nt=="=")
			cout << three_addr_code(p[0]) << "=" << three_addr_code(p[2]) << endl;
		else if(p[1]->nt=="+=")
			cout << three_addr_code(p[0]) << "="<< three_addr_code(p[0]) << "+" << three_addr_code(p[2]) << endl;
		else 
			cout << three_addr_code(p[0]) << "="<< three_addr_code(p[0]) << "-" << three_addr_code(p[2]) << endl;
		if(temp==1)
		{
			cout << "param " << three_addr_code(p[0]) << endl;
			set_arg=1;
		}
		return "";
	}
	else if(c=="SIMPL_EXPR")
	{
		int temp=set_arg;
		set_arg=0;
		string reg=get_new_reg();
		cout << reg << "=" << three_addr_code(p[0])<< p[1]->nt << three_addr_code(p[2]) << endl;
		if(temp==1)
		{
			cout << "param " << reg << endl;
			set_arg=1;
		}
		return reg;
	}
	else if(c=="COND")
	{
		string continue_label=get_new_label();
		string false_label=get_new_label();
		if(root->np==3)
		{
			cout << "if FALSE " << three_addr_code(p[1]) << " goto " << continue_label <<  endl;
			three_addr_code(p[2]);
			cout << continue_label << ":" << endl;
			return "";
		}
		else
		{
			cout << "if FALSE " << three_addr_code(p[1]) << " goto " << false_label << endl;
			three_addr_code(p[2]);
			cout << "goto " << continue_label << endl;
			cout << false_label << ":" << endl;
			three_addr_code(p[4]);
			cout << continue_label << ":" << endl;
			return "";
		}
	}
	else if(c=="LOOP")
	{
		string loop_label=get_new_label();
		string continue_label=get_new_label();
		cout << loop_label << ":" << endl;
		cout << "if FALSE " << three_addr_code(p[1]) << " goto " << continue_label << endl;
		three_addr_code(p[2]);
		cout << "goto " << loop_label << endl;
		cout << continue_label << ":" << endl;
	}
	else if(c=="FUNC_DEF")
	{
		set_param=1;
		cout << p[1]->val << ":" << endl;
		mah.clear();
		set_arg=0;
		int temp1=get_var_count(root);
		int temp3=get_max_para(p[3]);
		int frame_size=4*(2+temp1+temp3);
		if(frame_size%8!=0)
		frame_size += 8-(frame_size%8);
		cout << "func begin " << frame_size << "," <<  temp3 <<endl;
		cout << "paramx " ;
		three_addr_code(p[2]);
		cout << "," << endl;
		set_param=0;
		ret_present=0;
		three_addr_code(p[3]);
		if(ret_present==0)
			cout << "return null" << endl;
		cout << "func end" << endl; 
		return "";
	}
	else if(c=="RET")
	{
		ret_present=1;
		if(root->np==3)
			cout << "return " <<  three_addr_code(p[1]);
		else
			cout << "return null";
		cout << endl;
		return "";
	}
	else if(c=="FUNC_CALL")
	{
		set_arg=1;
		string r1=get_new_reg();
		three_addr_code(p[1]);
		set_arg=0;
		cout << r1 << " = call " << p[0]->val << "," << root->val << endl;
		return r1;
	}
	else if(c=="UN_EXP")
	{
		int temp=set_arg;
		set_arg=0;
		string reg=get_new_reg();
		cout << reg << "= -" << three_addr_code(p[1]) << endl;
		if(temp==1)
		{
			cout << "param " << reg << endl;
			set_arg=1;
		}
		return reg;
	}
	else
	{
		for(int i=0;i<root->np;i++)
			three_addr_code(p[i]);
		return "";
	}
}

int main()
{
	val=(val+yyparse());
/*	if(val==0)
	{
		dfs(root);
		printf("\n");
	}*/
//	for(int i=0;i<v2.size();i++)
//		cout << v2[i].name << " " << v2[i].scope << " " << endl;
	if(val==0 && semantic_error==0)
		three_addr_code(root);
	return 1;
}
