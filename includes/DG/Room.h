/*
* @author PELLETIER Benoit
*
* @file Room.h
*
* @date 11/10/2018
*
* @brief Define a dungeon room
*
*/

#ifndef _ROOM_H
#define _ROOM_H

#include <iostream>
#include <vector>
#include "Exports.h"

using namespace std;

class LIBDUNGEON_API Room
{
private:

	uint64_t m_id;
	int m_x, m_y;
	int m_w, m_h;

	Room* m_pParent;

	vector<Room*> m_neighbors;
	vector<Room*> m_links;

public:
	Room(int x = 0, int y = 0, int w = 1, int h = 1);
	Room(const Room& _r);
	~Room();

	inline void setId(uint64_t id) { m_id = id; }
	inline void setX(int x) { m_x = x; }
	inline void setY(int y) { m_y = y; }
	inline void setPosition(int x, int y) { m_x = x; m_y = y; }
	inline void setWidth(int w) { m_w = w; }
	inline void setHeight(int h) { m_h = h; }
	inline void setSize(int w, int h) { m_w = w; m_h = h; }
	inline void setParent(Room* parent) { m_pParent = parent; }

	inline uint64_t getId() { return m_id; }
	inline int getX() { return m_x; }
	inline int getY() { return m_y; }
	inline int getWidth() { return m_w; }
	inline int getHeight() { return m_h; }
	inline Room* getParent() { return m_pParent; }

	inline void addNeighbor(Room* room) { m_neighbors.push_back(room); }
	Room* getNeighbor(int index);
	inline size_t getNeighborCount() { return m_neighbors.size(); }

	void addLink(Room* room);
	Room* getLink(int index);
	inline size_t getLinkCount() { return m_links.size(); }

	bool isIn(int x, int y);

};

#endif // _ROOM_H