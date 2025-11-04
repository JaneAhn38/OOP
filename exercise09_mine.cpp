
#include <iostream>
using namespace std;

class CellPhone {
public:
	int camera; //카메라의 화소		range[400 ~ 600]
	int battery; //배터리 용량		range[1,000 ~ 3,000]
	int storage; //저장 용량		range[32 ~ 64]




	//Get Set 메서드 작성하는 이유: 
	// encapsulation(캡슐화) 
	// - 멤버 변수를 보호하기 위해 private으로 설정하고, 
	// public 메서드를 통해 접근하도록 함.
	// 귀찮게 이렇게 하는 이유: 그래야 사용자의 무분별한 접근을 막아서 보안성을 높임.
	//특징: Get 메서드는 값을 반환(int), Set 메서드는 값을 설정(void).
	int GetCamera() {
		return camera;
	}

	void SetCamera(int pCamera) {
		if ((pCamera >= 400) && (pCamera <= 600)) {
			camera = pCamera;
		}
		if (pCamera < 400) {
			camera = 400;
			cout << " CAMERA can't be changed to  " << pCamera << endl
				<< "because it's out of range." << endl;
			cout << "Therfore, CAMERA is now set to the minimum value 400." << endl;
		}
		if (pCamera > 600) {
			camera = 600;
			cout << " CAMERA can't be changed to  " << pCamera << endl
				<< "because it's out of range." << endl;
			cout << "Therfore, CAMERA is now set to the maximum value 600." << endl;
		}
	}

	int GetBattery() {
		return battery;
	}

	void SetBattery(int pBattery) {
		if ((pBattery >= 1000) && (pBattery <= 3000)) {
			battery = pBattery;
		}
		if (pBattery < 1000) {
			battery = 1000;
			cout << " BATTERY can't be changed to  " << pBattery << endl
				<< "because it's out of range." << endl;
			cout << "Therfore, BATTERY is now set to the minimum value 1000." << endl;
		}
		if (pBattery > 3000) {
			battery = 3000;
			cout << " BATTERY can't be changed to  " << pBattery << endl
				<< "because it's out of range." << endl;
			cout << "Therfore, BATTERY is now set to the maximum value 3000." << endl;
		}
	}

	int GetStorage() {
		return storage;
	}

	void SetStorage(int pStorage) {
		if ((pStorage >= 32) && (pStorage <= 64)) {
			storage = pStorage;
		}
		if (pStorage < 32) {
			storage = 32;
			cout << " STORAGE can't be changed to  " << pStorage << endl
				<< "because it's out of range." << endl;
			cout << "Therfore, STORAGE is now set to the minimum value 32." << endl;
		}
		if (pStorage > 64) {
			storage = 64;
			cout << " STORAGE can't be changed to  " << pStorage << endl
				<< "because it's out of range." << endl;
			cout << "Therfore, STORAGE is now set to the maximum value 64." << endl;
		}
	}



};

class SmartPhone : public CellPhone {
private:
	bool touchScreen;     // 터치스크린 유무 (true)
	bool faceRecognition; // 얼굴인식 유무	(true)

public:

	//매개변수 x 생성자
	SmartPhone() : CellPhone() {
		touchScreen = true;
		faceRecognition = true;
	}

	//매개변수 o 생성자 
	SmartPhone(int pCamera, int pBattery, int pStorage,
		bool pTouchScreen, bool pFaceRecognition) :
		CellPhone() {
		camera = pCamera;
		battery = pBattery;
		storage = pStorage;
		touchScreen = pTouchScreen;
		faceRecognition = pFaceRecognition;
	}

	//------------------------------------------------------------//
	//----- 두 가지 버전의 생성자를 만들었어도 정상 작동하는 이유------//
	// 함수 오버로딩 (function overloading)으로
	// 이름이 같은 함수(생성자)일지라도 배개변수가 다르면
	// 별개의 생성자로 간주되기 때문!!!!
	//------------------------------------------------------------//

	//소멸자
	~SmartPhone() {
	}



int main() {
	// CellPhone 클래스의 객체 생성. 
	// CellPhone 이라는 새롭게 생성된 자료형으로 myPhone 이라는 변수를 선언.
	CellPhone myPhone;

	myPhone.SetCamera(500);
	myPhone.SetBattery(4000);
	myPhone.SetStorage(64);

	cout << endl;
	cout << "myPhone: " << endl;
	cout << "Camera: " << myPhone.camera << endl;
	//Camera는 입력값이  범위 내의 integer이므로 입력값 그대로 출력.

	cout << "Battery: " << myPhone.battery << endl;
	//Battery의 입력값이 설정 범위 밖의 값이므로 초기값인 3000으로 출력 예정. 

	cout << "Storage: " << myPhone.storage << endl;
	//Storage는 입력값이 범위 내의 integer이므로 입력값 그대로 출력.


	return 0;


}

