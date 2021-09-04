#include "pch.h"
#include "Bullet.h"

Bullet::Bullet() 
	:mDir(DIR_NONE){
}

Bullet::~Bullet() {
	Release();
}

void Bullet::Initialize() {
	mInfo.cX = 30;
	mInfo.cY = 30;

	mSpeed = 20.f;
}

void Bullet::Update() {
	switch (mDir) {
	case DIR_LEFT:
		mInfo.x -= mSpeed;
		break;
	case DIR_UP:
		mInfo.y -= mSpeed;
		break;
	case DIR_RIGHT:
		mInfo.x += mSpeed;
		break;
	case DIR_BOTTOM:
		mInfo.y += mSpeed;
		break;
	case DIR_NONE:
		break;
	default:
		break;
	}
	updateRect();
}

void Bullet::Render(HDC& hdc) {
	Ellipse(hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void Bullet::Release() {
}
