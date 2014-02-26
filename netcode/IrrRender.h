#ifndef IRRRENDER_H
#define IRRRENDER_H

#ifdef IRRRENDER_EXPORTS
#define IRRRENDERAPI __declspec(dllexport) 
#else
#define IRRRENDERAPI __declspec(dllimport) 
#endif

IRRRENDERAPI void CreateRender(int handle);

IRRRENDERAPI bool RenderFrame();

IRRRENDERAPI void DestroyRender();

IRRRENDERAPI void SetCamera(float x,float y,float z);

IRRRENDERAPI void CreateTerrain();

#endif