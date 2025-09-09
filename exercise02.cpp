#include <iostream>
using namespace std;

// 사용자에게 10개의 정수들을 입력받아서 짝수와 홀수의 합과 개수 그리고 평균을 각각 출력하는 프로그램
int main() {
    int num;
    int evenSum = 0, oddSum = 0;
    int evenCount = 0, oddCount = 0;
    double evenAvg = 0, oddAvg = 0;

    cout << "정수 10개를 입력하세요: " << endl;

    for (int i = 0; i < 10; i++) {
        cin >> num;

        if (num % 2 == 0) { // 짝수
            evenSum += num;
            evenCount++;
        }
        else { // 홀수
            oddSum += num;
            oddCount++;
        }
    }

    // 짝수 평균
    if (evenCount != 0) {
        evenAvg = (double)evenSum / evenCount;
        cout << "짝수의 평균: " << evenAvg << endl;
    }
    else {
        cout << "짝수의 평균: 구할 수 없습니다." << endl;
    }

    // 홀수 평균
    if (oddCount != 0) {
        oddAvg = (double)oddSum / oddCount;
        cout << "홀수의 평균: " << oddAvg << endl;
    }
    else {
        cout << "홀수의 평균: 구할 수 없습니다." << endl;
    }

    cout << "짝수의 합: " << evenSum << endl;
    cout << "홀수의 합: " << oddSum << endl;
    cout << "짝수의 개수: " << evenCount << endl;
    cout << "홀수의 개수: " << oddCount << endl;

    return 0;
}
