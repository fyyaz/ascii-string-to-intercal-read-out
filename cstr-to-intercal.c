#include <stdio.h>
#include <assert.h>
#include <string.h>

static inline char b_revc(unsigned char c)
{
	unsigned char r = 0;
	for (unsigned int i = 0; i < 8; i++) {
		r |= ((c & (1 << i)) >> i) << (7 - i);
	}
	return r;
}

static inline char b_rev(unsigned char c)
{
	unsigned char r = b_revc(c);
	assert((unsigned char)b_revc(r) == (unsigned char)c);
	return r;
}

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		int len = strlen(argv[i]);
		char s[len + 2];
		strcpy(s, argv[i]);
		s[len] = '\n';
		s[len + 1] = 0;
		puts(s);
		printf("\nDO ,1 <- #%i\n",len + 2);
		unsigned char last = 0;
		for (unsigned int j = 0; j < len + 2; j++) {
			unsigned char ri = (unsigned char)b_rev(s[j]);
			unsigned char rl = (unsigned char)b_rev(last);
			unsigned char c = (unsigned char)rl - (unsigned char)ri;
			if (!(j % 4)) {
				printf("PLEASE ");
			}
			printf("DO ,1 SUB #%i <- #%i\n", j + 1, c);
			last = s[j];
		}
		puts("PLEASE READ OUT ,1");
	}
}