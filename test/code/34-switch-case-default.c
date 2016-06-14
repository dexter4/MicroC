// ======================================================================

int main(void)
{
  int i;

  i = 0;

  switch (i) {
    case 0:
      i = i + 1;
      output i;
      outputc '\n';
      break;
    case 1:
      i = i + 2;
      output i;
      outputc '\n';
      break;
    default:
      i = i + 3;
      output i;
      outputc '\n';
      break;
  }
}

// ======================================================================
