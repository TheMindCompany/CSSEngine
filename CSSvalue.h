/*
 * 		   Name:	CSS API
 *  Description:	C++ for CSS Logic
 *		    Web:	<www/.themindspot/.com>
 *
 *		Company: 	The Mind Company
 *
 *		   File:	CSSvalue.h
 *       Author:	Brandon L. Clark
 *
 *       2013 | All rights reserved unless authorized.
 */

#ifndef CSSVALUE_H_
#define CSSVALUE_H_
#include <string>

class CSSvalue {
public:
	CSSvalue(void);														// Initialize.
	CSSvalue(std::string, std::string);									// Initialize with properties.
	CSSvalue(int, std::string, std::string);							// Initialize with properties and browser type.
	virtual ~CSSvalue(void);											// Destructor.

	virtual void setValue(CSSvalue);									// Set value from value.
	virtual void setValue(std::string, std::string);					// Set value & setting from string.
	virtual void setValue(int, std::string, std::string);				// Set value with browser type & setting.

	void setValueName(std::string);										// Edit value name.
	void setValueSetting(std::string);									// Edit value setting.
	void setValueBrowser(int);											// Set browser type.

	virtual bool matchValue(std::string);								// Does value name match.
	virtual bool matchValue(int);										// Does value browser match.

	virtual CSSvalue getValue(void);									// Get value as CSSvalue.
	virtual std::string getValueString(void);							// Get value as string.
	std::string getValueName(void);										// Get name as string.
	std::string getValueSetting(void);									// Get setting as string.
	std::string getBrowserTag(void);									// Get browser type.
	int getBrowser(void);												// Get browser type.
																		// browser = NONE: 0, -webkit-: 1, -moz-: 2, -o-: 3, -ms-: 4, ALL BROWSERS: 5

private:
	std::string valueName;
	std::string valueSetting;
	int browser; // browser = NONE: 0, -webkit-: 1, -moz-: 2, -o-: 3, -ms-: 4, ALL BROWSERS: 5
};

#endif /* CSSVALUE_H_ */
