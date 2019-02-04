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
%token EQ
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

%token<id> ID
%token<val> NUMBER
