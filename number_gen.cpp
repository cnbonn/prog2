#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <new>


using namespace std;

int main()
{
  srand(time(NULL));
  int numbers;
  char file_name[10];
  bool check;
  int n;
int spot = 0;
  cout << "insert file name: " ;
  cin >> file_name;
  cout << " how many numbers generated: ";
  cin >> numbers;

  ofstream fout;
  fout.open("joesballs.txt");

  int *arraya;
  arraya = new (nothrow) int[numbers];
  if(arraya == NULL )
     return -1;


   for( int i = 0; i < numbers ; i++)
   {
     do{
     n = rand() % 1000;
     check = true;
     for( int j = 0; j< i; j++ )
     {
       if(n == arraya[j])
       {
         check = false;
         break;          
       }
      
     }
    }while(!check);
    arraya[spot] = n;
    spot++;
   }
  

  for(int i = 0; i < numbers; i++)
  {
     fout << arraya[i] << endl;
     cout << arraya[i] << endl;
  }
  delete[] arraya;
  fout.close();
  return 0;
}
