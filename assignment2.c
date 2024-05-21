#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
//Assignment 2.1
int findMin(int a[], int size, int *minP){
    int value = a[0];
    for(int i=0; i<size; i++){
        if(a[i]<value){
            value = a[i];
        }
    }
    *minP = value;
    return size;
}
//Assignment 2.2(a)
int findMaxMin(int a[], int size, int *maxP, int *minP){
    int val1 = a[0];
    int val2 = a[0];
    for(int i=0; i<size; i++){
        if(a[i]<val1){
            val1 = a[i];
        }
        if(a[i]>val2){
            val2 = a[i];
        }
    }
    *minP = val1;
    *maxP = val2;
    return size;
}
//Assignment 2.2(b)
int findMaxMinDnQ(int a[], int s, int e, int *maxP, int *minP, int comparisions){
   int p=0;
   if(s==e){
    *maxP = a[s];
    *minP = a[s];
    return 0;
   }
   else{
       if(s==(e-1)){
           if(a[s]<a[e]){
               *maxP = a[e];
               *minP = a[s];
               comparisions++;
           }
           else{
               *maxP = a[s];
               *minP = a[e];
               comparisions++;
           }
       }
       else{
           int mid, mx, mn;
           mx = INT_MIN;
           mn = INT_MAX;
           mid = (s + e)/2;
           p+=(findMaxMinDnQ(a, s, mid, maxP, minP, 0));
           p+=(findMaxMinDnQ(a, mid+1, e, &mx, &mn, 0));
           if(mx>*maxP){
                *maxP = mx;
                comparisions++;
           }
           if(mn<*minP){
                *minP = mn;
                comparisions++;
           }
       }
   }
   return comparisions+p;
}
int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    printf("\n");
    int a[n];
    printf("Enter elements of array : \n");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    //Assignment 2.1 -> findMin
    int minP1; //findMin
    int comparisions1 = findMin(a, n, &minP1);
    printf("Using findMin function \n");
    printf("Minimum element of the array is : ");
    printf("%d", minP1);
    printf("\n\n");
    //Assignment 2.2(a) -> findMaxMin
    int minP2, maxP2;
    int comparisions2 = findMaxMin(a, n, &maxP2, &minP2);
    printf("Using findMaxMin function \n");
    printf("Maximum element of the array is : ");
    printf("%d", maxP2);
    printf("\n");
    printf("Minimum element of the array is : ");
    printf("%d", minP2);
    printf("\n\n");
    //Assignment 2.2(b) -> findMaxMinDnQ
    int minP3, maxP3;
    int comparisions3 = findMaxMinDnQ(a, 0, n-1, &maxP3, &minP3, 0);
    printf("Using findMaxMinDnQ function \n");
    printf("Maximum element of the array is : ");
    printf("%d", maxP3);
    printf("\n");
    printf("Minimum element of the array is : ");
    printf("%d", minP3);
    printf("\n\n");

    return 0;
}