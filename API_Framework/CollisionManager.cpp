#include "pch.h"
#include "CollisionManager.h"
#include "Obj.h";

CollisionManager::CollisionManager() {
}

CollisionManager::~CollisionManager() {
}

void CollisionManager::CollisionRect(const std::list<Obj*>& dest, const std::list<Obj*>& src) {
	RECT rc = {};
	for (auto& pDest : dest) {
		for (auto& pSrc : src) {
			if (IntersectRect(&rc, &(pDest->GetRect()), &(pSrc->GetRect()))) {
				pDest->Die();
				pSrc->Die();
			}
		}
	}
}

void CollisionManager::CollisionSphere(const std::list<Obj*>& dest, const std::list<Obj*>& src) {
	for (auto& pDest : dest) {
		for (auto& pSrc : src) {
			if (checkSphere(pDest, pSrc)) {
				pDest->Die();
				pSrc->Die();
			}
		}
	}
}

bool CollisionManager::checkSphere(const Obj* pDst, const Obj* pSrc) {
	float disX = pDst->GetInfo().x - pSrc->GetInfo().x;
	float disY = pDst->GetInfo().y- pSrc->GetInfo().y;
	float dia = sqrtf(disX * disX + disY * disY);
	float rad =	(float)((pSrc->GetInfo().cX + pSrc->GetInfo().cX) >> 1);

	return dia <= rad;
}
