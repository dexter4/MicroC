int main(void){
  int a;
  int stdcnt;
  int stdmax;
  int k;
  int bound;
  int searchnum;
  int result;
  char esc;

  struct student {
    int studentnum;
    int eng;
    int math;
    int avg;
  };

  struct student s1[30];

  esc = 0x1B;

  clear;
  outputs "==================================================";
  outputc '\n';
  outputc '\n';
  outputc esc;
  outputs "[3;14H";
  outputs "Welcome to Monster world";
  outputc '\n';
  outputc '\n';
  outputs "==================================================";
  outputc '\n';

  outputs "How many students";
  outputc '\n';
  input stdmax;
  outputc '\n';

  for(stdcnt = 0; stdcnt < stdmax; stdcnt = stdcnt + 1) {
    outputs ""; 
    outputs "student number(";
    output stdcnt + 1;
    outputs "/";
    output stdmax;
    outputs ")";
    outputc '\n';

    input s1[stdcnt].studentnum;
    outputs "english score";
    outputc '\n';
    input s1[stdcnt].eng;
    outputs "math score";
    outputc '\n';
    input s1[stdcnt].math;
    outputc '\n';
    s1[stdcnt].avg = (s1[stdcnt].eng + s1[stdcnt].math)/2;
  }

  clear;

  a = 1;
  while ( a < 100) {
    outputs "1: full table";
    outputc '\n';
    outputs "2: searching student number";
    outputc '\n';
    outputs "3: quit";
    outputc '\n';

    input k;

    if (k == 1) {
      outputs "==============================================";
      outputc '\n';

      outputs "|student number";
      outputc esc;
      outputs "[6;18H";
      outputs "|english";
      outputc esc;
      outputs "[6;28H";
      outputs "|math";
      outputc esc;
      outputs "[6;37H";
      outputs "|average |";
      outputc '\n';

      outputs "==============================================";
      outputc '\n';

      for (stdcnt = 0; stdcnt < stdmax; stdcnt = stdcnt + 1) {
	bound = 8 + stdcnt;
	outputs "|";
	output s1[stdcnt].studentnum;
	outputc esc;
	outputs "[";
	output bound;
	outputs ";18H";
	outputs "|";
	output s1[stdcnt].eng;
	outputc esc;
	outputs "[";
	output bound;
	outputs ";28H";
	outputs "|";
	output s1[stdcnt].math;
	outputc esc;
	outputs "[";
	output bound;
	outputs ";37H";
	outputs "|";
	output s1[stdcnt].avg;
	outputc esc;
	outputs "[";
	output bound;
	outputs ";46H";
	outputs "|";
	outputc '\n';
      }

      outputs "==============================================";
      outputc '\n';

    } else if (k == 2) {
      outputc '\n';
      outputs "searching number";
      outputc '\n';
      input searchnum;

      for(stdcnt = 0; stdcnt < stdmax; stdcnt = stdcnt + 1) {
	if (s1[stdcnt].studentnum == searchnum) {
	  outputc '\n';
          outputs "==============================================";

	  outputc esc;
	  outputs "[10;0H";
	  outputs "|student number";
	  outputc esc;
	  outputs "[10;18H";
	  outputs "|english";
	  outputc esc;
	  outputs "[10;28H";
	  outputs "|math";
	  outputc esc;
	  outputs "[10;37H";
	  outputs "|average |";
	  outputc '\n';

	  outputs "==============================================";
	  outputc '\n';

	  outputc esc;
	  outputs "[12;0H";
	  outputs "|";
	  output s1[stdcnt].studentnum;
	  outputc esc;
	  outputs "[12;18H";
	  outputs "|";
	  output s1[stdcnt].eng;
	  outputc esc;
	  outputs "[12;28H";
	  outputs "|";
	  output s1[stdcnt].math;
	  outputc esc;
	  outputs "[12;37H";
	  outputs "|";
	  output s1[stdcnt].avg;
	  outputc esc;
	  outputs "[12;46H";
	  outputs "|";
	  outputc '\n';

	  outputs "==============================================";
	  outputc '\n';
	} else {
	  outputs "";
	}
      }
    } else if (k == 3) {
      a = 200;
    }

    if(a == 1) {
      outputc '\n'; 
      outputs "1: continue";
      outputc '\n';
      outputs "2: quit";
      outputc '\n';

      input k;

      switch(k) {
	case 1:
	  clear;
	  break;
	case 2:
	  a = 200;
	  break;
      }
    }

  }

}
