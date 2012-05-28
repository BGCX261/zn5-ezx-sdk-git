//--------------------------------------------------------------------------------------------------
//
//   Header Name: ZSkinSerivce.h
//
//   General Description: Defined the ZSkinService class.
//
//--------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                      (c) Copyright Motorola 2004, All Rights Reserved
//
//                     Template ID and version: TMP_LFC_50115 Version 1.1
//
// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description of Changes
// -------------------------   ------------    ----------   ----------------------------------------
// Developer Name/ID            MM/DD/YYYY     LIBXXXXXXX   BRIEF description of changes made
// Jack Zhao/w20997             02/04/2005                  Initial version
// Luwei /e2548c                11/29/2005                  for FSBA
//
//
//--------------------------------------------------------------------------------------------------

#ifndef __ZSKINSERVICE_H__
#define __ZSKINSERVICE_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//#ifdef MAKE_UISTYLE_CHAMELEON

//--------------------------------------------------------------------------------------------------
//                                       INCLUDE FILES
//--------------------------------------------------------------------------------------------------
#include <qstring.h>
#include <qlist.h>
#include <qmap.h>
#include <qpixmap.h>
#include <qfile.h>
#include <qapplication.h>
#include <ZWidgetSkinProps.h>
#include <ZConfig.h>

struct SkinInfo
{
    QString name;
    QString dir;
    QPixmap previewPixmap;
};

struct WidgetSkinInfo
{
    QString backgroundPixmapID;
    QString borderPixmapID;
    void* extProps;
};

typedef QList<struct SkinInfo> SkinInfoList;
typedef QListIterator<struct SkinInfo> SkinInfoListIt;
typedef QMap<QString, ZBASIC_SKINNABLE_PROP_T *> ZBasicSkinPropsMap;

class ZConfig;
class QStringList;
class ZSkinService
{
public:
    /**
     * constructor, initialize member
     * @param app is the application executive, similar to argv[0]
     */
    ZSkinService(const char *app = NULL)
    {
        ref ++;
        if (app)
        {
            this->appName = new QCString(app);
            //updateAppCommonSkin();
        }
	this->screenProps = NULL;
    }

    ~ZSkinService()
    {
        ref --;
        if (!ref)
        {
            if (appName)
            {
                delete appName;
                appName = NULL;
            }
            if (theme)
            {
                delete theme;
                theme = NULL;
            }
            if (device)
            {
                delete device;
                device = NULL;
            }
        }
	if (screenProps)
        {
	    delete screenProps;
	    screenProps = NULL;
        }
    }
    /**
     * @enum WidgetClsID
     */
    enum WidgetClsID
    {
        clsZAlternatesChooser,
        clsZAlternatesItem,
        clsZAlternatesList,
        clsZAppInfoArea,
        //modify by hongwei
        clsZCalendarModule,
        clsZCalendarModule_Day,
        clsZCalendarModule_CurDay,
        clsZCalendarModule_DayHeader,
        clsZCalendarModule_CurDayHeader,
        clsZCalendarModule_EmptyDay,
        clsZCalendarModule_Grid,
        //end by hongwei
        clsZCheckBox,
        clsZColorModule,
        clsZColorModule_Cname,
        clsZColorModule_Well,
        clsZColorPicker,
        clsZColorPicker_Well,
        clsZComboBox,
        clsZDateModule,
        clsZTimeModule = clsZDateModule,
        clsZNumModule = clsZDateModule,
        clsZDatePicker,
        clsZTimePicker = clsZDatePicker,
        clsZNumPicker = clsZDatePicker,
        clsZExhibitButton,
        clsZFiveWayButton1,
        clsZFiveWayButton2,
        clsZFormContainer,
        clsZFormItem,
        clsZGroupBox,
        clsZHeader1,
        clsZHeader2,
        clsZHeader3,
        clsZHeader4,
        clsZHeaderPopup,        // used by dialog, add by Zhang Rongkang - e2720c
        clsZIconView1,
        clsZIconView2,
        clsZIconViewItem1,
        clsZIconViewItem2,
        clsZInputMatrix,
        clsZInteractiveHighlight,
        clsZJumpBox,
        clsZJumpBox_Field,
        clsZLineEdit,
        clsZListBox1,
        clsZSettingView1 = clsZListBox1,
        clsZListBox2,
        clsZSettingView2 = clsZListBox2,
        clsZListItem1,
        clsZListItem2,
        clsZMatrixItem,
	//dy modified begin
        clsZMeter,
        clsZMeter_Indicator1,
        clsZMeter_Indicator2,
        clsZMeter_Indicator3,
	clsZMeter_Indicator4 = clsZMeter_Indicator3,  //same as indicator3, just change a pixmap for animation
	//dy modified end
        clsZMeterModule,
        clsZSliderModule = clsZMeterModule,
        clsZProgressSliderModule = clsZMeterModule,
        clsZMultiLineEdit1,
        clsZMultiLineEdit2,    //dy added
        clsZNavTabWidget,
	clsZNavTabWidget_TabArea,
        clsZOptionsMenu,
        clsZOptionsMenuItem,
        clsZPanel1,
        clsZPanel2,
        clsZPopup1,
        clsZPopup2,           //dy added
//      clsZPopup3,
        clsZPressButton,
        clsZRadioButton,
        clsZScrollPanel,
        clsZScrollView = clsZScrollPanel,
        clsZSegmentField,
        clsZSeparator1,
        clsZSeparator2,
        clsZSettingItem,
        clsZSlider,
        clsZProgressSlider = clsZSlider,
        clsZSoftKeyLeft,
        clsZSoftKeyRight,
	clsZSoftKeyMiddle,     //dy added
        clsZSplitPane,
	//dy added begin
        clsZDetailView1,
	clsZDetailView2,
	clsZDetailItem,
	clsZImageContainer,
        clsZImageContainer1,
	clsZImageContainer2,
	//clsZImageContainer4,
	clsZMediaControl,
	clsZScrollbar,
	clsZScrollbar_Input,
	clsZScrollbar_Field,
        clsZStructDataImage,
	clsZFsba1,
	clsZFsba2,
	//dy added end
        clsMax = clsZFsba2,
        clsTotal = clsMax + 1
    };

    typedef WidgetClsID SkinStyle;

    /**
     * Get the file name of the application specific skin in current theme skin.
     *
     * @param appName Name of the executable file of the application.
     *
     * @return The file name of the application specific skin.
     */
    QString getAppThemeSkinFile( const QString & appName );

    /**
     * Get the file name of the application specific skin in device skin.
     *
     * @param appName Name of the executable file of the application.
     *
     * @return The file name of the application specific skin.
     */
    QString getAppDeviceSkinFile( const QString & appName );

    /**
     * Get basic skinnable properties.
     * 2 conditions:
     * 1. if screenProps is NULL then return appname_c base props
     * 2. if screenProps is not NULL then return appname_p base props
     * @param clsId Id of the class.
     * @return Pointer to the structure that contains the properties.
     */
    const ZBASIC_SKINNABLE_PROP_T * const getBasicSkinnableProps(
        const enum WidgetClsID clsId ) const;

    /**
     * Get all the theme skin information.
     *
     * @param list List of the information of the theme skins.
     */
    void getSkinInfoList( SkinInfoList & list );

    /**
     * Get skin name by directory, return current ThemeSkin name
     * if the dir is empty.
     *
     * @param dir Directory of the theme skin.
     *
     * @return Name of the skin.
     */
    QString getSkinName( const QString &dir = QString::null );

    /**
     * Get a font object in terms of Skin font ID
     * 
     * @param fontID The Skin font property ID
     * @return a font object mapping to the font ID
     * @note The returned font object has the same font family as the
     * QApplication font
     */
    QFont getSkinFont(const FONT_INFO_T & ftInfo);
    
    /**
     * Get pointer to all the skinnable properties.
     *
     * @return Pointer to all the skinnable properties.
     */
    static const struct ZWidgetSkinProps * const getAllSkinnableProps();

    /**
     * Update share memory when current theme skin changes.
     * @param themeSkinDir is the current ThemeSkin directory
     */
    void updateThemeSkin(const QString themeSkinDir = QString::null);

    /**
     * Update application common skin.
     *
     * @warning Application developers, please don't use this function.
     * @ZApplication will call it to overwrite
     *    device.ini/common.ini setting with unique screen _p setting.
     */
     void updateAppCommonSkin( ZWidgetSkinProps *props );

     /**
     * Update application unique screen skin.
     *
     * @ Application developers, please use this function to overwrite
     *    appname_c setting with unique screen _p setting.
     * @param uScreenCfgName is the name of unique screen _p.ini
     */
     void updateAppScreenSkin( QString uScreenCfgName );

     /**
     *  get all the skinnable properties
     *  2 conditions :
     * 1. if screenProps is NULL then return appname_c setting
     * 2. if screenProps is not NULL then return unique screen _p setting
     */
     ZWidgetSkinProps * getEntireSkinnableProps();

    /**
     * Read number entry from skin files
     *
     * @param device ZConfig object for device skin.
     * @param theme ZConfig object for theme skin.
     * @param section Section in the ini file.
     * @param tag Tag name in the ini file.
     * @param dft Default value.
     *
     * @return Value of the tag. If tag doesn't exist, dft is returned.
     */
    int readNumEntryFromSkin(
        ZConfig & device,
        ZConfig & theme,
        const QString & section,
        const QString & tag,
        const int dft = -1 );

    /**
     * Read number entry from skin files
     *
     * @param section Section in the ini file.
     * @param tag Tag name in the ini file.
     * @param dft Default value.
     *
     * @return Value of the tag. If tag doesn't exist, dft is returned.
     */
    int readNumEntryFromSkin(
        const QString & section,
        const QString & tag,
        const int dft = -1 );

    /**
     * Read string entry from skin files
     *
     * @param device ZConfig object for device skin.
     * @param theme ZConfig object for theme skin.
     * @param section Section in the ini file.
     * @param tag Tag name in the ini file.
     * @param dft Default value.
     *
     * @return Value of the tag. If tag doesn't exist, dft is returned.
     */
    QString readStringEntryFromSkin(
        ZConfig & device,
        ZConfig & theme,
        const QString & section,
        const QString & tag,
        const QString & dft = QString::null );

    /**
     * Read string entry from skin files
     *
     * @param section Section in the ini file.
     * @param tag Tag name in the ini file.
     * @param dft Default value.
     *
     * @return Value of the tag. If tag doesn't exist, dft is returned.
     */
    QString readStringEntryFromSkin(
        const QString & section,
        const QString & tag,
        const QString & dft = QString::null );

    /**
     * Get the member of appName
     * @return the application name of AppSkin
     */
    QCString getAppName();

    /**
     * Set the member of appName
     * @param str the application name of AppSkin
     */
    void setAppName(const char * str);

    /**
     * Get all widget skinnable properties. include background and border pixmap
     * 2 conditions:
     * 1. if screenProps is NULL then return appname_c base props
     * 2. if screenProps is not NULL then return appname_p base props
     * @param clsId Id of the class.
     * @return structure that contains the properties.
     */
    WidgetSkinInfo getWidgetSkinInfo(const WidgetClsID clsId);

protected:

private:

    ZBASIC_SKINNABLE_PROP_T * internalGetBasicSkinnableProps(
        const enum WidgetClsID clsId,
        ZWidgetSkinProps * pProps = NULL ) const;

    ZConfig* ZSkinService::getThemeConfig();
    ZConfig* ZSkinService::getDeviceConfig();

    static QCString *appName;
    static ZConfig *theme;
    static ZConfig *device;
    static int ref;
    ZWidgetSkinProps * screenProps;
};

inline const ZBASIC_SKINNABLE_PROP_T * const ZSkinService::getBasicSkinnableProps(
    const enum ZSkinService::WidgetClsID clsId ) const
{
    return internalGetBasicSkinnableProps( clsId );
}

inline QFont ZSkinService::getSkinFont(const FONT_INFO_T & ftInfo)
{
    QFont ret = qApp->font();

    ret.setBold( ftInfo.style & fsBold ? true : false );
    ret.setItalic( ftInfo.style & fsItalic ? true : false );
    ret.setUnderline( ftInfo.style & fsUnderline ? true : false );
    ret.setStrikeOut( ftInfo.style & fsStrikeOut ? true : false );
    ret.setPointSize( ftInfo.size );
    
    return ret;
}

inline QCString ZSkinService::getAppName()
{
    if (!appName)
    {
        appName = new QCString(qApp->argv()[0]);
    }
    return appName->copy();
}

inline void ZSkinService::setAppName(const char * str)
{
    if (appName)
    {
        *appName = str ;
    }
    else
    {
        appName = new QCString(str);
    }
}

inline ZConfig* ZSkinService::getThemeConfig()
{
    if (theme==NULL)
    {
        QString themeConfigFileName = getAppThemeSkinFile( getAppName() );
        if (QFile(themeConfigFileName).exists())
        {
            theme = new ZConfig(themeConfigFileName);
        }
    }
    return theme;
}

inline ZConfig* ZSkinService::getDeviceConfig()
{
    if (device == NULL)
    {
        QString devConfigFileName = getAppDeviceSkinFile( getAppName() );
        //TODO: Device INI must be existing, the below decision is not necessary
        if (QFile(devConfigFileName).exists())
        {
            device = new ZConfig(devConfigFileName);
        }
    }
    return device;
}

//#endif  // #ifdef MAKE_UISTYLE_CHAMELEON

//--------------------------------------------------------------------------------------------------
#endif  // __ZSKINSERVICE_H__
