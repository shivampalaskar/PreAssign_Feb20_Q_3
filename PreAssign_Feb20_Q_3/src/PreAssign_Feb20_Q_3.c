/*
 ============================================================================
 Name        : PreAssign_Feb20_Q_3.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void addNum(int arr[]);
void delNum(int arr[]);
void maxNum(int arr[]);
void minNum(int arr[]);
void sumNum(int arr[]);
int avaIndex(int arr[]);
int avaIndex_Val(int arr[]);
void viewarr(int arr[]);
int isEmpty(int arr[]);

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	int arr[10];
	for(int i=0;i<10;i++)
		arr[i]=0;
	int choice;
	do{
		printf("\n\nChoose operation to perfom : ");
			printf("\n1. Add a Number");
			printf("\n2. Delete a Number");
			printf("\n3. Find Maximum Number");
			printf("\n4. Find Minimum Number");
			printf("\n5. Find Sum of Number");
			printf("\n6. View Array");
			printf("\n7. Exit");
			printf("\n Enter Choice: ");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				addNum(arr);
				break;
			case 2:
				delNum(arr);
				break;
			case 3:
				maxNum(arr);
				break;
			case 4:
				minNum(arr);
				break;
			case 5:
				sumNum(arr);
				break;
			case 6 :
			 	viewarr(arr);
			}
	}while(choice!=7);
	return EXIT_SUCCESS;
}

void addNum(int arr[]) {
	int index,num;
	if (avaIndex(arr)) {
		printf("\nEnter Index Number : ");
		scanf("%d", &index);
		printf("\nEnter a Number to add : ");
		scanf("%d", &num);
		arr[index] = num;
		printf("Number is successfully Added\n");
	}else
		printf("Array is Full");
}

void delNum(int arr[]){
	int index,num;
	if (avaIndex_Val(arr)) {
		printf("\nEnter Index Number to delete : ");
		scanf("%d", &index);
		arr[index]=0;
		printf("Number is Successfully deleted");
	} else
		printf("Array is Empty");
}

void maxNum(int arr[]){
	int max = 0,index;
	if(isEmpty(arr)){
		printf("Array is Empty");
	} else {
		for (int i = 0; i < 10; i++) {
			if (arr[i] > max){
				max = arr[i];
				index =i;
			}
		}
		printf("\nMax number is : %d and Index : %d", max,index);
	}
}

void minNum(int arr[]){
	int min = 99999999,index;
	if (isEmpty(arr)) {
		printf("Array is Empty");
	} else {
		for (int i = 0; i < 10; i++) {
			if (arr[i] < min && arr[i]!=0){
				min = arr[i];
				index = i;
			}
		}
		printf("\nMin number is : %d and Index : %d", min,index);
	}
}

void sumNum(int arr[]) {
	int sum = 0;
	if (isEmpty(arr)) {
		printf("\nArray is empty");
	} else {
		for (int i = 0; i < 10; i++) {
			sum += arr[i];
		}
		printf("\nSum = %d", sum);
	}
}

int isEmpty(int arr[]) {
	int check = 1;
	for (int i = 0; i < 10; i++) {
		if (arr[i] != 0)
			check = 0;
	}
	return check;
}

int avaIndex(int arr[]){
	int check=0;
	for(int i=0;i<10;i++){
		if(arr[i]==0){
			if(check==0)
				printf("Available Index : ");
			printf("%d ",i);
			check = 1;
		}
	}
	return check;
}

int avaIndex_Val(int arr[]){
	int check = 0;
	for (int i = 0; i < 10; i++) {
		if (arr[i] != 0) {
			if(check==0)
				printf("\nIndex Number");
			printf("\n %2d %5d", i, arr[i]);
			check = 1;
		}
	}
	return check;
}

void viewarr(int arr[]) {
	for (int i = 0; i < 10 ; i++) {
		printf("%d ", arr[i]);
	}
}
