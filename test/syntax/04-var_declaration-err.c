// ======================================================================

/* var_declaration -> type_specifier SEMICOLON */

// ======================================================================

struct human_global {
  int age;
}                       // error: no semicolon

void main(void)
{
  struct human_local {
    int age;
  };

}

// ======================================================================
