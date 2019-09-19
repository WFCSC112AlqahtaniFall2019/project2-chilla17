#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right); // divide lists until lists have 1 element each (divide)
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right); // merge each list (conquer)

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    vector<int> test = {3,-7, 14,11, 8, 1, 13, -16, 2, 0};
    vector<int> tmpTest = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    mergeSort(test, tmpTest, 0, 5);

    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v, t, 0, length-1);

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

/* your code here */

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(a, tmp, left, mid); // recursive statement dividing the left side of the vector
        mergeSort(a, tmp, mid + 1, right); // recursive statement dividing the right side of the vector
        mergeSortedLists(a, tmp, left, mid, right); // calling mergeSortedLists function
    }
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right) {
    // creating new variables here to 'travel' through the vector and compare values
    int posLeft = left; // left position in left half of vector
    int mid = middle + 1; // left position in right half of vector
    int posRight = mid; // right position in left half of vector
    int posTmp = left; // position in tmp array, incremented in each loop

    while ((posLeft <= middle) && (posRight <= right)) { // referring to the two halves of the vector
        if (a.at(posLeft) <= a.at(posRight)) { // if left element in left half is less than left element in right half
            tmp.at(posTmp) = a.at(posLeft); // move left element in left half to first available position in tmp vector
            posLeft++; // increment position in left half
        }
        else { // if left element in right half is less than left element in left half
            tmp.at(posTmp) = a.at(posRight); // move left element in right half to first available position in tmp vector
            posRight++; // increment position in right half
        }
        posTmp++; // increment position in tmp vector to next available position
    }

    while (posRight <= right) { // the case that all elements in left half have been sorted
        tmp.at(posTmp) = a.at(posRight); // move left element in right half to next available tmp position
        posRight++; // increment position in right half
        posTmp++; // increment position in tmp vector to next available position
    }

    while (posLeft <= middle) { // the case that all elements in right half have been sorted
        tmp.at(posTmp) = a.at(posLeft); // move left element in left half to next available tmp position
        posLeft++; // increment position in left half
        posTmp++; // increment position in tmp vector to next available position
    }

    for (int i = left; i <= right; i++) { // replace values in original vector with sorted values in tmp vector
        a.at(i) = tmp.at(i);
    }
}




