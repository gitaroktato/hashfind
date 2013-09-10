#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
const int STR_LEN = 255;
const int MIN_CHAR_SEQ = 32;
const int MAX_CHAR_SEQ = 126;

int check_hash(char* source, char* target_match) {
	return strcmp(source, target_match) == 0;
}

int main(int argc, char **argv) {
	char *str_start, *str_ptr;
	char* target_match = argv[1];
	int i;
	str_start = (char*)malloc(sizeof(char) * STR_LEN);
	str_ptr = str_start;
	printf("Target: %s \n", target_match);
	time_t start_time = time(0), end_time;
	while (str_ptr < str_start + STR_LEN - 1) {
		for (i = MIN_CHAR_SEQ; i <= MAX_CHAR_SEQ; i++) {
			*str_ptr = i;
		    // Check matching string.
			printf("\r%s", str_start);
			if (check_hash(str_start, target_match)) {
				end_time = time(0);
				printf("\rFound match: %s, lasted for: %ld sec.\n", str_start, end_time - start_time);
				return EXIT_SUCCESS;
			}
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
				// insert termination char at end
				*(str_ptr + 1) = '\0';
				// insert first char
				*str_ptr = MIN_CHAR_SEQ;
			} else {
				// increment last element
				*str_ptr = (*str_ptr) + 1;
			}
			// Step to first element
			str_ptr = str_start;
		}
	}
	free(str_start);
	return 0;
}
