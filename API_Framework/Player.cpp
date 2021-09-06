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

int Player::Update() {
	if (mbDead) {
		return OBJ_DEAD;
	}

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
}

void Player::Release() {
}

Obj* Player::createBullet(BULLET::DIRECTION dir) {
	Obj* pObj = AbFactory<Bullet>::Create(mInfo.x, mInfo.y);
	static_cast<Bullet*>(pObj)->SetDir(dir);

	return pObj;
}
