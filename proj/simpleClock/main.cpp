#include <iostream>
#include <windows.h>

int main () {
  short int hour, minute, second, error, a;
  error = a = 0;

  while(error==0) {
    std::cout << "Entre com a hora: ...... ";
    std::cin >> hour;
    std::cout << "Entre com os minutos: .. ";
    std::cin >> minute;
    std::cout << "Entre com os segundos: . ";
    std::cin >> second;

    if(hour < 24 && minute < 60 && second < 60) {
      error++;
    }
    else {
      system("cls");
    } 
  }
  while(a==0) {
    system("cls");
    std::cout << hour << ":" << minute << ":" << second << std::endl;
    Sleep(1000);
    second++;

    if(second > 59) {
      second = 0;
      minute++;
    }
    if(minute > 59) {
      minute = 0;
      hour++;
    }
  }
  return 0;
}