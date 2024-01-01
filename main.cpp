#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int MAX_SIZE = 8192;
void merge(int theArray[], int first, int mid, int last) {
    int tempArray[MAX_SIZE]; // temporary array
    int first1 = first; // beginning of first subarray
    int last1 = mid; // end of first subarray
    int first2 = mid + 1; // beginning of second subarray
    int last2 = last; // end of second subarray
    int index = first1; // next available location in tempArray
    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        if (theArray[first1] < theArray[first2]) {
            tempArray[index] = theArray[first1];
            ++first1;
        }
        else {
            tempArray[index] = theArray[first2];
            ++first2;
        }
    }
}

void mergesort(int theArray[], int first, int last) {
    if (first < last) {
        int mid = (first + last)/2; // index of midpoint
        mergesort(theArray, first, mid);
        mergesort(theArray, mid+1, last);
 		merge(theArray, first, mid, last);
 	}
}




void choosePivot(int theArray[], int first, int last)
{
    // Choose the median of three: first, middle, last
    int middle = (first + last) / 2;

    // Sort first, middle, last
    if (theArray[first] > theArray[middle])
        std::swap(theArray[first], theArray[middle]);
    if (theArray[middle] > theArray[last])
        std::swap(theArray[middle], theArray[last]);
    if (theArray[first] > theArray[middle])
        std::swap(theArray[first], theArray[middle]);
}
void partition(int theArray[], int first, int last, int &pivotIndex) {
 choosePivot(theArray, first, last);
 int pivot = theArray[first];
 int lastS1 = first; // index of last item in S1
 int firstUnknown = first + 1; // index of first item in unknown

 for ( ; firstUnknown <= last; ++firstUnknown) {
 if (theArray[firstUnknown] < pivot) { // belongs to S1
 ++lastS1;
 swap(theArray[firstUnknown], theArray[lastS1]);
 } // else belongs to S2
 }
 // place pivot in proper position and mark its location
 swap(theArray[first], theArray[lastS1]);
 pivotIndex = lastS1;
}


void quicksort(int theArray[], int first, int last) {
    // Precondition: theArray[first..last] is an array.
    // Postcondition: theArray[first..last] is sorted.
    int pivotIndex;
    if (first < last) {
    partition(theArray, first, last, pivotIndex);
    // sort regions S1 and S2
    quicksort(theArray, first, pivotIndex-1);
    quicksort(theArray, pivotIndex+1, last);
 }
}



void bubbleSort(int theArray[], int n) {
 bool sorted = false;

for (int pass = 1; (pass < n) && !sorted; ++pass) {
 sorted = true;
 for (int index = 0; index < n-pass; ++index) {
 int nextIndex = index + 1;
 if (theArray[index] > theArray[nextIndex]) {
 swap(theArray[index], theArray[nextIndex]);
 sorted = false; // signal exchange
 }
 }
 }
}


int *generate_almost_sorted_array(int size) {
srand((unsigned int)time(NULL));
int *my_array = new int[size];
for (int i = 0; i < size; i++) {
my_array[i] = i;
if (std::rand() % 10 == 1) {
my_array[i] = i + size;
}
}
return my_array;
}

int *generate_random_array(int size){
    int *my_array = new int[size];
    for (int i = 0; i < size; i++) {
        my_array[i] = std::rand()%100;
    }
}

int *generate_descending_array(int size){
    int *my_array = new int [size];
    for (int i= 0; i< size; i--){
        my_array[i] = size -i;
    }
    return my_array;
}

int * generate_ascending_array(int size)
{
    int *my_array = new int[size];
    for (int i = 0; i < size; i++)
    {
        my_array[i] = i + 1;
    }
    return my_array;
}
int main()
{
    int size = 16;
    double totalDuration = 0;
    for (int i = 0; i < 10; i++){
        int* arr = generate_almost_sorted_array(size);
        clock_t c_start = clock();

        mergesort(arr, 0, size);

        clock_t c_end = clock();
        double duration = (float) (c_end - c_start) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " seconds for Merge Sort, almost sorted array of size " << size << endl;
        size *= 2;
    }
    size = 16;
    totalDuration = 0;
    for (int i = 0; i < 10; i++){
        int* arr = generate_ascending_array(size);
        clock_t c_start = clock();

        mergesort(arr, 0, size);

        clock_t c_end = clock();
        double duration = (float) (c_end - c_start) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " seconds for Merge Sort, ascending array of size " << size << endl;
        size *= 2;
    }

     size = 16;
    totalDuration = 0;
    for (int i = 0; i < 10; i++){
        int* arr = generate_descending_array(size);
        clock_t c_start = clock();

        mergesort(arr, 0, size);

        clock_t c_end = clock();
        double duration = (float) (c_end - c_start) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " seconds for Merge Sort, descending array of size " << size << endl;
        size *= 2;
    }


    size = 16;
    totalDuration = 0;
    for (int i = 0; i < 10; i++){
        int* arr = generate_random_array(size);
        clock_t c_start = clock();

        mergesort(arr, 0, size);

        clock_t c_end = clock();
        double duration = (float) (c_end - c_start) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " seconds for Merge Sort, random array of size " << size << endl;
        size *= 2;
    }

     size = 16;
    totalDuration = 0;
    for (int i = 0; i < 10; i++){
        int* arr = generate_random_array(size);
        clock_t c_start = clock();

        bubbleSort(arr, size);

        clock_t c_end = clock();
        double duration = (float) (c_end - c_start) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " seconds for Bubble Sort, random array of size " << size << endl;
        size *= 2;
    }

    size = 16;
    totalDuration = 0;
    for (int i = 0; i < 10; i++){
        int* arr = generate_ascending_array(size);
        clock_t c_start = clock();

        bubbleSort(arr, size);

        clock_t c_end = clock();
        double duration = (float) (c_end - c_start) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " seconds for Bubble Sort, ascending array of size " << size << endl;
        size *= 2;
    }

    size = 16;
    totalDuration = 0;
    for (int i = 0; i < 10; i++){
        int* arr = generate_descending_array(size);
        clock_t c_start = clock();

        bubbleSort(arr, size);

        clock_t c_end = clock();
        double duration = (float) (c_end - c_start) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " seconds for Bubble Sort, descending array of size " << size << endl;
        size *= 2;
    }

    size = 16;
    totalDuration = 0;
    for (int i = 0; i < 10; i++){
        int* arr = generate_descending_array(size);
        clock_t c_start = clock();

        quicksort(arr, 0, size);

        clock_t c_end = clock();
        double duration = (float) (c_end - c_start) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " seconds for Quick Sort, descending array of size " << size << endl;
        size *= 2;
    }













    return 0;
}
