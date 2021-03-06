#pragma once

#include "WeaponInfo.h"

class CLaserBlaster : public CWeaponInfo
{
public:
	CLaserBlaster();
	virtual ~CLaserBlaster();

	// Initialised this instance to default values
	void Init(void);
	// Discharge this weapon
	void Discharge(Vector3 position, Vector3 target, CPlayerInfo *_source = NULL);
};