#include <stdio.h>
typedef struct shun{
  char store[10];
  int length;
}chuan;

void stringassign(chuan *a,char b[]){
  int i;
  for( i = 0;b[i]!='\n';i++){
    a->store[i] = b[i];
  }
  a->length = i;
}

int sEmpty(chuan a){
  if(a.length == 0){
    return 1;
  }else{
    return 0;
  }
}

int sLength(chuan a){
  return a.length;
}

int scomper(chuan a,chuan b){
  for(int i = 0;i<a.length&&i<b.length;i++){
    if(a.store[i]==b.store[i]){
      continue;
    }else if(a.store[i]>b.store[i]){
      return 1;
    }else if(a.store[i]<b.store[i]){
      return -1;
    }
  }
}