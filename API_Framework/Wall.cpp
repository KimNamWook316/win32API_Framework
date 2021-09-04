#include "pch.h"
#include "Wall.h"

Wall::Wall() 
	:mPBullet(nullptr) {
}

Wall::~Wall() {
	Release();
}

void Wall::Initialize() {
	mInfo.x = WINCX >> 1;
	mInfo.y = WINCY >> 1;
	mInfo.cX = (WINCX / 4) * 3;
	mInfo.cY = (WINCY / 3) * 2;
}

void Wall::Update() {
	checkBulletCollide();
	updateRect();
}

void Wall::Render(HDC& hdc) {
	Rectangle(hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void Wall::Release() {
}

void Wall::checkBulletCollide() {
	std::list<Obj*>::iterator iter = mPBullet->begin();

	while (iter != mPBullet->end()) {
		// 가로 충돌
		if ((*iter)->GetInfo().x < mRect.left || (*iter)->GetInfo().x > mRect.right) {
			Obj* bullet = *iter;
			iter = mPBullet->erase(iter);
			SAFE_DELETE(bullet);
		}
		// 세로 충돌
		else if ((*iter)->GetInfo().y < mRect.top || (*iter)->GetInfo().y > mRect.bottom) {
			Obj* bullet = *iter;
			iter = mPBullet->erase(iter);
			SAFE_DELETE(bullet);
		} else {
			++iter;
		}
	}
}
