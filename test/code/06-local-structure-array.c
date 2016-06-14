// ======================================================================

void main(void)
{
  struct s {
    char c;
    int ia[3];
    char ca[5];
    int i;
  } sa[2];

  sa[0].c = 'o';		// 111
  sa[0].ia[2] = 222;

  sa[1].ca[3] = '!';		// 33
  sa[1].i = 444;

  outputc sa[0].c;
  outputc '\n';
  output sa[0].ia[2];
  outputc '\n';

  outputc sa[1].ca[3];
  outputc '\n';
  output sa[1].i;
  outputc '\n';
}

// ======================================================================
