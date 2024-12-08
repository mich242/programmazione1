// fig06_15.c
// Binary search of a sorted array.
#include <stdio.h>
#define SIZE 14
 
// Prototipi
int binarySearch(const int b[], int key, size_t low, size_t high);
int binarySearch2(const int b[], int key, int low, int high);
int binarySearch3(const int a[], int key, size_t left, size_t right);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);
 
 
int main(void) {
   int a[SIZE] = {0}; // create array a
 
   // create data
   for (size_t i = 0; i < SIZE; ++i) {
      a[i] = 2 * i;
   } 
   
   printf("%s","Enter a number between 0 and 28: ");
   int key = 0; // value to locate in array a
   scanf("%d", &key);
 
   printHeader();
 
   // search for key in array a
   //int result = binarySearch(a, key, 0, SIZE-1);
   //int result = binarySearch2(a, key, 0, SIZE-1); 
   int result = binarySearch3(a, key, 0, SIZE); //SIZE!!!
 
   // display results
   if (result != -1) {
      printf("\n%d found at subscript %d\n", key, result);
   } 
   else {
      printf("\n%d not found\n", key);
   } 
} 


int binarySearch(const int b[], int key, size_t low, size_t high) {
   // loop until low subscript is greater than high subscript
		
   while (low <= high) {
      size_t middle = (low + high) / 2; //valore medio
 
      // display subarray used in this loop iteration
      printRow(b, low, middle, high);
 
      // if key matches, return middle subscript
      if (key == b[middle]) {
         //return middle; 
		  return middle;
      }                                           
      else if (key < b[middle]) {//if key<b[middle]
         high = middle - 1; // elimino la parte alta  <<<<Può essere negativo!!!!
      }  
      else { // key > b[middle], so adjust low
         low = middle + 1; // elimino la parte bassa
      }                                            
   } // end while
 
   return -1; // searchKey not found
} 

int binarySearch2(const int b[], int key, int low, int high) {
   // loop until low subscript is greater than high subscript
	
   int ret = -1;	
	
   while (low <= high && ret == -1) {
      size_t middle = (low + high) / 2; //valore medio
 
      // display subarray used in this loop iteration
      printRow(b, low, middle, high);
 
      // if key matches, return middle subscript
      if (key == b[middle]) {
         //return middle; 
		  ret = middle;
      }                                           
      else if (key < b[middle]) {//if key<b[middle]
         high = middle - 1; // elimino la parte alta
      }  
      else { // key > b[middle], so adjust low
         low = middle + 1; // elimino la parte bassa
      }                                            
   } // end while
 
   return ret; // searchKey not found
} 

// function to perform binary search of an array
int binarySearch3(const int a[], int key, size_t left, size_t right) {
  int ret = -1;
  // loop until the interval [l, r) is not empty AND the key has not been found
  while (right - left > 0 && ret == -1) {
	size_t middle = (left + right) / 2; // determine middle subscript
    
	// display subarray used in this loop iteration
	printRow(a, left, middle, right);
    
	// if key matches, return middle subscript
	if (key == a[middle]) {
  		ret = middle;
	}
	else if (key < a[middle]) { // if key < b[middle], adjust right
  		right = middle; // next iteration searches left end of array
	}
	else { // key > b[middle], so adjust left
  		left = middle +1; // next iteration searches right end of array
	}
  } // end while

  return ret;
}



// Print a header for the output
void printHeader(void) {
   puts("\nSubscripts:");
 
   // output column head
   for (int i = 0; i < SIZE; ++i) {
      printf("%3d ", i);
   } 
 
   puts(""); // start new line of output
 
   // output line of - characters
   for (int i = 1; i <= 4 * SIZE; ++i) {
      printf("%s", "-");
   } 
 
   puts(""); // start new line of output
} 

// Print one row of output showing the current
// part of the array being processed.
void printRow(const int b[], size_t low, size_t mid, size_t high) {
   // loop through entire array
   for (size_t i = 0; i < SIZE; ++i) {
      // display spaces if outside current subarray range
      if (i < low || i > high) {
         printf("%s", "    ");
      }  
      else if (i == mid) { // display middle element
         printf("%3d*", b[i]); // mark middle value
      }  
      else { // display other elements in subarray
         printf("%3d ", b[i]);
      } 
   } 
 
   puts(""); // start new line of output
} 


