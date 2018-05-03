//#include <registryFunction.h>
//#include <epicsExport.h>
#include <string.h> // man function_name(man strcpy) to find header
#include <stdio.h>

#ifndef VCS_PROC_H
#define VCS_PROC_H
 
#define CLEAR_TIME 600 //~ 2 minute (600 x scan time)
#define ERROR 		"\033[31;1m"	// red background
#define OK 			"\033[33;1m" 	// yellow background
#define CLR			"\033[32;1m"    // green background
#define DEF 		"\033[0m"    	// white background

static const char* mes_array[188] = {     
		"",										// 0it is a requirement that this array first element be an empty string
		"    CLEARED   ", 						// 1
        "    NOT CLEARED   ",					// 2
        "CLEAR UNDERWAY", 						// 3
        "     ERROR    ", 						// 4
        " CLEAR FAILED ", 						// 5
        "TIME OUT ERROR: RELEASE ALL WATCHMEN", // 6
        "Gate A001A switch 1 is open",			// 7
        "Gate A001A switch 2 is open",			// 8
        "Waiting on G5 switch 1 to close",		// 9
        "Waiting on G5 switch 2 to close",		// 10
        "Watchman 17 must be activated",		// 11
        "Watchman 16 must be released",			// 12
        "Gate G5 was opened",					// 13
        "Gate A001A was opened",				// 14
        "Panic button 16 was activated",		// 15
        "SSC cable labyrinth NOT cleared",		// 16
        "Door A001 was opened",					// 17
        "Gate G1 was opened",					// 18
        "Gate G2 was opened",					// 19
        "A Panic button was activated",			// 20
        "Watchman 1 was released too soon",		// 21
        "Hold watchman 1 and press 2",			// 22
        "Door A001 switch 1 is open",			// 23
        "Door A001 switch 2 is open",			// 24
        "Gate G1 switch 1 is open",				// 25
        "Gate G1 switch 2 is open",				// 26
        "Hold watchman 1 and press 3",			// 27
        "Hold watchman 1, press and hold 4",	// 28
        "Hold watchman 4 and press 5",			// 29
        "Watchman 4 was released too soon",		// 30
        "Release watchman 4 & 5",				// 31
        "Watchman 4 must be released",			// 32
        "Gate G2 must be closed",				// 33
        "Watchman 5 must be released",			// 34
        "Watchman 6 must be activated",			// 35
        "Hold watchman 1 and release 2",		// 36
        "Hold watchman 1 and release 3",		// 37
        "Hold watchman 4 and release 1",		// 38
        "SSC basement is not cleared",			// 39
        "Gate A1A was opened",					// 40
        "Door A1 was opened",					// 41
        "Gate G3 was opened",					// 42
        "Gate A1A switch 1 is open",			// 43
        "Gate A1A switch 2 is open",			// 44
        "Gate A1A switch 3 is open",			// 45
        "Gate A1A switch 4 is open",			// 46
        "Gate G3 must be closed",				// 47
        "Watchman 12 must be activated",		// 48
        "SSC Area 1 is not cleared",			// 49
        "Release watchman 13",					// 50
        "Watchman 14 must be activated", 		// 51
        "Release watchman 14",					// 52
        "Watchman 14 must be released",			// 53
        "Door A1 must be closed",				// 54
        "",										// 55
        "Watchman 15 must be activated",		// 56
        "Door A1A was opened",					// 57
        "Door A13 was opened",					// 58
        "Watchman 9 must be released",			// 59
        "Gate A1A switch 1 is open",			// 60
        "Gate A1A switch 2 is open",			// 61
        "Gate A1A switch 3 is open",			// 62
        "Gate A1A switch 4 is open",			// 63
        "Watchman 8 must be released",			// 64
        "Watchman 8 must be activated",			// 65
        "Waiting on A13 switch 1 to close",		// 66
        "Waiting on A13 switch 2 to close",		// 67
        "Watchman 7 must be activated",			// 68
        "Door A12 was opened",					// 69
        "Release watchman 26",					// 70
        "Hold watchman 27 and release 26",		// 71
        "Hold watchman 27 and press 28a",		// 72
        "Watchman 27 must be activated",		// 73
        "Watchman 28a must be activated",		// 74
        "Watchman 28b must be activated",		// 75
        "Waiting on A12 switch 1 to close",		// 76
        "Waiting on A12 switch 2 to close",		// 77
        "Watchman 29 must be activated", 		// 78
        "Release Watchman 27",					// 79
        "Release watchman 28a",					// 80
        "Release watchman 28b",					// 81
        "Door A004A was opened",				// 82
        "Gate G4 was opened",		        	// 83
        "Gate G4 switch 1 is open",				// 84
        "Gate G4 switch 2 is open",				// 85
        "Watchman 34a must be released",		// 86
        "Watchman 34b must be released",		// 87
        "Watchman 34b must be activated",		// 88
        "Door A004A switch 1 is open",			// 89
        "Door A004A switch 2 is open",			// 90
        "Watchman 35 must be activated",		// 91
        "Door A14 was opened",					// 92
        "Watchman 30 must be released",			// 93
        "Door A14 switch 1 is open",			// 94
        "Door A14 switch 2 is open",			// 95
        "Watchman 31 must be activated",		// 96
        "Door A004 was opened",					// 97
        "Watchman 32 must be released",			// 98
        "Door A004 switch 1 is open",			// 99
        "Door A004 switch 2 is open",			// 100
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
        "The roof is open",						// 148
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
        "Power faillure on vcs crate",
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
