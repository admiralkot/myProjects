#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char str[20], lol[30];
  cin.getline(lol,30);
  //cin.clear();
  cout<<"Введите название таблицы: \n";
  cin.getline(str,20);
  char query[] = "SELECT * FROM " ;
  strcat(query,str);
  cout<< query <<endl;
  return 0;
}
