#include <iostream>
using namespace std;

#include "EndSceneState.h"
#include "GL\glew.h"
#include "Application.h"
#include "LoadTGA.h"
#include "GraphicsManager.h"
#include "MeshBuilder.h"
#include "TextEntity.h"
#include "RenderHelper.h"
#include "SpriteEntity.h"
#include "EntityManager.h"

#include "KeyboardController.h"
#include "SceneManager.h"



CEndSceneState::CEndSceneState()
{
}

CEndSceneState::~CEndSceneState()
{
}

void CEndSceneState::Init()
{
	//Create and attach the camera to the scene
	camera.Init(Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));
	GraphicsManager::GetInstance()->AttachCamera(&camera);

	//Load all the meshes
	MeshBuilder::GetInstance()->GenerateQuad("ENDSTATE_BKGROUND", Color(1, 1, 1), 1.f);
	MeshBuilder::GetInstance()->GetMesh("ENDSTATE_BKGROUND")->textureID = LoadTGA("Image//EndScene.tga");
	float halfWindowWidth = Application::GetInstance().GetWindowWidth() / 2.0f;
	float halfWindowHeight = Application::GetInstance().GetWindowHeight() / 2.0f;
	EndStateBackground = Create::Sprite2DObject("ENDSTATE_BKGROUND",
		Vector3(halfWindowWidth, halfWindowHeight, 0.0f),
		Vector3(800.0f, 600.0f, 0.0f));
	cout << "CEndSceneState loaded\n" << endl;
	timer_nextscene = 5;
}

void CEndSceneState::Update(double dt)
{
	timer_nextscene -= dt;
	if (timer_nextscene <= 0)
	{
		cout << "Loading MenuState" << endl;
		SceneManager::GetInstance()->SetActiveScene("MenuState");
	}
	/*if (KeyboardController::GetInstance()->IsKeyReleased(VK_SPACE))
	{
	cout << "Loading MenuState" << endl;
	SceneManager::GetInstance()->SetActiveScene("MenuState");
	}*/
}

void CEndSceneState::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//GraphicsManager::GetInstance()->UpdateLightUniforms();

	// Setup 3D pipeline then render 3D
	GraphicsManager::GetInstance()->SetPerspectiveProjection(45.0f, 4.0f / 3.0f, 0.1f, 10000.0f);
	GraphicsManager::GetInstance()->AttachCamera(&camera);

	//Render the required entities
	EntityManager::GetInstance()->Render();

	// Setup 2D pipeline then render 2D
	GraphicsManager::GetInstance()->SetOrthographicProjection(0,
		Application::GetInstance().GetWindowWidth(),
		0,
		Application::GetInstance().GetWindowHeight(),
		-10, 10);
	GraphicsManager::GetInstance()->DetachCamera();

	//Render the rquired entities
	EntityManager::GetInstance()->RenderUI();
}


void CEndSceneState::Exit()
{
	//Remove the entity from EntityManager
	EntityManager::GetInstance()->RemoveEntity(EndStateBackground);

	//Remove the meshes which are specific to IntroState
	MeshBuilder::GetInstance()->RemoveMesh("ENDSTATE_BKGROUND");

	//Detach camera from other entities
	GraphicsManager::GetInstance()->DetachCamera();
}