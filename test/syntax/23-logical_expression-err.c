// ======================================================================

/* logical_expression -> logical_expression logop relational_expression
                       | relational_expression */

// ======================================================================

void main(void)
{
  int i;

  i = 0;
  i = i && if (i == 0) i = 1;	// error: not expression
}

// ======================================================================
