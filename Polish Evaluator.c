#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const int MAXN = 1e3;
typedef struct {
	int value;
	void *next;
} node;
node *stack = NULL;


int isempty() {
	return stack == NULL;
}


void push(int x) {
	node *temp = (node *) malloc(sizeof(node));

	temp->value = x;
	temp->next = stack;

	stack = temp;
}


int pop() {
	int value = stack->value;
	node *next = (node *) stack->next;

	free(stack);
	stack = next;
	return value;
}

int isnum(char *x) {
    while (*x) {
        if (!(*x >= '0' && *x <= '9')) {
            return 0;
        }
        x++;
    }
    return 1;
}



int main() {
	// expression must be space seperated
	int n;
	scanf("%d", &n);
	char expr[MAXN][20];
	for (int i = 0; i < n; i++) {
		scanf("%s", expr[i]);
	}

    int O1, O2;

    for (int i = 0; i < n; i++) {
        if (isnum(expr[i])) {
            push(atoi(expr[i]));
        } else {
            O1 = pop();
            O2 = pop();

            switch (expr[i][0])
            {
            case '/':
                push(O2/O1);
                break;
            case '*':
                push(O2*O1);
                break;
            case '+':
                push(O2+O1);
                break;
            case '-':
                push(O2-O1);
                break;
            default:
                break;
            }
        }
    }

    printf("%d\n", pop());

	return 0;
}