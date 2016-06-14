// ======================================================================

char c1;
int i2;
int i3;
char c4;

char *cp1;
int *ip2;
int *ip3;
char *cp4;

void main(void)
{
  cp1 = &c1;
  ip2 = &i2;
  ip3 = &i3;
  cp4 = &c4;

  *cp1 = 'o';
  *ip2 = 222;
  *ip3 = 333;
  *cp4 = ',';

  outputc c1;
  outputc '\n';
  output i2;
  outputc '\n';
  output i3;
  outputc '\n';
  outputc c4;
  outputc '\n';

  outputc *cp1;
  outputc '\n';
  output *ip2;
  outputc '\n';
  output *ip3;
  outputc '\n';
  outputc *cp4;
  outputc '\n';
}

// ======================================================================
