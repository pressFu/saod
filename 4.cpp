#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

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
  cout << "   " << SMC;
}
void FillDec(int *x, int n) {
  /*	int i,j,t;
          for(i=0;i<15-1;i++){
              for(j=(15-1);j>i;j--){
                          if(x[j-1]>x[j]){
                          t=x[j-1];
                          x[j-1]=x[j];
                          x[j]=t;
                  }
          }
          }
      for(i=14;i>0;i--){
                  cout<<x[i]<<" ";
          } 	*/
  for (int i = n; i > 0; i--) {
    x[i] = i;
    //		cout<<x[i]<<" ";
  }
}
void FillRand(int *x, int n) {
  srand(time(0));
  for (int i = 0; i < n; i++) {
    x[i] = rand() % 100;
    //			cout<< x[i] <<" ";
  }
}
void FillInc(int *x, int n) {
  /*	int i,j,t;
          for(i=0;i<15-1;i++){
         for(j=0;j<15-i-1;j++){
             if(x[j] > x[j+1]){
                t=x[j];
                x[j]=x[j+1] ;
                x[j+1]=t;
             }
          }
      }
      for(i=0;i<15;i++){
                  cout<<x[i]<<" ";
          } */
  for (int i = 0; i < n; i++) {
    x[i] = i + 1;
    //		cout<<x[i]<<" ";
  }
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
  cout << "   " << ShMC;
}

main() {
  setlocale(LC_ALL, "Rus");
  srand(time(0));
  /*
          int n;
          cin>>n;
          int A[n];
          for(int i=0;i<n;i++){			����� � �������� ������ ����
                  A[i]=rand() % 100;
                  cout<<A[i]<<" ";
          }
          cout<<endl;
          ShakerSort(A,n);
          for(int i=0;i<n;i++){
                  cout<<A[i]<<" ";
          }
          */

  int n, Mt, Ct, SumMC, SMC;
  int Ns[5];
  cout << "������� N" << endl;
  for (int i = 0; i < 5; i++) { // ���� ����������� ������ �� ������ N
    cin >> Ns[i];
  }
  cout << " n"
       << "\t\tM(f)+C(f) Bubble\t\t\tM(f)+C(f) Shaker" << endl;
  cout << "\tDec\t";
  cout << "   Rand\t";
  cout << " \tInc\t"; //�������
  cout << "\tDec\t";
  cout << "   Rand\t";
  cout << " \tInc\t";

  for (int i = 0; i < 5; i++) { //���� ������������ ������ �������� N
    n = Ns[i];
    cout << " " << n; //�������� N � ������ ������
    int A[n];

    FillDec(A, n); //�� ����������� � �����������
    BubbleSort(A, n);
    ShakerSort(A, n);

    FillRand(A, n); //������
    BubbleSort(A, n);
    ShakerSort(A, n);

    FillInc(A, n); // �� ����������� � �����������
    BubbleSort(A, n);
    ShakerSort(A, n);

    cout << endl;
  }
  return 0;
}
