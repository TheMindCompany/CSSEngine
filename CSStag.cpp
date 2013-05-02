/*
 * CSStag.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: brandon
 */

#include "CSStag.h"

CSStag::CSStag() : tagName(""), tagType(0), tagGroup(0), tagConnected(0), tagExtend(0) {}

CSStag::CSStag(int type, std::string name) : tagName(name), tagType(type), tagGroup(0), tagConnected(0), tagExtend(0) {
	if (type == ( 4 | 5 )){tagName = "";}
}

CSStag::CSStag(int type, int position, std::string name) : tagName(name), tagType(type), tagGroup(position), tagConnected(), tagExtend(0) {
	if (type == ( 4 | 5 )){tagName = "";}
}

CSStag::CSStag(int type, int position, int connection, std::string name) : tagName(name), tagType(type), tagGroup(position), tagConnected(connection), tagExtend(0) {
	if (type == ( 4 | 5 )){tagName = "";}
}

CSStag::~CSStag() {}

void CSStag::setTag(int type, std::string name) {
	setTag(type,0, 0,name);
}

void CSStag::setTag(int type, int position, std::string name) {setTag(type, position, 0, name);}

void CSStag::setTag(int type, int position, int connected, std::string name) {
	if (type == ( 4 | 5 )){tagName = "";}
	tagType = type;
	tagName = name;
	tagGroup = position;
	tagConnected = connected;
	tagExtend = 0;
}

void CSStag::setTagName(std::string name) {tagName = name;}

void CSStag::setTagType(int type) {
	if (type == ( 4 | 5 )){tagName = "";}
	tagType = type;
}

void CSStag::setTagGroup(int position) {tagGroup = position;}

void CSStag::setTagConnected(int connected) {tagConnected = connected;}

CSStag CSStag::getTag(void) {
	CSStag tag(tagType, tagGroup, tagConnected, tagName);
	tag.setTagExtend(tagExtend);
	return tag;
}

std::string CSStag::getTagName(void) {return tagName;}

int CSStag::getTagType(void) {return tagType;}

int CSStag::getTagGroup(void) {return tagGroup;}

void CSStag::setTagExtend(int extend) {tagExtend = extend;}

int CSStag::getTagConnected(void) {return tagConnected;}

void CSStag::setTag(CSStag tag) {
	tagType = tag.getTagType();
	tagName = tag.getTagName();
	tagGroup = tag.getTagGroup();
	tagConnected = tag.getTagConnected();
	tagExtend = tag.getTagExtend();
}

void CSStag::clearTag(void) {
	tagType = 0;
	tagName = "";
	tagGroup = 0;
	tagConnected = 0;
	tagExtend = 0;
}

int CSStag::getTagExtend(void) {return tagExtend;}
