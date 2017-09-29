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
	ENDURANCE 			= 0x00,
	X_NULL 				= 0x02,
	Y_NULL				= 0x04,
	Z_NULL				= 0x06,

	REC_FLSH_CNT		= 0x08,
	SUPPLY_OUT			= 0x0A,
	TEMP_OUT			= 0x0C,
	FFT_AVG				= 0x0E,
	BUF_PNTR			= 0x10,
	REC_PNTR			= 0x12,
	X_BUF				= 0x14,
	Y_BUF				= 0x16,
	Z_BUF				= 0x18,
	REC_CNTR			= 0x1A,
	REC_CTRL			= 0x1C,
	REC_PRD				= 0x1E,

	ALM_F_LOW			= 0x20,
 	ALM_F_HIGH			= 0x22,
	ALM_X_MAG1			= 0x24,
	ALM_Y_MAG1			= 0x26,
	ALM_Z_MAG1			= 0x28,
	ALM_X_MAG2			= 0x24,
	ALM_Y_MAG2			= 0x26,
	ALM_Z_MAG2			= 0x28,
	ALM_PNTR			= 0x30,
	ALM_S_MAG			= 0x32,
	ALM_CTRL			= 0x34,
	DIO_CTRL			= 0x36,
	GPIO_CTRL			= 0x38,
	dummy0				= 0x3A, // 2 bytes
	DIAG_STAT 			= 0x3C,
	GLOB_CMD			= 0x3E,

	ALM_X_STAT			= 0x40,
	ALM_Y_STAT			= 0x42,
	ALM_Z_STAT			= 0x44,
	ALM_X_PEAK			= 0x46,
	ALM_Y_PEAK			= 0x48,
	ALM_Z_PEAK			= 0x4A,
	TIME_STAMP			= 0xFFFF,	// 32 bit time stamp, in seconds
	dummy1				= 0xFF,		// reserved, 2 bytes
	REV					= 0x52,
	DATE				= 0x53,
	MONTH				= 0x54,
	YEAR				= 0x55,
	PROD_ID				= 0x56,
	SCRATCH_A			= 0x58,
	SCRATCH_B			= 0x5A,
	dummy2				= 0xFF,		// reserved, 20 bytes
	ALM_X_FREQ			= 0x70,
	ALM_Y_FREQ			= 0x72,
	ALM_Z_FREQ			= 0x74,
	REC_INFO			= 0x76
};
