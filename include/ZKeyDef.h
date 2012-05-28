

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef Z_KEYDEF_H
#define Z_KEYDEF_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qnamespace.h>

#define KEYCODE_0                              0x30       // 48
#define KEYCODE_1                              0x31       // 49
#define KEYCODE_2                              0x32       // 50
#define KEYCODE_3                              0x33       // 51
#define KEYCODE_4                              0x34       // 52
#define KEYCODE_5                              0x35       // 53
#define KEYCODE_6                              0x36       // 54
#define KEYCODE_7                              0x37       // 55
#define KEYCODE_8                              0x38       // 56
#define KEYCODE_9                              0x39       // 57
#define KEYCODE_STAR                           0x2a       // 42
#define KEYCODE_POUND                          0x23       // 35

#define KEYCODE_UP                             0x1013     // 4115
#define KEYCODE_DOWN                           0x1015     // 4117
#define KEYCODE_LEFT                           0x1012     // 4114
#define KEYCODE_RIGHT                          0x1014     // 4116
#define KEYCODE_CENTER_SELECT                  0x1004     // 4100

#define KEYCODE_SIDE_UP                        0x1016     // 4118
#define KEYCODE_SIDE_DOWN                      0x1017     // 4119
#define KEYCODE_SIDE_SELECT                    0x1005     // 4101

#define KEYCODE_CLEAR                          0x1032     // 4146

#define KEYCODE_SEND                           0x1030     // 4144
#define KEYCODE_END                            0x1031     // 4145

#define KEYCODE_MSG                            0x1043     // 4163
#define KEYCODE_CARRIER                        0x1033     // 4147
#define KEYCODE_IMAGING                        0x1034     // 4148
#define KEYCODE_VR                             0x1035     // 4149
#define KEYCODE_PTX                            0x1036     // 4150
#define KEYCODE_TASK                           0x103d     // 4157
#define KEYCODE_LSK                            0x1038     // 4152
#define KEYCODE_MSK                            0x1039     // 4153
#define KEYCODE_RSK                            0x103a     // 4154

#define KEYCODE_HOME                           0x103b     // 4155

#define KEYCODE_FLIP                           0x103c     // 4156

#define KEYCODE_POWER                          0x103f     // 4159

#define KEYCODE_VIDEO_CALL	               0x1040     

#define KEYCODE_HEADSET_ANSWER                 0x1044     
#define KEYCODE_HEADSET_INSERT                 0x1045     

#define KEYCODE_JUMP                           0x1048     
#define KEYCODE_PLAY_PAUSE                     0x1049     
#define KEYCODE_STOP                           0x104a     
#define KEYCODE_PREV                           0x104b     
#define KEYCODE_NEXT                           0x104c     
#define KEYCODE_LOCK                           0x103e     

#define KEYCODE_SLIDER                         0x1046     

#define KEYCODE_TS_PREV                        0x104d     
#define KEYCODE_TS_PLAY_PAUSE                  0x104e     
#define KEYCODE_TS_NEXT                        0x104f     

#define KEYCODE_BT_PLAY                        0x1050       
#define KEYCODE_BT_STOP                        0x1051       
#define KEYCODE_BT_PAUSE                       0x1052       
#define KEYCODE_BT_REWIND                      0x1053       
#define KEYCODE_BT_FAST_FORWARD                0x1054       
#define KEYCODE_BT_FORWARD                     0x1055       
#define KEYCODE_BT_BACKWARD                    0x1056
inline bool UTIL_KeyIsBTKey(int keycode){return keycode >=KEYCODE_BT_PLAY && keycode <= KEYCODE_BT_BACKWARD;}

#define KEYCODE_PROXIMITY                      0x4001                           

#define KEYCODE_SHUFFLE                        0x4002     
#define KEYCODE_REPEAT                         0x4003     
#define KEYCODE_ZOOM_OUT                       0x4004     
#define KEYCODE_ZOOM_IN                        0x4005     
#define KEYCODE_CAPTURE_PLAYBACK_TOGGLE        0x4006     
#define KEYCODE_STILL_VIDEO_TOGGLE             0x4007     
#define KEYCODE_EXIT                           0x4008     
#define KEYCODE_FLASH                          0x4009     
#define KEYCODE_TRASH                          0x400a     

#define KEYCODE_OMG_TOUCH                      Qt::Key_Omg_Touch      
#define KEYCODE_OMG_PAGEUP                     Qt::Key_Omg_Pageup     
#define KEYCODE_OMG_PAGEDOWN                   Qt::Key_Omg_Pagedown   
#define KEYCODE_OMG_SCROLL                     Qt::Key_Omg_Scroll     
#define KEYCODE_OMG_STOP                       Qt::Key_Omg_Stop       
#define KEYCODE_OMG_RESUME                     Qt::Key_Omg_Resume     
#define KEYCODE_OMG_RATE                       Qt::Key_Omg_Rate       

#define KEYCODE_SPEAKER                        0x4020                           
#define KEYCODE_AUTO_FOCUS                     0x4021                           
#define KEYCODE_CINGULARVIDEO                  0x4030                           
#define KEYCODE_UNKNOWN                        0xffff                           

typedef enum {
    SYSTEM_FLIP_OPEN = 0,   
    SYSTEM_FLIP_CLOSE       
} SYSTEM_FLIP_STATUS;

typedef enum {
    SYSTEM_SLIDER_OPEN = 0, 
    SYSTEM_SLIDER_CLOSE     
} SYSTEM_SLIDER_STATUS;

typedef enum {
    KEY_MSG_PRESS             = 0x00000001, 
    KEY_MSG_RELEASE           = 0x00000002, 
    KEY_MSG_PRESS_AND_HOLD    = 0x00000004, 
    KEY_MSG_AUTO_REPEAT_FLAG  = 0x10000000  
} KEY_MSG_T;

int UTIL_GetKeyPressAndHoldTime();
int UTIL_GetKeyFirstRepeatTime();
int UTIL_GetTimeBetweenKeyRepeat();

const char * UTIL_GetKeyBypassChannel();
const char * UTIL_GetKeyLockedMessage();
const char * UTIL_GetKeyUnlockedMessage();

void UTIL_BroadcastKeyMsg(int key, int type);

const char * UTIL_GetKeyEventChannel();

const char * UTIL_GetPttKeyChannel();

#endif  
