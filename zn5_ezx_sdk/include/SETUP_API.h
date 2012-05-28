#include <qstring.h>
#include <qpixmap.h>
enum ENUM_USB_STATUS_E
{
STATUS1,
STATUS2
};
class SETUP_API
{
	int data[1];
public:
	enum ENUM_ALERT_TYPE_E
	{
	Type1,
	Type2
	};

	enum ENUM_ALERT_STYLE_E
	{
	STYLE1,
	STYLE2
	};
	enum ENUM_PRELOADED_PROFILES_E
	{
	PROFILES1,
	PROFILES2
	};
	enum ENUM_VIBRATE_TYPE_E{TYPE1,TYPE2};
	enum ENUM_ALERT_SOUND_TYPE_E
	{TYPe1,TYPe2};
	
	int getLanguage(QString&);
	int getAlertFile(ENUM_ALERT_TYPE_E, QString&, int);
	int getAPVersion(QString&);
	int getUSBStatus(ENUM_USB_STATUS_E&);
	QPixmap getWallpaper(QString&);
	bool setUSBStatus(ENUM_USB_STATUS_E);
	bool setWallpaper(QString);
	int getAlertStyle(ENUM_ALERT_STYLE_E&, int);
	int getSoundVolume(ENUM_ALERT_SOUND_TYPE_E, int&, int);
	int getActiveProfile(int&);
	bool setActiveProfile(ENUM_PRELOADED_PROFILES_E);
	int getVibratePattern(ENUM_ALERT_TYPE_E, ENUM_VIBRATE_TYPE_E&, int);
};
