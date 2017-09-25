// -------------- ADIS16227 Buffers --------------------------------//

// Define Three Data Buffers
short int X_DATA[512]; 		   	// 16 bit
short int Y_DATA[512]; 		   	// 16 bit
short int Z_DATA[512]; 		   	// 16 bit

// Define Three FFT Average Buffers (accumulate FFTs)
unsigned short X_FFT[256]; 		// 16 bit
unsigned short Y_FFT[256]; 		// 16 bit
unsigned short Z_FFT[256];		// 16 bit

// -------------- ADIS16227 User Registers -------------------------//
enum user_regs
{
	ENDURANCE 			= 0x0000,
	X_NULL 				= 0x0200,
	Y_NULL				= 0x0400,
	Z_NULL				= 0x0600,

	REC_FLSH_CNT		= 0x0800,
	SUPPLY_OUT			= 0x0A00,
	TEMP_OUT			= 0x0C00,
	FFT_AVG				= 0x0E00,
	BUF_PNTR			= 0x1000,
	REC_PNTR			= 0x1200,
	X_BUF				= 0x1400,
	Y_BUF				= 0x1600,
	Z_BUF				= 0x1800,
	REC_CNT				= 0x1A00,
	REC_CTRL			= 0x1C00,
	REC_PRD				= 0x1E00,

	ALM_F_LOW			= 0x2000,
 	ALM_F_HIGH			= 0x2200,
	ALM_X_MAG1			= 0x2400,
	ALM_Y_MAG1			= 0x2600,
	ALM_Z_MAG1			= 0x2800,
	ALM_X_MAG2			= 0x2400,
	ALM_Y_MAG2			= 0x2600,
	ALM_Z_MAG2			= 0x2800,
	ALM_PNTR			= 0x3000,
	ALM_S_MAG			= 0x3200,
	ALM_CTRL			= 0x3400,
	DIO_CTRL			= 0x3600,
	GPIO_CTRL			= 0x3800,
	dummy0				= 0x3A00, // 2 bytes
	STATUS	 			= 0x3C00,
	COMMAND				= 0x3E00,

	ALM_X_STAT			= 0x4000,
	ALM_Y_STAT			= 0x4200,
	ALM_Z_STAT			= 0x4400,
	ALM_X_PEAK			= 0x4600,
	ALM_Y_PEAK			= 0x4800,
	ALM_Z_PEAK			= 0x4A00,
	TIME_STAMP			= 0xFFFFFFFF,	// 32 bit time stamp, in seconds
	dummy1				= 0xFF00,		// reserved, 2 bytes
	REV					= 0x5200,
	DATE				= 0x5300,
	MONTH				= 0x5400,
	YEAR				= 0x5500,
	PROD_ID				= 0x5600,
	SCRATCH_A			= 0x5800,
	SCRATCH_B			= 0x5A00,
	dummy2				= 0xFF00,		// reserved, 20 bytes
	ALM_X_FREQ			= 0x7000,
	ALM_Y_FREQ			= 0x7200,
	ALM_Z_FREQ			= 0x7400,
	REC_INFO			= 0x7600
};
