//Code by Sumon Kumar Das(2012069)
include <stdio.h>
#define N 4000

char last[N], second_Last[N], current[N], carry=0;
int k=N-1;
void fibbo_Number(int n){
    if(n==0){
        printf("%d", 0);
        return;
    }
    else if(n==1){
        printf("%d", 1);
        return;
    }
    last[N-1]=1;
    second_Last[N-1]=0;
    for(int i=2; i<=n; i++){
        for(int i=N-1; i>=k; i--){
            int l = last[i]+second_Last[i]+carry;
            current[i]=(l%10);
            carry=l/10;
            if(i==k && carry>0) k--;
        }
        for(int i=N-1; i>=k; i--){
            second_Last[i]=last[i];
            last[i]=current[i];   
        }
    }
    for(int i=k; i<N; i++)
        printf("%d", current[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    fibbo_Number(n);
    return 0;
}
