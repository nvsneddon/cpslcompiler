%{
	#include <iostream>
	#include <cstring>

	extern "C" int yylineno;

	extern int yylex();
	void yyerror(const char*);
%}

%code requires{
	#ifndef INCLUDES_HPP
	#define INCLUDES_HPP
	#include "includes.hpp"

	extern SymbolTable* symbols;
	extern ExpressionsList* elist;
	extern StatementList* slist;

	#endif
}

%union
{
	float val;
	char* id;
	Type* tpe;
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
%type<id> LValue
%type<id> CHAR
%type<id> STR
%type<tpe> Expression
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

SubTypeDecl: SubTypeDecl ID EQ Typestatement SEMCOL {} 
	| ID EQ Typestatement SEMCOL {}
	;

VarDecl: VAR SubVarDecl {} 
	; 
SubVarDecl: SubVarDecl IDList COL Typestatement SEMCOL {} 
	| IDList COL Typestatement SEMCOL {}
	; 

Typestatement: simpletype {} 
	| recordtype {} 
	| arraytype {}
	;


simpletype: ID {}
	;
recordtype: RECORD recordsubtype END {} 
	| RECORD END {}
	;
recordsubtype: recordsubtype IDList COL Typestatement SEMCOL {}
	| IDList COL Typestatement SEMCOL {}
	;
arraytype: ARRAY BOPEN Expression COL Expression BCLOSE OF Typestatement {}
	;

IDList: IDList COMMA ID {}  
	| ID {}
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

	}
	;
ProcedureCall: ID POPEN ExpressionsList PCLOSE {
		$3->write();
		delete $3;
	}
	| ID POPEN PCLOSE {}
	;
ExpressionsList: ExpressionsList COMMA Expression { $1->add($3); } 
	| Expression {
		$$ = new ExpressionsList();
		$$->add($1);
	}	
	;

Assignment: LValue ASSIGN Expression {}
	;
LValue: ID {$$ = $1;} //Thiis one is for normal variables
	| LValue DEC ID {} //This one is for records
	| LValue BOPEN Expression BCLOSE {} // And this one is for arrays

Expression: Expression OR Expression {}
	| Expression AND Expression {}
	| Expression EQ Expression {
		int result = ($1->getExpression() == $3->getExpression() ? 1 : 0);
		$$ = new Bool(result);
		delete $1;
		delete $3;
	}
	| Expression ARROWS Expression {
		Expression* newexpression;
		int result = ($1->getExpression() != $3->getExpression()) ? 1 : 0;
		$$ = new Bool(result);
		delete $1;
		delete $3;
	}
	| Expression GTE Expression {
		int result = ($1->getExpression() >= $3->getExpression()) ? 1 : 0;
		$$ = new Bool(result);
		delete $1;
		delete $3;
	}
	| Expression GT Expression {
		int result = ($1->getExpression() > $3->getExpression()) ? 1 : 0;
		$$ = new Bool(result);
		delete $1;
		delete $3;
	}
	| Expression LTE Expression {
		int result = ($1->getExpression() <= $3->getExpression()) ? 1 : 0;
		$$ = new Bool(result);
		delete $1;
		delete $3;
	}
	| Expression LT Expression {
		int result = ($1->getExpression() < $3->getExpression()) ? 1 : 0;
		$$ = new Bool(result);
		delete $1;
		delete $3;
	}
	| Expression ADD Expression {}
	| Expression SUB Expression {}
	| Expression MULT Expression {}
	| Expression DIV Expression {}
	| Expression PERC Expression {}
	| TILDA Expression {}
	| SUB Expression {}
	| POPEN Expression PCLOSE {}
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
		//std::cout << $1 << std::endl;
	}
	| STR {
		
	}
	| CHAR {
		//How do I get this to extract the newline account? 
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
		std::cerr << c << " is the character\n";
		$$ = new Character(int(c)); //TODO Make sure that this isn't spaghetti code. I think the index is 1 because the str looks like 'x'
	}
	| NUMBER {
		$$ = new Integer($1); 
	}
	;
%%
void yyerror(const char* message){
	std::cerr << message  << " on line " << yylineno << std::endl;
}
