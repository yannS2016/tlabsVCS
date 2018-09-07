//#include <registryFunction.h>
#include <string.h> // man function_name(man strcpy) to find header
#include <stdio.h>

#ifndef VCS_PROC_H
#define VCS_PROC_H

#define ERROR 		  "\033[31;1m"	// red background
#define OK		  "\033[33;1m" 	// yellow background
#define CLR		  "\033[32;1m"  // green background
#define DEF               "\033[0m"    	// white background

static const char* mes_array[186] = {
	"",						// 0 it is a requirement that this array first element be an empty string
	"CLEARED",				        // 1
        "NOT CLEARED",				        // 2
        "CLEAR UNDERWAY",				// 3
        "ERROR", 				        // 4
        "CLEAR FAILED", 				// 5
        "TIME OUT ERROR: RELEASE ALL WATCHMEN",         // 6
        "Gate A001A switch 1 is open",			// 7
        "Gate A001A switch 2 is open",			// 8
        "Waiting on G5 switch 1 to close",		// 9
        "Waiting on G5 switch 2 to close",		// 10
        "Watchman 17 must be activated",		// 11
        "Watchman 16 must be released",			// 12
        "Gate G5 was opened",				// 13
        "Gate A001A was opened",			// 14
        "Panic button 16 was activated",		// 15
        "SSC cable labyrinth NOT cleared",		// 16
        "Door A001 was opened",				// 17
        "Gate G1 was opened",				// 18
        "Gate G2 was opened",				// 19
        "A Panic button was activated",			// 20
        "Watchman 1 was released too soon",		// 21
        "Hold watchman 1 and press 2",			// 22
        "Door A001 switch 1 is open",			// 23
        "Door A001 switch 2 is open",			// 24
        "Gate G1 switch 1 is open",			// 25
        "Gate G1 switch 2 is open",			// 26
        "Hold watchman 1 and press 3",			// 27
        "Hold watchman 1, press and hold 4",	        // 28
        "Hold watchman 4 and press 5",			// 29
        "Watchman 4 was released too soon",		// 30
        "Release watchman 4 & 5",			// 31
        "Watchman 4 must be released",			// 32
        "Gate G2 must be closed",			// 33
        "Watchman 5 must be released",			// 34
        "Watchman 6 must be activated",			// 35
        "Hold watchman 1 and release 2",		// 36
        "Hold watchman 1 and release 3",		// 37
        "Hold watchman 4 and release 1",		// 38
        "SSC basement is not cleared",			// 39
        "Gate A1A was opened",				// 40
        "Door A1 was opened",				// 41
        "Gate G3 was opened",				// 42
        "Gate A1A switch 1 is open",			// 43
        "Gate A1A switch 2 is open",			// 44
        "Gate A1A switch 3 is open",			// 45
        "Gate A1A switch 4 is open",			// 46
        "Gate G3 must be closed",			// 47
        "Watchman 12 must be activated",		// 48
        "SSC Area 1 is not cleared",			// 49
        "Release watchman 13",				// 50
        "Watchman 14 must be activated", 		// 51
        "Release watchman 14",				// 52
        "Watchman 14 must be released",			// 53
        "Door A1 must be closed",			// 54
        "Waiting for Vault Clearance",			// 55
        "Watchman 15 must be activated",		// 56
        "Door A1A was opened",				// 57
        "Door A13 was opened",				// 58
        "Watchman 9 must be released",			// 59
        "Watchman 8 must be released",			// 60
        "Watchman 8 must be activated",			// 61
        "Waiting on A13 switch 1 to close",		// 62
        "Waiting on A13 switch 2 to close",		// 63
        "Watchman 7 must be activated",			// 64
        "Door A12 was opened",				// 65
        "Release watchman 26",				// 66
        "Hold watchman 27 and release 26",		// 67
        "Hold watchman 27 and press 28a",		// 68
        "Watchman 27 must be activated",		// 69
        "Watchman 28a must be activated",		// 70
        "Watchman 28b must be activated",		// 71
        "Waiting on A12 switch 1 to close",		// 72
        "Waiting on A12 switch 2 to close",		// 73
        "Watchman 29 must be activated", 		// 74
        "Release Watchman 27",				// 75
        "Release watchman 28a",				// 76
        "Release watchman 28b",				// 77
        "Door A004A was opened",			// 78
        "Gate G4 was opened",		        	// 79
        "Gate G4 switch 1 is open",			// 80
        "Gate G4 switch 2 is open",			// 81
        "Watchman 34a must be released",		// 82
        "Watchman 34b must be released",		// 83
        "Watchman 34b must be activated",		// 84
        "Door A004A switch 1 is open",			// 85
        "Door A004A switch 2 is open",			// 86
        "Watchman 35 must be activated",		// 87
        "Door A14 was opened",				// 88
        "Watchman 30 must be released",			// 89
        "Door A14 switch 1 is open",			// 90
        "Door A14 switch 2 is open",			// 91
        "Watchman 31 must be activated",		// 92
        "Door A004 was opened",				// 93
        "Watchman 32 must be released",			// 94
        "Door A004 switch 1 is open",			// 95
        "Door A004 switch 2 is open",			// 96
        "Watchman 33 must be activated",		// 97
        "Door A6 was opened",				// 98
        "Watchman 18 must be released",			// 99
        "Door A6 switch 1 is open",			// 100
        "Door A6 switch 2 is open",			// 101
        "Watchman 19 must be activated",		// 102
        "Door A7 was opened",				// 103
        "Watchman 20 must be released",			// 104
        "Door A7 switch 1 is open",			// 105
        "Door A7 switch 2 is open",			// 106
        "Watchman 21 must be activated",		// 107
        "Door A8 was opened",				// 108
        "Watchman 22 must be released",			// 109
        "Door A8 switch 1 is open",			// 110
        "Door A8 switch 2 is open",			// 111
        "Watchman 23 must be activated",		// 112
        "Panic button 24 was pressed",			// 113
        "Door A9 was opened", 				// 114
        "Watchman 24 must be released",			// 115
        "Watchman 25 must be activated",		// 116
        "Door A9 switch 1 is still open", 		// 117
        "Door A9 switch 2 is still open",		// 118
        "Panic button 38 was pressed",			// 119
        "Door A12A was opened",				// 120
        "Watchman 38 must be released",			// 121
        "Watchman 39 must be activated",		// 122
        "Door A12A switch 1 is still open",		// 123
        "Door A12A switch 2 is still open",		// 124
        "Panic button 36 was pressed",			// 125
        "Door A15 was opened",				// 126
        "Watchman 36 must be released",			// 127
        "Watchman 37 must be activated",		// 128
        "Door A15 switch 1 is still open",		// 129
        "Door A15 switch 2 is still open",		// 130
        "Panic button 18 was pressed",			// 131
        "Panic button 20 was pressed",			// 132
        "Panic button 22 was pressed",			// 133
        "Panic button 30 was pressed",			// 134
        "Panic button 32 was pressed",			// 135
        "Panic button 9a was pressed",			// 136
        "Gate 5A was opened",				// 137
        "Watchman 9a must be released",			// 138
        "Watchman 9b must be activated",		// 139
        "Gate 5A switch 1 is still open",		// 140
        "Gate 5A switch 2 is still open" ,		// 141
        "Area A13A is not cleared",			// 142
        "Watchman 11 must be released",			// 143
        "The roof is open",				// 144
        "Experimental vault 2 roof is open",    	// 145
        "The roof or Gate G8 is open",			// 146
        "A12, A9 or A15 is not cleared",		// 147
        "Gate G9 was opened",				// 148
        "Gate G10 was opened",				// 149
        "Close gate G9",				// 150
        "Close gate G10",				// 151
        "Gate G6 is open",				// 152
        "Door A007 is open",				// 153
        "Panic button 44 was pressed",			// 154
        "Watchman 44 must be released",			// 155
        "Close Gate G6",				// 156
        "Watchman 45 must be activated",		// 157
        "Gate G6a is open",				// 158
        "SPC2 Lower vault not cleared",			// 159
        "Door A3 is open",				// 160
        "Close Door A3",				// 161
        "Gate G6a is open",				// 162
        "Watchman 46 must be released",			// 163
        "Watchman 47 must be activated",		// 164
        "Watchman 47 must be released",			// 165
        "Watchman 48 must be activated",		// 166
        "Door A3A is open",				// 167
        "Close Door A3A",				// 168
        "Door A2 is Open", 				// 169
        "Door A001 is Open",				// 170
        "Door A005A is Open",				// 171
        "Door A005 is Open",				// 172
        "Watchman 40 must be released",			// 173
        "Watchman 41 must be released",			// 174
        "Watchman 41 must be activated",		// 175
        "Watchman 42 must be released",			// 176
        "Watchman 42 must be activated",		// 177
        "Close Door A005",				// 178
        "Watchman 43 must be activated",		// 179
        "Close Gate G7",				// 180
        "Gate G7 is Open",				// 181
        "SPC1 upper vault not cleared",			// 182
        "Panic button 40 was pressed",			// 183
        "Panic button 42 was pressed",			// 184
        "SPC1 roof is open",    	                // 185
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

