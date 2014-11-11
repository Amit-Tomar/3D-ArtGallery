#ifndef NODE_H
#define NODE_H

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

private:

    std::vector<ScenegraphNode*> childrenList;
    bool  isTransformationNode  ;
};

#endif // NODE_H
