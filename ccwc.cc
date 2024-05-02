// ccwc.cc simple version of wc for wc coding challenge 
// Anna Leitner: May 2024

#include <fstream>
#include <iostream>
#include <string>
// #include <set>
// #include <vector>
// #include <limits>
// #include <algorithm>

using namespace std; 

struct argsStruct{
        int argc;
        char** argv;
  } ;

void parse(argsStruct* argsPtr) {
   cout << argsPtr->argc << endl; 
   cout << argsPtr->argv[1] << endl; 
   // todo:
   // find the txt file 
   // parse the txt file and count the number of characters 
   // confirm that a text file is included (not just flags) 
   // if a file doesn't exist, return 0 
   // if no file is specified, return 0
}

/*
* main - intializes ccwc 
*/
int main(int argc, char** argv) {   
   if (argc < 2) {
      cout << "must include a txt file" << endl; 
      exit(0); 
   }
   argsStruct* argsPtr = (argsStruct*) malloc(sizeof(argsStruct));
   argsPtr->argc = argc;
   argsPtr->argv = argv;
   
   parse(argsPtr); 
   

  return 0;
}

