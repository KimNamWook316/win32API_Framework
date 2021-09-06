#pragma once
#include "Obj.h"
class Bullet : public Obj{
public:
	explicit Bullet();
	virtual ~Bullet();

	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC& hdc) override;
	virtual void Release() override;
	
	void SetDir(BULLET::DIRECTION dir);

private:
	BULLET::DIRECTION mDir;
};