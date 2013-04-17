#include <stdio.h>
#include <math.h>

int main(void){

	int days, i, l, r, m, dOperational, flag;
	scanf("%d", &days);
	l = r = m = dOperational = 0;

	for(i = 0; i < days; i++){
			flag = 0;
			l++, r++, m++;
			if(l > 2){
				l = 0;
				flag = 1;
			}
			if(r > 13){
				r = 0;
				flag = 1;
			}
			if(m > 99){
				m = 0;
				flag = 1;
			}
			if(flag == 0)
				dOperational++;
	}

	printf("\n%d",dOperational);

	return 0;
	
}
