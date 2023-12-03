#include<stdio.h>
int linearsearch(int a[],int data,int size);
int bin(int a[],int data,int l,int r);
int main(){
    int target,flag=0,n;
    printf("enter the number of studnts:");
    scanf("%d",&n);
    int a[n];
    printf("enter roll numbers:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter number to identify:");
    scanf("%d",&target);
    //prog1
    if(linearsearch(a,target,n)){
        printf("element present using linear search\n");
    }
    //prog2
    if(bin(a,target,0,n-1)){
        printf("element found using binarysearch\n");
    }

}
//for program1
int linearsearch(int a[],int data,int size){
    for(int i=0;i<size;i++){
        if(a[i]==data){
            return 1;
            break;
        }
    }
    return 0;
}
//for program2
int bin(int a[],int data,int l,int r){
    int mid=(l+r)/2;
    while(l<=r){
        if(data==a[mid]){
            return 1;
        }
        else if(data<a[mid]){
            r=mid-1;
            return bin(a,data,l,r);
        }
        else{
            l=mid+1;
            return bin(a,data,l,r);
        }
    }
    return 0;
    //utility:      bin(arr,key,0,size-1)?printf("found"):printf("not found");
}
