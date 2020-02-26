#include "stdio.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include </usr/include/mysql/mysql.h>
 
 
MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;


 
void die (void){
   printf("%s\n", mysql_error(&mysql));
   exit(0);
}

void print()
{
   while((row = mysql_fetch_row(res))) {
        for (int i = 0 ; i < mysql_num_fields(res); i++)
           printf("%s\t",row[i]);
        printf ("\n");
     }
}

void select()
{
   char str[200];
   std::cout<<"Введите запрос в БД: \n";
   std::cin.getline(str,200);
   //char query[] = "" ;
   //strcat(query,str);
   if (mysql_query(&mysql,str))
       die();
   if (!(res = mysql_store_result(&mysql))) 
       die();
   print();
   mysql_free_result(res);
   if (!mysql_eof(res)) 
       die (); 
}

int main (void)
{
    unsigned int menu = 0;
    //char *str = 0;
    bool exit=false;
    if (!mysql_init (&mysql)) abort ();
    if (!(mysql_real_connect(&mysql,"localhost","user_for_lab","t_Est444", "dblab", 3306 , NULL , 0))) // здесь вводить данные для подключения к mysql.  user_for_lab - имя юзера в БД, дальше пароль и название используемой БД.
       die();
    if (mysql_select_db(&mysql,"dblab")) //Название БД
       die();
    select();

    mysql_close(&mysql);
    return 0;
}