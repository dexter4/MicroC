// ======================================================================

void main(void)
{
  struct s {
    char c1;
    int i2;
    char ca[5];
    int ia[5];
  } s1;

  s1.c1 = 'o';		// 111
  s1.i2 = 222;
  s1.ca[3] = '!';	// 33
  s1.ia[4] = 444;

  outputc s1.c1;
  outputc '\n';
  output s1.i2;
  outputc '\n';
  outputc s1.ca[3];
  outputc '\n';
  output s1.ia[4];
  outputc '\n';
}

// ======================================================================
