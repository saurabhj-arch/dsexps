#include <stdio.h>
#define MAX_SIZE 100
void insertElement(int arr[], int *size, int item, int pos)
{
 if (*size == MAX_SIZE)
 {
 printf("Array is full! Cannot insert more elements.\n");
 return;
 }
 if (pos < 1 || pos > *size + 1)
 {
 printf("Invalid position!\n");
 return;
 }
 int i;
 for ( i = *size; i >= pos; i--)
 arr[i] = arr[i - 1];
 arr[pos - 1] = item;
 (*size)++;
 printf("Element inserted successfully.\n");
}
void deleteElement(int arr[], int *size, int key)
{
 if (*size == 0)
 {
 printf("Array is empty! No elements to delete.\n");
 return;
 }
 int found = 0,i;
 for ( i = 0; i < *size; i++)
 {
 if (arr[i] == key)
 {
 found = 1;
 int j;
 for ( j = i; j < *size - 1; j++)
 arr[j] = arr[j + 1];
 (*size)--;
 printf("Element deleted successfully.\n");
 break;
 }
 }
 if (!found)
 printf("Element not found!\n");
}
void displayArray(int arr[], int size)
{
 if (size == 0)
 printf("Array is empty!\n");
 else
 {
 printf("Current array: ");
 int i;
 for ( i = 0; i < size; i++)
 printf("%d ", arr[i]);
 printf("\n");
 }
}
int main()
{
 int arr[MAX_SIZE];
 int size = 0, choice, item, pos, key;
 printf("Enter the number of initial elements (up to %d): ", MAX_SIZE);
 scanf("%d", &size);
 if (size > MAX_SIZE || size < 0)
 {
 printf("Invalid size!\n");
 return 1;
 }
 printf("Enter %d elements: ", size);
 int i;
 for (i = 0; i < size; i++)
 scanf("%d", &arr[i]);
 do
 {
 printf("\nMenu:\n");
 printf("1. Insert an element\n");
 printf("2. Delete an element\n");
 printf("3. Display the array\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
      printf("Enter the element to be inserted: ");
      scanf("%d", &item);
      printf("Enter the position: ");
      scanf("%d", &pos);
      insertElement(arr, &size, item, pos);
      break;
 case 2:
      printf("Enter the element to delete: ");
      scanf("%d", &key);
      deleteElement(arr, &size, key);
      break;
 case 3:
      displayArray(arr, size);
      break;
 case 4:
      printf("Exiting program.\n");
      break;
 default:
 printf("Invalid choice! Please try again.\n");
 }
 } while (choice != 4);
 return 0;
}
