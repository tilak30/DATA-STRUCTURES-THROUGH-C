#include <stdio.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int l, int h) {

  int pivot = arr[h];
  int i = (l - 1);

  for (int j = l; j < h; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap( &arr[i + 1], &arr[h] );
  return (i + 1);
}

void quickSort(int arr[], int l, int h){
    if (l < h) {

    int p = partition(arr, l, h);

    quickSort(arr, l, p - 1);

    quickSort(arr, p + 1, h);
  }
}

int main()
{
    int n;  scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
