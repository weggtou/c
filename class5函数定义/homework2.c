#include <stdio.h>
int isPrime(int n);
int main(){
  while(1){
    int n;
    scanf("%d",&n);
    printf("%s\n",isPrime(n)?"yes":"no");
  }
}
int isPrime(int n){
  if(n==2||n==1)return 0;
  int cont = 0;
  for(int i = 2;i<n;i++){
    cont += (n%i==0);
  }
  return cont?1:0;
}