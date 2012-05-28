//--------------------------------------------------------------------------------------------------
//
//   Header Name: ZSkinHelper.h
//
//   General Description: Defined the ZSkinHelper class, which corresponds to skinnable functions.
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
// Liu Chao/e2472c              09/27/2005                  Initial version
//
//
//--------------------------------------------------------------------------------------------------


#ifndef __ZSKINHELPER_H__
#define __ZSKINHELPER_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//--------------------------------------------------------------------------------------------------
//                                    INCLUDE FILES
//--------------------------------------------------------------------------------------------------

#include <qstring.h>
#include <qpixmap.h>
#include <qfont.h>
#include <qpainter.h>
#include <qwidget.h>
#include <ZSkinService.h>
#include "ZSkinTool.h"
//--------------------------------------------------------------------------------------------------
//                                    CLASS ZSkinHelper
//--------------------------------------------------------------------------------------------------

class ZSkinHelper
{
  public:
    struct BorderPixmaps
    {
        QString id;
        QPixmap left;
        QPixmap right;
        QPixmap top;
        QPixmap bottom;
        QPixmap topLeft;
        QPixmap topRight;
        QPixmap bottomLeft;
        QPixmap bottomRight;
    };

    enum BorderType 
    {
       Empty_Border = 0, 
       Color_Border, 
       Pixmap_Border
    };
    
    enum BorderSide
    {
       BorderLeft = 0,
       BorderTop,
       BorderRight,
       BorderBottom
    };

    enum BackgroundType 
    {
       Empty_Background = 0, 
       Color_Background, 
       Pixmap_Background
    };

    enum SelectionState
    {
        StStandard = 0,
        StHighlighted,
        StSelected,
        StHighlightSelected,
        StateCount = StHighlightSelected + 1
    };

  public:
     
     /**
      *  Constructor of ZSkinHelper.
      *  @param w The widget that is inherited from ZSkinHelper.
      *  @param clsId The id of the style that the widget will use. Default value
      *  indicates none Skin.
      */
     ZSkinHelper(QWidget& w, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal, 
               bool isWidget = TRUE);

     /**
      *  Destructor of ZSkinHelper.
      */
     virtual ~ZSkinHelper();

     /**
      * Update the system's skin, call this function when the theme have changed.
      * if a widget has own skinnable properitis, it need reimplment this function,
      */
     void updateSkin();   

     /**
      * Get the skinnable property padding.
      */
     const WIDGET_PADDING_INFO_T & padding() const;

     /**
      * Set the skinnable property padding.
      * @param padding New value for setting the padding of the widget.
      */
     void setPadding( const WIDGET_PADDING_INFO_T & padding );
     
     /**
      * Get the state of widget. 
      */
     const SelectionState selectionState() const;

     /**
      * Set the state of widget, called only by widget developers.
      * @param state The new state of the widget.
      */
     void setSelectionState( const SelectionState state );
        
     /**
      * Set the blending percent.
      * @param percent Value is from 0 to 100.
      */
      void setBlendingPercent(uint percent);
  
     /**
      * Get the blending percent.
      */
      uint getBlendingPercent();

     /**
      * Set the border of widget.
      * @param borderItems a array that includes all border information,
      */
     void setZBorder( WIDGET_BORDER_INFO_T borderItems[StateCount]);

     /**
      * Get the border's width.
      * @param side The side that need to get its width.
      */
     int getBorderWidth(BorderSide side = BorderLeft) const; 

     /**
      * Set the background of widget.
      * @param bckgroundItems a array that includes all background information.
      */
     void setZBackground(WIDGET_BACKGROUND_INFO_T bckgroundItems[StateCount]);

    /**
     * Set a pixmap as the background and all state will use this pixamp.
     * @param image A image will be set as the background.
     */
    void setZBackground(QPixmap& image);

    /**
     * Cancel the user setting background.
     */
    void unsetZBackground();

  
     /**
      *  Get the skinnable proprities.
      */
     void* getProps() const {return extProps;}


    /**
     * set the widget that connect to ZSkinHelper.
     */
     void setSkinWidget(QWidget& w) {widget = &w;}

    /**
     * get the widget that connect to ZSkinHelper.
     */
    QWidget* getSkinWidget() const {return widget;}

    /**
     * Set the blending shift value, called only by widget developers.
     * @param x X shift value.
     * @param y Y shift value.
     */
    void setBlendingTranslate(int x, int y) {dx = x; dy = y;}

    /**
     * Set the pixmap id of background and border.
     * @param background The background pixmap id, if it is NULL, the background will not change.
     * @param border The border pixmap id, if it is NULL, the border will not change.
     */
    void setPixmapID(QString background, QString border);

    /** Set the prefix of the pixmap names of the background and border fow a application.
     *  @param prefix A string to add at the head of image name that are read from skin data file.
     */
    static void setPixmapPrefix(QString& prefix );

    /** Set the prefix of the pixmap names of the background and border for a widget.
     *  @param prefix A string to add at the head of image name that are read from skin data file.
     */
    void setWidgetPixmapPrefix(QString& prefix );

    /** Get the type of background.
     */
    BackgroundType getBackgroundType() const;

    /** Get the type of border.
     */
    BorderType getBorderType() const;

    /** Enable/Disable background's cache
     *  @param enable true set enable, otherwise set disable.
     */
    void enableCache(bool enable){mCachePixmap = enable;}

    /** Whether the current language's layout is from left to right.
     */
    bool isLeftToRightLanguage();


  protected:

     /**
      * Draw a border in the current widget.
      */
     void drawBorder(QPainter& painter, const QRect* rect = NULL);

     /**
      * Call this function to draw the background of the widget.
      * @param painter A paint device.
      * @param rect The rectangle in that background will be drawed.
      * @param border TRUE minus the region of border.
      */
     void drawBackground(QPainter& painter, const QRect* rect = NULL, bool border = TRUE);


     void stretchPixmap(QPixmap& pm, int width, int height, PIXMAP_STRETCH_POLICY_E type, bool must = false);
     void fillRect(QPainter& painter, QRect rect, QColor& color);
     void* getPixmapIDs(int&backgroundPixmapID, int&borderPixmapID);

  private:

     /**
      * Empty the border of the widget.
      *
      */
     void initBorder();

     /**
      * Set a color as the border of the widget.
      * @param width The border's new width.
      * @param color the color will be used to draw the border.
      */
     void initBorder(int width, const QColor & color);

     /**
      * Set a pixmap as border of the widget.
      * @param pixmapID the name of the border image.
      *        For a border have eight images, it is the main part of these names.
      *        For example, a list box has border images that named TopLeftListBox.bmp
      *        LeftListBox.bmp, RightListBox.bmp, TopListBox.bmp...., only need pass 
      *        ListBox.bmp as the param value.
      */
     void initBorder(const QString & pixmapId);

     /**
      * Empty the background of the widget.
      */
     void initBackground();

     /**
      * Set a color as the background.
      * @param color The color will to be used to draw a background.
      */
     void initBackground(const QColor& color);

     /**
      * Set a pixmap as the background.
      * @param pmID The name of the background image name.
      */
     void initBackground(const QString& pmID);

     /**
      * Get the skin ID.
      */
     const ZSkinService::WidgetClsID skinClsID() const;

     /**
      * Get the system wallpaper
      */
     QPixmap* ZSkinHelper::getWallPaper(QPainter& painter) const;

     QString getPixmapNameByState() const;
    
     void drawPixmap(QPainter& painter, QRect rect, QPixmap& pixmap);
     void drawPixmap(QPainter& painter, int x, int y, QPixmap& pixmap);

  protected:
    uint    own_padding : 1;
    uint    own_background : 1;
    uint    own_private_bg : 1;
    uint    own_border : 1;
    uint    own_percent : 1;

    uint    mIsWidget : 1;
    uint    mCachePixmap :1;

    ZSkinService::WidgetClsID mClsID;

    short mBgPercent;
    short mSelectionState;

    static QString mPrefix;
    QString mWidgetPrefix;

    QString backgroundPixmapID;
    QString borderPixmapID;
    void* extProps; 

    WIDGET_BACKGROUND_INFO_T * ownBackgroundItems;
    WIDGET_BORDER_INFO_T * ownBorderItems;

    QPixmap* mBgPixmap;
    WIDGET_PADDING_INFO_T* mPadding;

    short dx;
    short dy;

    QWidget* widget;
};


#endif
