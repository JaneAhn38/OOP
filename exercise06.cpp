#include <iostream>
#include <cmath>

using namespace std;

class Student {
public:
    int scores[4];  // 학생의 각 과목 성적
    double average;  // 학생의 평균
    double variance;  // 학생의 분산

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
            varSum += (scores[i] - average) * (scores[i] - average);  // 분산 계산
        }
        variance = varSum / 4.0;  // 데이터 개수로 나누어 분산 계산
    }
};

int main() {
    Student students[3];  // 3명의 학생
    string subjects[4] = { "국어", "영어", "수학", "물리" };  // 과목 목록

    // 성적 입력 받기
    for (int i = 0; i < 3; i++) {
        cout << "학생 " << i + 1 << " 성적 입력 (국어, 영어, 수학, 물리): \n";
        for (int j = 0; j < 4; j++) {
            cin >> students[i].scores[j];
        }

        // 평균과 분산 계산
        students[i].calculateAverage();
        students[i].calculateVariance();
    }

    // 과목별 평균과 분산 계산
    double subjectAverages[4] = { 0 };  // 각 과목의 평균
    double subjectVariances[4] = { 0 };  // 각 과목의 분산

    for (int j = 0; j < 4; j++) {  // 각 과목에 대해
        int subjectSum = 0;
        for (int i = 0; i < 3; i++) {
            subjectSum += students[i].scores[j];
        }
        subjectAverages[j] = subjectSum / 3.0;

        double subjectVarSum = 0;
        for (int i = 0; i < 3; i++) {
            subjectVarSum += (students[i].scores[j] - subjectAverages[j]) * (students[i].scores[j] - subjectAverages[j]);  // 분산 계산
        }
        subjectVariances[j] = subjectVarSum / 3.0;  // 데이터 개수로 나눠서 분산 계산
    }

    // 표 형태로 출력
    cout << "\n";
    cout << "국어\t영어\t수학\t물리\t평균\t분산\n";
    cout << "---------------------------------------------------------------\n";

    // 학생별 성적 출력
    for (int i = 0; i < 3; i++) {
        cout << "학생" << i + 1 << "   ";  // 학생 번호 출력
        for (int j = 0; j < 4; j++) {
            //cout << "\t";
            cout << students[i].scores[j] << "     ";  // 각 과목 성적 출력
        }
        cout << (int)(students[i].average * 100) / 100.0 << "     ";  // 평균 출력 
        cout << (int)(students[i].variance * 100) / 100.0 << endl;  // 분산 출력 
    }

    // 과목별 평균과 분산 출력
    cout << "\n";
    cout << "평균\t";
    for (int j = 0; j < 4; j++) {
        cout << (int)(subjectAverages[j] * 100) / 100.0 << "     ";  //
    }
    cout << endl;

    cout << "분산\t";
    for (int j = 0; j < 4; j++) {
        cout << (int)(subjectVariances[j] * 100) / 100.0 << "     ";  
    }
    cout << endl;

    return 0;
}
