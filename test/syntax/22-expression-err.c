// ======================================================================

/* expression -> unary_expression ASSIGN expression
               | logical_expression */

// ======================================================================

void main(void)
{
  int i;
  int j;

  i && j = 1;	// error: invalid expression on left-hand side
}

// ======================================================================
