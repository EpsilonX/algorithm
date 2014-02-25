#include <stdio.h>

void qsort(int left, int right, int a[])
{
    if(left < right){
        int i = left;
        int j = right;
        int k = a[left];

        while(i<j){
            while(a[j]>=k&&i<j) j--;
            if(i<j) a[i++]=a[j];
            while(a[i]<k&&i<j) i++;
            if(i<j) a[j--]=a[i];
        }
        a[i]=k;
        qsort(left,i-1,a);
        qsort(i+1,right,a);
    }
    return;
}

int main(void){
    int a[]={5,3,1,5,3,2,6,41,43242,22,1};
    int length = sizeof(a)/sizeof(int);
    qsort(0,length-1,a);
    int i;
    for(i=0;i<length;i++){
        printf("%d,",a[i]);
    }
    return 0;
}
