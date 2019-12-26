#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

bool isValid(char * s){
    char *stack = (char *) malloc(strlen(s));
    int top = 0;
    int i = 0;
    while (s[i]) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                stack[top++] = s[i];
                break;
            case ')':
            case ']':
            case '}':
                if (top - 1 < 0) return false;
                char c = stack[--top];
                if (c == '(' && s[i] != ')') return false;
                if (c == '[' && s[i] != ']') return false;
                if (c == '{' && s[i] != '}') return false;
                break;
        }
        i++;
    }
    return top == 0;
}

int main( int argc, char **argv )
{
    char *str = "()[]{}}";
	if (isValid(str)) {
		printf("ok\n");
	} else {
		printf("no\n");
	}
	return 0;
}

