#include "TPathParser.h"

#ifndef BOOST_FILESYSTEM_NO_DEPRECATED
#define BOOST_FILESYSTEM_NO_DEPRECATED
#endif

#include <boost/filesystem.hpp>
#include <boost/filesystem.hpp>

using namespace boost;

TPathParser::TPathParser()
{
    
}

TPathParser::~TPathParser()
{
    
}

void TPathParser::GeneratePathInfo(const std::string& rootpath)
{
    std::cout<<"init path: "<<rootpath<<"\n";
    filesystem::path Path(rootpath);
    filesystem::path TempPath;
    if (exists(Path)){
        if (filesystem::is_regular_file(Path)){
            std::cout<<"wrong path\n";
        }
        else if (filesystem::is_directory(Path)){
            filesystem::directory_iterator it = filesystem::directory_iterator(Path);
            while(it!=filesystem::directory_iterator()){
                TempPath=*it;
                if(filesystem::is_regular_file(*it)){
                    ResourcePathData.push_back(TempPath.string());
                }else{
                    GeneratePathInfo(TempPath.string());
                }
                ++it;
            }
            std::cout<<"the number of file: "<<ResourcePathData.size()<<"\n";
        }
        else{
            std::cout <<"wrong path\n";
        }
    }
    else{
        std::cout <<"wrong path\n";
    }
}

void TPathParser::DumpFilePathName()
{
    TVectorString::iterator it = ResourcePathData.begin();
    while(it!=ResourcePathData.end()){
        std::cout<<*it<<"\n";
        ++it;
    }
}

const char * TPathParser::GetBoolText(bool b)
{
    return b ? "true" : "false";
}

