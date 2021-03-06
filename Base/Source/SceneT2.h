#ifndef SCENE_T2_H
#define SCENE_T2_H

#include "Scene.h"
#include "Mtx44.h"
#include "PlayerInfo/PlayerInfo.h"
#include "GroundEntity.h"
#include "FPSCamera.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "GenericEntity.h"
#include "Enemy.h"

class ShaderProgram;
class SceneManager;
class TextEntity;
class Light;
class SceneT2 : public Scene
{
public:
	SceneT2();
	~SceneT2();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

private:
	//SceneText(SceneManager* _sceneMgr); // This is used to register to SceneManager
	//SkyBoxEntity* theSkyBox;
	ShaderProgram* currProg;
	CPlayerInfo* playerInfo;
	GroundEntity* groundEntity;
	FPSCamera camera;
	TextEntity* textObj[3];
	Light* lights[2];

	GenericEntity* theCube;
	//CEnemy *theEnemy;

	float countDown;
	//static SceneText* sInstance; // The pointer to the object that gets registered
};

#endif