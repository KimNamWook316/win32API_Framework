#pragma once
#include "Obj.h"
class Mouse : public Obj {
public:
	Mouse();
	~Mouse();

	// Inherited via Obj
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC& hdc) override;
	virtual void Release() override;

};

