%{
	#include <iostream>
	#include <cstring>
	#include <vector>

	extern "C" int yylineno;

	extern int yylex();
	void yyerror(const char*);
%}

%code requires{
	#ifndef INCLUDES_HPP
	#define INCLUDES_HPP
	#include "includes.hpp"

	extern SymbolTable* symbols;
	extern StatementList* slist;
	extern RegTable* rtable;

	#endif
}

%union
{
	float val;
	char* id;
	Type* tpe;
	IdList* ids;
	SimpleType* stpe;
	Expression* express;
	ExpressionsList* elist;
}

%token ADD
%token SUB
%token MULT
%token DIV
%token AND
%token OR
%token TILDA
%token EQ
%token ASSIGN
%token ARROWS
%token LT 
%token GT
%token GTE
%token LTE
%token DEC
%token COMMA 
%token COL
%token SEMCOL
%token POPEN
%token PCLOSE
%token BOPEN
%token BCLOSE
%token PERC 

%token ARRAY
%token START
%token CHR
%token CONST
%token DO
%token DOWNTO
%token ELSE
%token ELSEIF
%token END
%token FOR
%token FORWARD
%token FUNCTION
%token IF
%token OF
%token ORD
%token PRED
%token PROCEDURE
%token READ
%token RECORD
%token REF
%token REPEAT
%token RETURN
%token STOP
%token SUCC
%token THEN
%token TO
%token TYPE
%token UNTIL
%token VAR
%token WHILE
%token WRITE
%token ID
%token NUMBER
%token CHAR
%token STR

%type<id> ID
%type<val> NUMBER
%type<ids> IDList
%type<id> LValue
%type<stpe> simpletype 
%type<tpe> Typestatement
%type<id> CHAR
%type<id> STR
%type<express> Expression
%type<elist> ExpressionsList


%left OR
%left AND
%left ADD SUB
%left MULT DIV PERC
%nonassoc EQ ARROWS GT GTE LT LTE
%right TILDA
%right NEG

%define parse.error verbose
%locations
%%

Program: ConstantOption TypeOption VarOption Profunct Block DEC {}
	;

ConstantOption: ConstantDecl {}
	| {}
	;

TypeOption: TypeDecl {}
	| {}
	;

VarOption: VarDecl {}
	| {}
	;

Profunct: Profunct ProcedureDecl {} 
	| Profunct FunctionDecl {} 
	| ProcedureDecl {}
	| FunctionDecl {}
	| {}
	;

ConstantDecl: CONST ConstSubDecl {} 
	;

ConstSubDecl: ConstantDecl Expression SEMCOL {} 
	| Expression SEMCOL {}
	; 

TypeDecl: TYPE SubTypeDecl {} 
	;

SubTypeDecl: SubTypeDecl ID EQ Typestatement SEMCOL {

	} 
	| ID EQ Typestatement SEMCOL {
		
	}
	;

VarDecl: VAR SubVarDecl {} 
	; 
SubVarDecl: SubVarDecl IDList COL Typestatement SEMCOL {

	} 
	| IDList COL Typestatement SEMCOL {
		for(int i = 0; i < $1->ids.size(); i++){
			symbols->addVariable($1->ids[i], new MemExpression($3->getCopyPtr()));
		}
		//symbols->printStats();
		delete $3;
	}
	; 

Typestatement: simpletype {
		$$ = $1;
	} 
	| recordtype {
		$$ = new Integer();
	} 
	| arraytype {
		$$ = new Integer();
	}
	;


simpletype: ID {

		if(!strcmp($1, "integer") || !strcmp($1, "INTEGER")){
			$$ = new Integer();	
		}
		else if(!strcmp($1, "char") || !strcmp($1, "CHAR")){
			$$ = new Char();	
		}
		else if(!strcmp($1, "string") || !strcmp($1, "STRING")){
			$$ = new String();	
		}
		else if(!strcmp($1, "boolean") || !strcmp($1, "BOOLEAN")){
			$$ = new Boolean();	
		}
	}
	;
recordtype: RECORD recordsubtype END {} 
	| RECORD END {}
	;
recordsubtype: recordsubtype IDList COL Typestatement SEMCOL {}
	| IDList COL Typestatement SEMCOL {}
	;
arraytype: ARRAY BOPEN Expression COL Expression BCLOSE OF Typestatement {}
	;

IDList: IDList COMMA ID {
		//Do I do this or not? With the expressionlist it seems to be working fine.
		$$=$1;
		$$->ids.push_back(std::string($3));
	}  
	| ID {
		$$ = new IdList();
		$$->ids.push_back(std::string($1));
	}
	;

ProcedureDecl: PROCEDURE ID POPEN FormalParameters PCLOSE SEMCOL body SEMCOL {}
	| PROCEDURE ID POPEN FormalParameters PCLOSE SEMCOL FORWARD SEMCOL {}
	;
FunctionDecl: FUNCTION ID POPEN FormalParameters PCLOSE COL Typestatement SEMCOL body SEMCOL{}
	| FUNCTION ID POPEN FormalParameters PCLOSE COL Typestatement SEMCOL FORWARD SEMCOL{}
	; 

body: ConstSubDecl TypeDecl VarDecl Block {}
	| TypeDecl VarDecl Block {}
	| ConstSubDecl VarDecl Block {}
	| ConstSubDecl TypeDecl Block {}
	| TypeDecl Block {}
	| ConstSubDecl Block {}
	| VarDecl Block {}
	| Block {}
	;

Block: START StatementSequence END {}
	;

FormalParameters: {}
	| FormalParameters SEMCOL VarRef IDList COL Typestatement {} 
	| FormalParameters SEMCOL IDList COL Typestatement {} 
	| VarRef IDList COL Typestatement {} 
	| IDList COL Typestatement {} 
	;
	
VarRef: VAR {} 
	| REF {} 
	;

StatementSequence: StatementSequence SEMCOL Statement {} 
	| Statement {}
	;

Statement: Assignment {} 
	| IfStatement {} 
	| WhileStatement {} 
	| RepeatStatement {} 
	| ForStatement {} 
	| StopStatement {} 
	| ReturnStatement {} 
	| ReadStatement {} 
	| WriteStatement {} 
	| ProcedureCall {} 
	| {}
	;

IfStatement: IF Expression THEN StatementSequence ElseIfStatement ElseStatement END {}
	| IF Expression THEN StatementSequence ElseStatement END {}
	| IF Expression THEN StatementSequence ElseIfStatement END {}
	| IF Expression THEN StatementSequence END {}
	;
ElseIfStatement: ElseIfStatement ELSEIF Expression THEN StatementSequence {}
	| ELSEIF Expression THEN StatementSequence 
	;
ElseStatement: ELSE StatementSequence {}
	;
WhileStatement: WHILE Expression DO StatementSequence END {}
	;
RepeatStatement: REPEAT StatementSequence UNTIL Expression {}
	;
ForStatement: FOR ID ASSIGN Expression todownto Expression DO StatementSequence END {}
	;
todownto: TO {}
	| DOWNTO {}
	;
StopStatement: STOP {}
	;
ReturnStatement: RETURN Expression {} 
	| RETURN {}
	;
ReadStatement: READ POPEN ReadValues PCLOSE {}
	;
ReadValues: ReadValues COMMA LValue {} 
	| LValue {}
	;
WriteStatement: WRITE POPEN ExpressionsList PCLOSE {
		$3->write();
		delete $3;
	}
	;
ProcedureCall: ID POPEN ExpressionsList PCLOSE {
	}
	| ID POPEN PCLOSE {}
	;
ExpressionsList: ExpressionsList COMMA Expression { 
		$1->add($3); 
		$$ = $1;
	} 
	| Expression {
		$$ = new ExpressionsList();
		$$->add($1);
	}	
	;

Assignment: LValue ASSIGN Expression {}
	;
LValue: ID {
		$$ = $1;
	} //Thiis one is for normal variables
	| LValue DEC ID {} //This one is for records
	| LValue BOPEN Expression BCLOSE {} // And this one is for arrays
	;

Expression: Expression OR Expression {
		$$ = $1->orfun($3);
		delete $3;
		delete $1;
	}
	| Expression AND Expression {
		$$ = $1->andfun($3);
		delete $1;
		delete $3;
	}
	| Expression EQ Expression {
		$$ = $1->eq($3);
		delete $1;
		delete $3;
	}
	| Expression ARROWS Expression {
		$$ = $1->ne($3);
		delete $1;
		delete $3;
	}
	| Expression GTE Expression {
		$$ = $1->gte($3);
		delete $1;
		delete $3;
	}
	| Expression GT Expression {
		$$ = $1->gt($3);
		delete $1;
		delete $3;
	}
	| Expression LTE Expression {
		$$ = $1->lte($3);
		delete $1;
		delete $3;
	}
	| Expression LT Expression {
		$$ = $1->lt($3);
		delete $1;
		delete $3;
	}
	| Expression ADD Expression {
		$$ = $1->add($3);
		delete $1;
		delete $3;
	}
	| Expression SUB Expression {
		$$ = $1->sub($3);
		delete $1;
		delete $3;
	}
	| Expression MULT Expression {
		$$ = $1->mult($3);
		delete $1;
		delete $3;
	}
	| Expression DIV Expression {
		$$ = $1->div($3);
		delete $1;
		delete $3;
	}
	| Expression PERC Expression {
		$$ = $1->div($3);
		delete $1;
		delete $3;	
	}
	| TILDA Expression {}
	| SUB Expression {}
	| POPEN Expression PCLOSE { $$ = $2; }
	| ID POPEN ExpressionsList PCLOSE {
//		std::cout << $1 << std::endl;
	}
	| ID POPEN PCLOSE {
	//	std::cout << $1 << std::endl;
	}
	| CHR POPEN Expression PCLOSE {}
	| ORD POPEN Expression PCLOSE {}
	| PRED POPEN Expression PCLOSE {}
	| SUCC POPEN Expression PCLOSE {}
	| LValue {
		if(!strcmp($1, "true") || !strcmp($1, "TRUE")){
			$$ = new ConstExpression(1, new Boolean());
		}
		else if(!strcmp($1, "false") || !strcmp($1, "FALSE")){
			$$ = new ConstExpression(0, new Boolean());
		}
		else{
			//This is where you look for the memory location of the name
		}
	}
	| STR {

	}
	| CHAR {
		int length = strlen($1);
		char c;
		if (length == 3){
			c = $1[1]; 
		}
		else if(length == 4){
			std::string s;
			s += $1[1]; 
			s += $1[2]; 
			std::string temp;
			temp += '\\';
			temp += 'n';
			if (! s.compare(temp)){
				c = '\n';
			}
			else{
				std::cerr << "Somehow a wrong whitespace character showed up!";
			}
		}
		$$ = new ConstExpression(int(c), new Char()); //TODO Make sure that this isn't spaghetti code. I think the index is 1 because the str looks like 'x'
	}
	| NUMBER {
		$$ = new ConstExpression($1); 
	}
	;
%%
void yyerror(const char* message){
	std::cerr << message  << " on line " << yylineno << std::endl;
}
