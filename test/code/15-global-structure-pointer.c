// ======================================================================

struct s {
  int i1;
  char c2;
  int ia[4];
  char ca[10];
} s1;

struct s *sp;

void main(void)
{
  sp = &s1;

  sp->i1 = 111;
  sp->c2 = 'C';		// 67
  sp->ia[3] = 333;
  sp->ca[4] = ',';	// 44

  output sp->i1;
  outputc '\n';
  outputc sp->c2;
  outputc '\n';
  output sp->ia[3];
  outputc '\n';
  outputc sp->ca[4];
  outputc '\n';
}

// ======================================================================
