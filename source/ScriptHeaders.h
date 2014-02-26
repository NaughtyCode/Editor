#ifndef  SCRIPTHEADERS_H
#define  SCRIPTHEADERS_H

#ifdef SCRIPTPARSER_EXPORTS
#define SCRIPT_API __declspec(dllexport) 
#else
#define SCRIPT_API __declspec(dllimport)
#endif

#endif
