/* PROGRAM TO PASS ARRAYS USING POINTERS*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int i,n;

int * createArray(int *p){
    int a[10];
    srand( (unsigned)time( NULL ) );
    for(i = 0; i < 10; i++){
        a[i] = rand(); 
    }
    p=a;
    return p;
}

void AscentOrNot(int * p){
	int len = 0, max_len = 0;
	for (i = 0; i<10; i++){
		if(*(p+1) >= *(p+i)){
			len++;
			if (len > max_len){
				max_len=len;
			}
		}
		else{	
		len =0;	
		}
	}
	printf("\nMax Ascent length = %d",max_len);
}

void printArray(int*p){
	printf("\nTHE ARRAY CREATED:");
    for(i = 0; i < 10; i++){
        printf("%d ",*(p+i));
    }
}


int main(){
    int *p;
    p = createArray(p);
    printArray(p);
    AscentOrNot(p);
}
