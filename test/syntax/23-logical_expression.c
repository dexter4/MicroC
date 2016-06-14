// ======================================================================

/* logical_expression -> logical_expression logop relational_expression
                       | relational_expression */

// ======================================================================

void main(void)
{
  int i;
  int j;

  i = 0;
  j = 1;

  i = (i && j) || (i < j);
  i = i > j;
}

// ======================================================================
