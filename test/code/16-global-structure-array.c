// ======================================================================

struct s {
  int ia[3];
  char c;
  char ca[5];
  int i;
};

struct s sa[2];

void main(void)
{
  sa[0].ia[1] = 1111;
  sa[0].c = '2';
  sa[0].ca[2] = '!';	// 33
  sa[0].i = 4444;

  sa[1].ia[2] = 5555;
  sa[1].c = 'B';
  sa[1].ca[3] = 'M';	// 77
  sa[1].i = 8888;

  output sa[0].ia[1];
  outputc '\n';
  outputc sa[0].c;
  outputc '\n';
  outputc sa[0].ca[2];
  outputc '\n';
  output sa[0].i;
  outputc '\n';

  output sa[1].ia[2];
  outputc '\n';
  outputc sa[1].c;
  outputc '\n';
  outputc sa[1].ca[3];
  outputc '\n';
  output sa[1].i;
  outputc '\n';
}

// ======================================================================
