/*
 * 		   Name:	CSS API
 *  Description:	C++ for CSS Logic
 *		    Web:	<www/.themindspot/.com>
 *
 *		Company: 	The Mind Company
 *
 *		   File:	CSSvalue.cpp
 *       Author:	Brandon L. Clark
 *
 *       2013 | All rights reserved unless authorized.
 */

#include "CSSvalue.h"

CSSvalue::CSSvalue(): valueName(), valueSetting(), browser() {}

CSSvalue::CSSvalue(std::string name, std::string setting) : valueName(name), valueSetting(setting), browser() {}

CSSvalue::CSSvalue(int type, std::string name, std::string setting) {
	setValue(name,setting);
	setValueBrowser(type);
}

CSSvalue::~CSSvalue() {}

void CSSvalue::setValue(CSSvalue aValue) {
	valueName = aValue.getValueName();
	valueSetting = aValue.getValueSetting();
	browser = aValue.getBrowser();
}

void CSSvalue::setValue(std::string name, std::string setting) {
	valueName = name;
	valueSetting = setting;
}

void CSSvalue::setValue(int type, std::string name, std::string setting) {
	setValue(name,setting);
	setValueBrowser(type);
}

void CSSvalue::setValueName(std::string name) {valueName = name;}

void CSSvalue::setValueSetting(std::string setting) {valueSetting = setting;}

void CSSvalue::setValueBrowser(int type) {browser = type;}

bool CSSvalue::matchValue(std::string name) {return (name == valueName);}

bool CSSvalue::matchValue(int type) {return (type == browser);}

CSSvalue CSSvalue::getValue(void) {
	CSSvalue value;
	value.setValue(browser, valueName, valueSetting);
	return value;
}

std::string CSSvalue::getValueName(void) {return valueName;}

std::string CSSvalue::getValueSetting(void) {return valueSetting;}

std::string CSSvalue::getValueString(void) {return valueName + ": " + getBrowserTag() + valueSetting +";";}

int CSSvalue::getBrowser(void) {return browser;}

std::string CSSvalue::getBrowserTag(void) {
	std::string kit;
	switch (browser) {
		case 0:
			kit = "";
			break;
		case 1:
			kit = "-webkit-";
			break;
		case 2:
			kit = "-moz-";
			break;
		case 3:
			kit = "-o-";
			break;
		case 4:
			kit = "-ms-";
			break;
		default:
			kit = "";
			break;
	}
	return kit;
}
