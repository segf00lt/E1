/* recognize tokens for the calculator */

%option noyywrap
%{
#include "token.h"
#include <stdlib.h>
%}


%%


[0-9]+(\.[0-9]+)? {
  return NUM;
}

\* { return TIMES; }
\+ { return PLUS; }
- { return MINUS; }
\/ { return DIV; }
\n { return EOL; }
[ \t]+ ;
. { return ERROR; }

%%

