/*
 * CSStag.h
 *
 *  Created on: Apr 27, 2013
 *      Author: brandon
 */

#ifndef CSSTAG_H_
#define CSSTAG_H_

#include <string>

class CSStag {
public:
	CSStag();													//
	CSStag(int, std::string);									//
	CSStag(int, int, std::string);								//
	CSStag(int, int, int, std::string);							//
	virtual ~CSStag();											//

	virtual void setTag(CSStag);							//
	virtual void setTag(int, std::string);						//
	virtual void setTag(int, int, std::string);				//
	virtual void setTag(int, int, int, std::string);			//

	void setTagName(std::string);								//
	void setTagType(int);										//
	void setTagGroup(int);										//
	void setTagConnected(int);									//
	void setTagExtend(int);									//

	virtual void clearTag(void);									//

	CSStag getTag(void);										//

	std::string getTagName(void);									//
	int getTagType(void);											//
	int getTagGroup(void);											//
	int getTagConnected(void);										//
	int getTagExtend(void);

	virtual bool operator<(CSStag sort) {return tagGroup < sort.getTagGroup();}

private:
	std::string tagName;
	int tagType;													// tagType = 0: HTML Tag, 1: Class, 2: Id, 3:pseudo, 4:attribute-open, 5:attribute-close, 6:media, 7: comparison
	int tagGroup;													// group = 0 =< #
	int tagConnected;												// connected = NONE: 0, group: 0 < #
	int tagExtend;													// extend = 0: space, 1: no space
};

#endif /* CSSTAG_H_ */
