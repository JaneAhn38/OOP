#include <iostream>
#include <cmath>

using namespace std;

class Student {
public:
    int scores[4];  // �л��� �� ���� ����
    double average;  // �л��� ���
    double variance;  // �л��� �л�

    void calculateAverage() {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += scores[i];
        }
        average = sum / 4.0;
    }

    void calculateVariance() {
        double varSum = 0;
        for (int i = 0; i < 4; i++) {
            varSum += (scores[i] - average) * (scores[i] - average);  // �л� ���
        }
        variance = varSum / 4.0;  // ������ ������ ������ �л� ���
    }
};

int main() {
    Student students[3];  // 3���� �л�
    string subjects[4] = { "����", "����", "����", "����" };  // ���� ���

    // ���� �Է� �ޱ�
    for (int i = 0; i < 3; i++) {
        cout << "�л� " << i + 1 << " ���� �Է� (����, ����, ����, ����): \n";
        for (int j = 0; j < 4; j++) {
            cin >> students[i].scores[j];
        }

        // ��հ� �л� ���
        students[i].calculateAverage();
        students[i].calculateVariance();
    }

    // ���� ��հ� �л� ���
    double subjectAverages[4] = { 0 };  // �� ������ ���
    double subjectVariances[4] = { 0 };  // �� ������ �л�

    for (int j = 0; j < 4; j++) {  // �� ���� ����
        int subjectSum = 0;
        for (int i = 0; i < 3; i++) {
            subjectSum += students[i].scores[j];
        }
        subjectAverages[j] = subjectSum / 3.0;

        double subjectVarSum = 0;
        for (int i = 0; i < 3; i++) {
            subjectVarSum += (students[i].scores[j] - subjectAverages[j]) * (students[i].scores[j] - subjectAverages[j]);  // �л� ���
        }
        subjectVariances[j] = subjectVarSum / 3.0;  // ������ ������ ������ �л� ���
    }

    // ǥ ���·� ���
    cout << "\n";
    cout << "����\t����\t����\t����\t���\t�л�\n";
    cout << "---------------------------------------------------------------\n";

    // �л��� ���� ���
    for (int i = 0; i < 3; i++) {
        cout << "�л�" << i + 1 << "   ";  // �л� ��ȣ ���
        for (int j = 0; j < 4; j++) {
            //cout << "\t";
            cout << students[i].scores[j] << "     ";  // �� ���� ���� ���
        }
        cout << (int)(students[i].average * 100) / 100.0 << "     ";  // ��� ��� 
        cout << (int)(students[i].variance * 100) / 100.0 << endl;  // �л� ��� 
    }

    // ���� ��հ� �л� ���
    cout << "\n";
    cout << "���\t";
    for (int j = 0; j < 4; j++) {
        cout << (int)(subjectAverages[j] * 100) / 100.0 << "     ";  //
    }
    cout << endl;

    cout << "�л�\t";
    for (int j = 0; j < 4; j++) {
        cout << (int)(subjectVariances[j] * 100) / 100.0 << "     ";  
    }
    cout << endl;

    return 0;
}
