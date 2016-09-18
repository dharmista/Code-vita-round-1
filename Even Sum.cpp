#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

bool even(int n){
	int count = 0;
	while (n != 0){
		int temp = n & 1;
		n >>= 1;
		if (temp == 1)count++;
	}
	return count == 2;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int k = 0; k < T; k++){
		int n;
		scanf("%d", &n);
		int i = 0, count = 0, sum = 0;
		while(count < n){
			if (even(i++))
			{
				sum += (i - 1);
				count++;
			}
		}
		printf("%d\n", sum);
	}
	_getch();
}