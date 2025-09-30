#include <iostream>
#include <cmath>
using namespace std;

// -----------------------------------------------------
// 10개의 정수를 입력받아
// 1) 양수들의 합/평균/분산1(편차제곱의 평균) 계산
// 2) 음수들의 합/평균/분산2(E[X^2] - (E[X])^2) 계산
// main에서 입출력, 반드시 함수 활용
// -----------------------------------------------------

// 양수
void posFunc(int arr[], int size, int& PosSum, double& PosAvg, double& PosVar1) {
    PosSum = 0;
    
	// 평균
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            PosSum += arr[i];
            count++;
        }
    }
   
    if (count == 0) return;  // call by function name이라서 return이 필요함.

    PosAvg = static_cast<double>(PosSum) / count;

    // 분산1
    double acc = 0.0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            double diff = arr[i] - PosAvg;
            acc += diff * diff;
        }
    }
    PosVar1 = (double) acc / count;         
}


void negFunc(int arr[], int size, int& NegSum, double& NegAvg, double& NegVar2) {
    NegSum = 0;
 

    double sum = 0.0;     // 음수들의 합 (평균용)
    double sumSq = 0.0;  
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            NegSum += arr[i];
            sum += arr[i];
            sumSq += (double) (arr[i]) * arr[i];
            count++;
        }
    }

    if (count == 0) return;

    NegAvg = sum / count;                 
    double meanSq = sumSq / count;        

    // 분산2 (제평-평제)
    NegVar2 = meanSq - (NegAvg * NegAvg); 
}

int main() {
    const int N = 10;
    int arr[N];

    //입출력은 main에서 실행

    // 입력
    cout << "10개의 정수를 입력하세요:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 양수 
    int posSum; double posAvg, posVar1;
    posFunc(arr, N, posSum, posAvg, posVar1);

    // 음수 
    int negSum; double negAvg, negVar2;
    negFunc(arr, N, negSum, negAvg, negVar2);

    // 출력
    cout << "양수 합: " << posSum << "\n";
    cout << "양수 평균: " << posAvg << "\n";
    cout << "양수 분산1: " << posVar1 << "\n\n";



    cout << "음수 합: " << negSum << "\n";
    cout << "음수 평균: " << negAvg << "\n";
    cout << "음수 분산2: " << negVar2 << "\n";

    return 0;
}
