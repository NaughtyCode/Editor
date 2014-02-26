#ifndef  PROXYRENDERDEF_H
#define  PROXYRENDERDEF_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#ifdef PROXY_EXPORTS
#define PROXYAPI __declspec(dllexport) 
#else
#define PROXYAPI __declspec(dllimport) 
#endif




typedef unsigned int ObjectHandle;




static const char s_pathGrossini[]        = "GameRes/grossini.png";
static const char s_pathSister1[]         = "GameRes/grossinis_sister1.png";
static const char s_pathSister2[]         = "GameRes/grossinis_sister2.png";
static const char s_pathB1[]              = "GameRes/b1.png";
static const char s_pathB2[]              = "GameRes/b2.png";
static const char s_pathR1[]              = "GameRes/r1.png";
static const char s_pathR2[]              = "GameRes/r2.png";
static const char s_pathF1[]              = "GameRes/f1.png";
static const char s_pathF2[]              = "GameRes/f2.png";
static const char s_pathBlock[]           = "GameRes/blocks.png";
static const char s_back[]                = "GameRes/background.png";
static const char s_back1[]               = "GameRes/background1.png";
static const char s_back2[]               = "GameRes/background2.png";
static const char s_back3[]               = "GameRes/background3.png";
static const char s_stars1[]              = "GameRes/stars.png";
static const char s_stars2[]              = "GameRes/stars2.png";
static const char s_fire[]                = "GameRes/fire.png";
static const char s_snow[]                = "GameRes/snow.png";
static const char s_streak[]              = "GameRes/streak.png";
static const char s_PlayNormal[]          = "GameRes/btn-play-normal.png";
static const char s_PlaySelect[]          = "GameRes/btn-play-selected.png";
static const char s_AboutNormal[]         = "GameRes/btn-about-normal.png";
static const char s_AboutSelect[]         = "GameRes/btn-about-selected.png";
static const char s_HighNormal[]          = "GameRes/btn-highscores-normal.png";
static const char s_HighSelect[]          = "GameRes/btn-highscores-selected.png";
static const char s_Ball[]                = "GameRes/ball.png";
static const char s_Paddle[]              = "GameRes/paddle.png";
static const char s_pathClose[]           = "GameRes/close.png";
static const char s_MenuItem[]            = "GameRes/menuitemsprite.png";
static const char s_SendScore[]           = "GameRes/SendScoreButton.png";
static const char s_PressSendScore[]      = "GameRes/SendScoreButtonPressed.png";
static const char s_Power[]               = "GameRes/powered.png";
static const char s_AtlasTest[]           = "GameRes/atlastest.png";
static const char s_s9s_blocks9[]         = "GameRes/blocks9ss.png";
static const char s_s9s_blocks9_plist[]   = "GameRes/blocks9ss.plist";
static const char s_s9s_ui[]              = "GameRes/ui.png";
static const char s_s9s_ui_plist[]        = "GameRes/ui.plist";

#endif
