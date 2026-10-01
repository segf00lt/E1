


typedef enum {
  EOL=0,       // 0 - Final de linha
  NUM,         // 1
  PLUS,        // 2
  MINUS,       // 3
  TIMES,       // 4
  DIV,         // 5
  ERROR,       // 6 - Erro léxico
} token_t;

token_t my_token_to_token_t(Token t) {
  switch(t) {
    case TOKEN_EOL:
      return EOL;
    case TOKEN_NUM:
      return NUM;
    case (Token)'+':
      return PLUS;
    case (Token)'-':
      return MINUS;
    case (Token)'*':
      return TIMES;
    case (Token)'/':
      return DIV;
    default:
      printf("token = %s\n", (char*)lexer_token_debug_strings[t].s);
      printf("token = %c\n", t);
      UNREACHABLE;
    case TOKEN_ERROR:
      return ERROR;
  }
  return ERROR;
}


int main(int argc, char **argv) {
  Arena *a = arena_create(MB(1));

  if(argc == 1) {
    printf("o programa precisa de 1 argumento o path do arquivo\n");
    return 1;
  }

  Str8 src_path = str8_from_cstr(a, argv[1]);
  Str8 src = platform_read_entire_file(a, argv[1]);

  Lexer lexer;
  init_lexer(&lexer, src_path, src);

  for(Token token = lex(&lexer); token != 0; token = lex(&lexer)) {
    arena_scope(a) {

      token_t tok = my_token_to_token_t(token);

      if(tok == ERROR) {
        printf("erro léxico: caractere inválido\n");
      } else if(tok == NUM) {
        printf("<token %d, atrib %s>\n", tok, cstr_from_str8(a, lexer.token_text));
      } else {
        printf("<token %d>\n", tok);
      }

    }
    
  }


  return 0;
}

