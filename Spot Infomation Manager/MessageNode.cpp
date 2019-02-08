#include "stdafx.h"
//
// Created by badcw on 2019/1/25.
//

#include "MessageNode.h"

MessageNode::MessageNode(int _idx, CString _name, CString _desc): idx(_idx), name(_name), desc(_desc) {}

MessageNode::MessageNode() : idx(-1), name(TEXT("")), desc(TEXT("")) {}
