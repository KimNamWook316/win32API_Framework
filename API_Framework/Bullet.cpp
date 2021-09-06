#include "pch.h"
#include "Bullet.h"

Bullet::Bullet() 
	: mDir(BULLET::END){
}

Bullet::~Bullet() {
	Release();
}

void Bullet::Initialize() {
	mInfo.cX = 30;
	mInfo.cY = 30;

	mSpeed = 20.f;
}

int Bullet::Update() {
	if (mbDead) {
		return OBJ_DEAD;
	}

	switch (mDir) {
	case BULLET::LEFT:
		mInfo.x -= mSpeed;
		break;
	case BULLET::UP:
		mInfo.y -= mSpeed;
		break;
	case BULLET::RIGHT:
		mInfo.x += mSpeed;
		break;
	case BULLET::DOWN:
		mInfo.y += mSpeed;
		break;
	default:
		break;
	}
	updateRect();

	return OBJ_NOEVENT;
}

void Bullet::LateUpdate() {
	if (100 >= mRect.left
		|| WINCX - 100 <= mRect.right
		|| 100 >= mRect.top
		|| WINCY - 100 <= mRect.bottom) {
		mbDead = true;
	}
}

void Bullet::Render(HDC& hdc) {
	Ellipse(hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void Bullet::Release() {
}

void Bullet::SetDir(BULLET::DIRECTION dir) { mDir = dir; }
