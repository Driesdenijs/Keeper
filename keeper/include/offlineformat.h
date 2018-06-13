/*
 * offlineformat.h
 *
 *  Created on: Jan 5, 2018
 *      Author: dries
 */

#ifndef INCLUDE_OFFLINEFORMAT_H_
#define INCLUDE_OFFLINEFORMAT_H_

#define MAX_NR_ACCESSPROFILES 10
#define RAW_SIZE_ACCESSFILEHEADER 26
#define EXTRA_BYTES_FOR_CRC 6

typedef struct
{
		uint8_t Monday : 1;
		uint8_t Tuesday : 1;
		uint8_t Wednesday : 1;
		uint8_t Thursday : 1;
		uint8_t Friday : 1;
		uint8_t Saturday : 1;
		uint8_t Sunday : 1;
		uint8_t isOfficeModeRelated : 1;

		uint16_t StartMinute;
		uint16_t Duration;
}smartIntegoAccessFile_WeekSchedule_t;

#define RAW_SIZE_WEEKSCHEDULE 4

typedef  enum{
	unknown = -1,
	ListOfGroupId = 0,
	BitVectorGroup = 1,
	BitVectorLock = 2
}AccessProfile_ProfileType_t;

#define	ACCESSHEADER_COLOR 		"\x1B[94m"
#define ACCESSPROFILE_HEADER_COLOR	"\x1B[92m"
#define ACCESSPROFILE_COLOR		"\x1B[96m"
#define UNUSED_COLOR			"\x1B[32m"
#define BLACKLIST_COLOR			"\x1B[36m"


typedef struct __attribute__((packed)) {
	AccessProfile_ProfileType_t ProfileType;
	uint16_t WeekSchedulesCount : 4;	// 4 Bit number of Week Schedules in this profile
	uint16_t MainListWords : 10;			// 10 Bit 1 word = 2 Bytes
	uint8_t ExtraDoorsCount;		// 1 Byte
	uint8_t isLastProfile : 1;			// 1 Bit
	uint8_t NegExceptionsCount : 7;		// 7 Bit
}smartIntegoAccessFile_AccessProfile_header;

typedef struct __attribute__((packed)) {

	uint8_t WeekSchedulesCount;
	uint16_t MainListWords;
	uint8_t ExtraDoorsCount;
	uint8_t isLastProfile;
	uint8_t NegExceptionsCount;
}smartIntegoAccessFile_AccessProfile_count;

#define MAX_NR_WEEKSCHEDULES 15
typedef struct __attribute__((packed)) {
	AccessProfile_ProfileType_t ProfileType;
	uint16_t WeekSchedulesCount : 4;	// 4 Bit number of Week Schedules in this profile
	uint16_t MainListWords : 10;			// 10 Bit 1 word = 2 Bytes
	uint8_t ExtraDoorsCount;		// 1 Byte
	uint8_t isLastProfile : 1;			// 1 Bit
	uint8_t NegExceptionsCount : 7;		// 7 Bit

	//uint16_t * MainList; 			// Bytes: 2 * MainListWords
	//smartIntegoAccessFile_WeekSchedule_t * WeekSchedules[MAX_NR_WEEKSCHEDULES]; 		// Bytes: 4 * WeekSchedulesCount 	n * SI__WeekSchedule 	shows the lock that no further profiles will follow	contents depending on ProfileType
	//uint16_t * ExtraDoors; 			// Bytes: 2 * ExtraDoorsCount List of allowed lock IDs beyond the doors already included in the groups (n.a. when		profile type = 2)
	//uint16_t * NegativeExceptions; 	// Bytes: 2 * NegExceptionsCount Lock IDs where the card has no access, though they are belonging to a matching group (n.a. when profile type = 2)
	//uint16_t totalSize;
}smartIntegoAccessFile_AccessProfile_t;


typedef union{
	uint8_t raw[1];
	struct __attribute__((packed))
	{
		uint8_t upstreamFileContents : 2; 		//2 Bit 0: no upstream file
								//  1: all lists (access, prio, status)
								//  2: no access list
								//  3: no access list and no status list
		uint8_t upstreamFileType : 2; 			//2 Bit see below
		uint8_t isAccessListLongDate : 1; 		//1 Bit
		uint8_t reserved : 3; 					//3 Bit = 0
	};
}smartIntegoAccessFile_CardConf_t;

//Byte orientation in SICA is little endien
typedef union{
	uint8_t raw[2];
	struct __attribute__((packed))
	{
		uint8_t minAccessLogLevel : 2; //2 Bit see text below
		uint8_t noEntryAtAccessListFull  : 1; //1 Bit the card has to be read back by a Gateway / Updater reader when the access list is full be careful with this feature
		uint8_t suppressBeeping  : 1; //1 Bit longCoupling 1 Bit the lock engages the configured long coupling time in the lock
		uint8_t longCoupling  : 1; //1 Bit longCoupling 1 Bit the lock engages the configured long coupling time in the lock
		uint8_t suppressCoupling  : 1; //1 Bit the lock carries out all activities except coupling !applicable where a card is used solely to distribute a blacklist. If the card is applied longer than the office mode time threshold, an uncoupling from Office mode is excuted as well !
		uint8_t toggleDoorState  : 1;
		uint16_t reserved  : 9; //8 Bit = 0
	};
}smartIntegoAccessFile_Conf_t;

typedef union{
  uint8_t FileFormatMajorMinor;
	struct __attribute__((packed)){
		uint8_t FileFormatReleaseMajor : 3;
		uint8_t FileFormatReleaseMinor : 5;
	};
} FileFormatRelease;



typedef union{
	uint8_t raw[RAW_SIZE_ACCESSFILEHEADER];
	struct __attribute__((packed))
	{
		uint32_t CRC32; 						//4 Bytes
	        FileFormatRelease Version;           				//1 Byte
		uint8_t ContentIdentifier; 					//1 Byte not evaluated by the locks, can e.g. enable a Gateway Updater reader to quickly determine which contents is on a	card
		uint16_t AreaID; 						//2 Bytes defines closed area - all access data and upstream data are only valid inside, locks do not accept cards with different area though the card authentication was successful
		smartIntegoAccessFile_Conf_t Conf; 				//2 Bytes SI__Conf
		uint8_t ValidFrom[3]; 						//3 Bytes quarter hours since 1.1.2015
		uint8_t Expiry[3]; 						//3 Bytes quarter hours since 1.1.2015
		smartIntegoAccessFile_CardConf_t CardConf; 			//1 Byte SI__CardConf
		uint16_t BlacklistAddr; 					//2 Bytes if = 0 - no blacklist
		uint8_t reserved[6]; 						//6 Bytes = 0
		uint8_t AccessFileSize_x16; 					//1 Byte Size of the Access File * 16 Bytes
										//Total: 22 Bytes
	};
}smartIntegoAccessFile_AccessFileHeader_t;

typedef struct _smartIntegoAccessFile smartIntegoAccessFile;
typedef smartIntegoAccessFile * smartIntegoAccessFilePtr;
struct _smartIntegoAccessFile{
	smartIntegoAccessFile_AccessFileHeader_t AccessFileHeader;
	//Access Profiles
	smartIntegoAccessFile_AccessProfile_t * AccessProfiles[MAX_NR_ACCESSPROFILES]; //Max 10 access profiles possible;
};

typedef struct __attribute__((packed)) {
	uint16_t L_ID_1;// 2 Bytes ID of the respective Lock
	uint8_t Reason_1;// 4 Bit     0: other reasons
								//1: no matching area (see below)
								//2: card expired
								//3: no matching group or lock ID
								//4: no matching time schedule
								//5: card is black listed
								//6: access list is full ( + noEntryAtAccessListFull
								//is set)
								//7: lock has too low battery
								//8: lock is out of service
	uint32_t TimeStamp_1;	// 28 Bit minutes after 01.01.2015
	uint16_t L_ID_2; 		// 2 Bytes
	uint8_t Reason_2;		// 4 Bit
	uint32_t TimeStamp_2;	// 28 Bit
}smartIntegoUpstreamFile_LastDenied_t;

#endif /* INCLUDE_OFFLINEFORMAT_H_ */
