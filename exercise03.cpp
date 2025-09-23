/*#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int positiveNumbers[15];  // 양수 배열
    int negativeNumbers[15];  // 음수 배열
    int positiveCount = 0, negativeCount = 0;
    float posSum = 0, negSum = 0;
    float posAvg = 0, negAvg = 0;

    // 사용자로부터 15개의 정수 입력 받기
    cout << "15개의 정수를 입력하세요:" << endl;
    for (int i = 0; i < 15; i++) {
        int num;
        cin >> num;

        if (num > 0) {
            positiveNumbers[positiveCount++] = num;  // 양수일 경우 양수 배열에 저장
            posSum += num;  // 양수의 합 계산
        }
        else if (num < 0) {
            negativeNumbers[negativeCount++] = num;  // 음수일 경우 음수 배열에 저장
            negSum += num;  // 음수의 합 계산
        }
    }

    // 양수와 음수의 평균 계산
    if (positiveCount > 0) {
        posAvg = posSum / positiveCount;
    }
    if (negativeCount > 0) {
        negAvg = negSum / negativeCount;
    }

    // 양수들의 분산 계산
    float posVariance = 0;
    if (positiveCount > 0) {
        for (int i = 0; i < positiveCount; i++) {
            posVariance += pow(positiveNumbers[i] - posAvg, 2);
        }
        posVariance /= positiveCount;  // 양수들의 분산
    }

    // 음수들의 분산 계산
    float negVariance = 0;
    if (negativeCount > 0) {
        for (int i = 0; i < negativeCount; i++) {
            negVariance += pow(negativeNumbers[i] - negAvg, 2);
        }
        negVariance /= negativeCount;  // 음수들의 분산
    }

    // 결과 출력
    if (positiveCount > 0) {
        cout << "양수들의 분산: " << posVariance << endl;
    }
    else {
        cout << "양수들이 없습니다." << endl;
    }

    if (negativeCount > 0) {
        cout << "음수들의 분산: " << negVariance << endl;
    }
    else {
        cout << "음수들이 없습니다." << endl;
    }

    return 0;
}
*/