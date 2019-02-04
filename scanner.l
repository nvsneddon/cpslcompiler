%{
#include <cstdlib>

#include "parser.hpp"
%}


%%
"+" {return ADD;}
"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"&" {return AND;}
"|" {return OR;}
"=" {return EQ;}
":=" {return EQ;}
"<" {return LT;}
">" {return GT;}
">=" {return GTE;}
"<=" {return LTE;}
"." {return DEC;}
"," {return DONE;}
":" {return COL;}
";" {return SEMCOL;}
"(" {return POPEN;}
")" {return PCLOSE;}
"[" {return BOPEN;}
"]" {return BCLOSE;}
"%" {return PERC;}
[a-zA-Z]+ {yylval.id = strdup(yytext); return ID;}
[0-9]+ {yylval.val = atoi(yytext); return NUMBER;}
[0-9]*\.[0-9]* {yylval.val = atoi(yytext); return NUMBER;}
[\t] {}
%%
