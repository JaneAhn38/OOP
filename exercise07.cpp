#include <iostream>
using namespace std;

class Television {
public:
	int channel;		//[1~50]
	int volume;			//[1~100]
	int inch;			//[10~70]

public:
	void Initialize() { //��ü�� �Ӽ������� �ʱ�ȭ�ϴµ��� ����.
		channel = 10;
		volume = 20;
		inch = 30;
	}



	//Get:Ư���� ����� ������ ��ȯ�ϴ� �Լ�
	int GetChannel() { //�����ϱ� int������ ��ȯ.
		return channel;
	}

	//Set:Ư���� ����� ������ �����ϴ� �Լ�
	void SetChannel(int pChannel) { //Ư���� ������ ������ �϶�. ���� ��ȣ�ȿ� ÷�ڸ� �־���� ��.
		//�޾Ƽ� ���ư� ���� ������ void���� ��. (��ȯx)
		//channel = pChannel;

		if ((pChannel >= 1) && (pChannel <= 50)) {
			channel = pChannel;
		}

		if (pChannel < 1) {
			channel = 1;
			cout << "CHANNEL can't be changed to  " << pChannel << endl
				<< "because it's out of range." << endl;
			cout << "Therfore, CHANNEL is now set to the minimum value 1." << endl;
		}

		if (pChannel > 50) {
			channel = 50;
			cout << "CHANNEL can't be changed to  " << pChannel << endl
				<< "because it's out of range." << endl;
			cout << "Therfore, CHANNEL is now set to the maximum value 50." << endl;
		}

	}

	int GetVolume() {
		return volume;
	}

	void SetVolume(int pVolume) {
		if ((pVolume >= 1) && (pVolume <= 100)) {
			volume = pVolume;
		}

		if (pVolume < 1) {
			volume = 1;
			cout << "VOLUME can't be changed to  " << pVolume << endl
				<< "because it's out of range."  << endl;
			cout << "Therfore, VOLUME is now set to the minimum value 1." << endl;
		}

		if (pVolume > 50) {
			volume = 50;
			cout << "VOLUME cannot be changed to  " << pVolume << endl;
			cout << "Therfore, VOLUME is now set to the maximum value 50." << endl;
		}
	}




	int GetInch() {
		return inch;
	}
	void SetInch(int pInch) {
		if ((pInch >= 10) && (pInch <= 70)) {
			inch = pInch;
		}

		if (pInch < 10) {
			inch = 10;
			cout << "INCH can't be changed to  " << pInch << endl;
			cout << "because it's out of range." << endl ;
			cout << "Therfore, INCH is now set to the minimum value 1." << endl;
		}

		if (pInch > 70) {
			inch = 70;
			cout << "INCH can't be changed to  " << pInch << endl
				<< "because it's out of range." << endl ;
			cout << "Therfore, INCH is now set to the maximum value 70." << endl;
		}
	}
};






int main() {
	Television SStv; //Television�� ���ο� �ڷ����� ��. ���� 3���� ���� like ���ڵ� ����.

	SStv.SetChannel(-10);   //private���� �ϸ� ���� �Ұ��̹Ƿ� .�� ����� ������ �Ұ���.
	//����� ���� �������� ������ 
	SStv.SetVolume(200);
	SStv.SetInch(30);

	//--------------------��� �Լ��� ���� �����ϴ� ���---------------------//
	//--------------------��� �Լ��� ���� �����ϴ� ���---------------------//

	//SStv.Initialize(); //��� �Լ��� �ʱ�ȭ.


	cout << endl;
	cout << "SStv: " << endl;
	cout << "Channel: " << SStv.channel << endl;
	cout << "Volume: " << SStv.volume << endl;
	cout << "Inch: " << SStv.inch << endl;





	return 0;

}
