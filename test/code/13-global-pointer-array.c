// ======================================================================

char ca[4];
int ia[3];
char *cpa[4];
int *ipa[3];

void main(void)
{
  cpa[0] = &ca[0];
  cpa[3] = &ca[3];
  ipa[0] = &ia[0];
  ipa[2] = &ia[2];

  *cpa[0] = '0';	// 48
  *cpa[3] = 'Q';	// 81
  *ipa[0] = 100;
  *ipa[2] = 222;
  
  outputc ca[0];
  outputc '\n';
  outputc ca[3];
  outputc '\n';
  output ia[0];
  outputc '\n';
  output ia[2];
  outputc '\n';

  outputc *cpa[0];
  outputc '\n';
  outputc *cpa[3];
  outputc '\n';
  output *ipa[0];
  outputc '\n';
  output *ipa[2];
  outputc '\n';
}

// ======================================================================
