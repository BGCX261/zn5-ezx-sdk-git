#ifndef ZIMAGE_H_
#define ZIMAGE_H_

/*
 * unoffical E8 EZX SDK 
 * Author : tulanix@yahoo.com.cn
 * 
*/

class ZImage : public ZWidget//size:0x104
{
  Q_OBJECT
  public:
    ZImage(QWidget* parent, char const* name, WFlag f = 0);
    ZImage(QPixmap& img, QWidget* parent, char const* name, WFlag f = 0);
    virtual ~ZImage();
    void setMovie(QMovie const& movie);
    void setPixmap(QPixmap const& pixmap);
    bool isZEnabled();
    bool isZDisabled();
    void getFrameWidth(int & left,int & right,int &top, int &bottom) const;
    virtual void setEnabled(bool enabled);
    virtual void setGeometry(int x,int y, int w, int h);
    virtual void setGeometry(const QRect & r);
    virtual void resize(int w, int h);
    QSize sizeHint() const ;
  private slots:
    void movieUpdated(QRect const& rect);
    void movieResized(QSize const& size);
    void sizeChange(QSize const& size);
  private:
    QRect getContentRect();
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void setPalette(QPalette const& palette); 
private: 
    QPixmap *pixmap;//0xF0
    QMovie *movie;//0xF4
    int movieW;//0xF8
    int movieH;//0xFC
    bool enabled;//0x100
}

#endif//ZIMAGE_H_
