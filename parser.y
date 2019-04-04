%{
	#include <iostream>

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
	#endif
}

%union
{
	float val;
	char* id;
	Expression* expr;
	Type* tpe;
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
%token LE
%token GE
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
%type<id> CHAR
%type<id> STR
%type<expr> Expression


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
WriteStatement: WRITE POPEN ExpressionList PCLOSE {
		//Write::write("This is a test\n");
	}
	;
ProcedureCall: ID POPEN ExpressionList PCLOSE {}
	| ID POPEN PCLOSE {}
	;
ExpressionList: ExpressionList COMMA Expression {} 
	| Expression {}	
	;

Assignment: LValue ASSIGN Expression {}
	;
LValue: ID {}
	| LValue DEC ID {}
	| LValue BOPEN Expression BCLOSE {}

Expression: Expression OR Expression {}
	| Expression AND Expression {}
	| Expression EQ Expression {}
	| Expression ARROWS Expression {}
	| Expression GTE Expression {}
	| Expression GE Expression {}
	| Expression LTE Expression {}
	| Expression LE Expression {}
	| Expression LT Expression {}
	| Expression GT Expression {}
	| Expression ADD Expression {}
	| Expression SUB Expression {}
	| Expression MULT Expression {}
	| Expression DIV Expression {}
	| Expression PERC Expression {}
	| TILDA Expression {}
	| SUB Expression {}
	| POPEN Expression PCLOSE {}
	| ID POPEN ExpressionList PCLOSE {}
	| ID POPEN PCLOSE {}
	| CHR POPEN Expression PCLOSE {}
	| ORD POPEN Expression PCLOSE {}
	| PRED POPEN Expression PCLOSE {}
	| SUCC POPEN Expression PCLOSE {}
	| LValue {}
	| STR {}
	| CHAR {}
	| NUMBER {}
	;
%%
void yyerror(const char* message){
	std::cerr << message  << " on line " << yylineno << std::endl;
}
