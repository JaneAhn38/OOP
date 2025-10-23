#include <iostream>
using namespace std;

class CellPhone {
public:
	int camera; //ī�޶��� ȭ��		range[400 ~ 600]
	int battery; //���͸� �뷮		range[1,000 ~ 3,000]
	int storage; //���� �뷮		range[32 ~ 64]




	//Get Set �޼��� �ۼ��ϴ� ����: 
	// encapsulation(ĸ��ȭ) 
	// - ��� ������ ��ȣ�ϱ� ���� private���� �����ϰ�, 
	// public �޼��带 ���� �����ϵ��� ��.
	// ������ �̷��� �ϴ� ����: �׷��� ������� ���к��� ������ ���Ƽ� ���ȼ��� ����.
	//Ư¡: Get �޼���� ���� ��ȯ(int), Set �޼���� ���� ����(void).
	int GetCamera() {
		return camera;
	}

	void SetCamera(int pCamera) {
		if((pCamera >= 400) && (pCamera <= 600)) {
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





int main() {
	// CellPhone Ŭ������ ��ü ����. 
	// CellPhone �̶�� ���Ӱ� ������ �ڷ������� myPhone �̶�� ������ ����.
	CellPhone myPhone;

	myPhone.SetCamera(500);
	myPhone.SetBattery(4000);
	myPhone.SetStorage(64);

	cout << en








}