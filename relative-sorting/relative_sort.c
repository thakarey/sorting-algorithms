#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void * a, const void * b){
     int a1 = *(int *)a;
     int b1 = *(int *)b;
     if (a1 < b1) {
          return -1;
     }else if (a1 == b1) {
          return 0;
     }
     return 1;
}
int binary_first(int arr[],int l,int r,int k){
     if (l<=r) {
          int mid = l + (r-l)/2;
          if (arr[mid] == k && mid >=0 ) {
               if (mid == 0) {
                    return mid;
               }
               else if (arr[mid] != arr[mid-1]) {
                    return mid;
               }else{
                    int p=mid;
                    while (p-1 >= 0) {
                         if (arr[p] != arr[p-1]) {
                              break;
                         }
                         p--;
                    }
                    return p;
               }
          }
          else if (arr[mid] > k) {
               return binary_first(arr,l,mid-1,k);
          }else{
               return binary_first(arr,mid+1,r,k);
          }

     }
     return -1;
}
int sort_relative(int arr[],int arr1[],int n,int n1){
     int tmp[n],i,j,k,visited[n];
     memset(visited,0,sizeof(visited));
     for (i = 0; i < n; i++) {
          tmp[i] = arr[i];
     }
     //for sorting the tmp array
     qsort(tmp,sizeof(tmp)/sizeof(tmp[0]),sizeof(tmp[0]),compare);
     // printf("ds=%d\n", binary_first(tmp,0,n,2));
     for (i = 0,j=0; i < n1 && j < n; i++) {
          k = binary_first(tmp,0,n,arr1[i]);
          if (k >= 0) {
               while (k < n) {
                    if (tmp[k] != arr1[i] ) {
                         break;
                    }
                    visited[k] = 1;
                    arr[j++] = tmp[k];
                    k++;
               }
          }
     }
     for (k=0; k < n; k++) {
          if (visited[k] == 0) {
               arr[j++] = tmp[k];
          }
     }
}
int main() {
     int t,i,j,n,n1;
     scanf("%d",&t );
     while (t--) {
          scanf("%d",&n );
          scanf("%d",&n1 );
          int arr[n],arr1[n1];
          for (i = 0; i < n; i++) {
               scanf("%d",&arr[i] );
          }for (i = 0; i < n1; i++) {
               scanf("%d",&arr1[i] );
          }
          sort_relative(arr,arr1,n,n1);
          for (i = 0; i < n; i++) {
               printf("%d ",arr[i] );
          }
          printf("\n");
     }
	return 0;
}
