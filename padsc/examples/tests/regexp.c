
#include <pads.h>

#define LIMIT	20

int
main(int argc, char** argv)
{
	char*		s;
	int		c;
	regex_t		re;
	char		buf[8*LIMIT];

	while (s = *++argv)
		if (c = regcomp(&re, s, REG_AUGMENTED|REG_EXTENDED|REG_DELIMITED|REG_MUSTDELIM|REG_LENIENT|REG_ESCAPE|REG_SPAN|REG_MULTIREF))
		{
			regerror(c, &re, buf, sizeof(buf));
			sfprintf(sfstdout, "%s: failed: %s\n", s, buf);
		}
		else if ((c = regdecomp(&re, -1, buf, LIMIT)) > LIMIT)
			sfprintf(sfstdout, "%s: failed: %d byte buffer required\n", s, c);
		else
			sfprintf(sfstdout, "%s => %s\n", s, buf);
	return 0;
}



/* #include <pads.h>
int main(){
  const char *regexp_str = "/b+/";
  regflags_t c_flags = (REG_AUGMENTED|REG_EXTENDED|REG_DELIMITED|REG_MUSTDELIM|REG_LENIENT|REG_ESCAPE|REG_SPAN|REG_MULTIREF);
  regex_t  regexp;
  int cret = regcomp(&regexp, regexp_str, c_flags);
  char buf_space[100];
  size_t len = regdecomp(&regexp, -1, buf_space,100);
  sfprintf(sfstderr, "The reg exp decomp is: %s, length is %d\n", buf_space, len);
}
*/
