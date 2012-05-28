#ifndef ZSKINREADER_H
#define ZSKINREADER_H

#include "ZSkinTool.h"
#include <qpixmap.h>

class ZSkinReader
{
public:
    /**
     * CheckBox
     */
    //selected checkbox - enabled
    QPixmap getSelectedCheckBox();
    //selected checkbox - disabled
    QPixmap getSelectedCheckBoxDisabled();
    //Unselected checkbox - enabled
    QPixmap getUnselectedCheckBox();
    //Unselected checkbox - disabled
    QPixmap getUnselectedCheckBoxDisabled();

    /**
     * RadioButton
     */
    //Selected
    QPixmap getRadioButtonSelected();
    //Selected/Disabled
    QPixmap getRadioButtonSelDisabled();
    //UnSelected
    QPixmap getRadioButtonUnselected();
    //UnSelected/Disabled
    QPixmap getRadioButtonUnselDisabled();

private:
};
#endif //ZSKINREADER_H
