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

	mSpeed = 5.f;
}

void Player::Update() {
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		mInfo.y -= mSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		mInfo.y += mSpeed;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		mInfo.x -= mSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		mInfo.x += mSpeed;
	}

	// W
	if (GetAsyncKeyState(0x57) & 0x8000) {
		mPBullet->emplace_back(createBullet(DIR_UP));
	}
	// A
	if (GetAsyncKeyState(0x41) & 0x8000) {
		mPBullet->emplace_back(createBullet(DIR_LEFT));
	}
	// S
	if (GetAsyncKeyState(0x53) & 0x8000) {
		mPBullet->emplace_back(createBullet(DIR_BOTTOM));
	}
	// D
	if (GetAsyncKeyState(0x44) & 0x8000) {
		mPBullet->emplace_back(createBullet(DIR_RIGHT));
	}

	updateRect();
}

void Player::Render(HDC& hdc) {
	Rectangle(hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void Player::Release() {
}

Obj* Player::createBullet(DIRECTION dir) {
	Obj* pObj = new Bullet;
	pObj->Initialize();
	pObj->SetPos(mInfo.x, mInfo.y);
	static_cast<Bullet*>(pObj)->SetDir(dir);

	return pObj;
}
