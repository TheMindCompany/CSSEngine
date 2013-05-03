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

void CSSselector::selector(CSStag tag) {
	int group = tag.getTagGroup();
	int previousGroup = tagContainer.back().getTagGroup();
	int connected = tag.getTagConnected();
	int previousConnected = tagContainer.back().getTagType();

	// If group and connection is set in tag, see if it applies to current selector.
	if (group != 0 && group <= previousGroup){ group = previousGroup + 1;}
	if (group == previousGroup){ connected = previousConnected;}

	CSStag::setTag(tag.getTagType(), group, connected, tag.getTagName());
	insertSelector();
	clearTag();
}

void CSSselector::selector(std::string name) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	CSStag::setTag(0, group, connected, name);
	insertSelector();
	clearTag();
}

void CSSselector::selector(int type, std::string name) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	CSStag::setTag(type, group, connected, name);
	insertSelector();
	clearTag();
}


void CSSselector::nest(CSStag tag) {
	int group = tag.getTagGroup();
	int previousGroup = tagContainer.back().getTagGroup();
	int connected = tag.getTagConnected();
	int previousConnected = tagContainer.back().getTagType();

	// If group and connection is set in tag, see if it applies to current selector.
	if (group != 0 && group <= previousGroup){ group = previousGroup + 1;}
	if (group == previousGroup){ connected = previousConnected;}

	CSStag::setTag(tag.getTagType(), group, connected, tag.getTagName());
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::nest(std::string name) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	CSStag::setTag(0, group, connected, name);
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::nest(int type, std::string name) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	CSStag::setTag(type, group, connected, name);
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::pseudo(std::string name) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	CSStag::setTag(3, group, connected, name);
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::pseudo(CSStag tag) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	CSStag::setTag(3, group, connected, tag.getTagName());
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

// Special case of pseudo element "::"
void CSSselector::pseudo(int type, std::string name) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	if ( type == 1 ) {
		CSStag::setTag(3, group, connected, "");
		CSStag::setTagExtend(1);
		insertSelector();
	}
	pseudo(name);
}

void CSSselector::attribute(CSSselector selector) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	// Open attribute
	CSStag::setTag(4, group, connected, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();

	// Extract attribute from selector
	for (int i = 0;i < (int)selector.getSelectorContainer().size(); i++){
		CSStag::setTag(selector.getSelectorContainer().at(i).getTagType(), group, 4, selector.getSelectorContainer().at(i).getTagName());
		if (i != 1) {CSStag::setTagExtend(selector.getSelectorContainer().at(i).getTagExtend());}
		insertSelector();
		clearTag();
	}

	// Close attribute
	CSStag::setTag(5, group, connected, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::attribute(std::string name1, std::string comparision, std::string name2) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	// Open attribute
	CSStag::setTag(4, group, connected, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();

	// Create combinator element
	combinator(name1, comparision, name2);

	// Close attribute
	CSStag::setTag(5, group, connected, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::attribute(std::string name) {
	int group = 0;
	int connected = 0;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	// Open attribute
	CSStag::setTag(4, group, connected, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();

	// Create selector element
	selector(name);

	// Close attribute
	CSStag::setTag(5, group, connected, "");
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::media(std::string name) {
	// Media selector tags do not come before any other selector elements.
	tagContainer.clear();

	CSStag::setTag(6, name);
	setTagExtend(1);
	insertSelector();
	clearTag();
}

void CSSselector::media(CSStag tag) {
	// Media selector tags do not come before any other selector elements.
	tagContainer.clear();

	CSStag::setTag(6, tag.getTagName());
	setTagExtend(1);
	insertSelector();
	clearTag();
}

// TODO combinator elements
void CSSselector::combinator(CSSselector selector) {

}

void CSSselector::combinator(std::string valueComparison) {
	int group = 0;
	int connected = 0;
	std::string name;
	name = valueComparison;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}

	CSStag::setTag(7, group, connected, name);
	insertSelector();
	clearTag();

}

void CSSselector::combinator(std::string name1, std::string comparison, std::string name2) {
	int group = 0;
	int connected = 0;
	std::string compare;
	compare = comparison;

	// Check previous tag to see if it applies to this one.
	if (tagContainer.size() != 0){
		group = tagContainer.back().getTagGroup() + 1;
		connected = tagContainer.back().getTagType();
	}
	CSStag::setTag(0, group, connected, name1);
	CSStag::setTagExtend(1);
	insertSelector();
	clearTag();

	CSStag::setTag(7, group, connected, compare);
	insertSelector();
	clearTag();

	CSStag::setTag(0, group, connected, name2);
	insertSelector();
	clearTag();
}

CSStag CSSselector::getSelector(int index) {
	CSStag group;
	group = tagContainer.at(index).getTag();
	return group;
}

std::vector<CSStag> CSSselector::getSelectorContainer(void) {return tagContainer;}


void CSSselector::insertSelector(void) {if (tagContainer.size() == 0){setTagExtend(1);}tagContainer.push_back(CSStag::getTag());}
