// ======================================================================

/* relational_expression -> additive_expression relop additive_expression
                          | additive_expression */

// ======================================================================

void main(void)
{
  int i;
  int j;

  i = 0;
  j = 1;
  i = (i + j) !> (i - j);	// error: not relop
}

// ======================================================================
