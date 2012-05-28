//-------------------------------------------------------------------------------------------------
//
//                            Motorola Confidential Proprietary
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
 * @file ZResource.h
 * @brief classes to use and create resource files
 */

#ifndef Z_RESOURCE_H
#define Z_RESOURCE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>
#include <qpixmap.h>
#include <qarray.h>
#include <qsortedlist.h>


class QFile;
class ZResEntry;
struct ZResHTEntry;
struct ZResStartBlock;


/**
 * Base class for resource readers.  A resource reader is used to get icons
 * and other resources.  Most of the methods of this class are not implemented.
 */

class ZResReader {

  public:

    /**
     * virtual destructor.  Derived classes should reimplement if they have
     * cleanup to do.
     */
    virtual ~ZResReader();
   
    /**
     * return bool indicates whether or not a resource exists
     *
     * @param ID resource ID to lookup (something.g for a graphic, for example)
     *
     * @return if true, the resource will exist, or return false
     *
     */
    virtual bool exists(const QString& ID) const = 0;

    /**
     * get data for a resource.
     *
     * @param ID the resource ID for the resource
     * @param ppOutData out-pointer for the resource data
     * @param pOutLength out-integer for the size in bytes of the data
     * 
     * @note Do not delete/de-allocate the pointer returned from this function.
     *
     */
    virtual bool get(const QString& ID, unsigned char** ppOutData, 
                     int* pOutLength) const = 0;

    /**
     * get the first resource ID in this resource reader
     *
     * @note this function is not thread safe
     * @return first resource ID
     */
    virtual QString getFirstID();

    /**
     * get the next resource ID in this resource reader
     *
     * @note this function is not thread safe
     * @return current resource ID, increments iterator
     */
    virtual QString getNextID();

};

//----------------------------------------------------------------------------
//                            CLASS ZResFileReader
//----------------------------------------------------------------------------

/**
 * The class is to read the resource files which is written by a ZResFileWriter
 *
 * Use ZResFileReader to read QPixmaps or other data from a single resource
 * file.  If you want to use the current application skin (which is made of
 * a number of resource files).
 * 
 * @note you can see what resources are in a resource file by opening the
 * file with a text editor.  The beginning of the file contains an easy
 * readable list of resource names.
 *
 * @see ZSkin
 */

class ZResFileReader : public ZResReader
{
  public:

    /**
     * default constructor
     */
    ZResFileReader();

    /**
     * constructor taking a file name as an argument
     */
    ZResFileReader(const QString& fileName);


    /**
     * destructor
     */
    virtual ~ZResFileReader();

    /**
     * sets the filename for this resource reader.  This causes any previous
     * opened resource file to be closed. 
     *
     * @param fileName the filename to open
     * @return true if the file was successfully opened, otherwise it will be false
     *
     * @note any pointers returned from this object before calling this function
     * should be considered invalid
     */
    bool setFileName(const QString& fileName);

    /**
     * return the filename used by this resource reader
     */
    const QString& fileName() const;

    /**
     * return a value indicating whether or not a given string ID exists
     *
     * @return bool indicating whether or not a resource exists
     */
    virtual bool exists(const QString& ID) const;
    
    /**
     * get data for a resource.
     *
     * @param ID the resource ID for the resource
     * @param ppOutData out-pointer for the resource data
     * @param pOutLength out-integer for the size in bytes of the data
     * 
     * @note Do not delete/de-allocate the pointer returned from this function.
     *
     */
    virtual bool get(const QString& ID, unsigned char** ppOutData, 
                     int* pOutLength) const;

    /**
     * get the first resource ID in this resource reader
     *
     * @note this function is not thread safe
     * @return first resource ID
     */
    virtual QString getFirstID();

    /**
     * get the next resource ID in this resource reader
     *
     * @note this function is not thread safe
     * @return current resource ID, increments iterator
     */
    virtual QString getNextID();


  protected:

    /**
     * init is called by the constructors
     */
    void init(const QString& fileName);

    /**
     * reset resets the object state
     */
    void reset();

    /**
     * load actually loads the resource table
     */
    bool bLoadFailed;
    bool load();

    /**
     * getID return the resource ID for a given hash table
     * entry number
     */
    QString getID(unsigned hashTableEntryNum) const;

    /**
     * returns a pointer to a hashTableEntry for a given ID
     */
    const ZResHTEntry *getHashTableEntry(const QString& ID) const;

    /**
     * returns a pointer to the data at a given file offset
     * returns false if an error occurs.
     */
    bool getDataAtOffset(unsigned offset, 
                         unsigned char **ppOutData, 
                         int *pOutLength) const;

    bool getDataAtOffset(unsigned offset, 
                         QString& resourceFileName, 
                         unsigned char **ppOutData, 
                         int *pOutLength) const;
   
    QString m_fileName;   ///< the name of the resource file

    bool loaded;
    int fd;
    unsigned int fileLength;
    unsigned char *pResources;

    unsigned char *pIDs;
    unsigned hashTableSize;
    ZResHTEntry *pHashTable;
    unsigned char *pData;
    unsigned char *pEnd;

    unsigned currentIteratorEntry;

};


/**
 * class to create a resource file
 */

class ZResFileWriter {

  public:

    /**
     * constructor
     */

    ZResFileWriter();

    /**
     * constructor taking an output file name
     */

    ZResFileWriter(const QString& fileName);

    /**
     * set the output filename
     *
     * @param fileName the name of the file to write
     */

    void setFileName(const QString& fileName);

    /**
     * get the current filename being written to
     *
     * @return reference to the filename being written to
     */

    const QString& fileName() const;

    /**
     * throw away all data and start at the beginning
     */

    void reset();

    /**
     * add a block of data to the resource file
     *
     * @param ID resource ID of data to add
     * @param data QByteArray of the data to add
     */

    void add(const QString& ID, const QByteArray& data);

    /**
     * write the resource file
     *
     * @return true if write succeeded
     */

    bool write();

  protected:

    void init(const QString& fullFileName);

    QString m_fileName;  ///<  file name that we're writing to

    bool createTables();
    bool writeHeader(QFile&);
    bool writeIDs(QFile&);
    bool writeStartBlock(QFile&);
    bool writeHashTable(QFile&);
    bool writeData(QFile&);
    bool deleteTables();

    QSortedList<ZResEntry> list;   ///< list of resources before they're written to disk

    unsigned int hashTableSize;
    ZResHTEntry *hashTable;
    bool hash(const QString& ID, const QByteArray& inData);

    int nextLabelOffset;
    int nextDataOffset;
};

#endif // Z_RESOURCE_H
