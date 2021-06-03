#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int insert(int *arr, int value, int n)
{
    if(n!=0){
        arr = realloc(arr,sizeof(int));
    }
    arr[n] = value;
    ++n;
    return n;
}
int insert_at(int *arr, int value, int n,int index)
{
    if(n!=0){
        arr = realloc(arr,sizeof(int));
    }
    int crr,next;
    crr=arr[index];
    arr[index] = value;
    for(int i=index+1;i<=n;i++){
        next = arr[i];
        arr[i] = crr;
        crr = next;
    }
    ++n;
    return n;
}
int search(int *arr, int value, int n)
{
    int i, flag = 0;
    for (i = 0; i < n; ++i)
    {
        if (arr[i] == value)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }

    return -1;
}

int del(int *arr, int value, int n)
{
    int result, temp;
    result = search(arr, value, n);
    if (result == -1)
    {
        return -1;
    }
    for (int i = result + 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    return n - 1;
}

void display(int *arr, int n)
{
    if(n==0){
        printf("list is empty");
        return;
    }
    printf("|");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        printf("|");
    }
}

int main()
{
    int choice, n = 0, value, result,index;
    int *arr =  (int *)calloc(1,sizeof(int));

    do
    {
        system("cls");
        printf("Implimentation of list\nchoose any operation\n");
        printf("1. Insert an element\n2. Insert at\n3. Delete an element\n4. Search\n5. View list\n6. Exit \n");
        choice = (int)getch();
        switch (choice)
        {
        case 49:
            printf("Enter the value you want to insert");
            printf("\n:");
            scanf("%d", &value);
            n = insert(arr, value, n);
            printf("\nValue Added at index: %d\n", n - 1);
            printf("Updated array is :\n");
            display(arr, n);

            break;
        case 50:
            printf("Enter the value you want to insert");
            printf("\n:");
            scanf("%d", &value);
            printf("Enter the index where you want to insert");
            printf("\n:");
            scanf("%d", &index);
            if(index>n){
                printf("\nInvalid index\n");
            }
            n = insert_at(arr, value, n,index);
            printf("\nValue Added at index: %d\n",index);
            printf("Updated array is :\n");
            display(arr, n);

            break;
        case 51:
            printf("Enter the value you want to delete\n");
            printf("Current array is :\n");
            display(arr, n);
            printf("\n:");
            scanf("%d", &value);
            result = del(arr, value, n);
            if (result == -1 || n == 0)
            {
                printf("Element not found or array is empty");
                break;
            }
            else
            {
                n = result;
                printf("Element is deleted\n");
            }
            printf("Updated array is :\n");
            display(arr, n);
            break;
        case 52:
            printf("Enter the value you want to search\n");
            scanf("%d", &value);
            result = search(arr, value, n);
            if (result == -1 || n == 0)
                printf("Element not found or array is empty");
            else
                printf("Element found on index: %d", result);
            break;
        case 53:
            system("cls");
            display(arr, n);
            break;
        case 54:
            printf("press enter to exit...");
            getch();
            free(arr);
            exit(0);
            break;
        default:

            printf("Wrong choice");
            break;
        }
        printf("\nPress enter to continue");
        getch();
    } while (1);
}