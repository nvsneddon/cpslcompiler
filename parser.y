%{
	#include <iostream>
	
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
%token BEGIN 
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
%token<val> CHAR
%token<val> STR


%%

Program: ConstantDecl TypeDecl VarDecl Profunct Block DEC {};

Profunct: Profunct ProcedureDecl {} | Profunct FunctionDecl {} | {};

ConstantDecl: CONST ConstSubDecl {} | {};
ConstSubDecl: ConstSubDecl POPEN Expression SEMCOL PCLOSE {} | POPEN Expression SEMCOL PCLOSE {}; 
TypeDecl: TYPE SubTypeDecl {} | {};   
SubTypeDecl: SubTypeDecl POPEN ID EQ Typestatement PCLOSE SEMCOL {} | POPEN ID EQ Typestatement PCLOSE SEMCOL {}; 
VarDecl: VAR SubVarDecl POPEN IDList COL Typestatement SEMCOL PCLOSE {} | {}; 
SubVarDecl: SubVarDecl POPEN IDList COL Typestatement SEMCOL PCLOSE {} | {}; 

Typestatement: ID {} | recordtype {} | arraytype {};
recordtype: RECORD recordsubtype END{};
recordsubtype: recordsubtype IDList COL Typestatement SEMCOL {}| {};
arraytype: ARRAY BOPEN Expression COL Expression BCLOSE OF Typestatement {}; 

IDList: IDList COMMA ID {} | ID {};

ProcedureDecl: PROCEDURE ID POPEN FormalParameters PCLOSE COL TypeDecl SEMCOL ForBody SEMCOL {};
FunctionDecl: FUNCTION ID POPEN FormalParameters PCLOSE SEMCOL ForBody SEMCOL{}; 

ForBody: FORWARD {} | body{};
body: ConstSubDecl TypeDecl VarDecl Block {};
Block: BEGIN StatementSequence END {};

FormalParameters: {} | VarRef IDList COL Type {}; 
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
ProcedureCall: ID POPEN ExpressionList PCLOSE {}| ID POPEN PCLOSE {};


Assignment: {};
Expression: {};
LValue: {};
Type: {};

%%
void yyerror(const char* message){
	std::cerr << message << std::endl;
}
