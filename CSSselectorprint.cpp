/*
 * CSStagprint.cpp
 *
 *  Created on: Apr 29, 2013
 *      Author: brandon
 */

#include "CSSselectorprint.h"

CSSselectorprint::CSSselectorprint() {}

CSSselectorprint::~CSSselectorprint() {}

std::string CSSselectorprint::formatTag(CSStag tag) {
	std::string formatedString = "";
	if (tag.getTagExtend() == 0 ) {
		formatedString += " ";
	}
	formatedString += getTagCharacter(tag.getTagType());
	formatedString += tag.getTagName();

	return formatedString;
}

std::string CSSselectorprint::formatSelector(CSSselector tag) {
	std::string formatedString = "";

	for (int i = 0; i < (int)tag.getSelectorContainer().size(); i++){
		formatedString += formatTag(tag.getSelectorContainer().at(i).getTag());
	}
	formatedString += "\n";
	return formatedString;
}

std::string CSSselectorprint::getTagCharacter(int type) {
	std::string formatedString;
	switch (type) {
		case 0:
			formatedString = "";
			break;
		case 1:
			formatedString = ".";
			break;
		case 2:
			formatedString = "#";
			break;
		case 3:
			formatedString = ":";
			break;
		case 4:
			formatedString = "[ ";
			break;
		case 5:
			formatedString = " ]";
			break;
		case 6:
			formatedString = "@media ";
			break;
		default:
			formatedString = "";
			break;
	}
	return formatedString;
}
void CSSselectorprint::sortTags(void) {
	// TODO Sort selector tags by type and group.
}
