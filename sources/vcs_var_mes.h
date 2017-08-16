//#include <registryFunction.h>
//#include <epicsExport.h>
#include <string.h> // man function_name(man strcpy) to find header
#include <stdio.h>

#ifndef VCS_PROC_H
#define VCS_PROC_H
 
#define CLEAR_TIME 600 //~ 2 minute (600 x scan time)

static const char* mes_array[188] = {     
		"    CLEARED   ", 						// 0
        "    NOT CLEARED   ",					// 1
        "CLEAR UNDERWAY", 						// 2
        "     ERROR    ", 						// 3
        " CLEAR FAILED ", 						// 4
        "TIME OUT ERROR: RELEASE ALL WATCHMEN", // 5
        "Gate A001A switch 1 is open",			// 6
        "Gate A001A switch 2 is open",			// 7
        "Waiting on G5 switch 1 to close",		// 8
        "Waiting on G5 switch 2 to close",		// 9
        "Watchman 17 must be activated",		// 10
        "Watchman 16 must be released",			// 11
        "Gate G5 was opened",					// 12
        "Gate A001A was opened",				// 13
        "Panic button 16 was activated",		// 14
        "SSC cable labyrinth NOT cleared",		// 15
        "Door A001 was opened",					// 16
        "Gate G1 was opened",					// 17
        "Gate G2 was opened",					// 18
        "A Panic button was activated",			// 19
        "Watchman 1 was released too soon",		// 20
        "Hold watchman 1 and press 2",			// 21
        "Door A001 switch 1 is open",			// 22
        "Door A001 switch 2 is open",			// 23
        "Gate G1 switch 1 is open",				// 24
        "Gate G1 switch 2 is open",				// 25
        "Hold watchman 1 and press 3",			// 26
        "Hold watchman 1, press and hold 4",	// 27
        "Hold watchman 4 and press 5",			// 28
        "Watchman 4 was released too soon",		// 29
        "Release watchman 4 & 5",				// 30
        "Watchman 4 must be released",			// 31
        "Gate G2 must be closed",				// 32
        "Watchman 5 must be released",			// 33
        "Watchman 6 must be activated",			// 34
        "Hold watchman 1 and release 2",		// 35
        "Hold watchman 1 and release 3",		// 36
        "Hold watchman 4 and release 1",		// 37
        "SSC basement is not cleared",			// 38
        "Gate A1A was opened",					// 39
        "Door A1 was opened",					// 40
        "Gate G3 was opened",					// 41
        "Gate A1A switch 1 is open",			// 42
        "Gate A1A switch 2 is open",			// 43
        "Gate A1A switch 3 is open",			// 44
        "Gate A1A switch 4 is open",			// 45
        "Gate G3 must be closed",				// 46
        "Watchman 12 must be activated",		// 47
        "SSC Area 1 is not cleared",			// 48
        "Release watchman 13",					// 49
        "Watchman 14 must be activated", 		// 50
        "Release watchman 14",					// 51
        "Watchman 14 must be released",			// 52
        "Door A1 must be closed",				// 53
        "",										// 54
        "Watchman 15 must be activated",		// 55
        "Door A1A was opened",					// 56
        "Door A13 was opened",					// 57
        "Watchman 9 must be released",			// 58
        "Gate A1A switch 1 is open",			// 59
        "Gate A1A switch 2 is open",			// 60
        "Gate A1A switch 3 is open",			// 61
        "Gate A1A switch 4 is open",			// 62
        "Watchman 8 must be released",			// 63
        "Watchman 8 must be activated",			// 64
        "Waiting on A13 switch 1 to close",		// 65
        "Waiting on A13 switch 2 to close",		// 66
        "Watchman 7 must be activated",			// 67
        "Door A12 was opened",					// 68
        "Release watchman 26",					// 69
        "Hold watchman 27 and release 26",		// 70
        "Hold watchman 27 and press 28a",		// 71
        "Watchman 27 must be activated",		// 72
        "Watchman 28a must be activated",		// 73
        "Watchman 28b must be activated",		// 74
        "Waiting on A12 switch 1 to close",		// 75
        "Waiting on A12 switch 2 to close",		// 76
        "Watchman 29 must be activated", 		// 77
        "Release Watchman 27",					// 78
        "Release watchman 28a",					// 79
        "Release watchman 28b",					// 80
        "Door A004A was opened",				// 81
        "Gate G4 was opened",		        	// 82
        "Gate G4 switch 1 is open",				// 83
        "Gate G4 switch 2 is open",				// 84
        "Watchman 34a must be released",		// 85
        "Watchman 34b must be released",		// 86
        "Watchman 34b must be activated",		// 87
        "Door A004A switch 1 is open",			// 88
        "Door A004A switch 2 is open",			// 89
        "Watchman 35 must be activated",		// 90
        "Door A14 was opened",					// 91
        "Watchman 30 must be released",			// 92
        "Door A14 switch 1 is open",			// 93
        "Door A14 switch 2 is open",			// 94
        "Watchman 31 must be activated",		// 95
        "Door A004 was opened",					// 96
        "Watchman 32 must be released",			// 97
        "Door A004 switch 1 is open",			// 98
        "Door A004 switch 2 is open",			// 99
        "Watchman 33 must be activated",		// 100
        "Door A6 was opened",					// 101
        "Watchman 18 must be released",			// 102
        "Door A6 switch 1 is open",				// 103
        "Door A6 switch 2 is open",				// 104
        "Watchman 19 must be activated",		// 105
        "Door A7 was opened",					// 106
        "Watchman 20 must be released",			// 107
        "Door A7 switch 1 is open",				// 108
        "Door A7 switch 2 is open",				// 109
        "Watchman 21 must be activated",		// 110
        "Door A8 was opened",					// 111
        "Watchman 22 must be released",			// 112
        "Door A8 switch 1 is open",				// 113
        "Door A8 switch 2 is open",				// 114
        "Watchman 23 must be activated",		// 115
        "Panic button 24 was pressed",			// 116
        "Door A9 was opened", 					// 117
        "Watchman 24 must be released",			// 118
        "Watchman 25 must be activated",		// 119
        "Door A9 switch 2 is still open", 		// 120
        "Door A9 switch 1 is still open",		// 121
        "Panic button 38 was pressed",			// 122
        "Door A12A was opened",					// 123
        "Watchman 38 must be released",			// 124
        "Watchman 39 must be activated",		// 125
        "Door A12A switch 2 is still open",		// 126
        "Door A12A switch 1 is still open",		// 127
        "Panic button 36 was pressed",			// 128
        "Door A15 was opened",					// 129
        "Watchman 36 must be released",			// 130
        "Watchman 37 must be activated",		// 131
        "Door A15 switch 2 is still open",		// 132
        "Door A15 switch 1 is still open",		// 133
        "Panic button 18 was pressed",			// 134
        "Panic button 20 was pressed",			// 135
        "Panic button 22 was pressed",			// 136
        "Panic button 30 was pressed",			// 137
        "Panic button 32 was pressed",			// 138
        "Panic button 9a was pressed",			// 139
        "Gate 5A was opened",					// 140
        "Watchman 9a must be released",			// 141
        "Watchman 9b must be activated",		// 142
        "Gate 5A switch 2 is still open",		// 143
        "Gate 5A switch 1 is still open" ,		// 144
        "Area A13A is not cleared",				// 145
        "Watchman 11 must be released",			// 146
        "The roof is open",						// 147
        "Experimental vault 2 roof is open",	// 148
        "The roof or Gate G8 is open",			// 149
        "A12, A9 or A15 is not cleared",		// 150
        "Gate G9 was opened",					// 151
        "Gate G10 was opened",					// 152
        "Close gate G9",						// 153
        "Close gate G10",						// 154
        "Gate G6 is open",						// 155
        "Door A007 is open",					// 156
        "Panic button 44 was pressed",			// 157
        "Watchman 44 must be released",			// 158
        "Close Gate G6",						// 159
        "Watchman 45 must be activated",		// 160
        "Gate G6a is open",						// 161
        "SPC2 Lower vault not cleared",			// 162
        "Door A3 is open",						// 163
        "Gate G6a is open",						// 164
        "Watchman 46 must be released",			// 165
        "Watchman 48 must be activated",		// 166
        "Close Door A3",						// 167
        "Watchman 47 must be activated",		// 168
        "Watchman 47 must be released",			// 169
        "Door A3A is open",						// 170
        "Close Door A3A",						// 171
        "Door A2 is Open", 						// 172
        "Door A001 is Open",					// 173
        "Door A005A is Open",					// 174
        "Door A005 is Open",					// 175
        "Watchman 40 must be released",			// 176
        "Watchman 41 must be released",			// 177
        "Watchman 41 must be activated",		// 178
        "Watchman 42 must be released",			// 179
        "Watchman 42 must be activated",		// 180
        "Close Door A005",						// 181
        "Watchman 43 must be activated",		// 182
        "Close Gate G7",						// 183
        "Gate G7 is Open",						// 184
        "SPC1 upper vault not cleared",			// 185
        "Input Cable Reconnected",				// 186
        "Waiting for Vault Clearance",		    // 187
};	



//////////////////////////////////
extern inline void cleared(string vault_status); 
////////////////////////////////////////
extern inline void not_cleared(string vault_status); 
////////////////////////////////////////
extern inline void clear_underway(string vault_status);
/////////////////////////////////////////
extern inline void clear_failed(string vault_status);
////////////////////////////////////////
extern inline void report_error(string vault_interlock, short intlock);

#endif  // VCS_PROC_H
