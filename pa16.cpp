/// @author Arin Arjani
/// @note pa16
/// @file pa16.cpp
/// @version 2016-04-23
/// @brief Complete the following steps 3 times, measuring the time to complete
///        each search and sort function:
///
///        1. Call array initialization function to initialize an array
///           with random values. After initialization, this array shall
///           remain unaltered for the duration of the program.
///
///        2. Call an array copy function to make a working copy of the
///           random array.
///
///        3. Call a function that uses the sequential search algorithm to
///           locate the value 58980 in the array copy. If found, the function
///           should report its position in the array, or - 1 if not found.
///
///        4. Call a function that uses the bubble sort algorithm to sort the
///           array copy in ascending order.
///
///        5. Call a function that uses the binary search algorithm to locate
///           the value 58980 in the array copy. If found, the function should
///           report its position in the array, or - 1 if not found.
///
///        6. Call an array copy function to make a duplicate of the random
///            array.
///
///        7. Call a function that uses the selection sort algorithm to sort
///           the array (described in chapter 8).
///
///        8. Call an array copy function to make a duplicate of the random
///           array.
///
///        9. Call a function that uses the insertion sort algorithm to sort
///           the array.

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

// ============================================================================
//                            PROTOTYPES
//=============================================================================
void create_main_array ( int array[], int size );
void array_copy (const int array[], int size, int output[] );
int seqSearch ( const int list[], int listLength, int searchItem );
void bubbleSort ( int list[], int length );
int binarySeacrh ( const int list[], int listLength, int searchItem );
void selectionSort ( int list[], int length );
void insertionSort ( int list[], int listLength );

// ============================================================================
//                            MAIN
//=============================================================================

int main() {
  const int SIZE = 100000;  // states size of all arrays
  const int START = 1;  // start numer of tests
  const int STOP = 3;  // end number of tests
  int array_changer_1[SIZE];  // holder to be changed
  int array_changer_2[SIZE];  // holder to be changed
  int array_changer_3[SIZE];  // holder to be changed
  int main_array[SIZE];  // main array used to create duplicates
  clock_t clock_start;  // used to track CPU start time
  clock_t clock_stop;  // used to track CPU end time
  double seq_search_avg = 0;  // used to find search average
  double bub_sort_avg = 0;  // used to find sort average
  double bin_search_avg = 0;  // used to find search average
  double select_search_avg = 0;  // used to find search average
  double insert_search_avg = 0;  // used to find search average
  int times_around = 3;  // used to find aveage of tests

  srand( static_cast<unsigned>( time( NULL ) ) );

  for (int i = START; i <= STOP; i++) {
    // =========================================================================
    //                                 1
    //==========================================================================
      create_main_array ( main_array, SIZE );
    // =========================================================================
    //                                 2
    //==========================================================================
      array_copy ( main_array, SIZE, array_changer_1 );
    // =========================================================================
    //                                 3
    //==========================================================================
      clock_start = clock();
      seqSearch ( array_changer_1, SIZE, 58980 );
      clock_stop = clock();
      seq_search_avg += static_cast<double>(clock_stop - clock_start);
    // =========================================================================
    //                                 4
    //==========================================================================
      clock_start = clock();
      bubbleSort( array_changer_1, SIZE );
      clock_stop = clock();
      bub_sort_avg += static_cast<double>(clock_stop - clock_start);
    // =========================================================================
    //                                 5
    //==========================================================================
      clock_start = clock();
      binarySeacrh ( array_changer_1, SIZE, 58980 );
      clock_stop = clock();
      bin_search_avg += static_cast<double>(clock_stop - clock_start);
    // =========================================================================
    //                                 6
    //==========================================================================
      array_copy ( main_array, SIZE, array_changer_2 );
    // =========================================================================
    //                                 7
    //==========================================================================
      clock_start = clock();
      selectionSort ( array_changer_2, SIZE );
      clock_stop = clock();
      select_search_avg += static_cast<double>(clock_stop - clock_start);
    // =========================================================================
    //                                 8
    //==========================================================================
      array_copy ( main_array, SIZE, array_changer_3 );
    // =========================================================================
    //                                 9
    //==========================================================================
      clock_start = clock();
      insertionSort ( array_changer_3, SIZE );
      clock_stop = clock();
      insert_search_avg += static_cast<double>(clock_stop - clock_start);
  }

  seq_search_avg /= times_around;
  bub_sort_avg /= times_around;
  bin_search_avg /= times_around;
  select_search_avg /= times_around;
  insert_search_avg /= times_around;


  // output
  cout << "Average CPU times with " << SIZE << " elements" << endl;
  cout << setprecision(6) << fixed;
  cout << "Linear search:       " << seq_search_avg / CLOCKS_PER_SEC << endl;
  cout << "Binary search:       " << bin_search_avg / CLOCKS_PER_SEC << endl;
  cout << "Bubble sort:         " << bub_sort_avg / CLOCKS_PER_SEC << endl;
  cout << "Selection sort:      " << select_search_avg / CLOCKS_PER_SEC << endl;
  cout << "Insertion sort:      " << insert_search_avg / CLOCKS_PER_SEC << endl;

  return 0;
}

// ============================================================================
//                            FUNCTIONS
//=============================================================================

// ============================================================================
//                                 1
//=============================================================================
void create_main_array ( int array[], int size ) {
  int start = 0;  // start loop
  for (int i = start; i < size; i++) {
    array[i] = rand();
  }
}

// ============================================================================
//                                 2
//=============================================================================
void array_copy ( const int array[], int size, int output[] ) {

  for ( int i = 0; i < size; i++ ) {
    output[i] = array[i];
  }

}

// ============================================================================
//                                 3
//=============================================================================
int seqSearch ( const int list[], int listLength, int searchItem ) {

  int loc;  // location of searched item
  bool found = false;  // test to see if test went well
  loc = 0;  // location start for search

  while ( loc < listLength && !found ) {
    if ( list[loc] == searchItem ) {
      found = true;
    } else {
      loc++;
    }
  }

  return found ? loc : -1;

}

// ============================================================================
//                                 4
//=============================================================================
void bubbleSort(int list[], int length) {
  int temp;  // holder for sorting
  int iteration;  // temp + 1
  int index;  // index of sorted item
  for (iteration = 1; iteration < length; iteration++) {
    for (index = 0; index < length - iteration; index++) {
      if (list[index] > list[index + 1]) {
        temp = list[index];
        list[index] = list[index + 1];
        list[index + 1] = temp;
      }
    }
  }
}
// ============================================================================
//                                 5
//=============================================================================
int binarySeacrh ( const int list[], int listLength, int searchItem ) {
    int first = 0;  // first item in array
    int last = listLength -1;  // last item in array
    int mid;  // middle of array

    bool found = false;  // test to see if search went well

    while ( first <= last && !found ) {
      mid = ( first + last ) / 2;

      if ( list[mid] == searchItem ) {
        found = true;
      } else if ( list[mid] > searchItem ) {
        last = mid - 1;
      } else {
        first = mid + 1;
      }
    }

    return found ? mid : -1;
}
// ============================================================================
//                                 7
//=============================================================================
void selectionSort ( int list[], int length ) {
  int index;  // index of selection
  int smallestIndex;  // smalled item in list[]
  int location;  // location of loop
  int temp;  // holder for location of loop

  for ( index = 0; index < length - 1; index++ ) {
    smallestIndex = index;

    for ( location = index + 1; location < length; location++ ) {
      if ( list[location] < list[smallestIndex] ) {
        smallestIndex = location;
      }

    temp = list[smallestIndex];
    list[smallestIndex] = list[index];
    list[index] = temp;
    }
  }
}
// ============================================================================
//                                 9
//=============================================================================
void insertionSort ( int list[], int listLength ) {
  int firstOutOfOrder;  // start of loop
  int location;  // location of item to sort
  int temp;  // item to sort

  for (firstOutOfOrder = 1; firstOutOfOrder < listLength;  firstOutOfOrder++) {
      if ( list[firstOutOfOrder] < list[firstOutOfOrder - 1] ) {
        temp = list[firstOutOfOrder];
        location = firstOutOfOrder;
        do {
          list[location] = list[location - 1];
          location--;
        } while (location > 0 && list[location - 1] > temp);
        list[location] = temp;
      }
  }
}
