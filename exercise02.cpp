#include <iostream>
using namespace std;

// ����ڿ��� 10���� �������� �Է¹޾Ƽ� ¦���� Ȧ���� �հ� ���� �׸��� ����� ���� ����ϴ� ���α׷�
int main() {
    int num;
    int evenSum = 0, oddSum = 0;
    int evenCount = 0, oddCount = 0;
    double evenAvg = 0, oddAvg = 0;

    cout << "���� 10���� �Է��ϼ���: " << endl;

    for (int i = 0; i < 10; i++) {
        cin >> num;

        if (num % 2 == 0) { // ¦��
            evenSum += num;
            evenCount++;
        }
        else { // Ȧ��
            oddSum += num;
            oddCount++;
        }
    }

    // ¦�� ���
    if (evenCount != 0) {
        evenAvg = (double)evenSum / evenCount;
        cout << "¦���� ���: " << evenAvg << endl;
    }
    else {
        cout << "¦���� ���: ���� �� �����ϴ�." << endl;
    }

    // Ȧ�� ���
    if (oddCount != 0) {
        oddAvg = (double)oddSum / oddCount;
        cout << "Ȧ���� ���: " << oddAvg << endl;
    }
    else {
        cout << "Ȧ���� ���: ���� �� �����ϴ�." << endl;
    }

    cout << "¦���� ��: " << evenSum << endl;
    cout << "Ȧ���� ��: " << oddSum << endl;
    cout << "¦���� ����: " << evenCount << endl;
    cout << "Ȧ���� ����: " << oddCount << endl;

    return 0;
}
