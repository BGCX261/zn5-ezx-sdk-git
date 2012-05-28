

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef Z_KBMAINWIDGET_H
#define Z_KBMAINWIDGET_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

#include "ZMainWidget.h"
#include "ZHeader.h"

class ZSoftKey;
class ZCLISoftKey;
class ZAppInfoArea;
class ZKbMainWidgetData;


class ZKbMainWidget : public ZMainWidget
{
    Q_OBJECT
public:
    ZKbMainWidget( QWidget *parent = 0, const char *name = 0, WFlags f = 0 );

    ZKbMainWidget( const QString &mwTitle, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );

    ZKbMainWidget( ZHeader::HEADER_TYPE headerType, QWidget *parent = 0, const char *name = 0, WFlags f = 0 );

    virtual ~ZKbMainWidget();

  public:
    void setHeaderType(ZHeader::HEADER_TYPE headerType);

    static bool setAppTitle( const QString &appTitle );

    static QString getAppTitle();

    QPixmap getTitlePixmap(int nIdx);

    bool setMainWidgetTitle( const QString &mwTitle );

    QString getMainWidgetTitle();

    bool setMainWidgetTitleIcon(const QPixmap& pmp);

    QPixmap getMainWidgetTitleIcon();

    bool setAppInfoArea( ZAppInfoArea *aia );

    ZAppInfoArea* getAppInfoArea();

    bool setSoftKey( ZSoftKey *cstWidget );

    ZSoftKey* getSoftKey( bool createZSoftKey = TRUE );

    bool setCLISoftKey(ZCLISoftKey* cliSoftKey);

    ZCLISoftKey* getCLISoftKey(bool createZCLISoftKey = TRUE);

    virtual bool eventFilter(QObject*, QEvent*);
  //  virtual void show();
    void setTitleTruncEnable(bool bTrunc);

    bool isTitleTruncEnable();

    void updateHeader();

    QSize headerSize();

    void setWidgetPixmapPrefix(QString& prefix );
    void setHeaderPixmapPrefix(QString& prefix);
    void hideHeader() ;

    void showHeader() ;
    //virtual QWidget* getContentWidget(bool createZScrollView = TRUE);//fuz

    //virtual bool setContentWidget(QWidget* w = NULL);//fuz
    //virtual QWidget* getCSTWidget( bool create = TRUE );//fuz
    //virtual bool setCSTWidget( QWidget* w = NULL );//fuz
    //virtual bool setTitleBarWidget( QWidget* w = NULL );//fuz
    //virtual QWidget* getTitleBarWidget();	//fuz
    //virtual void setFullScreenMode(bool fullScreen, bool reserved = FALSE);//fuz

    //virtual bool getFullScreenMode();//fuz

    QSize getContentSize();

    //virtual bool getEditMode();//fuz


 signals:

    void clearKeyClicked( );

    void serverInitialized();

    void TitlePixmapChanged(int nIdx);
protected slots:
	/* fuz
    virtual void slotKbWidgetSizeChanged(const QRect & resizeR,
                                 int topLevelWinId,
                                 bool show,
                                 bool changed);
								 */
  protected:

    virtual bool event( QEvent *e );

    int getLRSBaseIndex();

    virtual void keyPressEvent( QKeyEvent * e);

    //virtual void resizeEvent( QResizeEvent * e);//fuz


  private slots:  
    void slotAppMessage(const QCString &msg, const QByteArray &);
    void childDestroyed();

  private:

     void init(ZHeader::HEADER_TYPE headerType);

    void initMainWidget();

  private:
    ZKbMainWidgetData *data;
};

#endif

