#include <stdio.h>
int main(){
  int a[3][4] = {{2,4,6,8},{10,12,14,16},{18,20,22,24}},(*p)[4];
  for(int i = 0;i<3;i++){
    p = a+i;
    for(int g =0;g<4;g++){
      printf("%d",*((*p)+g));
    }
    printf("\n");
  }

  for(int i = 0;i<3;i++){
    p = &a[i];
    for(int g =0;g<4;g++){
      printf("%d",*((*p)+g));
    }
    printf("\n");
  }
  for(int i = 0;i<3;i++){
    p = a+i;
    for(int g =0;g<4;g++){
      printf("%d",(*p)[g]);
    }
    printf("\n");
  }
}