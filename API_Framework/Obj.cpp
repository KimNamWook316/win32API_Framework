#include "pch.h"
#include "Obj.h"

Obj::Obj() 
	:mSpeed(0.f) 
	,mbDead(false){
	ZeroMemory(&mInfo, sizeof(mInfo));
	ZeroMemory(&mInfo, sizeof(mRect));
}

Obj::~Obj() {
}

void Obj::updateRect() {
	mRect.left = mInfo.x - (mInfo.cX >> 1);
	mRect.top = mInfo.y - (mInfo.cY >> 1);
	mRect.right = mInfo.x + (mInfo.cX >> 1);
	mRect.bottom = mInfo.y + (mInfo.cY >> 1);
}