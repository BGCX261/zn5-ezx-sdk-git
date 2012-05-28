//--------------------------------------------------------------------------------------------------
//
//   Header Name: ZInputField.h
//
//   General Description: Abstract interface to control editor. 
//
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
// li jun/a18547                3/16/2005                           Initial version
//
//
//--------------------------------------------------------------------------------------------------
#ifndef Z_INPUT_FIELD_H
#define Z_INPUT_FIELD_H

#ifndef __cplusplus
#error "This is a C++ header file;it requires C++ to compile."
#endif

//--------------------------------------------------------------------------------------------------
//                                       INCLUDE FILES
//--------------------------------------------------------------------------------------------------
#include "ZKbGlobal.h"
#include "ZKbInputField.h"
#include <qobject.h>

    /**
     * Field's default length
     */
#define INPUT_FIELD_DEFAULT_LEN 50
//the gap between char and the underline, this value is a skin value.
#define INPUT_FIELD_GAP_BETWEEN_CHAR_AND_UNDERLINE 1


class ZInputField;
class QWidget; 

typedef ZInputField ZKbCommonInputField;

//-----------------------------------------------------------------------------------------------------
//                                            CLASS DECLARATIONS
//-----------------------------------------------------------------------------------------------------


/**
 * This interface defines a registration agent and a event filter which is
 * used to monitor the events from ZInputField objects so as to drive the
 * text entry. 
 */

struct ZInputFieldEventFilter
: public QObject
{
    
    ZInputFieldEventFilter(QObject * parent=NULL): QObject(parent)
    {
    }
    
    virtual ~ZInputFieldEventFilter() {}

    
    /**
    * The input field calls this function to let the input field adaptor 
    * to monitor its events, including 
    *    QFocusEvent :  focus changing event 
    *    QMouseEvent :  mouse action event
    *    QModifyEvent:  text changing event 
    *    QKeyEvent   :  key action event 
    *    QCursorEvent:   editor's cursor action event 
    */
    virtual bool eventFilter(ZInputField* field, ZEvent * e)=0; 	


    /**
     * Alocate, initialize and register native instance of an input field
     * This method is intended to be called only by an InputAdapter instance.
     * @param field Input field   
     */
    virtual bool registerField(ZInputField* field)=0;

    /**
     * Unregister and dispose native instance of an input field
     * This method is intended to be called only by an InputAdapter instance.
     * (usually when assiciated widget is disposed)   
     * @param field Input field   
     */
    virtual bool unregisterField(ZInputField* field)=0;

}; 



struct ZInlineEditing
{
    /**
     * A field's text.
     * @param pos position where to get the text , invalid position (-1,-1) means the whole text
     * @param forward the direction to get the text
     * @return text
     */
    virtual ZString getText(ZPoint pos , bool forward)=0;
    
        
    /**
     * A command to set a field's text. A Field can ignore it and process only 
     * <code>delete</code> and <code>insert</code> commands.
     * @param text field's text
     */
    virtual void setText(ZString text)=0;

    
    /**
     * A cursor position in the field's text.
     * @return cursor position
     */
    virtual ZPoint getCursorPos()=0; 


    /**
     * A command to set the cursor position in the text.
     * @param pos start cursor position
     * @param offset the moving length from the start pos, nagtive to left, positive to right
     * @retval return the current cursor position 
     */
    virtual ZPoint setCursorPos(ZPoint start_pos, int offset, bool update = true)=0;
    

    /**
     * The possible values for the <code>type</code> are: CURSOR_NONE, CURSOR_BLOCK, CURSOR_BAR
     * @param type cursor type  
     */
    virtual void setCursorType(int type)=0;

    /**
     * The possible values for the <code>flag</code> are: ZKB_CF_NONE, ZKB_CF_L2R, ZKB_CUF_R2L. 
     * @param flag cursor flag
     */
    virtual void setCursorFlag(int flag)=0;
        
    /**
     * The possible values for the <code>direction</code> are: ASTAT_L2R_CURSOR, ASTAT_R2L_CURSOR
     * @param direction cursor direction  
     */
    virtual void setCursorDirection(int direction)=0;


    /**
     * A command to show a hint for a suggested completition in reverse video.
     * @param pos starting position of the reverse video (completion)
     * @param len length of reverse video  
     */
    virtual void setReverse(ZPoint pos, int len, bool update=true)=0;


    /**
     * A command to remove the current reverse state without removing string 
     */
    virtual void clearReverse(bool update=true)=0;
    
    
    /**
     * A command to show a hint for a text part subject for disambiquation when in 
     * predictive mode.   
     * @param pos starting position of the underlined part
     * @param len length of the underlined part
     * @param alternateAvailable to show a hint for availability of alternates when in predictive mode.   
     */
    virtual void setUnderline(ZPoint pos, int len, bool alternateAvailable, bool update=true)=0;

    /*
     * A command to remove the current underline without removing string 
     */
    virtual void clearUnderline(bool update=true)=0;



    /**
     * A command to delete a part of the text. Usually it will be pared with the <code>insert</code> command
     * @param pos position to start deleting the text
     * @param len number of characters to delete 
     */
    virtual void deleteString(ZPoint start_pos, int len,  bool autoUpdate=true )=0;

    /**
     * A command to insert a text at the given positioni. Usually it will be pared with the <code>delete</code> command
     * @param pos position to start inserting the text 
     * @param text text to insert 
     */
    virtual void insertString(ZPoint start_pos, ZString text, bool update=true)=0;

    /*
     * @param cursorPos: the cursor position in the inserted string.
     */
    virtual void insertString(ZPoint start_pos , ZString text , int reverse_start , int reverse_len , int underline_start , int underline_len , bool alternateAvailable,int cursorPos )=0;

    /**
     * A command to insert an image at the given positioni. Usually it will be pared with the <code>delete</code> command
     * @param pos position to start inserting the image 
     * @param icon icon name to insert 
     */
    virtual void insertImage(ZPoint start_pos, ZString icon)=0;

    
    /**
     * A callback method that <code>InputEngine</code> will call when time comes
     * to learn the field's text. The parameter is an unformatted string, The return value 
     * is the formatted String.    
     */
    virtual ZString format(ZString text)=0;


    /**
     * A callback method that <code>InputEngine</code> will call when time comes to
     * to compute position of the UI popup with alternatives and helper tooltips.
     * @return boundindg rectangle of the field on the screen 
     */
    virtual ZRect getFieldBounds()=0;
    
    /**
     * A callback method that <code>InputEngine</code> will call when time comes to
     * to compute position of the UI popup with alternatives and helper tooltips.
     * 
     * @param pos of a character in the field's text
     * @return boundindg rectangle of the character in the field's recctangle 
     */
    virtual ZRect getCharBounds(ZPoint pos)=0;

    virtual ZRect getUnderlineBounds(ZPoint pos)=0;
    /**
     * A  method that <code>InputEngine</code> will call before insert a char 
     * or string in the editor. If there is a validator, the engine should call 
     * canInsertString to confirm the string can insert or not.
     * @return  true if the editor has a valid and not empty validator
     */
    virtual bool  hasValidator(void) = 0;
    /**
     * A  method that <code>InputEngine</code> will call before insert a char 
     * or string in the editor. If there is a validator, this methods should be called 
     * to confirm the char can insert or not.
     * @param the QString that engine want to insert.
     * @return  true if all the char of the string can be inserted.
     */
    virtual bool  canInsertString(const QString& string) = 0;
    
}; 



struct ZInlineEditInfo
{
    /**
     *  return the widget pointer the input field supports
     * @retval the widget pointer
     *
     */
    virtual QWidget * getEditorWidget()=0;
    
    /**
     * get the WinId of the edit widget the input field binds.
     * @retval the WinId of the edit widget
     * 
     */
    virtual int getWinId()=0;


    /**
     * get the WinId of the top level widget the edit widget lives.
     * @retval the toplevel windget WinId. 
     *
     */
    virtual int getTopWidgetWinId()=0; 

    /**
     * register the input field adapter in the field, and let the adapter to monitor all
     * events from the input field.
     * @param pointer to the input field event fiter
     */
    
    virtual void  enableFilter(bool enable)=0; 
    
}; 



/**
 * This interface defines a consumer of the InputService. InputField acts as a View for a  
 * text model maintained by the InputService. InputField should not implement any logic 
 * to process text editing. It blindly passes all input events to the service and executes 
 * commands invoked by the service.  
 *   
 *
 */

struct ZInputFieldData;

class ZInputField:
    public QObject, 
    public ZKbInputField,
    public ZInlineEditing,
    public ZInlineEditInfo
{
    
  public:
    // construction/destruction 
// default construction 
    ZInputField(QWidget * editWidget); 
    
// default destruction
    virtual ~ZInputField(); 

  public: // member functions of the interface ZKbInputField
    /**
     * set the name of the field, which is used to label and differentiate the field from others
     * @param fieldName the name given to the field 
     */
    virtual void setFieldName(const char* fieldName);
    
    /**
     * get the field name
     * @retval the field name to be gotten
     */
    virtual const char* getFieldName();
    

    /** 
     * A <code>type</code> is a value, that defines the semantic of the field.
     * This can be one of the predefined by the Input Method Framework types 
     * The existing field types are:
     * <pre>
     * FIELD_TYPE_REGULAR general text (messages, notes)
     * FIELD_TYPE_NAME last name, first name
     * FIELD_TYPE_EMAILADDR email address
     * FIELD_TYPE_URL URL
     * FIELD_TYPE_PHONENUMBER phone number
     * FIELD_TYPE_FDN Fixed Dialling number
     * FIELD_TYPE_DIALER dialer field
     * FIELD_TYPE_NUMERIC digits only
     * FIELD_TYPE_ZIP zip-code
     * FIELD_TYPE_PASSWORD password
     * FIELD_TYPE_SEARCHFIELD search field
     * FIELD_TYPE_NUMPLUS sdk number field
     * FIELD_TYPE_MULTIPHONENUMBER multi phone number field
     * </pre>     
     * @return type 
     */ 

    virtual int getType() const;

    /**
     * set the field type
     * @param fieldType define the field type of the current edit field 
     */
    virtual void setType(int fieldType);

    /**
     * set the field options
     * @param fieldOptions define the field option of the current edit field
     * @param optionData the addtional data for seting the option.
     * @note: some field options depends on field type. So suggest set field type first.
     */
    virtual void setOptions(int fieldOptions, long optionData = 0);

    /**
     * The existing field options are:
     * <pre>
     * FIELD_OPTION_HYPHEN Show hyphen in phone number field type
     * </pre>
     *  @param the option type, the default is composite options
     *  @return the option addtional data, if the option id is less than 100, return the option composite data.
     */
    virtual long getOptions(int optionType = FIELD_OPTION_COMPOSITE_OPTIONS) const;

    /**
     * Define a preferred input mode list so that just the input modes in the list are available
     * while others are excluded when text entry. The preferred input modes should be saved in the preferredKbList
     * in advance. The input method lists are
     *
     * <pre>
     * ZKB_INPUT_MULTITAP        multitap input mode for keypad
     * ZKB_INPUT_PREDICTIVE      predictive input mode for keypad
     * ZKB_INPUT_PINYIN_TS       Pinyin Soft keyboard for touch screen
     * ZKB_INPUT_HANDWRITING_TS  Handwriting input method for touch screen
     * </pre>
     * 
     * @param preferredKbList holds the preferred input method ID.
     */
    
    virtual void setPreferredInputModes(const QValueList<QUuid> & preferredKbList, const QUuid & defaultKb); 
    
    /**
     * get the preferred input mode list the input field defines in advance.The incoming array
     * will hold the preferred input methods the input field defines. 
     *@param preferredKbList returns the preferred input modes the field defines,
     *@retval return TRUE if the operation is successful. 
     *
     * for example:
     * 
     *       ZInputField * field;
     *       QValueList<QUuid> kbList; 
     *       field->getPreferredInputModes(kbList); // get the input method lists. 
     * 
     */
    virtual bool getPreferredInputModes( QValueList<QUuid> & preferredKbList, QUuid & defaultKb) const; 

    
    /**
     * the editType means whether or not the editor represented by the input field is accompanied with an input field object.
     * @ retval the edit type, the value is between
     * <pre>
     * ZKB_GENERAL_EDIT   the editor is not accompanied by a input field object, such as QLineEdit and QMultiLineEdit 
     * ZKB_SUPPORTED_EDIT  the editor is accompanied with a input field, such as ZMulitLineEdit and ZLineEdit 
     **/
    virtual int editType() const;  

  public:
    // member of the interface ZInlineEditInfo
    
    /**
     * get the WinId of the edit widget the input field binds.
     * @retval the WinId of the edit widget
     * 
     */
    virtual int getWinId();


    /**
     * get the WinId of the top level widget the edit widget lives.
     * @retval the toplevel windget WinId. 
     *
     */
    virtual int getTopWidgetWinId(); 

    /**
     * register the input field adapter in the field, and let the adapter to monitor all
     * events from the input field.
     * @param pointer to the input field event fiter
     */
    
    virtual void  enableFilter(bool enable); 


    /**
     *  return the widget pointer the input field supports
     * @retval the widget pointer
     *
     */
    virtual QWidget * getEditorWidget();



  public:
    // members of the interface ZInlineEditing 
    /**
     * A field's text.
     * @param pos position where to get the text , invalid position (-1,-1) means the whole text
     * @param forward the direction to get the text
     * @return text
     */
    virtual ZString getText(ZPoint pos , bool forward);
    
    
    /**
     * A cursor position in the field's text.
     * @return cursor position
     */
    virtual ZPoint getCursorPos(); 


    /**
     * A command to set a field's text. A Field can ignore it and process only 
     * <code>delete</code> and <code>insert</code> commands.
     * @param text field's text
     */
    virtual void setText(ZString text);
    
    
    /**
     * A command to set the cursor position in the text.
     * @param pos start cursor position
     * @param offset the moving length from the start pos, nagtive to left, positive to right
     * @retval return the current cursor position 
     */
    virtual ZPoint setCursorPos(ZPoint start_pos, int offset, bool update = true);

    /**
     * The possible values for the <code>type</code> are: CURSOR_NONE, CURSOR_BLOCK, CURSOR_BAR
     * @param type cursor type  
     */
    virtual void setCursorType(int type);

    /**
     * The possible values for the <code>flag</code> are: ZKB_CF_NONE, ZKB_CF_L2R, ZKB_CUF_R2L. 
     * @param flag cursor flag
     */
    virtual void setCursorFlag(int flag);
        
    /**
     * The possible values for the <code>direction</code> are: ASTAT_L2R_CURSOR, ASTAT_R2L_CURSOR
     * @param direction cursor direction  
     */
    virtual void setCursorDirection(int direction);

    /**
     * A command to show a hint for a suggested completition in reverse video.
     * @param pos starting position of the reverse video (completion)
     * @param len length of reverse video  
     */
    virtual void setReverse(ZPoint pos, int len, bool update=true);

    /**
     * A command to remove the current reverse state without removing string 
     */
    virtual void clearReverse(bool update=true);
    
    
    /**
     * A command to show a hint for a text part subject for disambiquation when in 
     * predictive mode.   
     * @param pos starting position of the underlined part
     * @param len length of the underlined part
     * @param alternateAvailable to show a hint for availability of alternates when in predictive mode.   
     */
    virtual void setUnderline(ZPoint pos, int len, bool alternateAvailable, bool update=true);

    /*
     * A command to remove the current underline without removing string 
     */
    virtual void clearUnderline(bool update=true);


    /**
     * A command to delete a part of the text. Usually it will be pared with the <code>insert</code> command
     * @param pos position to start deleting the text
     * @param len number of characters to delete 
     */
    virtual void deleteString(ZPoint start_pos, int len,  bool autoUpdate=true );


    /**
     * A command to insert a text at the given positioni. Usually it will be pared with the <code>delete</code> command
     * @param pos position to start inserting the text 
     * @param text text to insert 
     */
    virtual void insertString(ZPoint start_pos, ZString text, bool update=true);
    
    /*
     * @param cursorPos: the cursor position in the inserted string.
     */
    virtual void insertString(ZPoint start_pos , ZString text , int reverse_start , int reverse_len , int underline_start , int underline_len , bool alternateAvailable,int cursorPos);

    /**
     * A command to insert an image at the given positioni. Usually it will be pared with the <code>delete</code> command
     * @param pos position to start inserting the image 
     * @param icon icon name to insert 
     */
    virtual void insertImage(ZPoint start_pos, ZString icon);

    
    /**
     * A callback method that <code>InputEngine</code> will call when time comes
     * to learn the field's text. The parameter is an unformatted string, The return value 
     * is the formatted String.    
     */
    virtual ZString format(ZString text);

    /**
     * A callback method that <code>InputEngine</code> will call when time comes to
     * to compute position of the UI popup with alternatives and helper tooltips.
     * @return boundindg rectangle of the field on the screen 
     */
    virtual ZRect getFieldBounds();
    
    /**
     * A callback method that <code>InputEngine</code> will call when time comes to
     * to compute position of the UI popup with alternatives and helper tooltips.
     * 
     * @param pos of a character in the field's text
     * @return boundindg rectangle of the character in the field's recctangle 
     */
    virtual ZRect getCharBounds(ZPoint pos);

    virtual ZRect getUnderlineBounds(ZPoint pos);

    /**
     * A function to get max length of input field.
     * If there's no limit, then return -1
     */
    virtual int maxLength(); 

    /**
     * A function to judge whether this editor is refocus. 
     * Refocus means editor is focused out by pressed option menu or matrix/alternate list is popuped
     * This function is internally used
     */
    bool isReFocused();

    /**
     * A function to set refocus flag
     * Refocus means editor is focused out by pressed option menu or matrix/alternate list is popuped
     * This function is internally used
     */
    void setRefocusdFlag(bool );
    
    /**
     * A  method that <code>InputEngine</code> will call before insert a char 
     * or string in the editor. If there is a validator, the engine should call 
     * canInsertString to confirm the string can insert or not.
     * @return  true if the editor has a valid and not empty validator
     */
    virtual bool  hasValidator(void) {return false;};
    /**
     * A  method that <code>InputEngine</code> will call before insert a char 
     * or string in the editor. If there is a validator, this methods should be called 
     * to confirm the char can insert or not.
     * @param the QString that engine want to insert.
     * @return  true if all the char of the string can be inserted.
     */
    virtual bool  canInsertString(const QString& string){return true;};
    
#ifdef MAKE_TOUCHSCREEN_SUPPORT 
    /*
     * set the field type to pass word type if the editor's echo mode is password
     */
    void autoSetType();
#endif     
  protected:
    // members of the class QObject 
    virtual bool eventFilter ( QObject * o, QEvent * e);


  protected: 
    ZInputFieldData * d; 
};


#endif
