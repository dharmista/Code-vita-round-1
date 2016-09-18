#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Return{
	int * arr;
	int count;
};

Return get_primes(int target){
	int * arr = (int *)malloc(sizeof(int)), count = 1;
	arr[0] = 2;
	int curr = 1, k;
	while (true){
		curr += 2;
		int temp = 0;
		for (k = 0; k < count; k++){
			if (curr%arr[k] == 0)
				temp++;
		}
		if (temp == 0){
			if (curr > target)
				break;
			arr = (int *)realloc(arr, sizeof(int)*(count + 1));
			arr[count++] = curr;
		}
	}
	Return k1;
	k1.arr = arr;
	k1.count = count;
	return k1;
}

bool check_prime(int num, int * arr){
	int finale = pow(num, 0.5), i;
	int count = 0;
	for (i = 0; i < finale; i++){
		if (arr[i] != 0)
		if (num % arr[i] == 0)
			count++;
	}
	if (count == 0)
		return true;
	return false;
}

int main(){
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	Return ans = get_primes(n);
	bool first_time = true;
	for (i = 0; i < ans.count; i++){
		int temp = 2 * ans.arr[i] + 1;
		bool sats = false;
		for (j = 0; j < k; j++){
			sats = check_prime(temp, ans.arr);
			if (!sats)break;
			temp = 2 * temp + 1;
		}
		if (sats){
			if (!first_time){
				printf(" ");
			}
			else
				first_time = false;
			printf("%d", ans.arr[i]);
		}
	}
	return 0;
}