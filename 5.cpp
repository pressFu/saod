#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void InsertSort(int *x,int n){
	int i, key, j, M=0, C=0, insert;
    for (i = 1; i < n; i++) { 
        key = x[i]; 
        j = i - 1; 
        while (j >= 0 && x[j] > key) { 
            x[j + 1] = x[j]; 
            j = j - 1;
			C+=2; 
        } 
        x[j + 1] = key;
		M++; 
    } 
    insert = M+C;
    cout<<"    "<<insert<<endl;
}
void BubbleSort(int *x, int n) {
  int M = 0, C = 0, SMC = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > 0; j--) {
      if (x[j] < x[j - 1]) {
        int t = x[j];
        x[j] = x[j - 1];
        x[j - 1] = t;
        C += 3;
      }
      M++;
    }
  }
  //	cout<<"M: "<<M<<endl;
  //	cout<<"C: "<<C<<endl;
  SMC = M + C;
  cout << "    " << SMC<<endl;
}
void ShakerSort(int *x, int n) {
  int t = 0, u = 0, d = (n - 1);
  int M = 0, C = 0, ShMC = 0;
  while (u < d) {
    for (int i = u; i < d; i++) {
      if (x[i] > x[i + 1]) {
        t = x[i];
        x[i] = x[i + 1];
        x[i + 1] = t;
        C += 3;
      }
      M++;
    }
    d--;
    for (int j = d; j > u; j--) {
      if (x[j] < x[j - 1]) {
        t = x[j];
        x[j] = x[j - 1];
        x[j - 1] = t;
        C += 3;
      }
      M++;
    }
    u++;
  }
  ShMC = M + C;
  cout << "    " << ShMC<<endl;
}
void SelectSort(int *x,int n){
	int m=0,c=0,select;
	for(int i=0;i<n-1;i++){
		int min = i;
		for(int j = i+1;j<n;j++){
			if(x[j]<x[min]) min = j;
			c++;
		}
		int t = x[i];
		x[i] = x[min];
		x[min] = t;
		m++;
	}
	select=m+c;
	cout<<"    "<<select<<endl;
/*	for(int i=0;i<n;i++){
		cout<<x[i]<<" ";
	}*/
}
void FillDec(int *x, int n) {
  for (int i = n; i > 0; i--) {
    x[i] = i;
  }
}
void FillRand(int *x, int n) {
  srand(time(0));
  for (int i = 0; i < n; i++) {
    x[i] = rand() % 100;
  }
}
void FillInc(int *x, int n) {
  for (int i = 0; i < n; i++) {
    x[i] = i + 1;
  }
}
void printmass(int *x,int n){
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ";
	}
}


main(){
	setlocale(LC_ALL, "Rus");
    srand(time(0));
	int *a;
	int n,arr[5];
	a = new int (n);
//	cout<<"INPUT N: "; cin>>n;
/*	FillRand(a,n);
	InsertSort(a,n); //	testing insert sort
	printmass(a,n);*/
	for(int N=0;N<5;N++){
		cout<<"Input n["<<N+1<<"] "; cin>>arr[N]; //mass n
	}
	cout<<" n     "<<"select "<<endl;
	for(int i=0;i<5;i++){
		cout<<arr[i];
		FillRand(a,arr[i]);
		SelectSort(a,arr[i]);
	}
	cout<<endl<<" n     "<<"Bubble "<<endl;
	for(int i=0;i<5;i++){
		cout<<arr[i];
		FillRand(a,arr[i]);
		BubbleSort(a,arr[i]);
	}
		cout<<endl<<" n     "<<"Shaker "<<endl;
	for(int i=0;i<5;i++){
		cout<<arr[i];
		FillRand(a,arr[i]);
		ShakerSort(a,arr[i]);
	}
		cout<<endl<<" n     "<<"Insert "<<endl;
	for(int i=0;i<5;i++){
		cout<<arr[i];
		FillRand(a,arr[i]);
		InsertSort(a,arr[i]);
	}
	
	
	return 0;
}
