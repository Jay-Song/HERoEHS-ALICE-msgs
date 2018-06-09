#ifndef ROBOCUP_STRUCT_H
#define ROBOCUP_STRUCT_H

#include <stdint.h>

#define GAMECONTROLLER_RETURN_STRUCT_HEADER      "RGrt"
#define GAMECONTROLLER_RETURN_STRUCT_VERSION     3

#define GAMECONTROLLER_RETURN_MSG_ALIVE          0
#define MAX_NUM_PLAYERS 6

struct RobotInfo
{ 
  uint8_t penalty;              // penalty state of the player
  uint8_t secsTillUnpenalised;  // estimate of time till unpenalised
};

struct TeamInfo
{ 
  uint8_t teamNumber;           // unique team number
  uint8_t teamColour;           // colour of the team
  uint8_t score;                // team's score
  uint8_t penaltyShot;          // penalty shot counter
  uint16_t singleShots;         // bits represent penalty shot success
  RobotInfo players[MAX_NUM_PLAYERS]; // the team's players
};

struct RoboCupGameControlData
{
  char header[4];               // header to identify the structure
  uint16_t version;             // version of the data structure
  uint8_t packetNumber;         // number incremented with each packet sent (with wraparound)
  uint8_t playersPerTeam;       // the number of players on a team
  uint8_t competitionPhase;     // phase of the competition (COMPETITION_PHASE_ROUNDROBIN, COMPETITION_PHASE_PLAYOFF)
  uint8_t competitionType;      // type of the competition (COMPETITION_TYPE_NORMAL, COMPETITION_TYPE_MIXEDTEAM, COMPETITION_TYPE_GENERAL_PENALTY_KICK)
  uint8_t gamePhase;            // phase of the game (GAME_PHASE_NORMAL, GAME_PHASE_PENALTYSHOOT, etc)
  uint8_t state;                // state of the game (STATE_READY, STATE_PLAYING, etc)
  uint8_t setPlay;              // active set play (SET_PLAY_NONE, SET_PLAY_GOAL_FREE_KICK, etc)
  uint8_t firstHalf;            // 1 = game in first half, 0 otherwise
  uint8_t kickingTeam;          // the team number of the next team to kick off, free kick, DROPBALL etc.
  uint8_t dropInTeam;           // number of team that caused last drop in
  uint16_t dropInTime;          // number of seconds passed since the last drop in. -1 (0xffff) before first dropin
  uint16_t secsRemaining;       // estimate of number of seconds remaining in the half
  uint16_t secondaryTime;       // number of seconds shown as secondary time (remaining ready, until free ball, etc)
  TeamInfo teams[2];
};

struct RoboCupGameControlReturnData
{
  char header[4];
  uint8_t version;
  uint8_t team;    // team number
  uint8_t player;  // player number starts with 1
  uint8_t message; // one of the three messages defined above

#ifdef __cplusplus
  // constructor
  RoboCupGameControlReturnData() : version(GAMECONTROLLER_RETURN_STRUCT_VERSION)
  {
    const char* init = GAMECONTROLLER_RETURN_STRUCT_HEADER;
    for(unsigned int i = 0; i < sizeof(header); ++i)
      header[i] = init[i];
  }
#endif
};

#endif
