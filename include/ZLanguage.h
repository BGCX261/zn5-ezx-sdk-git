#ifndef ZLANGUAGE_H
#define ZLANGUAGE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//--------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
//                    (c) Copyright Motorola 2002-2003, All Rights Reserved
//
//
// Revision History:
//                             Modification     Tracking
// Author (core ID)                Date          Number     Description of Changes
// -------------------------   ------------    ----------   ----------------------------------------
// Wang Mingju/w20128            03/20/2003     LIBbb88079  Created
// Wang Yajun/w20506             08/15/2003     LIBbb66186  For E680 STK(Add a field of drmLangCode
//                                                          in mcc, to map current language code to
//                                                          DRM code(ISO 936-1))
// Wang Guochen/a17530           04/12/2004     LIBdd96947  Implement CPHS in Utility for A780
// Edward Wang/a17530            06/08/2004     LIBee18863  bugs fix for 780 util
// Edward Wang/a17530            07/13/2004     LIBee32820  Fix Language Prompt issue.
// Wang Lisa(a17783)             10/19/2004     LIBff09790  Add Language ID
// Ou Wensheng/e12058            09/23/2005     LIBhh03408  Add Language ID
//
//--------------------------------------------------------------------------------------------------
//                                       INCLUDE FILES
//--------------------------------------------------------------------------------------------------

/**
 * @file ZLanguage.h
 * @brief system language api
 */

#include <qstring.h>
//#include "EZX_TypeDefs.h"

class ZLanguage
{
public:
    // language id define value
    typedef enum LanguageId
    {
        TD_LNGID_ENGLISH = 0,    // English
        TD_LNGID_GERMAN,         // German
        TD_LNGID_DANISH,         // Danish
        TD_LNGID_FRENCH,         // French
        TD_LNGID_ITALIAN,        // Italian
        TD_LNGID_SPANISH,        // Spanish
        TD_LNGID_SWEDISH,        // Swedish
        TD_LNGID_DUTCH,          // Dutch
        TD_LNGID_PORTUGUESE,     // Portuguese
        TD_LNGID_FINNISH,        // Finnish
        TD_LNGID_NORWEGIAN,      // Norwegian
        TD_LNGID_GREEK,          // Greek
        TD_LNGID_HUNGARIAN,      // Hungarian
        TD_LNGID_TURKISH,        // Turkish
        TD_LNGID_POLISH,         // Polish
        TD_LNGID_THAI,           // Thai
        TD_LNGID_VIETNAMESE,     // Vietnamese
        TD_LNGID_MALAY,          // Malay
        TD_LNGID_INDONESIAN,     // Indonesian
        TD_LNGID_TAGALOG,        // Tagalog
        TD_LNGID_CHINESE,        // Simplified Chinese
        TD_LNGID_CZECH,          // Czech
        TD_LNGID_TRAD_CHINESE,   // Traditional Chinese
        TD_LNGID_BULGARIAN,      // Bulgarian
        TD_LNGID_CROATIAN,       // Croatian
        TD_LNGID_ESTONIAN,       // Estonian
        TD_LNGID_LATVIAN,        // Latvian
        TD_LNGID_LITHUANIAN,     // Lithuanian
        TD_LNGID_ROMANIAN,       // Romanian
        TD_LNGID_RUSSIAN,        // Russian
        TD_LNGID_SERBIAN,        // Serbian
        TD_LNGID_SLOVAK,         // Slovak
        TD_LNGID_SLOVENIAN,      // Slovenian
        TD_LNGID_UKRAINIAN,      // Ukrainian
        TD_LNGID_HEBREW,         // Hebrew
        TD_LNGID_ARABIC,         // Arabic
        TD_LNGID_FARSI,          // Farsi
        TD_LNGID_HINDI,          // Hindi
        TD_LNGID_URDU,           // Urdu

        // add new language to full set
        /*
        TD_LNGID_AFRIKAANS,      // Afrikaans
        TD_LNGID_BASQUE,         // Basque
        TD_LNGID_BELARUSIAN,     // Belarusian
        TD_LNGID_CATALAN,        // Catalan
        TD_LNGID_FAEROESE,       // Faeroese
        TD_LNGID_FARSI,          // Farsi
        TD_LNGID_GAELIC,         // Gaelic
        TD_LNGID_HINDI,          // Hindi 
        TD_LNGID_ICELANDIC,      // Iceland
        TD_LNGID_JAPANESE,       // Japan
        TD_LNGID_KOREAN,         // Korea
        TD_LNGID_FYROMACEDONIAN, // FYRO Macedonian
        TD_LNGID_MALTESE,        // Maltese
        TD_LNGID_RHAETOROMANIC,  // Rhaeto-Romanic
        TD_LNGID_SAMI,           // Sami
        TD_LNGID_SORBIAN,        // Sorbian
        TD_LNGID_SUTU,           // Sutu
        TD_LNGID_TSONGA,         // Tsonga
        TD_LNGID_TSWANA,         // Tswana
        TD_LNGID_URDU,           // Urdu
        TD_LNGID_URDU,           // Venda
        TD_LNGID_XHOSA,          // Xhosa
        TD_LNGID_YIDDISH,        // Yiddish
        TD_LNGID_ZULU,           // Zulu

        */

        // Add new language ID values above this line
        TD_LNGID_NUM_OF_LANGUAGES, // number of languages with HSC language ID values
        TD_LNGID_INVALID = TD_LNGID_NUM_OF_LANGUAGES,  // invalid language id value
        TD_LNGID_ALL =  TD_LNGID_NUM_OF_LANGUAGES,

        TD_LNGID_AUTOMATIC = 0xF0,    // reserved for automatic language selection setting
        TD_LNGID_UTF8      = 0xF1,    // reserved for UTF8
        TD_LNGID_UCS2      = 0xF2,    // reserved for UNICODE
        TD_LNGID_CURRENT_LANG = 0xFE  // equivalent to 'current language'
    };

    static LanguageId getSystemLanguageId();
    static QString getSystemLanguageCode();
    static QString getSystemLanguageString();
    static QString getLanguageStringByLanguageCode(const QString& langCode);
};

typedef ZLanguage::LanguageId ZLanguageId;
typedef ZLanguageId ZKbLanguageId;

#endif // ZLANGUAGE_H
