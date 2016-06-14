// ======================================================================

int array[10];	// sorting array
int x;		// moving block's point of x
int y;		// moving block's point of y
int v;		// moving block's value
int dp;		// moving block's decimal points
char esc;	// escape character

// ======================================================================

/* return the number of decimal points */
int decimal_point(int num)
{
  int i;

  if (num < 0) {
    for (i = 2; num < -9; i = i + 1) {
      num = num / 10;
    }
    return i;
  } else {
    for (i = 1; num > 9; i = i + 1) {
      num = num / 10;
    }
    return i;
  }
}

/* count 3 sec */
void go3s(void)
{
  output 3;
  outputc '\n';
  sleep(800);
  output 2;
  outputc '\n';
  sleep(800);
  output 1;
  outputc '\n';
  sleep(800);
  outputs "Go!";
  sleep(800);
}

/* print array */
void print_array(int array[], int length)
{
  int i;
  int j;

  for (i = 0; i < length; i = i + 1) {
    outputs "------- ";
  }
  outputc '\n';

  for (i = 0; i < length; i = i + 1) {
    outputs "       |";
  }
  outputc '\n';

  /* value line */
  for (i = 0; i < length; i = i + 1) {
    outputc ' ';
    output array[i];
    j = decimal_point(array[i]);
    for ( ; j < 5; j = j + 1) {
      outputc ' ';
    }
    outputs " |";
  }
  outputc '\n';

  for (i = 0; i < length; i = i + 1) {
    outputs "       |";
  }
  outputc '\n';

  for (i = 0; i < length; i = i + 1) {
    outputs "------- ";
  }
  outputc '\n';
}

/* index's point of x */
int pointx(int index)
{
  return index * 8 + 2;
}

/* move cursor to (x, y) */
void move_cursor(int x, int y)
{
  outputc esc;
  outputc '[';
  output y;
  outputc ';';
  output x;
  outputc 'H';
}

/* erase next characters */
void erase(int n)
{
  for ( ; n > 0; n = n - 1) {
    outputc ' ';
  }
}

/* blink index's value with Green color */
void blink(int array[], int index)
{
  int i;
  int x;

  x = pointx(index);
  for (i = 0; i < 3; i = i + 1) {
    outputc esc;
    outputs "[5;";	// move cursor
    output x;
    outputc 'H';

    outputc esc;
    outputs "[42;5m";	// set color
    output array[index];
    sleep(400);

    outputc esc;
    outputs "[5;";	// move cursor
    output x;
    outputc 'H';

    outputc esc;
    outputs "[0m";	// clear color
    output array[index];
    sleep(400);
  }
}

/* blink double values with magenta color */
void blink_double(int index)
{
  int v2;
  int i;

  v2 = array[index];
  for (i = 0; i < 2; i = i + 1) {
    move_cursor(x, 1);
    outputc esc;
    outputs "[33;45;1m";	// set color
    output v;

    move_cursor(x, 5);
    output v2;
    outputc esc;
    outputs "[0m";		// clear color
    sleep(400);

    move_cursor(x, 1);
    outputc esc;
    outputs "[42;5m";		// set color
    output v;

    move_cursor(x, 5);
    outputc esc;
    outputs "[0m";		// clear color
    output v2;
    sleep(400);
  }
}

/* pop index's value up */
void pop_up(int array[], int index)
{
  x = pointx(index);
  v = array[index];
  dp = decimal_point(v);

  for (y = 5; y > 1; y = y - 1) {
    move_cursor(x, y - 1);
    outputc esc;
    outputs "[42;5m";	// set color
    output v;
    outputc esc;
    outputs "[0m";	// clear color
    move_cursor(x, y);
    if (y == 3)
      outputs "-----";
    else
      erase(dp);
    sleep(300);
  }
}

/* shift index's value right */
void shift_right(int array[], int index)
{
  int x2;
  int v2;
  int i;

  x2 = pointx(index);
  v2 = array[index];
  for (i = 0; i < 3; i = i + 1) {
    move_cursor(x2, 5);
    outputs "  ";
    outputc esc;
    outputs "[33;45;1m";	// set color
    output v2;
    outputc esc;
    outputs "[0m";		// clear color
    x2 = x2 + 2;
    sleep(300);
  }
  move_cursor(x2, 5);
  outputs "|      ";
  move_cursor(x2 + 2, 5);
  outputc esc;
  outputs "[33;45;1m";		// set color
  output v2;
  outputc esc;
  outputs "[0m";		// clear color
  sleep(300);
  move_cursor(x2 + 2, 5);
  output v2;
  sleep(300);
}

/* move block left */
void move_left(void)
{
  int i;

  for (i = 0; i < 4; i = i + 1) {
    x = x - 2;
    move_cursor(x, y);
    outputc esc;
    outputs "[42;5m";	// set color
    output v;
    outputc esc;
    outputs "[0m";	// clear color
    erase(2);
    sleep(300);
  }
}

/* move block right */
void move_right(void)
{
  int i;

  for (i = 0; i < 4; i = i + 1) {
    move_cursor(x, y);
    outputs "  ";
    outputc esc;
    outputs "[42;5m";	// set color
    output v;
    outputc esc;
    outputs "[0m";	// clear color
    x = x + 2;
    sleep(300);
  }
}

/* move block down */
void move_down(void)
{
  for (y = 1; y < 5; y = y + 1) {
    move_cursor(x, y + 1);
    outputc esc;
    outputs "[42;5m";	// set color
    output v;
    outputc esc;
    outputs "[0m";	// clear color
    move_cursor(x, y);
    if (y == 3)
      outputs "-----";
    else
      erase(dp);
    sleep(300);
  }
  move_cursor(x, y);
  outputc esc;
  outputs "[0m";	// clear color
  output v;
}

// ======================================================================

int main(void)
{
  int i;
  int j;
  int length;

  esc = 0x1B;

  /* input number of sorting number */
  outputs "How many do you want to sort?(max 10) ";
  input length;
  if ((length < 2) || (length > 10)) {
    outputs "Error: Please insert the number between 2 ~ 10";
    outputc '\n';
    return 1;
  }

  i = 0;
  while (i < length) {
    outputs "Insert number(max 5 digits)(";
    output i + 1;
    outputs ") ";
    input array[i];
    j = decimal_point(array[i]);
    if (j > 5) {
      outputs "Please insert 1 ~ 5 digits number, retry";
      outputc '\n';
    } else {
      i = i + 1;
    }
  }

/*  for (i = 0; i < length; i = i + 1) {
    outputs "Insert number(max 5 digits)(";
    output i + 1;
    outputs ") ";
    input array[i];
    j = decimal_point(array[i]);
    if (j > 5) {
      outputs "Please insert 1 ~ 5 digits number, retry";
      outputc '\n';
      i = i - 1;
    }
  }
*/
  outputc esc;
  outputs "[?25l";	// hide cursor
  sleep(800);
  go3s();

  /* print input array */
  outputc esc;
  outputs "[2J";	// erase screen
  outputc esc;
  outputs "[3;0H";	// reset cursor

  print_array(array, length);
  sleep(800);

  /* insertion sorting */
  for (i = 1; i < length; i = i + 1) {

    /* select key */
    blink(array, i);
    pop_up(array, i);

    /* inner loop */
    for (j = i - 1; j >= 0; j = j - 1) {
      move_left();
      sleep(400);
      blink_double(j);
      if (array[j] > v) {
	shift_right(array, j);
	array[j + 1] = array[j];
      } else {
	move_right();
	array[j + 1] = v;
	j = -1;
      }
    }
    move_down();
    array[j + 1] = v;
    sleep(400);
  }

  outputc esc;
  outputs "[0m";	// clear attribute
  outputc esc;
  outputs "[10;1H";	// move bottom
  outputc esc;
  outputs "[?25h";	// show cursor

  return 0;
}

// ======================================================================
