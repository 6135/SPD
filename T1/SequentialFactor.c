#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

extern char *optarg;
extern int  optind, opterr;


int main(int argc, char **argv) {
    int x = '0';
    if(argc > 2)
        x = *argv[1];
    if(x == 'A')
        factorizedSequential(atoi(argv[2]));
    else
        printf("Please select option and a number\n");
   return (0);
}

void factorizedSequential(int x){
    clock_t begin = clock();
    int sum=0,factorSize = 1,digits = x, digitsCount = 0;
    if(x==0) {
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%f\n",time_spent);
        return 0;
    }

    while (digits != 0) {
        digits /= 10;
        digitsCount++;
    }
    
    int a[digitsCount],factors[12];
    split(a,x,digitsCount);
    factors[0]=1;
    //ints_println_basic(a,digitsCount);
    for(int i = 0; i<digitsCount; i++)
        sum+=a[i]; 
    
    if(byTwo(a[digitsCount-1])){
        factors[factorSize++]=2;
        if(byFour(a+(digitsCount-2)))
            factors[factorSize++]=4;
        if(byThree(sum)){
            factors[factorSize++]=3;
            factors[factorSize++]=6;
            if(byNine(sum))
                factors[factorSize++]=9;
        }
    } else if(byThree(sum)){
        factors[factorSize++]=3;
        if(byNine(sum))
            factors[factorSize++]=9;
    }
    if(byFive(a[digitsCount-1]))
        factors[factorSize++]=5;
    if(byTen(a[digitsCount-1]))
        factors[factorSize++]=10;
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //ints_println_basic(factors,factorSize);
    //printf("%f\n",time_spent);
}

void ints_println_basic(const int *a, int n){
  if (n > 0) {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)  // i = 1
      printf(" %d", a[i]);
  }
  printf("\n");
}
void split(int *a,int x, int dCount){
    if(dCount!=0){
        int count = 0;    
        int n = x;

        while (n != 0){
            a[count] = n % 10;
            n /= 10;
            count++;
        }
        int b[dCount];
        n=0;
        for(int i = dCount-1;i>-1;i--)
            b[n++]=a[i];
        for(int i=0;i<dCount;i++)
            a[i]=b[i];
    }
}

int byTwo(int x){
    return x%2 == 0;
}

int byThree(int sum){
    return sum%3==0;
}

int byFour(int *a){
    char num[2];
    num[0] = a[0];
    num[1] = a[1];
    return atoi(num)%4;
}

int byFive(int x){
    return (x==5 || x==0);
}

int byNine(int sum){
    return sum%9==0;
}

int byTen(int x){
    return x==0;
}