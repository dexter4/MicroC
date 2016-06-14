// ======================================================================

struct s {
  int i1;
  char c2;
  int ia[4];
  char ca[10];
};

struct s s1;

void main(void)
{
  s1.i1 = 111;
  s1.c2 = 'C';		// 67
  s1.ia[3] = 333;
  s1.ca[4] = ',';	// 44

  output s1.i1;
  outputc '\n';
  outputc s1.c2;
  outputc '\n';
  output s1.ia[3];
  outputc '\n';
  outputc s1.ca[4];
  outputc '\n';
}

// ======================================================================
