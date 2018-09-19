#include <string.h> // man function_name(man strcpy) to find header
#include <stdio.h>

#ifndef VCS_PROC_H
#define VCS_PROC_H

#define ERROR 	"\033[31;1m"	// red background
#define OK		"\033[33;1m" 	// yellow background
#define CLR		"\033[32;1m"  	// green background
#define DEF     "\033[0m"    	// white background

static const char* mes_array[195] = {
		"",										// 0 it is a requirement that this array first element be an empty string
		"CLEARED",				        		// 1
		"NOT CLEARED",							// 2
        "CLEAR UNDERWAY",						// 3
        "ERROR", 				        		// 4
        "CLEAR FAILED", 						// 5
        "TIME OUT ERROR: RELEASE ALL WATCHMEN", // 6
		/// SPC1 VAULTS interlocks  /////////////////	
 		"SPC1 roof is open",    				// 7 
        "Door A2 is Open", 						// 8
        "Watchman 40 must be released",			// 9
        "Close Gate G7",						// 10
        "Gate G7 is Open",						// 11
        "Watchman 41 must be released",			// 12
		"Panic Button 40 was activated",        // 13
 		"SPC1 vault roof is open",    			// 14
        "SPC1 upper vault not cleared",			// 15
        "Door A005A is Open",					// 16
        "Door A001 is Open",					// 17
		"Watchman 42 must be released",			// 18
        "Door A005 is Open",					// 19
        "Door A005 switch 1 is open",			// 20
        "Door A005 switch 2 is open",			// 21
        "Close Door A005",						// 22
        "Watchman 43 must be activated",		// 23
        "Panic button 42 was pressed",			// 24
		/// SSC cable passageway interlocks ////
        "Gate A001A was opened",				// 25
        "Gate A001A switch 1 is open",			// 26
        "Gate A001A switch 2 is open",			// 27
        "Watchman 16 must be released",			// 28
        "Gate G5 was opened",					// 29
        "Waiting on G5 switch 1 to close",		// 30
        "Waiting on G5 switch 2 to close",		// 31
        "Watchman 17 must be activated",		// 32
        "Panic button 16 was activated",		// 33
        /// SSC basement interlocks //////////////////
        "SSC cable labyrinth NOT cleared",		// 34
        "Door A001 was opened",					// 35
        "Door A001 switch 1 is open",			// 36
        "Door A001 switch 2 is open",			// 37
        "Gate G1 was opened",					// 38
        "Gate G1 switch 1 is open",				// 39
        "Gate G1 switch 2 is open",				// 40
        "Hold watchman 1 and press 2",			// 41
        "Hold watchman 1 and release 2",		// 42
        "Hold watchman 1 and press 3",			// 43
        "Hold watchman 1 and release 3",		// 44
        "Hold watchman 1, press and hold 4",	// 45
        "Hold watchman 4 and release 1",		// 46
        "Hold watchman 4 and press 5",			// 47
        "Watchman 1 was released too soon",		// 48
        "Watchman 4 was released too soon",		// 49
        "Release watchman 4 & 5",				// 50
        "Watchman 4 must be released",			// 51
        "Watchman 5 must be released",			// 52
		"Gate G2 must be closed",				// 53
        "Gate G2 was opened",					// 54
        "Gate G2 switch 1 is open",				// 55
        "Gate G2 switch 2 is open",				// 56
        "Watchman 6 must be activated",			// 57
        "A Panic Button in SSC Basement was activated", // 58
		/// SSC GF vault area 1 interlocks ///////////
        "SSC basement is not cleared",			// 59
        "Gate A1A was opened",					// 60
        "Gate A1A switch 1 is open",			// 61
        "Gate A1A switch 2 is open",			// 62
        "Gate A1A switch 3 is open",			// 63
        "Gate A1A switch 4 is open",			// 64
		"Watchman 11 must be released",			// 65
        "Gate G3 must be closed",				// 66
        "Gate G3 was opened",					// 67
        "Watchman 12 must be activated",		// 68
        "Panic button 11 was activated",        // 69
		"SSC ground floor roof is open",        // 70
		/// SSC GF vault area 2 interlocks  //////////	
        "SSC Area 1 is not cleared",			// 71
        "Watchman 13 must be released",			// 72 
        "Watchman 14 must be activated", 		// 73
        "Watchman 14 must be released",			// 74
        "Door A1 must be closed",				// 75
        "Gate A1 switch 1 is open",				// 76
        "Gate A1 switch 2 is open",				// 77		
        "Watchman 15 must be activated",		// 78
		"A Panic Button in SSC A2 was activated",// 79
		/// I-LINE(A13A) interlocks     //////////////	
		"Watchman 9a must be released",			// 80
        "Gate 5A was opened",					// 81
        "Gate 5A switch 1 is still open",		// 82
        "Gate 5A switch 2 is still open" ,		// 83	
        "Watchman 9b must be activated",		// 84
        "Panic button 9a was pressed",			// 85
		/// BEAM EXTRACTION(A13) interlocks //////////
        "Area A13A is not cleared",			    // 86		
        "Watchman 9 must be released",			// 87
        "Watchman 8 must be activated",			// 88
        "Watchman 8 must be released",			// 89
        "Door A13 was opened",					// 90
        "Door A13 switch 1 is still open",		// 91
        "Door A13 switch 2 is still open",		// 92
        "Watchman 7 must be activated",			// 93
		"Beam extraction vault roof is open",   // 94
        "A Panic Button in IBL was activated",  // 95
		/// EXPERIMENTAL VAULT interlocks  ///////////
        "Close gate G9",						// 96
        "Gate G9 was opened",					// 97
        "Watchman 26 must be released",			// 98
        "Close gate G10",						// 99
        "Gate G10 was opened",					// 100
        "Watchman 28b must be activated",		// 101
        "Watchman 28a must be activated",		// 102
        "Watchman 27 must be activated",		// 103
        "Door A12 switch 1 is still open",		// 104
        "Door A12 switch 2 is still open",		// 105
        "Door A12 was opened",					// 106
        "Watchman 29 must be activated", 		// 107
		"A Panic Button in EXP was activated",  // 108
		"Experimental beamline vault roof is open",//109
		/// EXPERIMENTAL VAULT 1 interlocks  ////////////	
        "Watchman 18 must be released",			// 110
        "Door A6 switch 1 is open",				// 111
        "Door A6 switch 2 is open",				// 112
		"Door A6 was opened",					// 113
        "Watchman 19 must be activated",		// 114	
		"Panic button 18 was activated",       	// 115
		"Experimental vault 1 roof is open",    // 116
		/// EXPERIMENTAL VAULT 2 interlocks  /////////	
        "Watchman 20 must be released",			// 117
        "Door A7 switch 1 is open",				// 118
        "Door A7 switch 2 is open",				// 119
		"Door A7 was opened",					// 120
        "Watchman 21 must be activated",		// 121	
		"Panic button 20 was activated",       	// 122
		"Experimental vault 2 roof is open",    // 123
		/// EXPERIMENTAL VAULT 3 interlocks //////////
        "Watchman 22 must be released",			// 124
        "Door A8 switch 1 is open",				// 125
        "Door A8 switch 2 is open",				// 126
		"Door A8 was opened",					// 127
        "Watchman 23 must be activated",		// 128	
		"Panic button 22 was activated",       	// 129	
		"Experimental vault 3 roof is open",    // 130	
		/// SPECTROMETER VAULT interlocks  ///////////
        "Watchman 24 must be released",			// 131
        "Door A9 switch 1 is still open", 		// 132
        "Door A9 switch 2 is still open",		// 133
        "Door A9 was opened", 					// 134
        "Watchman 25 must be activated",		// 135
        "Panic button 24 was pressed",			// 136
  		"Spectrometer vault roof is open",    	// 137
		/// BEAM SWINGER VAULT interlocks  ////////////
        "Watchman 36 must be released",			// 138
        "Door A15 switch 1 is still open",		// 139
        "Door A15 switch 2 is still open",		// 140
        "Door A15 was opened",					// 141
        "Watchman 37 must be activated",		// 142
        "Panic button 36 was pressed",			// 143
 		"Beam swinger vault roof is open",    	// 144  
		/// NORTHERN PASSAGEWAY of A-BLOCK interlocks ////
        "A12, A9 or A15 is not cleared",		// 145
        "Watchman 38 must be released",			// 146		
        "Door A12A was opened",					// 147
        "Door A12A switch 1 is still open",		// 148
        "Door A12A switch 2 is still open",		// 149
        "Watchman 39 must be activated",		// 150
        "Panic button 38 was pressed",			// 151
		/// SPC2 vault interlocks  ////////////////////
        "Door A007 is open",					// 152
        "Door A3A is open",						// 153
        "Watchman 44 must be released",			// 154
        "Close Gate G6",						// 155
        "Watchman 45 must be activated",		// 156	
        "Panic button 44 was pressed",			// 157
        "SPC2 Lower vault not cleared",			// 158
        "Gate G6a is open",						// 159
        "Watchman 46 must be released",			// 160
        "Watchman 47 must be activated",		// 161
        "Watchman 47 must be released",			// 162
        "Door A3 is open",						// 163
        "Close Door A3",						// 164
        "Door A3 switch 1 is still open",		// 165
        "Door A3 switch 2 is still open",		// 166
        "Watchman 48 must be activated",		// 167		
		"A Panic Button in SPC2 vault was activated", // 168
 		"SPC2 vault roof is open",    			// 169  
		/// Horizontal Beam Line vault interlocks  /////	
        "Watchman 30 must be released",			// 170
        "Door A14 switch 1 is open",			// 171
        "Door A14 switch 2 is open",			// 172
        "Door A14 was opened",					// 173
        "Watchman 31 must be activated",		// 174
        "Panic button 30 was pressed",			// 175
 		"HLI roof is open",    					// 176 	
		/// Vertical Beam Line vault interlocks  //////	
        "Gate G4 was opened",		        	// 177
        "Gate G4 switch 1 is open",				// 178
        "Gate G4 switch 2 is open",				// 179
        "Watchman 32 must be released",			// 180
        "Door A004 switch 1 is open",			// 181
        "Door A004 switch 2 is open",			// 182
        "Door A004 was opened",					// 183
        "Watchman 33 must be activated",		// 184
        "Panic button 32 was pressed",			// 185
		/// TROLLEY PASSAGEWAY A004A interlocks  /////
        "Watchman 34a must be released",		// 186
        "Watchman 34b must be released",		// 187
        "Watchman 34b must be activated",		// 188
        "Door A004A switch 1 is open",			// 189
        "Door A004A switch 2 is open",			// 190
		"Door A004A was opened",				// 191
        "Watchman 35 must be activated",		// 192
        "A Panic Button in TRL vault was activated",// 193
        /// optional
	    "Waiting for Vault Clearance",			// 194
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


