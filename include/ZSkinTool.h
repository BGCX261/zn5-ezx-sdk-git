//--------------------------------------------------------------------------------------------------
//
//   Header Name: ZSkinTool.h
//
//   General Description: Defined the ZSkinTool class, which is the implementation of the chameleon
//                        CheckBox widget.
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
//  Kenny Yu/a18604             8/09/2004                   Initial version
//  Liu Chao/e2472c             3/07/2005                   Add more stretch methods
//
//--------------------------------------------------------------------------------------------------
#ifndef __ZSKIN_TOOL_H__ 
#define __ZSKIN_TOOL_H__ 

#include <qpixmap.h>

#ifdef MAKE_UISTYLE_CHAMELEON
#include <ZWidgetSkinProps.h>
#endif

/*
enum StretchType
{
  StretchV = 0,
  StretchH,
  StretchTile,
  StretchScale,
  StretchCenter
};
*/

class ZSkinTool
{
public:
#if 0
    QPixmap cut(QPixmap &, QRect r);
    QPixmap leftTopCorner(QPixmap &);
    QPixmap rightTopCorner(QPixmap &);
    QPixmap leftBottomCorner(QPixmap &);
    QPixmap rightBottomCorner(QPixmap &);

    QPixmap leftBorder(QPixmap &, int extension);
    QPixmap rightBorder(QPixmap &, int extension);
    QPixmap topBorder(QPixmap &, int extension);
    QPixmap bottomBorder(QPixmap &, int extension);
    
    QColor readSkinColor(int colorID);
#endif

#ifdef MAKE_UISTYLE_CHAMELEON
    QPixmap process(QPixmap &pm, int width, int height, PIXMAP_STRETCH_POLICY_E type);
#endif

    QPixmap stretchV(QPixmap &, int height);
    QPixmap stretchH(QPixmap &, int width);
private:
#if 0
    /**
     * Cut shared Skin pixmap in specific rectangle
     * @param r rectangle area in Skin pixmap shared
     */
    QPixmap cutSkinPixmap(QRect r);
    /**
     * Read color at point of Skin shared pixmap
     * @param pos point where to read color
     */
    QColor readSkinColor(QPoint pos);
#endif
};
#endif //__ZSKIN_TOOL_H__ 
