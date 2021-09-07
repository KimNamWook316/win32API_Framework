#include "pch.h"
#include "Obj.h"
#include "Player.h"
#include "Bullet.h"

Player::Player() {
}

Player::~Player() {
	Release();
}

void Player::Initialize() {
	mInfo.x = 400.f;
	mInfo.y = 300.f;
	mInfo.cX = 100;
	mInfo.cY = 100;

	POINT pt = {};
	pt.x = mInfo.x + 100;
	pt.y = mInfo.y;
	mFirePoint = pt;

	mAngle = atan2f(pt.y - mInfo.y, pt.x - mInfo.x) * 3.141592f / 180;

	mSpeed = 5.f;
}

int Player::Update() {
	if (mbDead) {
		return OBJ_DEAD;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		//if (GetAsyncKeyState(VK_UP) & 0x8000) {
		//	mInfo.x -= mSpeed / sqrtf(2.f);
		//	mInfo.y -= mSpeed / sqrtf(2.f);
		//} else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		//	mInfo.x -= mSpeed / sqrtf(2.f);
		//	mInfo.y += mSpeed / sqrtf(2.f);
		//} else {
		//	mInfo.x -= mSpeed;
		//}
		mAngle += 3.141592f / 180;
		mFirePoint.x = 100.f * cosf(mAngle);
		mFirePoint.y = 100.f * sinf(mAngle);
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		//if (GetAsyncKeyState(VK_UP) & 0x8000) {
		//	mInfo.x += mSpeed / sqrtf(2.f);
		//	mInfo.y -= mSpeed / sqrtf(2.f);
		//} else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		//	mInfo.x += mSpeed / sqrtf(2.f);
		//	mInfo.y += mSpeed / sqrtf(2.f);
		//} else {
		//	mInfo.x += mSpeed;
		//}
		mAngle += atan2f(mInfo.y - mFirePoint.y, mInfo.x - mFirePoint.x);
		mFirePoint.x = 100.f * cosf(mAngle);
		mFirePoint.y = 100.f * sinf(mAngle);
	}
	else if (GetAsyncKeyState(VK_UP) & 0x8000) {
		mInfo.y -= mSpeed;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		mInfo.y += mSpeed;
	}

	// W
	if (GetAsyncKeyState('W') & 0x8000) {
		mPBullet->emplace_back(createBullet(BULLET::UP));
	}
	// A
	if (GetAsyncKeyState('A') & 0x8000) {
		mPBullet->emplace_back(createBullet(BULLET::LEFT));
	}
	// S
	if (GetAsyncKeyState('S') & 0x8000) {
		mPBullet->emplace_back(createBullet(BULLET::DOWN));
	}
	// D
	if (GetAsyncKeyState('D') & 0x8000) {
		mPBullet->emplace_back(createBullet(BULLET::RIGHT));
	}

	updateRect();

	return OBJ_NOEVENT;
}

void Player::LateUpdate() {
}

void Player::Render(HDC& hdc) {
	Rectangle(hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
	MoveToEx(hdc, mInfo.x, mInfo.y, nullptr);
	LineTo(hdc, mFirePoint.x, mFirePoint.y);
}

void Player::Release() {
}

Obj* Player::createBullet(BULLET::DIRECTION dir) {
	Obj* pObj = AbFactory<Bullet>::Create(mInfo.x, mInfo.y);
	static_cast<Bullet*>(pObj)->SetDir(dir);

	return pObj;
}
