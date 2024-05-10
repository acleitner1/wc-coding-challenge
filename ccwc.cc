// ccwc.cc simple version of wc for wc coding challenge 
// Anna Leitner: May 2024

#include <fstream>
#include <iostream>
#include <string>

using namespace std; 

/*
* main - intializes ccwc 
*/
int main(int argc, char** argv) {  
   // initialize counters, base number of words, chars, bytes, etc.  
   ifstream input; 
   string filename; 
   int arg = 1;
   int l = 0;  
   int w = 0; 
   int c = 0; 
   int num_lines = 0; 
   int num_words = 0; 
   int file_bytes = 0; 
   int startWord = 0; 
   int num_chars = 0; 

   // pull filename from command line if it exists 
   while (arg < argc && argv[arg][0] == '-') {
      arg++; 
   }
   if (arg != argc) {
      filename = argv[arg]; 
   }
   arg = 1; 
   string word; 
   input.open(filename); 

   // If filename present and extant
   if (input) {

      // Read each line 
      while (getline(input, word)) {
         int position = 0; 

         // count number of bytes and number of lines 
         file_bytes += word.size(); 
         file_bytes++;
         num_lines++; 

         //count words in the line by looking at when a word starts and adding when a word stops 
         for (int i = 0; i < word.size(); i++) {
            if (word[i] != ' ' && word[i] != '\n' && word[i] != '\r' && word[i] != '\t'){
               startWord = 1;
             }

            if ((word[i] == ' ' || word[i] == '\n' || word[i] == '\r' || word[i] == '\t') && startWord == 1){ \
               num_words++; 
               startWord = 0; 
            }
         }

         // count number of chars 
         num_chars += word.size(); 
         num_chars++; 

         // check for multibyte characters (max size, 2 bytes and if one is found, delete a)
         int last = 0; 
         int last_counter = 1; 
         for (int i = 0; i < word.size(); i++) {

            if ((0x80 & word[i])!=0) {

               if (last && last_counter < 3) {
                  num_chars--; 
                  last_counter++; 
               }
               else {
                  last_counter = 1; 
               }
               last = 1; 
            }
            else {
               last = 0; 
               last_counter = 1; 
            }
         }
      }
   }
   // If no filename, proceed but using standard input 
   else if (!input) {

      // read each line 
      while (getline(cin, word)) {
         int position = 0; 

         // count number of bytes and number of lines 
         file_bytes += word.size(); 
         file_bytes++;
         num_lines++; 

         //count words in the line by looking at when a word starts and adding when a word stops 
         for (int i = 0; i < word.size(); i++) {
            if (word[i] != ' ' && word[i] != '\n' && word[i] != '\r' && word[i] != '\t'){
               startWord = 1;
             }
            
            if ((word[i] == ' ' || word[i] == '\n' || word[i] == '\r' || word[i] == '\t') && startWord == 1){ \
               num_words++; 
               startWord = 0; 
            }
         }

         // count number of chars 
         num_chars += word.size(); 
         num_chars++; 

         // check for multibyte characters (max size, 2 bytes and if one is found, delete a)
         int last = 0; 
         int last_counter = 1; 
         for (int i = 0; i < word.size(); i++) {
            if ((0x80 & word[i])!=0) {
               if (last && last_counter < 3) {
                  num_chars--; 
                  last_counter++; 
               }
               else {
                  last_counter = 1; 
               }
               last = 1; 
            }
            else {
               last = 0; 
               last_counter = 1; 
            }
         }
      }
   }

   // determine which output types have been requested and print them
   while (arg < argc && argv[arg][0] == '-') {
      if (argv[arg][1] == 'l') {
         l = 1; 
         cout << num_lines << '\t'; 
      }
      if (argv[arg][1] == 'w') {
         w = 1; 
         cout << num_words << '\t'; 
      }
      if (argv[arg][1] == 'm') {
         c = 1; 
         cout << num_chars << '\t'; 
      }
      arg++; 
   }
   input.close(); 
   input.open(filename); 

   // print all information if no flags 
   if (!l && !w && !c) {
      cout << num_lines << '\t' << num_words << '\t' << file_bytes << '\t'; 
      if (input) {
         cout << filename << endl; 
      }
      else {
         cout << endl; 
      }
   }
   else {
      if (input) {
         cout << filename << endl; 
      }
      else { 
         cout << endl; 
      }
   }
   input.close(); 
   return 0;
}

