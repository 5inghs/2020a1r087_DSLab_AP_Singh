#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *arr;
	int i, NumberOfElements , search;
	printf("enter how many elements:\n");
	scanf("%d", &NumberOfElements);
	// create the array of numberofelements
	arr= (int *)calloc(NumberOfElements, sizeof(int));
	// reading into array arr
	for(i=0;i<NumberOfElements;i++)
	{
		printf("enter arr[%d]\n", i);
		scanf("%d",(arr+i));
	}
	//showing the elements of arr
	for(i=0; i<NumberOfElements; i++)
	{
		printf("arr[%d] = %d\n", i , *(arr+i));
	}
	// reallocation for (numberofelements + 1) elements

	arr = realloc(arr, (NumberOfElements*sizeof(int)+1));
	printf("enter arr[%d]\n", NumberOfElements);
	scanf("%d", (arr + NumberOfElements));
	for(i=0; i< NumberOfElements + 1; i++)
	{
		printf("arr[%d] = %d\n", i , *(arr+i));
	}

	// Find an element
	printf("which element you want to find?\n");
	scanf("%d", &search);
	for(i = 0; i < (NumberOfElements+1) ; ++i)
	{
		if (search == *(arr+i))
		{
			printf("found at %d\n" , i);
			break;
		}
	}
    return 0;
}
