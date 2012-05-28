#ifndef ZKBWRITINGSYSTEM_H_
#define ZKBWRITINGSYSTEM_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

/// \file ZStructureDataParser.h
///
/// \brief This file serves as a "C++" header file template for use with the Doxygen document
///        generation tool.  It contains a sample set of constants, macros, enums, structs,
///        global variables, function prototypes, and class definitions that would be required
///        by applications.
///
/// \if MOTOROLA_CONFIDENTIAL_PROPRIETARY
///--------------------------------------------------------------------------------------------------
///
///                            Motorola Confidential Proprietary
///                                   Template Version 1.1
///                    (c) Copyright Motorola 2006, All Rights Reserved
///
///
/// Internal Revision History:
///                             Modification     Tracking
/// Author                          Date          Number     Description of Changes
/// -------------------------   ------------    ----------   ----------------------------------------
/// Zhang Yueting/e7366c         06/15/2006      LIByyXXXXX   Using standard comments
///
/// \endif
///
///
/// External Revision History:
///
/// Modification      Release
///     Date            ID         Description of Changes
/// ------------   -------------   --------------------------------
/// MM/DD/YYYY     SDK_Version_X   <Description>
///
///
//--------------------------------------------------------------------------------------------------
//                                       INCLUDE FILES
//--------------------------------------------------------------------------------------------------
#include <qvaluelist.h>
#include <qstringlist.h>
#include "ZLanguage.h"

class ZKbWritingSystem
{
public:

    //--------------------------------------------------------------------------------------------------
    //                                         ENUMS
    //--------------------------------------------------------------------------------------------------
    typedef enum WritingSystemId{
        TD_WSID_ROMAN = ZLanguage::TD_LNGID_NUM_OF_LANGUAGES,        //Roman. To avoid overlaping with languages.
        TD_WSID_HEBREW,       //Hebrew
        TD_WSID_ARABIC,       //Arabic
        TD_WSID_CYRILLIC,     //Cyrillic
        TD_WSID_CHINESE,      //Chinese
        TD_WSID_GREEK,        //Greek
        TD_WSID_THAI,         //Thai
        TD_WSID_HINDI,        //Hindi
        TD_WSID_INVALID       //invalid
    };

    //================================================================================================
    ///
    /// Get the writing system ID with writing system Code 
    ///
    /// \par Sync (or) Async:
    /// This is a Synchronous function.
    ///
    /// \par Important Notes:
    /// - Note: \n
    ///
    /// \warning
    ///
    /// \param writingSystemCode  will be the writing system code.
    ///
    /// \return writing system ID
    ///
    /// \par Prospective Clients:
    /// External Classes.
    ///
    /// \par Example of how this function would be called:
    /// \code
    /// ...
    /// QString theCode = "Roman";
    /// ZWritingSystemId theZWritingSystemId;
    /// theZWritingSystemId = ZKbWritingSystem::getWritingSystemIdByWritingSystemCode(theCode);
    /// ...
    /// \endcode
    ///
    //================================================================================================
    static WritingSystemId getWritingSystemIdByWritingSystemCode(QString writingSystemCode);
    //================================================================================================
    ///
    /// Get the WritingSystem Code with writing System ID
    ///
    /// \par Sync (or) Async:
    /// This is a Synchronous function.
    ///
    /// \par Important Notes:
    /// - Note: \n
    ///
    /// \warning
    ///
    /// \param writingSystemId will be the writing system id.
    ///
    /// \return writing system code
    ///
    /// \par Prospective Clients:
    /// External Classes.
    ///
    /// \par Example of how this function would be called:
    /// \code
    /// ...
    /// QString theCode;
    /// ZWritingSystemId theZWritingSystemId = ZKbWritingSystem::TD_WSID_ROMAN;
    /// theCode = ZKbWritingSystem::getWritingSystemCodeByWritingSystemId(theZWritingSystemId);
    /// ...
    /// \endcode
    ///
    //================================================================================================
    static QString  getWritingSystemCodeByWritingSystemId(WritingSystemId writingSystemId);
    //================================================================================================
    ///
    /// Get writing system using language ID
    ///
    /// \par Sync (or) Async:
    /// This is a Synchronous function.
    ///
    /// \par Important Notes:
    /// - Note: \n
    ///
    /// \warning
    ///
    /// \param writingSystemId will be the language id.
    ///
    /// \return writing system ID
    ///
    /// \par Prospective Clients:
    /// External Classes.
    ///
    /// \par Example of how this function would be called:
    /// \code
    /// ...
    /// int theLangID = 3;
    /// ZWritingSystemId theZWritingSystemId;
    /// theZWritingSystemId = ZKbWritingSystem::getWritingSystemID(theLangID);
    /// ...
    /// \endcode
    ///
    //================================================================================================
    static WritingSystemId getWritingSystemID(int languageID);
    //================================================================================================
    ///
    /// Get supported writing system ID, and store them into a list
    ///
    /// \par Sync (or) Async:
    /// This is a Synchronous function.
    ///
    /// \par Important Notes:
    /// - Note: \n
    ///
    /// \warning
    ///
    /// \return writing system ID list
    ///
    /// \par Prospective Clients:
    /// External Classes.
    ///
    /// \par Example of how this function would be called:
    /// \code
    /// ...
    /// QValueList<WritingSystemId> theWSList;
    ///
    /// theWSList = ZKbWritingSystem::getSupportedWritingSystem();
    /// ...
    /// \endcode
    ///
    //================================================================================================
    static QValueList<WritingSystemId> getSupportedWritingSystem();
    //================================================================================================
    ///
    /// Verify if the given writing system id can be supported.
    ///
    /// \par Sync (or) Async:
    /// This is a Synchronous function.
    ///
    /// \par Important Notes:
    /// - Note: \n
    ///
    /// \warning
    ///
    /// \param writingSystemId will be the language id.
    ///
    /// \return true-can be supported, false-can not be supported
    ///
    /// \par Prospective Clients:
    /// External Classes.
    ///
    /// \par Example of how this function would be called:
    /// \code
    /// ...
    /// ZWritingSystemId theZWritingSystemId = ZKbWritingSystem::TD_WSID_ROMAN;
    ///
    /// if(ZKbWritingSystem::isSupportedWritingSystem(theZWritingSystemId))
    /// {
    ///     ...
    /// }
    /// \endcode
    ///
    //================================================================================================
    static bool isSupportedWritingSystem(WritingSystemId theWritingSystemID);
};
typedef ZKbWritingSystem::WritingSystemId ZWritingSystemId;
#endif /*ZKBWRITINGSYSTEM_H_*/
