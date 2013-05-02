/*
 * CSSselectorprint.h
 *
 *  Created on: Apr 29, 2013
 *      Author: brandon
 */

#ifndef CSSSELECTORPRINT_H_
#define CSSSELECTORPRINT_H_

#include <string>
#include "CSSselector.h"

class CSSselectorprint : public CSStag {
public:
	CSSselectorprint();
	virtual ~CSSselectorprint();

	virtual std::string formatSelector(CSSselector);
	virtual std::string formatTag(CSStag);

	std::string getTagCharacter(int);

	void sortTags(void);
};

#endif /* CSSSELECTORPRINT_H_ */
