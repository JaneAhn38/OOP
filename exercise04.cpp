#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int s[3][4]; // 3�� �� 4���� ����

    // �Է�
    for (int i = 0; i < 3; ++i) {
        cout << "�л�" << i + 1 << " ���� ������ ������� �Է����ּ���(���� ���� ���� ����): \n";
        for (int j = 0; j < 4; ++j) cin >> s[i][j];
        cout << "\n";
        
    }
   

    // �л��� ���
    int maxStu[3], minStu[3], sumStu[3];
    double avgStu[3], var1Stu[3];

    for (int i = 0; i < 3; i++) {
        maxStu[i] = minStu[i] = s[i][0];
        sumStu[i] = 0;
        for (int j = 0; j < 4; j++) {
            sumStu[i] += s[i][j];
            if (s[i][j] > maxStu[i]) maxStu[i] = s[i][j];
            if (s[i][j] < minStu[i]) minStu[i] = s[i][j];
        }
        avgStu[i] = sumStu[i] / 4.0;

        double acc = 0.0;
        for (int j = 0; j < 4; j++) {
            double d = s[i][j] - avgStu[i];
            acc += d * d;
        }
        var1Stu[i] = acc / 4.0;
    }

    // ���� ���
    int maxSub[4], minSub[4], sumSub[4];
    double avgSub[4], var2Sub[4];

    for (int j = 0; j < 4; j++) {
        maxSub[j] = minSub[j] = s[0][j];
        sumSub[j] = 0;
        double sumSq = 0.0;
        for (int i = 0; i < 3; i++) {
            sumSub[j] += s[i][j];
            if (s[i][j] > maxSub[j]) maxSub[j] = s[i][j];
            if (s[i][j] < minSub[j]) minSub[j] = s[i][j];
            sumSq += s[i][j] * s[i][j];
        }
        avgSub[j] = sumSub[j] / 3.0;
        var2Sub[j] = (sumSq / 3.0) - (avgSub[j] * avgSub[j]);
    }

    // ���
    cout << "\n\t����\t����\t����\t����\t�ִ�\t�ּ�\t��\t���\t�л�1\n";

    for (int i = 0; i < 3; i++) {
        cout << "�л�" << i + 1 << "\t"
            << s[i][0] << "\t" << s[i][1] << "\t" << s[i][2] << "\t" << s[i][3] << "\t"
            << maxStu[i] << "\t" << minStu[i] << "\t" << sumStu[i] << "\t"
            << avgStu[i] << "\t" << var1Stu[i] << "\n";
    }

    cout << "�ִ�\t" << maxSub[0] << "\t" << maxSub[1] << "\t" << maxSub[2] << "\t" << maxSub[3] << "\n";
    cout << "�ּ�\t" << minSub[0] << "\t" << minSub[1] << "\t" << minSub[2] << "\t" << minSub[3] << "\n";
    cout << "��\t" << sumSub[0] << "\t" << sumSub[1] << "\t" << sumSub[2] << "\t" << sumSub[3] << "\n";
    cout << "���\t" << avgSub[0] << "\t" << avgSub[1] << "\t" << avgSub[2] << "\t" << avgSub[3] << "\n";
	cout << "�л�2\t" << var2Sub[0] << "\t" << var2Sub[1] << "\t" << var2Sub[2] << "\t" << var2Sub[3] << "\n";
}
