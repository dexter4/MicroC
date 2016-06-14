// ======================================================================

void main(void)
{
  int ia[5];
  char ca[10];
  int *ipa[5];
  char *cpa[10];

  ipa[2] = &ia[2];
  ipa[3] = &ia[3];
  cpa[5] = &ca[5];
  cpa[6] = &ca[6];

  *ipa[2] = 222;
  *ipa[3] = 333;
  *cpa[5] = '5';
  *cpa[6] = '6';
  
  output ia[2];
  outputc '\n';
  output ia[3];
  outputc '\n';
  outputc ca[5];
  outputc '\n';
  outputc ca[6];
  outputc '\n';

  output *ipa[2];
  outputc '\n';
  output *ipa[3];
  outputc '\n';
  outputc *cpa[5];
  outputc '\n';
  outputc *cpa[6];
  outputc '\n';
}

// ======================================================================
