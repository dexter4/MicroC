// ======================================================================

void main(void)
{
  int i1;
  char c2;
  char c3;
  int i4;

  int *ip1;
  char *cp2;
  char *cp3;
  int *ip4;

  ip1 = &i1;
  cp2 = &c2;
  cp3 = &c3;
  ip4 = &i4;

  *ip1 = 111;
  *cp2 = 'h';	// 104
  *cp3 = 'k';	// 107
  *ip4 = 444;

  output i1;
  outputc '\n';
  outputc c2;
  outputc '\n';
  outputc c3;
  outputc '\n';
  output i4;
  outputc '\n';

  output *ip1;
  outputc '\n';
  outputc *cp2;
  outputc '\n';
  outputc *cp3;
  outputc '\n';
  output *ip4;
  outputc '\n';
}

// ======================================================================
