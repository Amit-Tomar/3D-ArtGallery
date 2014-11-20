#include "Node.h"

ScenegraphNode::ScenegraphNode(bool isTransformationNode)
{
    this->isTransformationNode  = isTransformationNode;
    performTraversal = true;
}

ScenegraphNode::~ScenegraphNode()
{
    // for( unsigned int i = 0 ; i < childrenList.size() ; ++ i ) {}
        // delete childrenList[i];
}

void ScenegraphNode::addChild(ScenegraphNode * childNode)
{
    childrenList.push_back(childNode);
}

void ScenegraphNode::depthFirstTraversal()
{
    if(!performTraversal)
        return;

    if(isTransformationNode)
        glPushMatrix();

    traverseNode();

    if( 0 == childrenList.size() )
    {
        return ;
    }
    else
    {
        for( unsigned int i = 0 ; i < childrenList.size() ; ++i )
        {
            (childrenList[i])->depthFirstTraversal();
        }
    }

    if(isTransformationNode)
        glPopMatrix();
}

void ScenegraphNode::deleteAllChildren()
{
    childrenList.clear();
}

void ScenegraphNode::removeChild(unsigned int index)
{
    if( index < childrenList.size() )
        childrenList.erase(childrenList.begin()+index);
}
