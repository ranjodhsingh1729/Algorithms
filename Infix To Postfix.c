#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const int MAXN = 1e3;
typedef struct {
	char *value;
	void *next;
} node;
node *stack = NULL;


int isempty() {
	return stack == NULL;
}


void push(char *x) {
	node *temp = (node *) malloc(sizeof(node));

	if (!temp)
		return;
	
	temp->value = x;
	temp->next = stack;

	stack = temp;
}


char *pop() {
	if (!stack)
		return NULL;

	char *value = stack->value;
	node *next = (node *) stack->next;

	free(stack);
	stack = next;
	return value;
}

int findidx(char *x, int n, char *arr[]) {
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(x, arr[i]) == 0)
			break;
	}
	
	return i < n ? i : -1;
}


int main() {
	// expression must be space seperated
	int n;
	scanf("%d", &n);
	char expr[MAXN][20];
	for (int i = 0; i < n; i++) {
		scanf("%s", expr[i]);
	}


	int k = 0;
	char *polish[MAXN];

	const int opc = 5;
	char *opv[] = {"/", "*", "+", "-", "^"};

	int p; char *temp;
	for (int i = 0; i < n; i++) {
		for (p = 0; p < opc; p++) {
			if (strcmp(opv[p], expr[i]) == 0)
				break;
		}

		
		if (p == opc) {
			if (strcmp("(", expr[i]) == 0) {
				push(expr[i]);
			}
			
			else if (strcmp(")", expr[i]) == 0) {
				while ((temp = pop()) && (strcmp("(", temp) != 0)) {
					polish[k++] = temp;
				}

			}
				
			else {
				polish[k++] = expr[i];
			}

		} else {
			if (isempty() || strcmp("(", stack->value) == 0) {
				push(expr[i]);

			}

			else if (findidx(expr[i], opc, opv) < findidx(stack->value, opc, opv)) {
				push(expr[i]);
			}
			
			else {
				polish[k++] = pop();
				i--;
			}
		}

		node *tmp = stack;
		while (tmp) {
			printf("%s ", tmp->value);
			tmp = (node *) tmp->next;
		}
		printf("\n");

		for (int x = 0; x < k; x++) {
			printf("%s ", polish[x]);
		}
		printf("\n");
	}

	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		printf("%s ", polish[i]);
	}
	printf("\n");

	return 0;
}