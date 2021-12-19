#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1024

int main()
{
	char input[MAX];
	
	while (fgets(input, sizeof(input), stdin) != NULL) {
		int paren_cnt;
		paren_cnt = 0;
		for (char *ch = input; *ch != '\0' ; ch++) {
			if (*ch == '(')
				paren_cnt++;
			else if (*ch == ')')
				paren_cnt--;
			if (paren_cnt < 0)
				break;
		}
		printf("%s\n", paren_cnt != 0 ? "incorrect" : "correct"); 
	}
	
//	printf("%s\n", input);
	return 0;
}
