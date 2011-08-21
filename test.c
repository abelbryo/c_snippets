#include <stdio.h>
#include <string.h>

#define MAXCHARS 	1000

int getline(char *line, int max);

int main(int argc, char *argv[]){
	char line[MAXCHARS];
	int count = getline(line, MAXCHARS);
	printf("Input was %s\n", line);
	printf("Length: %d\n", count-1);
	
	
	
	return 0;
}

/**
 * Reads user input
 */
int getline(char *line, int max){
	int c, count = 0;
	while((c = getchar())!= EOF && c != '\n'){
		if(count < max){
			*(line++) = c;
			count++;
		}
	}
	*(line) = '\0';
	
	return count+1; // The plus one accounts for the null character which
}					// is appended at the end of the string.