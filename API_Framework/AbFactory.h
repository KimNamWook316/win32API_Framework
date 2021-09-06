#pragma once

class Obj;
template<typename T>
class AbFactory {
public:
	static Obj* Create() {
		Obj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static Obj* Create(const float& _x, const float& _y) {
		Obj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_x, _y);
		
		return pObj;
	}
};