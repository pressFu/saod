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
  cout << "              " << SMC;
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

main() {
  setlocale(LC_ALL, "Rus");
  srand(time(0));
  int n, Mt, Ct, SumMC, SMC;
  int Ns[5];
  cout << "������� N" << endl;
  for (int i = 0; i < 5; i++) { // ���� ����������� ������ �� ������ N
    cin >> Ns[i];
  }
  cout << "   n\t"
       << "M + C (teor)\t          "
       << "\tM(f)+C(f)" << endl; //�������
  cout << "\t"
       << "\t\t\tDEC\t\tRand\t\tInc" << endl; //�������
  for (int i = 0; i < 5; i++) { //���� ������������ ������ �������� N
    n = Ns[i];
    cout << " " << n; //�������� N � ������ ������
    Mt = 3 * ((pow(n, 2) - n) / 4);
    Ct = (pow(n, 2) - n) / 2;
    SumMC = Mt + Ct; //����� ������������� �������� � � �
    cout << "     " << SumMC;
    int A[n];
    FillDec(A, n); //�� ����������� � �����������
    BubbleSort(A, n);
    FillRand(A, n); //������
    BubbleSort(A, n);
    FillInc(A, n); // �� ����������� � �����������
    BubbleSort(A, n);
    cout << endl;
  }
  return 0;
}
