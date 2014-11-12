#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include "GL/freeglut.h"

class ScenegraphNode
{
public:
    ScenegraphNode(bool isTransformationNode = false);
    virtual ~ ScenegraphNode();

    virtual void traverseNode()  = 0 ;

    void addChild(ScenegraphNode*) ;
    void depthFirstTraversal();
    void deleteAllChildren();
    void removeChild(unsigned int);
    bool  isTransformationNode ;

private:

    std::vector<ScenegraphNode*> childrenList;
};

#endif // NODE_H
