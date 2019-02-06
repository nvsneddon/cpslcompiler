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

Statement: Expression DONE {std::cout << $1 << std::endl;};
ProcedureDecl: PROCEDURE 


%%
void yyerror(const char* message){
	std::cerr << message << std::endl;
}
