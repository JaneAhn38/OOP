#include <iostream>
using namespace std;

class CellPhone {
public:
	int camera; //카메라의 화소		range[400 ~ 600]
	int battery; //배터리 용량		range[1,000 ~ 3,000]
	int storage; //저장 용량		range[32 ~ 64]



	int GetCamera() {
		return camera;
	}

	void SetCamera(int pCamera) {
		if((pCamera >= 400) && (pCamera <= 600)) {
			camera = pCamera;
		}
		if (pCamera < 400) {
			camera = 400;
			cout << " CAMERA can't be changed to  " << pCamera << endl;
		}
	}

};





int main() {
	CellPhone myPhone;








}