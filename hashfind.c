#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int STR_LEN = 3;
const int MIN_CHAR_SEQ = 32;
const int MAX_CHAR_SEQ = 38;

int main(int argc, char **argv) {
	char *str_start, *str_ptr;
	int i;
	str_start = (char*)malloc(sizeof(char) * STR_LEN);
	str_ptr = str_start;
	while (str_ptr < str_start + STR_LEN - 1) {
		for (i = MIN_CHAR_SEQ; i <= MAX_CHAR_SEQ; i++) {
			*str_ptr = i;
			printf("%s\n", str_start);
			// TODO check hash.
		}
		// Step at end of string.
		while (*str_ptr == MAX_CHAR_SEQ) {
			//clear actual
			*str_ptr = MIN_CHAR_SEQ;
			//step right
			str_ptr++;
		}
		if (str_ptr < str_start + STR_LEN - 1) {
			if (*str_ptr == '\0') {
				// insert first char
				*str_ptr = MIN_CHAR_SEQ;
			} else {
				// increment last element
				*str_ptr = *str_ptr + 1;
			}
			// insert termination char
			*(str_ptr + 1) = '\0';
			// Step to first element
			str_ptr = str_start;
		}
	}
	free(str_start);
	return 0;
}
