/*
 * 		   Name:	CSS API
 *  Description:	C++ for CSS Logic
 *		    Web:	<www/.themindspot/.com>
 *
 *		Company: 	The Mind Company
 *
 *		   File:	CSStag.h
 *       Author:	Brandon L. Clark
 *
 *       2013 | All rights reserved unless authorized.
 */

#ifndef CSSSELECTOR_H_
#define CSSSELECTOR_H_

#include <string>
#include <vector>
#include "CSStag.h"

class CSSselector : public CSStag {
public:
	CSSselector();														// Initialize. No tag.
	CSSselector(int, std::string);    									// Initialize tag type & name.
	CSSselector(int, int, std::string);    								// Initialize tag type, position & name.
	CSSselector(int, int, int, std::string);    						// Initialize tag type, position, connected & name.
																		// tagType = 0: HTML Tag, 1: Class, 2: Id
	virtual ~CSSselector();												// Destructor.

	virtual void setSelector(CSStag);									// Initialize tag.
	virtual void setSelector(int, std::string);							// Initialize tag type and name.
																		// tagType = 0: HTML Tag, 1: Class, 2: Id

	void setSelectorContainer(std::vector<CSStag>);						// Set tag container.

	virtual void selector(CSStag);										// Add extend tag.
	virtual void selector(std::string);									// Add extend tag type & name.  Inner tagType = HTML
	virtual void selector(int, std::string);							// Add selector tag type & name.
																		// tagType = 4

	virtual void nest(CSStag);											// Add nested tag.
	virtual void nest(std::string);										// Add nested tag name.  tagType = HTML
	virtual void nest(int, std::string);								// Add nested tag type & name.
																		// tagType = 3

	void pseudo(CSStag);												// Add pseudo tag.
	void pseudo(std::string);											// Add pseudo tag type & name.
	void pseudo(int, std::string);										// Add pseudo tag name. Special case "::"
																		// tagType = 6

	void attribute(CSSselector);										// Add attribute to tag by tag.
	void attribute(std::string);										// Add attribute to tag with name. tagType = HTML
	void attribute(std::string, std::string, std::string);				// Add attribute to tag by name. tagType = HTML
																		// tagType = 7

	void media(CSStag);													// Add media by tag.
	void media(std::string);											// Add media to tag with name. Inner tagType = HTML

	void combinator(CSSselector);										// Add comparison tag.
	void combinator(std::string);												// Add comparison tag from string.
	void combinator(std::string, std::string, std::string);				// Add comparison tag from formula of tag types.

	CSStag getSelector(int);											// Get tag by index.
	std::vector<CSStag> getSelectorContainer(void);						// Get tag container

	void insertSelector(void);

private:
	std::vector<CSStag> tagContainer;
};

#endif /* CSSSELECTOR_H_ */
