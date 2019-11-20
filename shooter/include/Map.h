#ifndef MAP_H
#define MAP_H

#include "Settings.h"
class Map
{
    public:
        Map();
        void read();
        void write();
        void remove();
        std::string getSourceDir();
        std::string getBuildDir();
        virtual ~Map();
        std::string name;
        int width;
        int height;
        int ordering;
        int tileWidth;
        int tileHeight;
    private:

};

#endif // MAP_H
