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

int readFile(string filename, int line, int words) {
   ifstream input; 
   input.open(filename); 
   string word; 
   if (!input) {
      // file does not exist 
      return -1; 
   }
   // instead of counting bytes, we want to count lines 
   if (line) {
      int num_lines = 0; 
      
      while (getline(input, word)) {
         num_lines++; 
      }
      return num_lines; 

   }
   if (words) {
      int num_words = 0; 
      while (input >> word) {
         num_words++; 
      }
      return num_words; 
   }
   // generic case 
   input.seekg(0, ios::end); 
   int file_bytes = input.tellg(); 
   input.close(); 
   return file_bytes; 
}


/*
* main - intializes ccwc 
*/
int main(int argc, char** argv) {   
   if (argc < 2) {
      cout << "must include a txt file" << endl; 
      exit(0); 
   }
   ifstream input; 
   string filename; 
   int arg = 1;
   int l = 0;  
   int w = 0; 
   // iterate through the flags to get to the file 
   while (arg < argc && argv[arg][0] == '-') {
      // if (argv[arg].length() != 2) {
      //    cout << "improper flag" << endl; 
      //    exit(0); 
      // }
      if (argv[arg][1] == 'l') {
         l = 1; 
      }
      if (argv[arg][1] == 'w') {
         w = 1; 
      }
      arg++; 
   }
   if (arg == argc) {
      cout << "must include a txt file" << endl; 
      exit(0); 
   }
   // open the file 
   //input.open(argv[arg]); 
   filename = argv[arg]; 
   long chars = readFile(filename, l, w); 
   cout << chars << " " << filename << endl; 
   return 0;

}

