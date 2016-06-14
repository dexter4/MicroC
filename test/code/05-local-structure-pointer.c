// ======================================================================

void main(void)
{
  struct s {
    char c1;
    int i2;
    char ca[5];
    int ia[5];
  };

  struct s s1;
  struct s *sp;

  sp = &s1;

  sp->c1 = 'o';		// 111
  sp->i2 = 222;
  sp->ca[3] = '!';	// 33
  sp->ia[4] = 444;

  outputc sp->c1;
  outputc '\n';
  output sp->i2;
  outputc '\n';
  outputc sp->ca[3];
  outputc '\n';
  output sp->ia[4];
  outputc '\n';
}

// ======================================================================
