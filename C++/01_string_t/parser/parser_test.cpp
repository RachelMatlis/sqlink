#include<iostream>
#include"parser.h"

using namespace std;

int main(int argc, char argv[])
{
   Parser p;
   try 
   {
	   p.parse("test1.txt");
   }
   catch (string err)
   {
	   cout << err;
   }
 

   int i;
   cin >> i;
}

