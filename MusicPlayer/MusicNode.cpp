//Documentation in MusicNode.h

#include "stdafx.h"
#include "MusicNode.h"

MusicNode::MusicNode(int playlist_id)
{
	this->playlist_id = playlist_id;
	this->is_playing = false;
}

MusicNode::~MusicNode()
{}



