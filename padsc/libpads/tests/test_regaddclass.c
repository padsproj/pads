#include <ast.h>
#include <ast_common.h>
#include <sfio.h>
#include <regex.h>
#include <error.h>

int is_f(int c) { return c == 'f'; }

int main(int argc, char** argv) {
  regex_t          preg;
  int              i;
  char            *exp, *str;
  int              c_flags   = REG_AUGMENTED|REG_EXTENDED|REG_DELIMITED|REG_MULTIREF;
  int              e_flags   = 0;
  int              cret, eret, pin;
  regmatch_t       match[100];

  regaddclass("f", is_f);

  exp = "/[[:f:]]+/";
  str = "fff";
  error(0, "Matching pattern %s against string %s", exp, str);
  error(0, "(should match string \"fff\")");
  pin = 0;
  if (pin) { e_flags |= REG_LEFT; }
  cret = regcomp(&preg, exp, c_flags);
  if (cret) {
    error(ERROR_FATAL, "Failed to compile re %s, cret = %d", exp, cret);
  }
  error(0, "compiled %s, nsub = %d", exp, preg.re_nsub);
  eret = regexec(&preg, str, preg.re_nsub+1, match, e_flags);
  error(0, "match of RE %s against string %s produced %s",
	exp, str, (eret ? "FALSE" : "TRUE" ));
  if (!eret) {
    for (i = 0; i <= preg.re_nsub; i++) {
      error(0, "      sub %d so %d eo %d = \"%.*s\"", i, match[i].rm_so, match[i].rm_eo, match[i].rm_eo - match[i].rm_so, str + match[i].rm_so);
    }
  }
  return 0;
}
