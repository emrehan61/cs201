#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
int linearsearch( int *&arr1,  int *&arr2, int arr1length, int arr2length);

int binarySearch( int *&arr1, int l, int h, int x);
bool binary2 (int *& arr1, int *&arr2, int arr1length, int arr2length);
bool freqtable(int *& arr1, int *&arr2, int arr1length, int arr2length);


int main(int argc, char const *argv[]) {
  std::cout << "n" << '\n';
  int* arr1 = new int[100000];//n
  int arr1length = 100000;
  int* arr2 = new int[10000];//m
  int arr2length = 10000;

  for (int i  = 0; i<arr1length;i++){
    arr1[i] = rand();
  }

  for (int i = 0;i<arr2length;i++){
    arr2[i] = rand();
  }//forlinear search and freq

  /*for (int i  = 0; i<arr1length;i++){
    arr1[i] = rand();
  }

  for (int i = 0;i<arr2length;i++){
    arr2[i] = rand();
  }*///for binary
  double duration;
  clock_t startime = clock();
  linearsearch(arr1, arr2,arr1length,arr2length);
 //for(int i = 0;i<10000;i++){
  //  binary2(arr1, arr2, arr1length,arr2length);
 //}
//  freqtable(arr1, arr2, arr1length,arr2length);
  duration = 1000* double(clock()-startime)/CLOCKS_PER_SEC ;
  std::cout << "Execution took " <<duration<<"miliseconds"<< '\n';



  delete [] arr1;
  delete [] arr2;
  return 0;
}


int linearsearch( int *&arr1,  int *&arr2,int arr1length , int arr2length){
    int count = 0;

    for(int i=0;i<arr1length;i++){

      for(int j = 0;j<arr2length;j++){
         if(arr2[j] == arr1[i]) {count++;
         }

      }
    }
    if(count == arr2length) return 1;
    else return 0;

}

int binarySearch(int *&arr1, int l, int h, int x)
{
    if (h >= l)
    {

        int m = (l + h) / 2;

        if ((m == 0 || x > arr1[m - 1]) && (arr1[m] == x))
            return m;
        else if (x > arr1[m])
            return binarySearch(arr1, (m + 1), h, x);
        else
            return binarySearch(arr1, l, (m - 1), x);
    }
    return -1;
}

bool binary2(int *& arr1, int*& arr2, int arr1length, int arr2length){

   int i = 0;
   for (i = 0; i < arr2length; i++) {
       if (binarySearch(arr1, 0, arr1length-1  ,arr2[i]) == -1) return 0;
   }


   return 1;
}

bool freqtable(int *& arr1, int *&arr2, int arr1length, int arr2length){

    std::map<int,int> freq;
    for (int i = 0; i < arr1length; i++)
    {
        freq [arr1[i]]++;
    }
    for (int i = 0; i < arr2length; i++)
    {
        if (freq [arr2[i]] > 0)
            freq [arr2[i]]--;
        else
        {
            return false;
        }
    }
    return true;

}
