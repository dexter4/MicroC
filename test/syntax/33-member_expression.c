// ======================================================================

/* member_expression -> member_expression memop var
                      | factor */

// ======================================================================

struct human {
  int age;
};

void main(void)
{
  struct human h;
  struct human *hp;

  h.age = 25;
  hp->age = 26;
}

// ======================================================================
