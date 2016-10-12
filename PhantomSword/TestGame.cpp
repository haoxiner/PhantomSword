#ifdef TESTGAME
#include "Display.h"
#include "Loader.h"
#include "MasterRenderer.h"
#include "StaticShader.h"
#include "Entity.h"
#include "Camera.h"
#include "PointLight.h"
#include "InputHandler.h"
#include "MoveCameraForward.h"
#include "Player.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <fstream>
#include <sstream>
#include <random>
#include <queue>

int WINAPI wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PWSTR pCmdLine,
	int nCmdShow)
{
	Display display;

	if (!display.Initialize())
	{
		return -1;
	}

	while (display.IsRunning())
	{
    float delta = display.GetDelta();
    for (auto entity : cubes)
    {
      renderer.ProcessEntity(*entity);
    }
    for (auto terrain : terrains)
    {
      renderer.ProcessTerrain(*terrain);
    }
    renderer.Prepare();
    renderer.Render(pointLight, camera);
		display.Update();
	}
	display.Destroy();
	return 0;
}
#endif