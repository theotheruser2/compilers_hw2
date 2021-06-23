#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main() {

    char* string = (char*)calloc(1024, sizeof(char));

    puts("Enter your string to see if it matches b(ab)*bbc? :\n");
    fgets(string, 1024, stdin);

    bool endState = false;
    char symbol;
    int state = 1;
    int i = 0;	

    for (i = 0; i < 1024; i++) {

        symbol = string[i];

        switch (state) {
        case 1:
            switch (symbol) {
            case 'b':
                state = 2;
                break;
            default:
                fprintf(stderr, "Invalid character: %c\n", symbol);
                state = -1;
                break;
            }
            break;

        case 2:
            switch (symbol) {
            case 'a':
                state = 1;
                break;
            case 'b':
                state = 3;
                break;
            default:
                fprintf(stderr, "Invalid character: %c\n", symbol);
                state = -1;
                break;
            }
            break;

        case 3:
            switch (symbol) {
            case 'b':
                state = 4;
                break;
            default:
		fprintf(stderr, "Invalid character: %c\n", symbol);
                state = -1;
                break;
            }
            break;

        case 4:
            switch (symbol) {
            case 'c':
		state = 5;
                break;
	    case '\n':
		endState = true;
		break; 
	    case 0:
		endState = true; 
		break;
            default:
		fprintf(stderr, "Invalid character: %c\n", symbol);
                state = -1;
                break;
            }
            break;

        case 5:
            switch (symbol) {
	    case '\n':
		endState = true;
		break; 
	    case 0:
		endState = true; 
		break;
            default:
		fprintf(stderr, "Invalid character: %c\n", symbol);
                state = -1;
                break;
            }
            break;


        default:
            fprintf(stderr, "Invalid state: %d\n", state);
            state = -1;
            break;
        }

        if (endState || state == -1) {
            break;
        }
    }

    if (endState) {
        printf("The string matches the regular expression\n");
    }
    else {
        printf("The string does not match the regular expression\n");
    }
    free(string);
    return 0;
}

