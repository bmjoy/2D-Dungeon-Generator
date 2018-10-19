/*
* @author PELLETIER Benoit
*
* @file Dungeon.h
*
* @date 15/10/2018
*
* @brief Define and generate dungeons
*
*/

#ifndef _DUNGEON_H
#define _DUNGEON_H

#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

enum TileType
{
	Empty = 0,
	Wall,
	In,
	Out,
	Door,
	LockedDoor,
	key,
	Chest,
	Enemy
};

class Dungeon
{
private:
	vector<Room*> m_roomList;
	uint64_t m_width, m_height;

	short **m_array;

public:
	Dungeon(uint64_t width, uint64_t height);
	~Dungeon();

	inline size_t getRoomCount() { return m_roomList.size(); }
	inline Room* getRoom(int index) { return m_roomList[index]; }
	Room* getRoomAt(uint64_t x, uint64_t y);

	void setSize(uint64_t width, uint64_t height);
	inline uint64_t getWidth() { return m_width; }
	inline uint64_t getHeight() { return m_height; }

	void generate(int iteration);


	short getValue(uint64_t x, uint64_t y);
	void setValue(uint64_t x, uint64_t y, short value);

private:
	int _RandRange(int min, int max);

	void _ClearRoomList();
	void _ClearArray();

	void _GenerateRooms(int iteration);
	void _FillArray();

	void _ResetArray();

	void _ListNeighbors(Room* r);
};

#endif // _DUNGEON_H