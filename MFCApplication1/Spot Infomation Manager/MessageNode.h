//
// Created by badcw on 2019/1/25.
//

#ifndef DATASTRUCTUREGUI_MESSAGENODE_H
#define DATASTRUCTUREGUI_MESSAGENODE_H
#include "stdafx.h"

class MessageNode {
public:
	// index
	int idx;
	// name
	CString name;
	// description
	CString desc;
	MessageNode(int _idx, CString _name, CString _desc);
	MessageNode();
};


#endif //DATASTRUCTUREGUI_MESSAGENODE_H
