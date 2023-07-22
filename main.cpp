#include <stdio.h>

void butler(void);
int main(void) {
	printf("* I will call butler;\n");
	butler();
	printf("* Finish;\n");
}
void butler(void) {
	printf("\t- This is butler;\n");
}
