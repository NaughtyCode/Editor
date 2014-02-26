#include "GlobalSetting.h"

static std::string EditorResourcePath="";
static std::string GameResourcePath="";

const std::string GetEditorResourcePath(const std::string& filename)
{
    return EditorResourcePath+filename;
}

void SetEditorResourcePath(const std::string& pathname){
    EditorResourcePath=pathname;
}

const std::string GetGameResourcePath(const std::string& filename)
{
    return GameResourcePath+filename;
}

void SetGameResourcePath(const std::string& pathname){
    GameResourcePath=pathname;
}
