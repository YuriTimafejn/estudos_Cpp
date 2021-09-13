#include <iostream>
#include <conio.h>
#include <dos.h>
#include <Windows.h>
#include <time.h>

char d0[5][3] = {
  '*','*','*',
  '*',' ','*',
  '*',' ','*',
  '*',' ','*',
  '*','*','*'
};
char d1[5][3] = {
  ' ',' ','*',
  ' ',' ','*',
  ' ',' ','*',
  ' ',' ','*',
  ' ',' ','*'  
};
char d2[5][3] = {
  '*','*','*',
  ' ',' ','*',
  '*','*','*',
  '*',' ',' ',
  '*','*','*'
};
char d3[5][3] = {
  '*','*','*',
  ' ',' ','*',
  '*','*','*',
  ' ',' ','*',
  '*','*','*',
};
char d4[5][3] = {
  '*',' ','*',
  '*',' ','*',
  '*','*','*',
  ' ',' ','*',
  ' ',' ','*',
};
char d5[5][3] = {
  '*','*','*',
  '*',' ',' ',
  '*','*','*',
  ' ',' ','*',
  '*','*','*',
};
char d6[5][3] = {
  '*','*','*',
  '*',' ',' ',
  '*','*','*',
  '*',' ','*',
  '*','*','*',
};
char d7[5][3] = {
  '*','*','*',
  ' ',' ','*',
  ' ','*',' ',
  ' ','*',' ',
  '*',' ',' ',
};
char d8[5][3] = {
  '*','*','*',
  '*',' ','*',
  '*','*','*',
  '*',' ','*',
  '*','*','*',
};
char d9[5][3] = {
  '*','*','*',
  '*',' ','*',
  '*','*','*',
  ' ',' ','*',
  '*','*','*',
};
char separator[5][3] = {
  ' ',' ',' ',
  ' ','*',' ',
  ' ',' ',' ',
  ' ','*',' ',
  ' ',' ',' '
};

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
  CursorPosition.X = x;
  CursorPosition.Y = y;
  SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size)
{
  if (size == 0)
    size = 20;

  CONSOLE_CURSOR_INFO lpCursor;
  lpCursor.bVisible = visible;
  lpCursor.dwSize = size;
  SetConsoleCursorInfo(console, &lpCursor);
}

void printDigit(int no, int x, int y)
{
  
  for(int i=0;i<5;i++) {
    for (int j=0;j<3;j++) {
      switch(no) {
        case 0:
          gotoxy(x+j,y+i);
          std::cout << d0[i][j];
          break;
        case 1:
          gotoxy(x+j,y+i);
          std::cout << d1[i][j];
          break;
        case 2:
          gotoxy(x+j,y+i);
          std::cout << d2[i][j];
          break;
        case 3:
          gotoxy(x+j,y+i);
          std::cout << d3[i][j];
          break;
        case 4:
          gotoxy(x+j,y+i);
          std::cout << d4[i][j];
          break;
        case 5:
          gotoxy(x+j,y+i);
          std::cout << d5[i][j];
          break;
        case 6:
          gotoxy(x+j,y+i);
          std::cout << d6[i][j];
          break;
        case 7:
          gotoxy(x+j,y+i);
          std::cout << d7[i][j];
          break;
        case 8:
          gotoxy(x+j,y+i);
          std::cout << d8[i][j];
          break;
        case 9:
          gotoxy(x+j,y+i);
          std::cout << d9[i][j];
          break;
      }
    }
  }
}

void drawBorder(int x=0, int y=0)
{
  char vertical = 186;
  char horizontal = 205;
  char tr = 187;
  char br = 188;
  char tl = 201;
  char bl = 200;
  int width = 50;
  int height = 11;

  gotoxy((width/2)+x-11, y);
  std::cout << "H O R A R I O  A T U A L :";

  for(int i=1;i<=height;i++) {
    for(int j=1;j<=width;j++) {
      gotoxy(j+x,i+y);

      if(j==1 && i==1) 
        std::cout << tl;
      else if(i==height && j==1)
        std::cout << bl;
      else if(i==1 && j==width)
        std::cout << tr;
      else if(i==height && j==width)
        std::cout << br;
      else if(i==1 || i==height)
        std::cout << horizontal;
      else if(j==1 || j==width)
        std::cout << vertical;
    }
  }
}

int main () {
  system("cls");
  setcursor(0,0);
  srand((unsigned) time(NULL));

  time_t now = time(0);

  char* dt = ctime(&now); // Convert time_t now to string
  tm *lotm = localtime(&now); // Convert time_t now to tm struct for UTC
  dt = asctime(lotm);

  int hour = lotm->tm_hour;
  int minute = lotm->tm_min;
  int second = lotm->tm_sec;

  int gap = 5;
  int posX;
  int posY = 8;

  while(true) {
    system("cls");
    drawBorder(9,4);

    posX = 15;

    if(kbhit()) {
      char ch = getch();
      if(ch==27) {
        break;
      }
    }
    if(hour < 10) {
      printDigit(0,posX,posY);
      printDigit(hour,posX+=gap,posY);
    } else  {
      printDigit(hour/10, posX, posY);
      printDigit(hour%10, posX+=gap, posY);
    }

    printDigit(10, posX+=gap, posY);

    if(minute < 10) {
      printDigit(0,posX+=gap,posY);
      printDigit(minute,posX+=gap,posY);
    } else  {
      printDigit(minute/10, posX+=gap, posY);
      printDigit(minute%10, posX+=gap, posY);
    }

    printDigit(10,posX+=gap, posY);

    if(second < 10) {
      printDigit(0,posX+=gap,posY);
      printDigit(second,posX+=gap,posY);
    } else  {
      printDigit(second/10, posX+=gap, posY);
      printDigit(second%10, posX+=gap, posY);
    }

    printDigit(10,posX+=gap, posY);

    Sleep(950); // Refresh
    second++;
    if(second>=60){
      second=0;
      minute++;
    }
    if(minute>=60){
      minute=0;
      hour++;
    }
    if(hour>=24){
      second=0;
      minute=0;
      hour=0;
    }
  }

  return 0;
}