#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int i,n;

int * createArray(int *p){
    int a[10] = {3, 1, 4, 2, 4, 4, 5, 3};
    p=a;
    return p;
}

void AscentOrNot(int * p){
	int len = 0, max_len = 0;
	for (i = 0; i<10; i++){
		if(*(p+1) >= *(p)){
			len++;
			if (len > max_len){
				max_len=len;
			}
			p++;		
		}
		else{	
		len =0;	
		}
	}
	printf("max ascent = %d",max_len);
}

int main(){
    int *p;
    p = createArray(p);
    printf("THE ARRAY CREATED:");
    for(i = 0; i < 10; i++){
        printf("%d ",*(p));
        p++;
    }
    AscentOrNot(p);
}
