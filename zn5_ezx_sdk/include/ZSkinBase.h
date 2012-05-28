//--------------------------------------------------------------------------------------------------
//
//   Header Name: ZSkinBase.h
//
//   General Description: Defined the ZSkinBase class, which corresponds to skinnable functions.
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
// Liu Chao/e2472c              01/21/2005                  Initial version
//
//--------------------------------------------------------------------------------------------------


#ifndef __ZSKINBASE_H__
#define __ZSKINBASE_H__

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
#include <qbitmap.h>
#include <qasciicache.h>
#include <string.h>

class QBitArray;
class ZWidget;

//--------------------------------------------------------------------------------------------------
//                                    CLASS ZSkinBase
//--------------------------------------------------------------------------------------------------

class ZSkinBase
{
  public:
	  /*
    class borderPixmapCacheItem {
        public:
        borderPixmapCacheItem( const char *thisId )
        { 
            size_t length = strlen( thisId );
            id = new (char)[ length+1 ];
            strncpy( id, thisId, length );
            id[ length ] = '\0';

            pixmap = NULL;
        };
        ~borderPixmapCacheItem( void )
        {
//            printf( "<----- (%s)\n", id );
            if ( id != NULL )
            {
                delete []id;
            }

            if ( pixmap != NULL )
            {
                delete pixmap;
            }
        };
        char *id;
        QPixmap *pixmap;
    };
	*/

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

    enum BorderSide
    {
       BorderLeft = 0,
       BorderTop,
       BorderRight,
       BorderBottom
    };

  public:
     
     ZSkinBase(ZWidget& w, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal, 
               bool isWidget = TRUE);

     /**
      *  Destructor of ZSkinBase.
      */
     virtual ~ZSkinBase();

     /**
      * Update the system's skin, call this function when the theme have changed.
      * if a widget has own skinnable properitis, it need reimplment this function,
      */
     void updateSkin();   

     /**
      * clear the border pixmap cache - intended to be called when the theme changes
      */
     static void clearBorderPixmapCache(void);

     /**
      * Get the skinnable property padding.
      */
     const WIDGET_PADDING_INFO_T padding() const;

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

     uint getBackgroundBlendingPercent();
     uint getBorderBlendingPercent();

     /**
      * Set the border of widget.
      * @param borderItems a array that includes all border information,
      */
     void setZBorder( WIDGET_BORDER_INFO_T borderItems[StateCount]);

     /**
      * Set the border of widget.
      * @param pixmaps The border's pixmaps;
      */
     void setZBorder( BorderPixmaps& pixmaps);

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
      * Draw a border in the current widget.
      */
     void drawBorder(QPainter& painter, ZWidget& widget, const QRect* rect = NULL, bool realWidget = TRUE);

     /**
      * Call this function to draw the background of the widget.
      * @param painter A paint device.
      * @param rect The rectangle in that background will be drawed.
      * @param border TRUE minus the region of border.
      */
     void drawBackground(QPainter& painter, ZWidget& widget, const QRect* rect = NULL, bool border = TRUE, bool realWidget = TRUE);
  
     void drawBackgroundAndBorder(QPainter& painter, ZWidget& widget, const QRect* rect = NULL, bool realWidget = TRUE);

     /**
      *  Get the skinnable proprities.
      */
     void* getProps() const;

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
    void enableCache(bool enable);

    /** Whether the current language's layout is from left to right.
     */
    bool isLeftToRightLanguage() const;

  protected:
     void stretchPixmap(QPixmap& pm, int width, int height, PIXMAP_STRETCH_POLICY_E type, bool must = false);

  private:

     //static QAsciiCache<borderPixmapCacheItem> borderPixmapCache;

     QPixmap* getParentBackImage(ZWidget& widget, int x, int y, int& xBg, int& yBg, bool& freeImage);
     void drawBorder(QPainter& painter, QRect& rect, QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void drawBackground(QPainter& painter, QRect& rect, QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);

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


     QString getPixmapNameByState() const;
    
  private:
     void fillRect(QPainter& painter, QRect rect, QColor& color);
     void* getPixmapIDs(int&backgroundPixmapID, int&borderPixmapID);

     void loadBorderPixmaps(BorderPixmaps& border) const;
     QPixmap *getPixmapFromCache( const char *id ) const;

     void stretchAndDrawPixmap(QPainter& painter, QRect& rect, QPixmap& pixmap, PIXMAP_STRETCH_POLICY_E policy, 
                          QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);

     void drawPixmap(QPainter& painter, int x, int y, int w, int h, QPixmap& pixmap, 
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void drawPixmap(QPainter& painter, QRect& rect, QPixmap& pixmap, 
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void fillRect(QPainter& painter, int x, int y, int w, int h, QColor& color, 
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);
     void fillRect(QPainter& painter, QRect& rect, QColor& color, 
                     QPixmap* bgPixmap, int xBg, int yBg, int blendPercent);

     bool hasAlphaValue(QPixmap& pixmap);
     bool borderHasAlphaValue();

  public:

    // The functions in this sector are obsolete, please don't use them again

    /**
     * LRS element
     * @note Obsolete, called by CLI
     */
    struct Padding
    {
        int all;
        int left;
        int right;
        int top;
        int bottom;
    };
    enum RelativeAlignment
    {
       ImageLeft,
       ImageRight
    };

     ZSkinBase(QWidget& w, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal, 
               bool isWidget = TRUE);

     void setSkinWidget(QWidget& w) {widget = &w;}
     QWidget* getSkinWidget() const {return widget;}
     void drawBorder(QPainter& painter, const QRect* rect = NULL);
     void drawBackground(QPainter& painter, const QRect* rect = NULL, bool border = TRUE);

  private:
    // The functions in this sector are obsolete, please don't use them again

     void drawPixmap(QPainter& painter, QRect rect, QPixmap& pixmap);
     void drawPixmap(QPainter& painter, int x, int y, QPixmap& pixmap);
     QPixmap* ZSkinBase::getWallPaper(QPainter& painter) const;

  protected:
    uint    own_padding : 1;
    uint    own_background : 1;
    uint    own_private_bg : 1;
    uint    own_border : 1;
    uint    own_private_border : 1;
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

    WIDGET_BACKGROUND_INFO_T * ownBackgroundItems;
    WIDGET_BORDER_INFO_T * ownBorderItems;

    QPixmap* mBgPixmap;
    BorderPixmaps* mBorderPixmaps;

    WIDGET_PADDING_INFO_T* mPadding;

    short dx;
    short dy;
    
    QWidget* widget;
};


#endif
