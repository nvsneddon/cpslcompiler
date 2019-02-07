%{
#include <cstdlib>
#include "parser.hpp"

%}

%option noyywrap
DIGIT 	[0-9]
id  [a-zA-Z][a-zA-Z0-9]*

%%
"+" {return ADD;}
"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"&" {return AND;}
"|" {return OR;}
"~" {return TILDA;}
"=" {return EQ;}
":=" {return ASSIGN;} 
"<>" {return ARROWS;}
"<" {return LT;}
">" {return GT;}
">=" {return GTE;}
"<=" {return LTE;}
"." {return DEC;}
"," {return COMMA;}
":" {return COL;}
";" {return SEMCOL;}
"(" {return POPEN;}
")" {return PCLOSE;}
"[" {return BOPEN;}
"]" {return BCLOSE;}
"%" {return PERC;}


"array"|"ARRAY" {return ARRAY;}
"begin"|"BEGIN" {return START;}
"chr"|"CHR" {return CHR;}
"const"|"CONST" {return CONST;}
"do"|"DO" {return DO;}
"downto"|"DOWNTO" {return DOWNTO;}
"else"|"ELSE" {return ELSE;}
"elseif"|"ELSEIF" {return ELSEIF;}
"end"|"END" {return END;}
"for"|"FOR" {return FOR;}
"forward"|"FORWARD" {return FORWARD;}
"function"|"FUNCTION" {return FUNCTION;}
"if"|"IF" {return IF;}
"of"|"OF" {return OF;}
"ord"|"ORD" {return ORD;}
"pred"|"PRED" {return PRED;}
"procedure"|"PROCEDURE" {return PROCEDURE;}
"read"|"READ" {return READ;}
"record"|"RECORD" {return RECORD;}
"ref"|"REF" {return REF;}
"repeat"|"REPEAT" {return REPEAT;}
"return"|"RETURN" {return RETURN;}
"stop"|"STOP" {return STOP;}
"succ"|"SUCC" {return SUCC;}
"then"|"THEN" {return THEN;}
"to"|"TO" {return TO;}
"type"|"TYPE" {return TYPE;}
"until"|"UNTIL" {return UNTIL;}
"var"|"VAR" {return VAR;} 
"while"|"WHILE" {return WHILE;}
"write"|"WRITE" {return WRITE;}


{id} {yylval.id = strdup(yytext); return ID;}
{DIGIT}+ {yylval.val = atoi(yytext); return NUMBER;}
0x({DIGIT}+) {yylval.val = atoi(yytext); return NUMBER;}
'[a-zA-Z]' {yylval.id = strdup(yytext); return CHAR;}
\"[a-zA-Z]*\" {yylval.id = strdup(yytext); return STR;}
[ \t] {}
$(.*)\n {}
