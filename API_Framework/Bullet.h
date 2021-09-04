#pragma once
#include "Obj.h"
class Bullet : public Obj{
public:
	explicit Bullet();
	virtual ~Bullet();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC& hdc) override;
	virtual void Release() override;

	void SetDir(DIRECTION dir) { mDir = dir; }

private:
	DIRECTION mDir;
};