/*#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int positiveNumbers[15];  // ��� �迭
    int negativeNumbers[15];  // ���� �迭
    int positiveCount = 0, negativeCount = 0;
    float posSum = 0, negSum = 0;
    float posAvg = 0, negAvg = 0;

    // ����ڷκ��� 15���� ���� �Է� �ޱ�
    cout << "15���� ������ �Է��ϼ���:" << endl;
    for (int i = 0; i < 15; i++) {
        int num;
        cin >> num;

        if (num > 0) {
            positiveNumbers[positiveCount++] = num;  // ����� ��� ��� �迭�� ����
            posSum += num;  // ����� �� ���
        }
        else if (num < 0) {
            negativeNumbers[negativeCount++] = num;  // ������ ��� ���� �迭�� ����
            negSum += num;  // ������ �� ���
        }
    }

    // ����� ������ ��� ���
    if (positiveCount > 0) {
        posAvg = posSum / positiveCount;
    }
    if (negativeCount > 0) {
        negAvg = negSum / negativeCount;
    }

    // ������� �л� ���
    float posVariance = 0;
    if (positiveCount > 0) {
        for (int i = 0; i < positiveCount; i++) {
            posVariance += pow(positiveNumbers[i] - posAvg, 2);
        }
        posVariance /= positiveCount;  // ������� �л�
    }

    // �������� �л� ���
    float negVariance = 0;
    if (negativeCount > 0) {
        for (int i = 0; i < negativeCount; i++) {
            negVariance += pow(negativeNumbers[i] - negAvg, 2);
        }
        negVariance /= negativeCount;  // �������� �л�
    }

    // ��� ���
    if (positiveCount > 0) {
        cout << "������� �л�: " << posVariance << endl;
    }
    else {
        cout << "������� �����ϴ�." << endl;
    }

    if (negativeCount > 0) {
        cout << "�������� �л�: " << negVariance << endl;
    }
    else {
        cout << "�������� �����ϴ�." << endl;
    }

    return 0;
}
*/