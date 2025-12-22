#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define w 50
#define h 50
#define RAND_RANGE(a, b) ((a) + rand() % ((b) - (a)))

struct bodynode{
  int x;
  int y;
}food;

struct snack{
  struct bodynode body [2500];
  int size;
}S;

void initsnack(){
  S.body[0].x = w/2;
  S.body[0].y = h/2;
  S.body[1].x = S.body[0].x-1;
  S.body[1].y = S.body[0].y;
  S.size = 2;
}

void initfood(){
  food.x = RAND_RANGE(0,50);
  food.y = RAND_RANGE(0,50);
}

int score = 0;

void initui(){
  COORD c;
  c.X = S.body[0].x;
  c.Y = S.body[0].y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
  printf("@");
  for(int i = 1;i<S.size;i++){
    c.X = S.body[i].x;
    c.Y = S.body[i].y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    printf("*");
  }
  c.X = food.x;
  c.Y = food.y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
  printf("#");

  c.X = 0;
  c.Y = h+2;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


int main(){
  srand((unsigned)time(NULL));
  initsnack();
  initfood();
  initui();
}