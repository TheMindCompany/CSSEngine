/*
 * 		   Name:	CSS API
 *  Description:	C++ for CSS Logic
 *		    Web:	<www/.themindspot/.com>
 *
 *		Company: 	The Mind Company
 *
 *		   File:	CSStag.cpp
 *       Author:	Brandon L. Clark
 *
 *       2013 | All rights reserved unless authorized.
 */

#include "CSSselector.h"

CSSselector::CSSselector() {}

CSSselector::CSSselector(int type, std::string name) : CSStag(type, name) {insertSelector();}

CSSselector::CSSselector(int type, int group, std::string name) : CSStag(type, group, name) {insertSelector();}

CSSselector::CSSselector(int type, int group, int connected, std::string name) : CSStag(type, group, connected, name) {insertSelector();}

CSSselector::~CSSselector() {}

void CSSselector::setSelector(CSStag tag) {
	tagContainer.clear();
	setTag(tag.getTag());
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::setSelector(int type, std::string name) {
	tagContainer.clear();
	CSStag::setTag(type, name);
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::setSelectorContainer(std::vector<CSStag> container) {
	tagContainer.clear();
	tagContainer.insert(tagContainer.begin(), container.begin(), container.end());
}

void CSSselector::nest(CSStag tag) {
	CSStag::setTag(tag.getTagType(), tag.getTagGroup(), tag.getTagConnected(), tag.getTagName());
	insertSelector();
	clearTag();
}

void CSSselector::nest(std::string name) {
}

void CSSselector::nest(int type, std::string name) {
	int group = 0;
	group = tagContainer.at(tagContainer.size()).getTagGroup() + 1;
	CSStag::setTag(type, group, name);
	insertSelector();
	clearTag();
}

void CSSselector::extend(CSStag tag) {
	int group = 0;
	if (tag.getTagGroup() != 0){ group = tag.getTagGroup();}
	else {group = tagContainer.back().getTagGroup();}
	CSStag::setTag(tag.getTagType(), group, tag.getTagConnected(), tag.getTagName());
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::extend(std::string name) {
}

void CSSselector::extend(int type, std::string name) {
	int group = 0;
	group = tagContainer.at(tagContainer.size()).getTagGroup();
	CSStag::setTag(type, group, name);
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::pseudo(CSStag tag) {
	int group = 0;
	if (tag.getTagGroup() != 0){ group = tag.getTagGroup();}
	else {group = tagContainer.back().getTagGroup();}
	CSStag::setTag(3, group, tag.getTagConnected(), tag.getTagName());
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::pseudo(int type, std::string name) {
	int group = 0;
	group = tagContainer.at(tagContainer.size()).getTagGroup();
	CSStag::setTag(3, group, name);
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::attribute(CSSselector tag) {
	int group = 0;
	if (tagContainer.size() != 0) {group = tagContainer.at(tagContainer.size()).getTagGroup() + 1;}
	// Open attribute
	CSStag::setTag(4, group, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
	// Extract attribute from tag
	for (int i = 0;i < (int)tag.getSelectorContainer().size(); i++){
		CSStag::setTag(tag.getSelectorContainer().at(i).getTagType(), group, 4, tag.getSelectorContainer().at(i).getTagName());
		if (i != 1) {CSStag::setTagExtend(tag.getSelectorContainer().at(i).getTagExtend());}
		insertSelector();
		clearTag();
	}
	// Close attribute
	CSStag::setTag(5, group, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::attribute(std::string name1, char comparision, std::string name2) {
}

void CSSselector::attribute(std::string name) {
	int group = 0;
	if (tagContainer.size() != 0) {group = tagContainer.at(tagContainer.size()).getTagGroup() + 1;}
	// Open attribute
	CSStag::setTag(4, group, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
	group = tagContainer.at(tagContainer.size()).getTagGroup();
	// Attribute setting
	CSStag::setTag(0, group, 4, name);
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
	// Close attribute
	CSStag::setTag(5, group, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::media(std::string name) {
	tagContainer.clear();
	CSStag::setTag(6, name);
	setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::media(CSStag tag) {
	tagContainer.clear();
	CSStag::setTag(6, tag.getTagName());
	setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::combinator(CSSselector tag) {
	int group = 0;
	if (tagContainer.size() != 0) {group = tagContainer.at(tagContainer.size()).getTagGroup() + 1;}
	// Open attribute
	CSStag::setTag(4, group, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
	// Extract attribute from tag
	for (int i = 0;i < (int)tag.getSelectorContainer().size(); i++){
		CSStag::setTag(tag.getSelectorContainer().at(i).getTagType(), group, 4, tag.getSelectorContainer().at(i).getTagName());
		if (i != 1) {CSStag::setTagExtend(tag.getSelectorContainer().at(i).getTagExtend());}
		insertSelector();
		clearTag();
	}
	// Close attribute
	CSStag::setTag(5, group, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::combinator(char valueComparison) {
}

void CSSselector::combinator(std::string name1, char comparision, std::string name2) {
}

CSStag CSSselector::getSelector(int index) {
	CSStag group;
	group = tagContainer.at(index).getTag();
	return group;
}

std::vector<CSStag> CSSselector::getSelectorContainer(void) {return tagContainer;}

void CSSselector::pseudo(std::string allocator) {
}

void CSSselector::insertSelector(void) {tagContainer.push_back(CSStag::getTag());}
