//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                     Template ID and version: TMP_LFC_50068  Version 1.2
//                      (c) Copyright Motorola 200{x}, All Rights Reserved
//
// Revision History:
//                   Modification    Tracking
// Author (core ID)         Date      Number  Description of Changes
// -----------------  ----------  ----------  ---------------------------------
// Developer Name/ID  MM/DD/YYYY  LIBXXXXXXX  BRIEF description of changes made
// 
//-------------------------------------------------------------------------------------------------

/**
 * @file ZScrollView.h
 * @brief EZX ScrollView class
 */

#ifndef Z_SCROLLVIEW_H
#define Z_SCROLLVIEW_H
 
#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include <qscrollview.h>
#include <qsize.h>
#include <qrect.h>
#include <qpixmap.h>

class ZScrollViewData;

/**
 * ZScrollView is similar to QScrollView, but has a few additional behaviors:
 *
 * 1. Adjusts the children's geometry automatically when the size of 
 * ZMultiLineEdit child is changed because of text set.
 *
 * 2. Changes the geometry of the text-entry area when the keyboard is shown/
 * hidden.
 *
 * @code
 * ZScrollView* sv = new ZScrollView( this, "sv" );
 * sv->enableClipper(true);
 * UTIL_MulitLineEdit *ml1, *ml2;
 *
 * //add a 6 lines ZMultiLineEdit 
 * ml1 = new ZMultiLineEdit(sv->viewport(),true,6);
 * sv->addChild(ml1,0,0);
 *
 * //set indent
 * ml1->setIndent(20);
 * ml2 = new ZMultiLineEdit(sv->viewport());
 * 
 * //need to change the widget width when ZScrollView's scrollbar is shown/hidden
 * sv->addChild(ml2,0,30,true);
 * @endcode

 * @see ZMultiLineEdit
 *
 * @note for the class, it has changed the scrollview's resize policy to Manual
 * setResizePolicy(Manual), and turn off the horizon scroll bar
 * setHScrollBarMode(QScrollView::AlwaysOff).
 *
 * @note LSR for the Chameleon
 * In the Chamleon. Application can use the ZScrollView for the Scroll Panel and Form Container
 * in the default, the Form Container's padding has been set into the ZScrollView
 * If application hopes to set the Scroll Panel' LRS, please do as following:
 * 
 * #ifdef MAKE_UISTYLE_CHAMELEON
 *    const struct ZWidgetSkinProps *prop = ZSkinService::getAllSkinnableProps();
 *    WIDGET_PADDING_INFO_T padding = prop->zScrollView.base.padding;
 *    setMargins(padding.left,padding.top,padding.right,padding.bottom);
 * #endif    
 * 
 */

class ZScrollView : public QScrollView  
{
    Q_OBJECT

  public:

    /**
     * Constructor of ZScrollView
     *
     * @param parent the parent widget of the ZScrollView
     * @param name the name of the ZScrollView
     * @param f the flags of the ZScrollView
     */
    ZScrollView( QWidget* parent = 0, const char* name = 0, WFlags f = 0) ;

    /**
     * Destructor of ZScrollView. 
     */
    virtual ~ZScrollView();

    /**
     * reimplemented from QScrollView
     * Insert a child into the scrolled area positioned at (x,y)
     *
     * @param child the child will be inserted
     * @param x the child's x position in the scrolled area
     * @param y the child's y position in the scrolled area
     */
    virtual void addChild( QWidget* child, int x = 0, int y = 0 );

    /**
     * ZScrollView's addChild.
     * 
     * @param child the child will be inserted
     * @param x the child's x position in the scrolled area
     * @param y the child's y position in the scrolled area
     * @param autoAdjustWidth if true, when the vertical scrollbar appears/disappears,
     * the widget's width will be adjusted, it is width() -(+) verticalScrollBar->width()
     */
    virtual void addChild( QWidget* child, int x, int y, bool autoAdjustWidth );

    /**
     * ZScrollView's moveChild.
     * 
     * @param child the child will be moved
     * @param x the child's new x position in the scrolled area
     * @param y the child's new y position in the scrolled area
     * @param autoAdjustWidth if true, when the vertical scrollbar appears/disappears,
     * the widget's width will be adjusted, it is width() -(+) verticalScrollBar->width()
     */
    virtual void moveChild( QWidget* child, int x, int y, bool autoAdjustWidth = FALSE );

    /**
     * Update Content Size correctly by the all children's frame geometry
     */
    void updateContentSize();

    /**
     * Set a flag for flush events in doLayout(), it is called sendPostedEvents()
     * which reduces screen flash. 
     *
     * By default, the flag is on.
     *
     * If the application needs to assure the sequence of the events during the period,
     * please turn off the flag.
     *
     * @param flush if true,it needs to flush the events during doLayout
     *
     * @see doLayout()
     */
    void setFlushEvents( bool flush = true );

    /**
     * Get the flush event flag
     *
     * @return if TRUE, the event will be flushed during doLayout, or will not be flushed
     *
     * @see setFlushEvents()
     */
    bool getFlushEvents() const;

    /**
     * Set the flag to do layout automatically, usually doing layout is caused
     * by the ZMultiLineEdit's text change.
     *
     * @param doLayout if true, do layout automatically, or need to do layout by yourself
     * The default is to do layout automatically.
     *
     * @see doLayout() and getAutoLayout()
     */
    void setAutoLayout( bool doLayout = true ); 

    /**
     * Get the DoLayout flag
     *
     * @return if TRUE,  ZScrollView will do layout automatically, or it doesn't.
     *
     * @see setDoLayout()
     */
    bool getAutoLayout() const; 

    /**
     * Set the flag to scroll automatically
     *
     * @param autoScroll if true, the ZScollView will automatically scroll to make the QWidget
     * visible which lead to do auto-layout 
     * In the default, the Flag is set to TRUE
     * 
     * @see setDoLayout()
     */
    void setAutoScroll( bool autoScroll = true ); 

    /**
     * Set the background pixmap for scroll view 
     *
     */
    void setBackGroundPixmap(const QPixmap &pix);

    void setNoFocusChange(bool nofocus);

    public slots:

    /**
     * reimplemented from QWidget
     */
    virtual void show();

    /**
     * reimplemented from QWidget
     */
    virtual void hide();

    /**
     * Layout the children in the ZScrollView.
     *
     * @param widget the widget whose geometry changed.
     * @param size the size(height and width) changed. Now only supports height
     * @param cursorPos the cursor's position. 
     * @param enlarge if true, the size of widget is enlarged
     */
    virtual void doLayout( QWidget* widget,QSize size,QPoint cursorPos,int enlarge );

    /**
     * ZScrollView's enableClipper, the function will call QScrollView's enableClipper
     *
     * @param clipper if true, it will have an extra widget to group child widgets
     *
     * @see QScrollView::enableClipper( bool )
     */
    void enableClipper( bool clipper );

    /**
     * reimplemented from QScrollView
     */
    void setMargins(int left, int top, int right, int bottom);

    void resizeContents( int w, int h );

  signals:

    /**
     * Emitted when the vertical scrollbar of the ZScrollView is shown/hidden
     *
     * @param show if true, the vertical scrollbar is shown
     */
    void vScrollBarStateChanged( int show );

  protected:

    /**
     * reimplemented from QWidget
     */
    virtual bool eventFilter( QObject *obj, QEvent* event );

    /**
     * reimplemented from QWidget
     */
    virtual bool event ( QEvent* event );

    /**
     * reimplemented from QScrollView
     */
    virtual void keyPressEvent( QKeyEvent* event );

    /**
     * Reimplement
     */
    virtual void drawContents(QPainter *p,int cx, int cy, int cw,int ch);
    
    /**
     * Reimplement QScrollView for Chameleon Up/Down key behavior
     */
    bool focusNextPrevChild( bool next );

    void resizeEvent( QResizeEvent* event );

  private:

    void removeSVChild( QWidget* child );
    bool nextFocusWidgetVisible(bool next);
    QWidget* nextFocusWidget(bool next);
        
  private slots:

    void updateFieldsWidth( int cause );
    void makeFocusWidgetVisible( bool show );
    
  private:

    bool flushEvents;
    bool autoLayout;
    ZScrollViewData* d;
};

#endif 
