#include<stdio.h>
#include<math.h>
int main(){
    int i, size=1;
    while(scanf("%d",&i)){
        int i1=i;
        while(i1/10){
            size++;
            i1/=10;
        }
        int mid=size/2;
        int j;
        for(j=0;j<mid+1;j++){
            int b1=i/pow(10,j);
            int b2=i/pow(10,(j+1));
            int c1=i/pow(10,(size-j-1));
            int c2=i/pow(10,(size-j));
            int a1=b1-b2*10;
            int a2=c1-c2*10;
           // int a2=(i/(10^(size+1-j))-10*i/(10^(size+2-j)));
            if(a1==a2){
                continue;
            }
            else{
                printf("no");
                break;
            }
        }
        if(j>mid){

                printf("yes");

        }
        i=0;
        size=1;
    }

    return 0;
}