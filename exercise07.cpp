#include <iostream>
using namespace std;

class Television {
public:
	int channel;		//[1~50]
	int volume;			//[1~100]
	int inch;			//[10~70]

public:
	void Initialize() { //객체의 속성값들을 초기화하는데에 쓰임.
		channel = 10;
		volume = 20;
		inch = 30;
	}



	//Get:특정한 멤버의 값으로 반환하는 함수
	int GetChannel() { //갖고가니까 int형으로 반환.
		return channel;
	}

	//Set:특정한 멤버의 값으로 세팅하는 함수
	void SetChannel(int pChannel) { //특정한 값으로 세팅을 하라. 따라서 괄호안에 첨자를 넣어줘야 함.
		//받아서 돌아갈 것이 없으니 void형을 씀. (반환x)
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
	Television SStv; //Television이 새로운 자료형이 됨. 변수 3개를 받음 like 레코드 개념.

	SStv.SetChannel(-10);   //private으로 하면 접근 불가이므로 .을 멤버로 접근이 불가능.
	//멤버에 직접 접근하지 않으면 
	SStv.SetVolume(200);
	SStv.SetInch(30);

	//--------------------멤버 함수에 직접 접근하는 방식---------------------//
	//--------------------멤버 함수에 직접 접근하는 방식---------------------//

	//SStv.Initialize(); //멤버 함수로 초기화.


	cout << endl;
	cout << "SStv: " << endl;
	cout << "Channel: " << SStv.channel << endl;
	cout << "Volume: " << SStv.volume << endl;
	cout << "Inch: " << SStv.inch << endl;





	return 0;

}
