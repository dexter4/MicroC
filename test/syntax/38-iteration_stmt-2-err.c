// ======================================================================

/* iteration_stmt -> FOR LPAR expression_stmt expression_stmt RPAR statement */

// ======================================================================

void main(void)
{
  int i;

  for (i = 0; i < 10 ) {	// error: no 2nd SEMICOLON(expression_stmt)
  }
}

// ======================================================================
