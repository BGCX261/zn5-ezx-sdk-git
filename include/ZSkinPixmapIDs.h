//--------------------------------------------------------------------------------------------------
//
//   Header Name: ZSkinPixmapIDs.h
//
//   General Description: Defined the skin pixmap IDs.
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
// Jack Zhao/w20997             02/25/2005                  Initial version
//
//
//--------------------------------------------------------------------------------------------------

#ifndef __ZSKINPIXMAPIDS_H__
#define __ZSKINPIXMAPIDS_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

// BARBADOS macro should be here, because we are not sure now whether different
// products may have different pixmap IDs. So currently, for MARTINIQ to pass
// the build, we eliminated.
//#ifdef BARBADOS

//
// Default highlighted background
//
#define DEFAULT_BG_H_HS_PIXMAPID                   "highlight_list_center.epx"


//
// ZAlternatesChooser
//
// Background
#define ZALTERNATECHOOSER_BG_STD_PIXMAPID           "alt_chooser_bg"   //dy added
// Border
#define ZALTERNATECHOOSER_BD_STD_PIXMAPID           "alt_chooser"          //dy added
// Other
#define ZALTERNATECHOOSER_LEFT_INDICATOR_PIXMAPID   "alt_chooser_left_indicator_std.epx"
#define ZALTERNATECHOOSER_RIGHT_INDICATOR_PIXMAPID  "alt_chooser_right_indicator_std.epx"

//
// ZAlternatesItem
//
// Background
#define ZALTERNATEITEM_BG_STD_PIXMAPID           "alt_item_bg"
// Border
#define ZALTERNATEITEM_BD_STD_PIXMAPID           "alt_item"

//
// ZAlternatesList
//
// Background
#define ZALTERNATESLIST_BG_STD_PIXMAPID           "alt_list_bg"
// Border
#define ZALTERNATESLIST_BD_STD_PIXMAPID           "alt_list"

//
// ZAppInfoArea
//
// Background
#define ZAPPINFOAREA_BG_STD_PIXMAPID           "aia_bg"
// Border
#define ZAPPINFOAREA_BD_STD_PIXMAPID           "aia"  //dy modified "aia"

//
// ZPressButton
//
// Background
#define ZPRESSBUTTON_BG_STD_PIXMAPID        "button_bg"   //button
// Border
#define ZPRESSBUTTON_BD_STD_PIXMAPID        "button"

//
// ZCalendarModule
//
// Background
#define ZCALENDARMODULE_BG_STD_PIXMAPID           "calmod_bg"
// Border
#define ZCALENDARMODULE_BD_STD_PIXMAPID           "calmod"

//
// ZCalendarModule_Day
//
// Background
#define ZCALENDARMODULE_DAY_BG_STD_PIXMAPID           "calmod_date_bg"
// Border
#define ZCALENDARMODULE_DAY_BD_STD_PIXMAPID           "calmod_date"

//
// ZCalendarModule_CurDay
//
// Background
#define ZCALENDARMODULE_CURDAY_BG_STD_PIXMAPID       "calmod_date_curr_bg"
// Border
#define ZCALENDARMODULE_CURDAY_BD_STD_PIXMAPID       "calmod_date_curr"

//
// ZCalendarModule_DayHeader
//
// Background
#define ZCALENDARMODULE_DAYHEADER_BG_STD_PIXMAPID           "calmod_dayheader_bg"
// Border
#define ZCALENDARMODULE_DAYHEADER_BD_STD_PIXMAPID           "calmod_dayheader"

//
// ZCalendarModule_CurDayHeader
//
// Background
#define ZCALENDARMODULE_CURDAYHEADER_BG_STD_PIXMAPID           "calmod_dayheader_curr_bg"
// Border
#define ZCALENDARMODULE_CURDAYHEADER_BD_STD_PIXMAPID           "calmod_dayheader_curr"

//
// ZCalendarModule_EmptyDay
//
// Background
#define ZCALENDARMODULE_EMPTYDAY_BG_STD_PIXMAPID           "calmod_emptyday_bg" //dy comment, no this item
// Border
#define ZCALENDARMODULE_EMPTYDAY_BD_STD_PIXMAPID           "calmod_emptyday"

//
// ZCalendarModule_Grid
//
// Background
#define ZCALENDARMODULE_GRID_BG_STD_PIXMAPID           "calmod_daygrid_bg"   //dy comment, no this item
// Border
#define ZCALENDARMODULE_GRID_BD_STD_PIXMAPID           "calmod_daygrid"

//
// ZCheckBox
//
// Background
#define ZCHECKBOX_BG_STD_PIXMAPID           "chkbx_bg"
// Border
#define ZCHECKBOX_BD_STD_PIXMAPID           "chkbx"
// Other
//#define ZCHECKBOX_CHECK_PIXMAPID            "chkbX_img_chk.epx"
//#define ZCHECKBOX_PARTIALCHECK_PIXMAPID     "chkbx_img_partial_chk.epx"
//#define ZCHECKBOX_UNCHECK_PIXMAPID          "chkbx_img_unchk.epx"
#define ZCHECKBOX_INDICATORH_PIXMAPID         "chkbx_mark_indicator_h.epx"
#define ZCHECKBOX_INDICATORHS_PIXMAPID        "chkbx_mark_indicator_hs.epx"
#define ZCHECKBOX_INDICATORPS_PIXMAPID        "chkbx_mark_indicator_ps.epx"
#define ZCHECKBOX_INDICATORSEL_PIXMAPID       "chkbx_mark_indicator_sel.epx"
#define ZCHECKBOX_INDICATORSTD_PIXMAPID       "chkbx_mark_indicator_std.epx"

//
// ZColorModule
//
// Background
#define ZCOLORMODULE_BG_STD_PIXMAPID           "colormod_bg"
// Border
#define ZCOLORMODULE_BD_STD_PIXMAPID           "colormod"
// Other
#define ZCOLORMODULE_HIGHLIGHT_PIXMAPID        "colormod_highlight_std.epx"

//
// ZColorModule_Cname
//
// Background
#define ZCOLORMODULE_CNAME_BG_STD_PIXMAPID           "colormod_cname_bg"
// Border
#define ZCOLORMODULE_CNAME_BD_STD_PIXMAPID           "colormod_cname"

//
// ZColorModule_Well
//
// Background
#define ZCOLORMODULE_WELL_BG_STD_PIXMAPID           "colormod_well_bg"
// Border
#define ZCOLORMODULE_WELL_BD_STD_PIXMAPID           "colormod_well"

//
// ZColorPicker
//
// Background
#define ZCOLORPICKER_BG_STD_PIXMAPID           "button_bg"
// Border
#define ZCOLORPICKER_BD_STD_PIXMAPID           "button"

//
// ZColorPicker_Well
//
// Background
#define ZCOLORPICKER_WELL_BG_STD_PIXMAPID           "colorpicker_well_bg"
// Border
#define ZCOLORPICKER_WELL_BD_STD_PIXMAPID           "colorpicker_well"

//
// ZComboBox/Date/Number/Time control
//
// Background
#define ZCOMBOBOX_BG_STD_PIXMAPID           "combobox_bg"
// Border
#define ZCOMBOBOX_BD_STD_PIXMAPID           "combobox"
// Other
#define ZCOMBOBOX_IMAGE_STD_PIXMAPID        "combobox_img_std.epx"
#define ZCOMBOBOX_IMAGE_H_PIXMAPID          "combobox_img_h.epx"
#define ZCOMBOBOX_IMAGE_S_PIXMAPID          "combobox_img_h.epx"
#define ZCOMBOBOX_IMAGE_HS_PIXMAPID         "combobox_img_hs.epx"

#define ZDATECONTROL_IMAGE_STD_PIXMAPID     "datecontrol_img_std.epx"    //dy comment, no this item, begin
#define ZDATECONTROL_IMAGE_H_PIXMAPID       "datecontrol_img_h.epx"
#define ZDATECONTROL_IMAGE_S_PIXMAPID       "datecontrol_img_h.epx"
#define ZDATECONTROL_IMAGE_HS_PIXMAPID      "datecontrol_img_hs.epx"

#define ZNUMBERCONTROL_IMAGE_STD_PIXMAPID   "numbercontrol_img_std.epx"
#define ZNUMBERCONTROL_IMAGE_H_PIXMAPID     "numbercontrol_img_h.epx"
#define ZNUMBERCONTROL_IMAGE_S_PIXMAPID     "numbercontrol_img_h.epx"
#define ZNUMBERCONTROL_IMAGE_HS_PIXMAPID    "numbercontrol_img_hs.epx"

#define ZTIMECONTROL_IMAGE_STD_PIXMAPID     "timecontrol_img_std.epx"
#define ZTIMECONTROL_IMAGE_H_PIXMAPID       "timecontrol_img_h.epx"
#define ZTIMECONTROL_IMAGE_S_PIXMAPID       "timecontrol_img_h.epx"
#define ZTIMECONTROL_IMAGE_HS_PIXMAPID      "timecontrol_img_hs.epx"       //dy comment, no this item, end

//
// ZDate/Number/Time Module
//
// Background
#define ZDATEMODULE_BG_STD_PIXMAPID           "datemod_bg"
// Border
#define ZDATEMODULE_BD_STD_PIXMAPID           "datemod"

//
// ZDate/Number/Time Picker
//
// Background
#define ZDATEPICKER_BG_STD_PIXMAPID           "datepicker_bg"
// Border
#define ZDATEPICKER_BD_STD_PIXMAPID           "datepicker"
// Other
#define ZDATEPICKER_INCREMENT_STD_PIXMAPID    "picker_increment_std.epx"
#define ZDATEPICKER_INCREMENT_H_PIXMAPID        "picker_increment_h.epx"
#define ZDATEPICKER_INCREMENT_HS_PIXMAPID      "picker_increment_hs.epx"

#define ZDATEPICKER_DECREMENT_STD_PIXMAPID    "picker_decrement_std.epx"
#define ZDATEPICKER_DECREMENT_H_PIXMAPID        "picker_decrement_h.epx"
#define ZDATEPICKER_DECREMENT_HS_PIXMAPID      "picker_decrement_hs.epx"

#define ZDATEPICKER_BUTTON_STD_IMAGE                 "datepicker_img_std.epx"
#define ZDATEPICKER_BUTTON_H_IMAGE                     "datepicker_img_h.epx"
#define ZDATEPICKER_BUTTON_HS_IMAGE                   "datepicker_img_hs.epx"
#define ZDATEPICKER_BUTTON_S_IMAGE                     "datepicker_img_s.epx"


//
// ZExhibitButton
//
// Background
#define ZEXHIBITBUTTON_BG_STD_PIXMAPID           "exhibit_bg"
// Border
#define ZEXHIBITBUTTON_BD_STD_PIXMAPID           "exhibit"

//
// ZLineEdit
//
// Background
#define ZLINEEDIT_BG_STD_PIXMAPID           "field_bg"
// Border
#define ZLINEEDIT_BD_STD_PIXMAPID           "field"

//
// ZFiveWayButton1
//
// Background
#define ZFIVEWAYBUTTON1_BG_STD_PIXMAPID           "fiveway01_bg"
// Border
#define ZFIVEWAYBUTTON1_BD_STD_PIXMAPID           "fiveway01"
// Other
#define ZFIVEWAYBUTTON1_IMG_STD_PIXMAPID          "fiveway_standard.epx"
#define ZFIVEWAYBUTTON1_IMG_UP_PIXMAPID           "fiveway_up_sel.epx"                      //dy modified begin
#define ZFIVEWAYBUTTON1_IMG_DOWN_PIXMAPID         "fiveway_down_sel.epx"
#define ZFIVEWAYBUTTON1_IMG_LEFT_PIXMAPID         "fiveway_left_sel.epx"
#define ZFIVEWAYBUTTON1_IMG_RIGHT_PIXMAPID        "fiveway_right_sel.epx"
#define ZFIVEWAYBUTTON1_IMG_CENTER_PIXMAPID       "fiveway_center_sel.epx"           //dy modified end

//
// ZFiveWayButton2
//
// Background
#define ZFIVEWAYBUTTON2_BG_STD_PIXMAPID           "fiveway02_bg"
// Border
#define ZFIVEWAYBUTTON2_BD_STD_PIXMAPID           "fiveway02"
// Other
#define ZFIVEWAYBUTTON2_IMG_STD_PIXMAPID          "calculator_img_normal.epx"
#define ZFIVEWAYBUTTON2_IMG_UP_PIXMAPID            "calculator_img_multiply.epx"
#define ZFIVEWAYBUTTON2_IMG_DOWN_PIXMAPID      "calculator_img_divide.epx"
#define ZFIVEWAYBUTTON2_IMG_LEFT_PIXMAPID         "calculator_img_add.epx"
#define ZFIVEWAYBUTTON2_IMG_RIGHT_PIXMAPID        "calculator_img_substract.epx"
#define ZFIVEWAYBUTTON2_IMG_CENTER_PIXMAPID       "calculator_img_equal.epx"

//
// ZFormContainer
//
#define ZFORMCONTAINTER_BG_STD_PIXMAPID     "formcont_bg"
#define ZFORMCONTAINTER_BD_STD_PIXMAPID     "formcont"

//
// ZFormItem
//
// Background
#define ZFORMITEM_BG_STD_PIXMAPID           "formitem_bg"
// Border
#define ZFORMITEM_BD_STD_PIXMAPID           "formitem"

//
// ZIconView1---GridContainer1
//
// Background
#define ZICONVIEW1_BG_STD_PIXMAPID           "iconview01_bg"
// Border
#define ZICONVIEW1_BD_STD_PIXMAPID           "iconview01"

//
// ZIconView2---GridContainer2
//
// Background
#define ZICONVIEW2_BG_STD_PIXMAPID           "iconview02_bg"
// Border
#define ZICONVIEW2_BD_STD_PIXMAPID           "iconview02"

//
// ZIconViewItem1---GridItem1
//
// Background
#define ZICONVIEWITEM1_BG_STD_PIXMAPID           "griditem_bg"
// Border
#define ZICONVIEWITEM1_BD_STD_PIXMAPID           "griditem"
// Other dy added
#define ZICONVIEWITEM1_CHECK_STD_PIXMAPID            "chkbx_mark_indicator_sel.epx"
#define ZICONVIEWITEM1_UNCHECK_STD_PIXMAPID       "chkbx_mark_indicator_std.epx"
#define ZICONVIEWITEM1_CHECK_H_PIXMAPID                "chkbx_mark_indicator_hs.epx"
#define ZICONVIEWITEM1_UNCHECK_H_PIXMAPID            "chkbx_mark_indicator_h.epx"
#define ZICONVIEWITEM1_CHECK_PARTSEL_PIXMAPID     "chkbx_mark_indicator_ps.epx"

#define ZICONVIEWITEM1_SINGLEMARK_UNCHECK_STD_PIXMAPID    "singlesel_mark_indicator_std.epx"
#define ZICONVIEWITEM1_SINGLEMARK_CHECK_STD_PIXMAPID         "singlesel_mark_indicator_sel.epx"
#define ZICONVIEWITEM1_SINGLEMARK_UNCHECK_H_PIXMAPID         "singlesel_mark_indicator_h.epx"
#define ZICONVIEWITEM1_SINGLEMARK_CHECK_H_PIXMAPID              "singlesel_mark_indicator_hs.epx"

//
// ZGroupBox
//
// Background
#define ZGROUPBOX_BG_STD_PIXMAPID           "groupbox_bg"    //dy comment, no this item
// Border
#define ZGROUPBOX_BD_STD_PIXMAPID           "groupbox"

//
// ZHeader1
//
// Background
#define ZHEADER1_BG_STD_PIXMAPID           "header_bg"
// Border
#define ZHEADER1_BD_STD_PIXMAPID           "header"              //dy comment, no this item

//
// ZHeader2
//
// Background
#define ZHEADER2_BG_STD_PIXMAPID           "popup_header_bg"
// Border
#define ZHEADER2_BD_STD_PIXMAPID           "popup_header"

//
// ZHeader3
//
// Background
#define ZHEADER3_BG_STD_PIXMAPID           "header_bg" //??
// Border
#define ZHEADER3_BD_STD_PIXMAPID           "header"

//
// ZHeader4
//
// Background
#define ZHEADER4_BG_STD_PIXMAPID           "header_bg"  //??
// Border
#define ZHEADER4_BD_STD_PIXMAPID           "header"

//
// ZHeader Popup
//
// Background
#define ZHEADERPOPUP_BG_STD_PIXMAPID           "popup_header_bg"
// Border
#define ZHEADERPOPUP_BD_STD_PIXMAPID           "popup_header"

//
// ZImageContainer1--4, current no images defined
//
// Background
#define ZIMAGECONTAINER_BG_STD_PIXMAPID            "imgcontain_bg"
// Border
#define ZIMAGECONTAINER_BD_STD_PIXMAPID            "imgcontain"
// Background
#define ZIMAGECONTAINER1_BG_STD_PIXMAPID           "imgcontain01_bg"
// Border
#define ZIMAGECONTAINER1_BD_STD_PIXMAPID           "imgcontain01"
// Background
#define ZIMAGECONTAINER2_BG_STD_PIXMAPID           "imgcontain02_bg"
// Border
#define ZIMAGECONTAINER2_BD_STD_PIXMAPID           "imgcontain02"
// Background
//#define ZIMAGECONTAINER4_BG_STD_PIXMAPID      "mm_imgcontain04_bg_h.gif"
// Border
//#define ZIMAGECONTAINER4_BD_STD_PIXMAPID      ""
//
// ZInputMatrix
//
// Background
#define ZINPUTMATRIX_BG_STD_PIXMAPID           "input_matrix_bg"
// Border
#define ZINPUTMATRIX_BD_STD_PIXMAPID           "input_matrix"

//
// ZInteractiveHighlight
//
// Background
#define ZINTERACTIVEHIGHLIGHT_BG_STD_PIXMAPID           "inthighlight_bg"
// Border
#define ZINTERACTIVEHIGHLIGHT_BD_STD_PIXMAPID           "inthighlight"
// Other
#define ZINTERACTIVEHIGHLIGHT_ALTINDICATOR_PIXMAPID     "inthighlight_indicator_std.epx"

//
// ZJumpBox
//
// Background
#define ZJUMPBOX_BG_STD_PIXMAPID           "jumpbox_bg"
// Border
#define ZJUMPBOX_BD_STD_PIXMAPID           "jumpbox"        //dy comment, no this item
// Other
#define ZJUMPBOX_JUMP_PIXMAPID             "jumpbox_icon_std.epx"  //dy comment, no this item

//
// ZJumpBox_Field
//
// Background
#define ZJUMPBOX_FIELD_BG_STD_PIXMAPID           "jumpbox_field_bg"
// Border
#define ZJUMPBOX_FIELD_BD_STD_PIXMAPID           "jumpbox_field"   //dy comment, no this item

//
// ZListBox1
//
// Background
#define ZLISTBOX1_BG_STD_PIXMAPID           "listbox01_bg"
// Border
#define ZLISTBOX1_BD_STD_PIXMAPID           "listbox01"

//
// ZListBox2
//
// Background
#define ZLISTBOX2_BG_STD_PIXMAPID           "listbox02_bg"
// Border
#define ZLISTBOX2_BD_STD_PIXMAPID           "listbox02"

//
// ZListItem1
//
// Background
#define ZLISTITEM1_BG_STD_PIXMAPID           "listitem_bg"
// Border
#define ZLISTITEM1_BD_STD_PIXMAPID           "listitem"
// Other
#define ZLISTITEM1_NAVINDICATOR_STD_PIXMAPID "listitem_nav_indicator_std.epx"
#define ZLISTITEM1_NAVINDICATOR_H_PIXMAPID     "listitem_nav_indicator_h.epx"
#define ZLISTITEM1_NAVINDICATOR_S_PIXMAPID     "listitem_nav_indicator_sel.epx"
#define ZLISTITEM1_NAVINDICATOR_HS_PIXMAPID   "listitem_nav_indicator_hs.epx"

#define ZLISTITEM1_PICBORDER_STD_PIXMAPID    "listitem_img_border_std.epx"  //dy modified begin
#define ZLISTITEM1_PICBORDER_H_PIXMAPID        "listitem_img_border_h.epx"
#define ZLISTITEM1_PICBORDER_S_PIXMAPID        "listitem_img_border_sel.epx"
#define ZLISTITEM1_PICBORDER_HS_PIXMAPID      "listitem_img_border_hs.epx"

#define ZLISTITEM1_MARK_UNCHECK_STD_PIXMAPID    "chkbx_mark_indicator_std.epx"
#define ZLISTITEM1_MARK_CHECK_STD_PIXMAPID         "chkbx_mark_indicator_sel.epx"
#define ZLISTITEM1_MARK_UNCHECK_H_PIXMAPID         "chkbx_mark_indicator_h.epx"
#define ZLISTITEM1_MARK_CHECK_H_PIXMAPID              "chkbx_mark_indicator_hs.epx"
#define ZLISTITEM1_MARK_PARTSEL_PIXMAPID              "chkbx_mark_indicator_ps.epx"

#define ZLISTITEM1_SINGLEMARK_UNCHECK_STD_PIXMAPID    "singlesel_mark_indicator_std.epx"
#define ZLISTITEM1_SINGLEMARK_CHECK_STD_PIXMAPID         "singlesel_mark_indicator_sel.epx"
#define ZLISTITEM1_SINGLEMARK_UNCHECK_H_PIXMAPID         "singlesel_mark_indicator_h.epx"
#define ZLISTITEM1_SINGLEMARK_CHECK_H_PIXMAPID              "singlesel_mark_indicator_hs.epx"    //dy modified end

//inorder to pass build
#define ZLISTITEM1_UNMARK_PIXMAPID ""
#define ZLISTITEM1_MARK_PIXMAPID     ""

//
// ZListItem2
//
// Background
#define ZLISTITEM2_BG_STD_PIXMAPID           "listitem_bg"
// Border
#define ZLISTITEM2_BD_STD_PIXMAPID           "listitem"
// Other
#define ZLISTITEM2_NAVINDICATOR_STD_PIXMAPID "listitem_nav_indicator_std.epx"  //dy added begin
#define ZLISTITEM2_NAVINDICATOR_H_PIXMAPID     "listitem_nav_indicator_h.epx"
#define ZLISTITEM2_NAVINDICATOR_S_PIXMAPID     "listitem_nav_indicator_sel.epx"
#define ZLISTITEM2_NAVINDICATOR_HS_PIXMAPID   "listitem_nav_indicator_hs.epx"

#define ZLISTITEM2_PICBORDER_STD_PIXMAPID       "listitem_img_border_std.epx"
#define ZLISTITEM2_PICBORDER_H_PIXMAPID           "listitem_img_border_h.epx"
#define ZLISTITEM2_PICBORDER_S_PIXMAPID           "listitem_img_border_sel.epx"
#define ZLISTITEM2_PICBORDER_HS_PIXMAPID         "listitem_img_border_hs.epx"

#define ZLISTITEM2_MARK_UNCHECK_STD_PIXMAPID    "chkbx_mark_indicator_std.epx"
#define ZLISTITEM2_MARK_CHECK_STD_PIXMAPID         "chkbx_mark_indicator_sel.epx"
#define ZLISTITEM2_MARK_UNCHECK_H_PIXMAPID         "chkbx_mark_indicator_h.epx"
#define ZLISTITEM2_MARK_CHECK_H_PIXMAPID              "chkbx_mark_indicator_hs.epx"  //dy added end
#define ZLISTITEM2_MARK_PARTSEL_PIXMAPID              "chkbx_mark_indicator_ps.epx"
//
// ZMatrixItem
//
// Background
#define ZMATRIXITEM_BG_STD_PIXMAPID           "matrixitem_bg"
// Border
#define ZMATRIXITEM_BD_STD_PIXMAPID           "matrixitem"
//
//MediaController, dy added, current not be used
//
// Background
#define ZMEDIACONTROL_BG_STD_PIXMAPID                 "media_controller_bg"
// Border
#define ZMEDIACONTROL_BD_STD_PIXMAPID                 "media_controller"
//
// ZMeter1
//
// Background
#define ZMETER1_BG_STD_PIXMAPID                 "meter01_bg"
// Border
#define ZMETER1_BD_STD_PIXMAPID                 "meter01"
// Other
#define ZMETER1_FILLEDSTARTENDCAP_PIXMAPID      ""
#define ZMETER1_UNFILLEDSTARTENDCAP_PIXMAPID    ""
#define ZMETER1_ACTIVESTARTENDCAP_PIXMAPID      ""
#define ZMETER1_FILLEDFINISHENDCAP_PIXMAPID     ""
#define ZMETER1_UNFILLEDFINISHENDCAP_PIXMAPID   ""
#define ZMETER1_ACTIVEFINISHENDCAP_PIXMAPID     ""
#define ZMETER1_FILLEDSEGMENTIMAGE_PIXMAPID     "meter01_filled_segment_std.epx"
#define ZMETER1_UNFILLEDSEGMENTIMAGE_PIXMAPID   "meter01_unfilled_segment_std.epx"
#define ZMETER1_ACTIVESEGMENTIMAGE_PIXMAPID     ""
#define ZMETER1_INCREMENT_PIXMAPID              "meter01_increment_icon_std.epx"
#define ZMETER1_DECREMENT_PIXMAPID              "meter01_decrement_icon_std.epx"
#define ZMETER1_INDETERMINATE_PIXMAPID          ""

//
// ZMeter2
//
// Background
#define ZMETER2_BG_STD_PIXMAPID                 ""
// Border
#define ZMETER2_BD_STD_PIXMAPID                 ""
// Other
#define ZMETER2_FILLEDSTARTENDCAP_PIXMAPID      "meter02_filled_start_std.epx"
#define ZMETER2_UNFILLEDSTARTENDCAP_PIXMAPID    "meter02_unfilled_start_std.epx"
#define ZMETER2_ACTIVESTARTENDCAP_PIXMAPID      ""
#define ZMETER2_FILLEDFINISHENDCAP_PIXMAPID     "meter02_filled_finish_std.epx"
#define ZMETER2_UNFILLEDFINISHENDCAP_PIXMAPID   "meter02_unfilled_finish_std.epx"
#define ZMETER2_ACTIVEFINISHENDCAP_PIXMAPID     ""
#define ZMETER2_FILLEDSEGMENTIMAGE_PIXMAPID     "meter02_filled_segment_std.epx"
#define ZMETER2_UNFILLEDSEGMENTIMAGE_PIXMAPID   "meter02_unfilled_segment_std.epx"
#define ZMETER2_ACTIVESEGMENTIMAGE_PIXMAPID     ""
#define ZMETER2_INCREMENT_PIXMAPID              "meter01_increment_icon_std.epx"     //dy comment, no this item
#define ZMETER2_DECREMENT_PIXMAPID              "meter01_decrement_icon_std.epx"  //dy comment, no this item
#define ZMETER2_INDETERMINATE_PIXMAPID          ""

//
// ZMeter3
//
// Background
#define ZMETER3_BG_STD_PIXMAPID                 ""
// Border
#define ZMETER3_BD_STD_PIXMAPID                 ""
// Other
#define ZMETER3_FILLEDSTARTENDCAP_PIXMAPID      ""
#define ZMETER3_UNFILLEDSTARTENDCAP_PIXMAPID    ""
#define ZMETER3_ACTIVESTARTENDCAP_PIXMAPID      ""
#define ZMETER3_FILLEDFINISHENDCAP_PIXMAPID     ""
#define ZMETER3_UNFILLEDFINISHENDCAP_PIXMAPID   ""
#define ZMETER3_ACTIVEFINISHENDCAP_PIXMAPID     ""
#define ZMETER3_FILLEDSEGMENTIMAGE_PIXMAPID     ""
#define ZMETER3_UNFILLEDSEGMENTIMAGE_PIXMAPID   ""
#define ZMETER3_ACTIVESEGMENTIMAGE_PIXMAPID     ""
#define ZMETER3_INCREMENT_PIXMAPID                 "meter01_increment_icon_std.epx"      //dy comment, no this item
#define ZMETER3_DECREMENT_PIXMAPID                "meter01_decrement_icon_std.epx"   //dy comment, no this item
#define ZMETER3_INDETERMINATE_PIXMAPID          "meter03_indeterminate_std.g"

//
// ZMeter4 for AIA
//
#define ZMETER4_INDETERMINATE_PIXMAPID          "meter04_indeterminate_std.g"

//
// ZMeterModule
//
// Background
#define ZMETERMODULE_BG_STD_PIXMAPID           ""
// Border
#define ZMETERMODULE_BD_STD_PIXMAPID           ""

//
// ZMultiLineEdit1 dy modified use ZLineEdit bg and border
//
// Background
#define ZMULTILINEEDIT1_BG_STD_PIXMAPID           "field_bg"
// Border
#define ZMULTILINEEDIT1_BD_STD_PIXMAPID           "field"      //dy modified
// Other
#define ZMULTILINEEDIT1_LINE_PIXMAPID             ""

//
// ZMultiLineEdit2, dy added
//
// Background
#define ZMULTILINEEDIT2_BG_STD_PIXMAPID           ""
// Border
#define ZMULTILINEEDIT2_BD_STD_PIXMAPID           ""
// Other
#define ZMULTILINEEDIT2_LINE_PIXMAPID             ""

//
// ZNavTabWidget
//
// Background
#define ZNAVTABWIDGET_NAVTAB_BG_PIXMAPID        "navtab_bg"
#define ZNAVTABWIDGET_TABAREA_BG_PIXMAPID      "navtab_tabarea_bg"  //"navtab_tabarea_bg"
// Border
#define ZNAVTABWIDGET_NAVTAB_BD_PIXMAPID        "navtab"
#define ZNAVTABWIDGET_TABAREA_BD_PIXMAPID      "navtab_tabarea"
//Other
#define ZNAVTABWIDGET_NAVTAB_STD_PIXMAPID       "navtab_tab_std.epx"
#define ZNAVTABWIDGET_NAVTAB_S_PIXMAPID            "navtab_tab_sel.epx"
//
// ZOptionsMenu
//
// Background
#define ZOPTIONSMENU_BG_STD_PIXMAPID            "optmenu_bg"
// Border
#define ZOPTIONSMENU_BD_STD_PIXMAPID            "optmenu"
// Other
#define ZOPTIONSMENU_INCREMENT_PIXMAPID         "optmenu_increment_std.epx"
#define ZOPTIONSMENU_DECREMENT_PIXMAPID         "optmenu_decrement_std.epx"

//
// ZOptionsMenuItem
//
// Background
#define ZOPTIONSMENUITEM_BG_STD_PIXMAPID        "optmenu_item_bg"
// Border
#define ZOPTIONSMENUITEM_BD_STD_PIXMAPID        ""
// Other
#define ZOPTIONSMENUITEM_MARK_PIXMAPID            ""
#define ZOPTIONSMENUITEM_MARK_H_PIXMAPID        "optmenu_mark_indicator_h.epx"
#define ZOPTIONSMENUITEM_MARK_S_PIXMAPID        "optmenu_mark_indicator_sel.epx"
#define ZOPTIONSMENUITEM_MARK_HS_PIXMAPID       "optmenu_mark_indicator_hs.epx"

#define ZOPTIONSMENUITEM_SUB_STD_PIXMAPID       "optmenu_submenu_indicator_std.epx"
#define ZOPTIONSMENUITEM_SUB_H_PIXMAPID           "optmenu_submenu_indicator_h.epx"
#define ZOPTIONSMENUITEM_SUB_S_PIXMAPID           "optmenu_submenu_indicator_sel.epx"
#define ZOPTIONSMENUITEM_SUB_HS_PIXMAPID         "optmenu_submenu_indicator_h.epx"

//
// ZPanel1
//
// Background
#define ZPANEL1_BG_STD_PIXMAPID           "panel01_bg"  //dy modified
// Border
#define ZPANEL1_BD_STD_PIXMAPID           ""

//
// ZPanel2
//
// Background
#define ZPANEL2_BG_STD_PIXMAPID           "panel02_bg"  //dy modified
// Border
#define ZPANEL2_BD_STD_PIXMAPID           ""

//
// ZPopup1
//
// Background
#define ZPOPUP1_BG_STD_PIXMAPID           "popup_bg"
// Border
#define ZPOPUP1_BD_STD_PIXMAPID           "popup"  //dy comment, no this item

 //
 // ZPopup2
 //
 // Background
 #define ZPOPUP2_BG_STD_PIXMAPID           "notipopup_bg"   //dy added
 // Border
 #define ZPOPUP2_BD_STD_PIXMAPID           "notipopup"

// //
// // ZPopup3
// //
// // Background
// #define ZPOPUP3_BG_STD_PIXMAPID           "popup_emgncy_bg"
// // Border
// #define ZPOPUP3_BD_STD_PIXMAPID           "popup_emgncy_b"

//
// ZProgressSlider
//
// Other
#define ZPROGRESSSLIDER_FILLEDSTARTENDCAP_PIXMAPID      "progress_slider_filled_start_std.epx"
#define ZPROGRESSSLIDER_FILLEDFINISHENDCAP_PIXMAPID     "progress_slider_filled_finish_std.epx"
#define ZPROGRESSSLIDER_FILLEDCENTERIMAGE_PIXMAPID      "progress_slider_filled_center_std.epx"

#define ZPROGRESSSLIDER_FILLEDSTARTENDCAP_HS_PIXMAPID      "progress_slider_filled_start_hs.epx"
#define ZPROGRESSSLIDER_FILLEDFINISHENDCAP_HS_PIXMAPID     "progress_slider_filled_finish_hs.epx"
#define ZPROGRESSSLIDER_FILLEDCENTERIMAGE_HS_PIXMAPID      "progress_slider_filled_center_hs.epx"


#define ZPROGRESSSLIDER_FILLEDSTARTENDCAP_H_PIXMAPID      "progress_slider_filled_start_h.epx"
#define ZPROGRESSSLIDER_FILLEDFINISHENDCAP_H_PIXMAPID     "progress_slider_filled_finish_h.epx"
#define ZPROGRESSSLIDER_FILLEDCENTERIMAGE_H_PIXMAPID      "progress_slider_filled_center_h.epx"

#define ZPROGRESSSLIDER_FILLEDSTARTENDCAP_S_PIXMAPID      "progress_slider_filled_start_h.epx"
#define ZPROGRESSSLIDER_FILLEDFINISHENDCAP_S_PIXMAPID     "progress_slider_filled_finish_h.epx"
#define ZPROGRESSSLIDER_FILLEDCENTERIMAGE_S_PIXMAPID      "progress_slider_filled_center_h.epx"

//
// ZRadioButton
//
// Background
#define ZRADIOBUTTON_BG_STD_PIXMAPID        "radiobtn_bg"
// Border
#define ZRADIOBUTTON_BD_STD_PIXMAPID        "radiobtn"
// Other
#define ZRADIOBUTTON_INDICATORH_PIXMAPID       "radiobtn_mark_indicator_h.epx"
#define ZRADIOBUTTON_INDICATORHS_PIXMAPID      "radiobtn_mark_indicator_hs.epx"
#define ZRADIOBUTTON_INDICATORPS_PIXMAPID      "radiobtn_mark_indicator_ps.epx"
#define ZRADIOBUTTON_INDICATORSEL_PIXMAPID     "radiobtn_mark_indicator_sel.epx"
#define ZRADIOBUTTON_INDICATORSTD_PIXMAPID     "radiobtn_mark_indicator_std.epx"

//
// ZScrollBar Normal
//
#define ZSCROLLBAR_INCREMENT_SEL_PIXMAPID       ""
#define ZSCROLLBAR_DECREMENT_SEL_PIXMAPID       ""
#define ZSCROLLBAR_INCREMENT_STD_PIXMAPID       ""
#define ZSCROLLBAR_DECREMENT_STD_PIXMAPID       ""
#define ZSCROLLBAR_THUMB_START_STD_PIXMAPID     "scrollbar_thumb_start_std.epx"
#define ZSCROLLBAR_THUMB_CENTER_STD_PIXMAPID    "scrollbar_thumb_center_std.epx"
#define ZSCROLLBAR_THUMB_FINISH_STD_PIXMAPID    "scrollbar_thumb_finish_std.epx"
#define ZSCROLLBAR_TRACK_START_STD_PIXMAPID     "scrollbar_track_start_std.epx"
#define ZSCROLLBAR_TRACK_CENTER_STD_PIXMAPID    "scrollbar_track_center_std.epx"
#define ZSCROLLBAR_TRACK_FINISH_STD_PIXMAPID    "scrollbar_track_finish_std.epx"

//
// ZScrollBar Input
//
#define ZSCROLLBAR_INPUT_INCREMENT_SEL_PIXMAPID         ""
#define ZSCROLLBAR_INPUT_DECREMENT_SEL_PIXMAPID         ""
#define ZSCROLLBAR_INPUT_INCREMENT_STD_PIXMAPID         ""
#define ZSCROLLBAR_INPUT_DECREMENT_STD_PIXMAPID         ""
#define ZSCROLLBAR_INPUT_THUMB_START_STD_PIXMAPID       "scrollbar_input_thumb_start_std.epx"
#define ZSCROLLBAR_INPUT_THUMB_CENTER_STD_PIXMAPID      "scrollbar_input_thumb_center_std.epx"
#define ZSCROLLBAR_INPUT_THUMB_FINISH_STD_PIXMAPID      "scrollbar_input_thumb_finish_std.epx"
#define ZSCROLLBAR_INPUT_TRACK_START_STD_PIXMAPID       "scrollbar_input_track_start_std.epx"
#define ZSCROLLBAR_INPUT_TRACK_CENTER_STD_PIXMAPID      "scrollbar_input_track_center_std.epx"
#define ZSCROLLBAR_INPUT_TRACK_FINISH_STD_PIXMAPID      "scrollbar_input_track_finish_std.epx"

//
// ZScrollBar Field
//
#define ZSCROLLBAR_FIELD_INCREMENT_SEL_PIXMAPID         ""
#define ZSCROLLBAR_FIELD_DECREMENT_SEL_PIXMAPID         ""
#define ZSCROLLBAR_FIELD_INCREMENT_STD_PIXMAPID         ""
#define ZSCROLLBAR_FIELD_DECREMENT_STD_PIXMAPID         ""
#define ZSCROLLBAR_FIELD_THUMB_START_STD_PIXMAPID       "scrollbar_field_thumb_start_std.epx"
#define ZSCROLLBAR_FIELD_THUMB_CENTER_STD_PIXMAPID      "scrollbar_field_thumb_center_std.epx"
#define ZSCROLLBAR_FIELD_THUMB_FINISH_STD_PIXMAPID      "scrollbar_field_thumb_finish_std.epx"
#define ZSCROLLBAR_FIELD_TRACK_START_STD_PIXMAPID       "scrollbar_field_track_start_std.epx"
#define ZSCROLLBAR_FIELD_TRACK_CENTER_STD_PIXMAPID      "scrollbar_field_track_center_std.epx"
#define ZSCROLLBAR_FIELD_TRACK_FINISH_STD_PIXMAPID      "scrollbar_field_track_finish_std.epx"

//
// ZScrollBar CLI
//
#define ZSCROLLBAR_CLI_INCREMENT_SEL_PIXMAPID         ""
#define ZSCROLLBAR_CLI_DECREMENT_SEL_PIXMAPID         ""
#define ZSCROLLBAR_CLI_INCREMENT_STD_PIXMAPID         ""
#define ZSCROLLBAR_CLI_DECREMENT_STD_PIXMAPID         ""
#define ZSCROLLBAR_CLI_THUMB_START_STD_PIXMAPID       "cli_scrollbar_thumb_start_std.epx"
#define ZSCROLLBAR_CLI_THUMB_CENTER_STD_PIXMAPID      "cli_scrollbar_thumb_center_std.epx"
#define ZSCROLLBAR_CLI_THUMB_FINISH_STD_PIXMAPID      "cli_scrollbar_thumb_finish_std.epx"
#define ZSCROLLBAR_CLI_TRACK_START_STD_PIXMAPID       "cli_scrollbar_track_start_std.epx"
#define ZSCROLLBAR_CLI_TRACK_CENTER_STD_PIXMAPID      "cli_scrollbar_track_center_std.epx"
#define ZSCROLLBAR_CLI_TRACK_FINISH_STD_PIXMAPID      "cli_scrollbar_track_finish_std.epx"

//
// ZScrollView
//
// Other
#define ZSCROLLVIEW_FILLGRAPHIC_PIXMAPID        "scroll_panel_img_fill.epx"

//
// ZSegmentField
//

//
// ZSeparator1
//
#define ZSEPARATOR1_RIGHTSTRETCH_PIXMAPID           "separator_img_right_std.epx"
#define ZSEPARATOR1_LEFTSTRETCH_PIXMAPID            "separator_img_left_std.epx"

//
// ZSeparator2
//
#define ZSEPARATOR2_RIGHTSTRETCH_PIXMAPID           "separator_opt_img_right_std.epx"
#define ZSEPARATOR2_LEFTSTRETCH_PIXMAPID            "separator_opt_img_left_std.epx"

//
// ZSettingItem
//
// Background
#define ZSETTINGITEM_BG_STD_PIXMAPID           "setting_bg"
// Border
#define ZSETTINGITEM_BD_STD_PIXMAPID           "setting"

#define ZSETTINGITEM_MARK_PIXMAPID             "chkbx_mark_indicator_sel.epx"
#define ZSETTINGITEM_UNMARK_PIXMAPID           "chkbx_mark_indicator_std.epx"

//
//ZSingleSelect, dy added, currently not be used
//
#define ZSINGLESELECT_MARK_CHECK_STD_PIXMAPID           "singlesel_mark_indicator_sel.epx"
#define ZSINGLESELECT_MARK_UNCHECK_STD_PIXMAPID       "singlesel_mark_indicator_std.epx"
#define ZSINGLESELECT_MARK_PCHECK_STD_PIXMAPID          "singlesel_mark_indicator_ps.epx"
#define ZSINGLESELECT_MARK_CHECK_H_PIXMAPID                "singlesel_mark_indicator_hs.epx"
#define ZSINGLESELECT_MARK_UNCHECK_H_PIXMAPID           "singlesel_mark_indicator_h.epx"

//
// ZSlider
//
// Other
#define ZSLIDER_INCREMENT_STD_PIXMAPID          "slider_increment_icon_std.epx"
#define ZSLIDER_INCREMENT_S_PIXMAPID            "slider_increment_icon_h.epx"
#define ZSLIDER_INCREMENT_H_PIXMAPID            "slider_increment_icon_h.epx"
#define ZSLIDER_INCREMENT_HS_PIXMAPID           "slider_increment_icon_hs.epx"

#define ZSLIDER_DECREMENT_STD_PIXMAPID          "slider_decrement_icon_std.epx"
#define ZSLIDER_DECREMENT_H_PIXMAPID            "slider_decrement_icon_h.epx"
#define ZSLIDER_DECREMENT_S_PIXMAPID            "slider_decrement_icon_h.epx"
#define ZSLIDER_DECREMENT_HS_PIXMAPID           "slider_decrement_icon_hs.epx"

#define ZSLIDER_THUMBH_STD_PIXMAPID             "slider_thumb_horz_std.epx"
#define ZSLIDER_THUMBH_H_PIXMAPID               "slider_thumb_horz_h.epx"
#define ZSLIDER_THUMBH_S_PIXMAPID               "slider_thumb_horz_h.epx"
#define ZSLIDER_THUMBH_HS_PIXMAPID              "slider_thumb_horz_hs.epx"

#define ZSLIDER_THUMBV_STD_PIXMAPID             "slider_thumb_vert_std.epx"
#define ZSLIDER_THUMBV_H_PIXMAPID               "slider_thumb_vert_h.epx"
#define ZSLIDER_THUMBV_S_PIXMAPID               "slider_thumb_vert_h.epx"
#define ZSLIDER_THUMBV_HS_PIXMAPID              "slider_thumb_vert_hs.epx"

#define ZSLIDER_STARTENDCAP_HS_PIXMAPID            "slider_track_start_hs.epx"
#define ZSLIDER_TRACKFINISHENDCAP_HS_PIXMAPID      "slider_track_finish_hs.epx"
#define ZSLIDER_TRACKCENTERIMAGE_HS_PIXMAPID       "slider_track_center_hs.epx"

#define ZSLIDER_STARTENDCAP_H_PIXMAPID            "slider_track_start_h.epx"
#define ZSLIDER_TRACKFINISHENDCAP_H_PIXMAPID      "slider_track_finish_h.epx"
#define ZSLIDER_TRACKCENTERIMAGE_H_PIXMAPID       "slider_track_center_h.epx"

#define ZSLIDER_STARTENDCAP_PIXMAPID            "slider_track_start_std.epx"
#define ZSLIDER_TRACKFINISHENDCAP_PIXMAPID      "slider_track_finish_std.epx"
#define ZSLIDER_TRACKCENTERIMAGE_PIXMAPID       "slider_track_center_std.epx"


//
// ZSoftKeyLeft
//
// Background
#define ZSOFTKEYLEFT_BG_STD_PIXMAPID           "softkey_lft_bg"
// Border
#define ZSOFTKEYLEFT_BD_STD_PIXMAPID           "softkey_lft"   //dy comment, no this item

//
// ZSoftKeyRight
//
// Background
#define ZSOFTKEYRIGHT_BG_STD_PIXMAPID           "softkey_rgt_bg"
// Border
#define ZSOFTKEYRIGHT_BD_STD_PIXMAPID           "softkey_rgt"   //dy comment, no this item

//
// ZSoftKey Middle
//
// Background
#define ZSOFTKEYMIDDLE_BG_STD_PIXMAPID           "softkey_mid_bg"
// Border
#define ZSOFTKEYMIDDLE_BD_STD_PIXMAPID           "softkey_mid"  //dy comment, no this item

#define ZICONVIEWITEM1_CHECK_PIXMAPID            ""             //cao jinghua comment, no this item, for compiling
#define ZICONVIEWITEM1_UNCHECK_PIXMAPID          ""             //cao jinghua comment, no this item, for compiling


//
// ZSplitPane
//
// Other
#define ZSPLITPANE_DIVIDER_PIXMAPID             "splitpane_divider_std.epx"

// See comments above.
// #endif  // #ifdef BARBADOS

#endif  // __ZSKINPIXMAPIDS_H__
