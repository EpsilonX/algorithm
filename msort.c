#include <stdio.h>

void merge_queue(int a[],int first,int mid,int last,int t[]){
    int i = first;
    int m = mid;
    int j = mid+1;
    int n = last;
    int k=0;

    while(i<=m&&j<=n){
        if(a[i]<=a[j]){
            t[k++] = a[i++];
        }else{
            t[k++] = a[j++];
        }
    }
    while(i<=m)
        t[k++]=a[i++];

    while(j<=n)
        t[k++]=a[j++];

    for(i=0;i<k;i++){
        a[first+i] = t[i];
    }
}

void merge_sort(int a[],int first,int last,int temp[]){
    if(first<last){
        int mid = (first+last)/2;
        merge_sort(a,0,mid,temp);
        merge_sort(a,mid+1,last,temp);
        merge_queue(a,first,mid,last,temp);
    }
}

int main(void){
    int a[] = {3,2,4,5,53,14,6,3,12,66};
    int temp[100];
    memset(temp,0,sizeof(temp));
    int last = sizeof(a)/sizeof(int)-1;
    int first = 0;
    merge_sort(a,first,last,temp);
    int i;
    for(i=0;i<=last;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}
