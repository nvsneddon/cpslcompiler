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
%token DONE 
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
%token UNTIL
%token VAR
%token WHILE
%token WRITE

%token<id> ID
%token<val> NUMBER
%token<val> CHAR
%token<val> STR


%%

/*Program: ConstantDecl? TypeDecl? VarDecl? (ProcedureDecl | FunctionDecl|)* Block {};*/

ConstantDecl: CONST POPEN ConstantSubDecl PCLOSE {};
ConstantSubDecl: ID EQ Expression SEMCOL {} | ConstantSubDecl ID EQ Expression SEMCOL {};
Expression: {}
/*
ProcedureDecl: PROCEDURE ID POPEN FormalParameters PCLOSE SEMCOL FORWARD SEMCOL {}|
	    PROCEDURE ID POPEN FormalParameters PCLOSE SEMCOL body SEMCOL{}; 
FunctionDecl: FUNCTION ID POPEN FormalParameters PCLOSE COL Type SEMCOL {};
FormalParameters: {}| (VAR|REF)? IdentList COL Type (SEMCOL (VAR|REF)? IdentList COL Type)*;*/

%%
void yyerror(const char* message){
	std::cerr << message << std::endl;
}
