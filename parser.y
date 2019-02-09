%{
	#include <iostream>

	extern "C" int yylineno;
	
	extern int yylex();
	void yyerror(const char*);
%}


%union
{
float val;
char* id;
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

%token<id> ID
%token<val> NUMBER
%token<id> CHAR
%token<id> STR

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

Program: ConstantDecl TypeDecl VarDecl Profunct DEC {}
	| TypeDecl VarDecl Profunct DEC {}
	;

Profunct: Profunct ProcedureDecl Block {} 
	| Profunct FunctionDecl Block {} 
	| Block {}
	;

ConstantDecl: CONST ConstSubDecl {} 
	;

ConstSubDecl: ConstantDecl POPEN Expression SEMCOL PCLOSE {} 
	| POPEN Expression SEMCOL PCLOSE {}
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
	|ID {}
	;

ProcedureDecl: PROCEDURE ID POPEN FormalParameters PCLOSE SEMCOL FORWARD SEMCOL {}
	| PROCEDURE ID POPEN FormalParameters PCLOSE SEMCOL body SEMCOL {}
	;
FunctionDecl: FUNCTION ID POPEN FormalParameters PCLOSE COL Typestatment SEMCOL FORWARD SEMCOL{}
	| FUNCTION ID POPEN FormalParameters PCLOSE COL Typestatement SEMCOL body SEMCOL{}
	; 

body: ConstSubDecl TypeDecl VarDecl Block {}
	| TypeDecl VarDecl Block {}
	| ConstSubDecl VarDecl Block {}
	| ConstSubDecl TypeDecl Block {}
	| TypeDecl Block {}
	| ConstSubDecl Block {}
	| VarDecl Block {}
	;

Block: START StatementSequence END {};

FormalParameters: VarRef IDList COL Typestatement {} 
	| {}
	;
VarRef: VAR {} | REF {} | {};


StatementSequence: StatementSequence SEMCOL Statement {} |
	Statement {};

Statement: Assignment {} |
	IfStatement {} |
	WhileStatement {} |
	RepeatStatement {} |
	ForStatement {} |
	StopStatement {} |
	ReturnStatement {} |
	ReadStatement {} |
	WriteStatement {} |
	ProcedureCall {} |
	{};

IfStatement: IF Expression THEN StatementSequence ElseIfStatement ElseStatement {};
ElseIfStatement: ElseIfStatement ELSEIF Expression THEN StatementSequence | {};
ElseStatement: ELSE Expression THEN StatementSequence | {};
WhileStatement: WHILE Expression DO StatementSequence END {};
RepeatStatement: REPEAT StatementSequence UNTIL Expression {};
ForStatement: FOR ID ASSIGN Expression todownto Expression DO StatementSequence END {};
todownto: TO {}| DOWNTO {};
StopStatement: STOP {};
ReturnStatement: RETURN Expression {}; | RETURN {};
ReadStatement: READ POPEN ReadValues PCLOSE {};
ReadValues: ReadValues COMMA LValue {} | LValue {};
WriteStatement: WRITE POPEN ExpressionList PCLOSE;
ExpressionList: ExpressionList COMMA Expression {} | Expression {};
ProcedureCall: ID POPEN ExpressionList PCLOSE {}
	| ID POPEN PCLOSE {}
	;




Assignment: LValue ASSIGN Expression {}
	;
LValue: ID SubLValue {}
	;
SubLValue: POPEN DEC ID PCLOSE {} 
	| BOPEN Expression BCLOSE {} 
	| {}
	;

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
	| SUB Expression %prec NEG {}
	| POPEN Expression PCLOSE {}
	| ID POPEN ExpressionList PCLOSE {}
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
	std::cerr << message  << "\tOn line" << yylineno << std::endl;
}
