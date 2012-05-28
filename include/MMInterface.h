

// Copyright (c) 12-Mar-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef MMINTERFACE_H 
#define MMINTERFACE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

enum
{
    MMINTERFACE_ID_BASE = 0x00000100,

    MMINTERFACE_ID_CONTROLLABLE = (MMINTERFACE_ID_BASE + 1) ,

    MMINTERFACE_ID_DISPLAY_CONTROL,

    MMINTERFACE_ID_METADATA_CONTROL,

    MMINTERFACE_ID_MIDI_CONTROL,

    MMINTERFACE_ID_PITCH_CONTROL,

    MMINTERFACE_ID_SNAPSHOT_CONTROL,

    MMINTERFACE_ID_RECORD_CONTROL,

    MMINTERFACE_ID_STOPTIME_CONTROL,

    MMINTERFACE_ID_TONE_CONTROL,

    MMINTERFACE_ID_VOLUME_CONTROL,

    MMINTERFACE_ID_EFFECT_CONTROL,

    MMINTERFACE_ID_CAMERA_CONTROL,

    MMINTERFACE_ID_EXPOSURE_CONTROL,

    MMINTERFACE_ID_FLASH_CONTROL,

    MMINTERFACE_ID_FOCUS_CONTROL,

    MMINTERFACE_ID_ZOOM_CONTROL,

    MMINTERFACE_ID_AUDIO_CONTROL,

    MMINTERFACE_ID_AUDIOEFFECT_CONTROL,

    MMINTERFACE_ID_FORMAT_CONTROL,

    MMINTERFACE_ID_MEMORY_CONTROL,

    MMINTERFACE_ID_SHUTTERFEEDBACK_CONTROL,

    MMINTERFACE_ID_IMAGETRANSFORM_CONTROL,

    MMINTERFACE_ID_IMAGEEFFECT_CONTROL,

    MMINTERFACE_ID_OVERLAY_CONTROL,

    MMINTERFACE_ID_TEMPO_CONTROL,

    MMINTERFACE_ID_IMAGEFORMAT_CONTROL,

    MMINTERFACE_ID_VIDEOFORMAT_CONTROL,

    MMINTERFACE_ID_RATE_CONTROL,

    MMINTERFACE_ID_DVBHTRACK_CONTROL,

    MMINTERFACE_ID_AUDIOFORMAT_CONTROL,

    MMINTERFACE_ID_CAMERAVFDATA_CONTROL,

    MMINTERFACE_CONTROL_END,

    MMINTERFACE_ID_PLAYER,

    MMINTERFACE_ID_PLAYER_LISTENER,

    MMINTERFACE_ID_MEDIA_EXTRACTOR,

    MMINTERFACE_ID_MEDIA_PROCESSOR_LISTENER,

    MMINTERFACE_END

};

typedef int MMInterface;

#endif  