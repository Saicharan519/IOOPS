// PROGRAM -3 : WA C++ file handling program to read data from the file called student.doc

#include<iostream>
#include<fstream>

using namespace std;

main()
{
      int rno,fee;
      char name[50];
  
      ifstream fin("student.txt");
  
      fin>>rno>>name>>fee;   //read data from the file student
  
      fin.close();
  
      cout<<endl<<rno<<"\t"<<name<<"\t"<<fee;
 
      return 0;    
}
