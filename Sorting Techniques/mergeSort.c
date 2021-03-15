#include <stdio.h>

void mergeArrays(int arr[], int left, int mid, int right){

    int n1=mid-left+1;
    int n2=right-mid;

    int i=0,j=0,total=left;

    int first[n1],sec[n2];

    for(int k=0;k<n1;k++)
        first[k]=arr[left+k];

    for(int k=0;k<n2;k++)
        sec[k]=arr[mid+1+k];

    while(i<n1 && j<n2){

        if(first[i]<=sec[j]){
            arr[total]=first[i];
            total++; i++;
        }

        else{
            arr[total]=sec[j];
            total++; j++;
        }
    }

    while(i<n1){
        arr[total]=first[i];
        total++; i++;
    }
    while(j<n2){
        arr[total]=sec[j];
        total++; j++;
    }

}

void mergeSort(int arr[], int left, int right){

    if(left==right)
        return;

    int mid=(left+right)/2;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    mergeArrays(arr,left,mid,right);
}

int main()
{
    int n;  scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    mergeSort(arr,0,n-1);

    printf("Sorted Array : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
