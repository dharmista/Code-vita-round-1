#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	n = 2 * n + 1;
	int offs = 2;
	for (int i = 0; i < n; i++){
		if (i == 0 || i == n - 1){
			for (int j = 0; j < n; j++){
				printf("*");
			}
		}
		else if (i % 2 == 0){
			for (int j = 0; j < i + 1; j++){
				printf("*");
			}
			int pos = i;
			for (int j = i + 1; j < n; j++){
				if (j == n - 1 || j == 0)
					printf("*");
				else if (j>=pos && j % 2 == 0)
					printf("*");
				else
					printf(" ");
			}
		}
		else{
			int pos = i + 1;
			for (int j = 0; j < n; j++){
				if (j == n - 1 || j == 0)
					printf("*");
				else if (j >= pos && j % 2 == 0)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	fflush(stdin);
	getchar();
	return 0;
}