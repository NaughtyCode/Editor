#include "IrrRender.h"

#include <irrlicht.h>
#include <windows.h>
#include <iostream>

using namespace irr;

static IrrlichtDevice*            Device       = 0;
static scene::ISceneManager*      SceneManager = 0;
static video::IVideoDriver*       VideoDriver  = 0;
scene::ICameraSceneNode*          Camera       = 0;
static HWND                       Handle       = 0;
static video::SExposedVideoData   VideoData(0);
static scene::ITerrainSceneNode*  Terrain      = 0;

IRRRENDERAPI void CreateRender(int handle)
{
    Handle=(HWND)handle;
    irr::SIrrlichtCreationParameters param;
    param.DriverType = video::EDT_DIRECT3D9;
    param.WindowId = (void*)Handle;
    Device = irr::createDeviceEx(param);
    if (!Device) return;
    SceneManager = Device->getSceneManager();
    VideoDriver = Device->getVideoDriver();
    Camera = SceneManager->addCameraSceneNode();
    CreateTerrain();
}

IRRRENDERAPI bool RenderFrame(){
    if(IsWindow(Handle) && IsWindowVisible(Handle) && Device->run())
    {
        VideoDriver->beginScene(true,true,0,VideoData);
        SceneManager->drawAll();
        VideoDriver->endScene();
        return true;
    }else{
        return false;
    }
}

IRRRENDERAPI void DestroyRender(){
    if(Device!=0){
        Device->closeDevice();
        Device->drop();
    }
    Device=0;
    printf("Í£Ö¹äÖÈ¾\n");
}

IRRRENDERAPI void SetCamera(float x,float y,float z){
    if(Camera!=0){
        Camera->setTarget(core::vector3df(x,y,z));
    }
}

IRRRENDERAPI void CreateTerrain(){
    if(SceneManager!=0 && VideoDriver!=0){
        
	Terrain = SceneManager->addTerrainSceneNode(
		"Resource//Game//terrain-heightmap.bmp",
		0,					// parent node
		-1,					// node id
		core::vector3df(-2500.f,-600.f,2000.f),		// position
		core::vector3df(0.f, 15.f,0.f),		// rotation
		core::vector3df(30.f,8.0f,35.f),	// scale
		video::SColor ( 255, 255, 255, 255 ),	// vertexColor
		5,					// maxLOD
		scene::ETPS_17,				// patchSize
		4					// smoothFactor
		);
        
	Terrain->setMaterialFlag(video::EMF_LIGHTING, false);
	Terrain->setMaterialTexture(0,VideoDriver->getTexture("Resource//Game//terrain-texture.jpg"));
	Terrain->setMaterialTexture(1,VideoDriver->getTexture("Resource//Game//detailmap3.jpg"));
	Terrain->setMaterialType(video::EMT_DETAIL_MAP);
	Terrain->scaleTexture(1.0f, 20.0f);
        
	VideoDriver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);
        
	scene::ISceneNode* skybox=SceneManager->addSkyBoxSceneNode(
		VideoDriver->getTexture("Resource//Game//irrlicht2_up.jpg"),
		VideoDriver->getTexture("Resource//Game//irrlicht2_dn.jpg"),
		VideoDriver->getTexture("Resource//Game//irrlicht2_lf.jpg"),
		VideoDriver->getTexture("Resource//Game//irrlicht2_rt.jpg"),
		VideoDriver->getTexture("Resource//Game//irrlicht2_ft.jpg"),
		VideoDriver->getTexture("Resource//Game//irrlicht2_bk.jpg"));
	scene::ISceneNode* skydome = SceneManager->addSkyDomeSceneNode(VideoDriver->getTexture("Resource//Game//skydome.jpg"), 16, 8, 0.95f, 2.0f);

	VideoDriver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
    }
}