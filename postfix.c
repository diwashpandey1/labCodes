#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
	if(top == MAX - 1) {
		printf("Stack Overflow\n");
		exit(1);
	}
	stack[++top] = c;
}

char pop() {
	if (top == -1) {
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack[top--];
}

char peek() {
	if(top == -1) {
		return -1;
	}
	return stack[top];
}

int precedence(char op) {
	switch (op) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}

int is_operator(char c) {
	return(c == '+' || c == '-' || c == '/' || c == '*' || c == '^');
}

void infix_to_postfix(char *exp) {
	int i = 0;
	while (exp[i] != '\0') {
		char c = exp[i];
		
		if(isalnum(c)) {
			printf("%c", c);
		} else if (c == '(') {
			push(c);
		} else if (c == ')') {
			while (peek() != '(') {
			printf("%c",pop());
			}
			pop();
		} else if (is_operator(c)) {
			while (top != -1 && precedence(peek()) >= precedence(c)) {
				printf("%c", pop());
			}
			push(c);
		} 
		i++;
	}
	
	while(top != -1) {
		printf("%c", pop());
	}
}

int main() {
	char exp[MAX];
	
	printf("\nEnter infix expression: ");
	scanf("%s", exp);
	
	printf("Postfix expression: ");
	infix_to_postfix(exp);
	
	return 0;
}