#ifndef GROUPNODE_H
#define GROUPNODE_H

#include <Node.h>

class GroupNode : public ScenegraphNode
{
public:
    GroupNode();
    void traverseNode();
};

#endif // GROUPNODE_H
