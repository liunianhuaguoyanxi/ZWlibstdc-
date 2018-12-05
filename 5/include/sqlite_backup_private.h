//
//  sqlite_backup_private.h
//  SQLite
//

#ifndef sqlite_backup_private_h
#define sqlite_backup_private_h

#include <sqlite3.h>
#include <sqlite3_private.h>

typedef enum {
    /* Library chooses operation type and falls back to more conversative approaches dynamically as needed */
    SQLITE_ARCHIVE_BEST_EFFORT = 0,
    
    /* Create an archive of sql text and compressing it.  If the database cannot be represented this way, fail. */
    SQLITE_ARCHIVE_COMPRESSED_SQLTEXT = 1,
    
    /* Create an archive by dropping the indices, vacuuming, and compressing it.  The SQL to rebuild the indices is inclued in the archive.  If the database cannot be represented this way, fail. */
    SQLITE_ARCHIVE_COMPRESSED_BINARY = 2,
    
    /* Instead of a compressed archive, copy the sqlite database safely. */
    SQLITE_ARCHIVE_FILE_COPY = 3
} sqlite_apple_archive_operation;

typedef enum {
    /* library chooses compression algorithm based on file size, contents, and platform horse power */
    SQLITE_ARCHIVE_COMPRESSION_BEST_EFFORT = 0,
    
    /* any other specific values from <compression.h> compression_algorithm enum like COMPRESSION_LZFSE, COMPRESSION_ZLIB, COMPRESSION_LZMA or */
    
    /* no compression.  currently only used by SQLITE_ARCHIVE_FILE_COPY */
    SQLITE_ARCHIVE_COMPRESSION_NONE = -1
} sqlite_compression_algorithm_extension;

/* enum of possible result for the output parameter for _sqlite3_apple_archive_type() */
typedef enum {
    SQLITE_ARCHIVE_TYPE_ERROR = -1,
    SQLITE_ARCHIVE_TYPE_UNKNOWN = 0,
    SQLITE_ARCHIVE_TYPE_NOTADB = 1,
    SQLITE_ARCHIVE_TYPE_ENCRYPTED = 2,
    SQLITE_ARCHIVE_TYPE_DATABASE_FILE = 3,
    SQLITE_ARCHIVE_TYPE_SQLTEXT_ARCHIVE = 4,
    SQLITE_ARCHIVE_TYPE_BINARY_ARCHIVE = 5
} sqlite_archive_file_type;


/* return 0 on success and populates outputType.  return non-zero errno on failure and populates errorMessage if non-null, which must be freed with sqlite3_free() */
SQLITE_EXPERIMENTAL int _sqlite3_apple_archive_type(const char* sourceDatabasePath, sqlite_archive_file_type* outputType, char** errorMessage);


/* return 0 on success and populates outputFilePaths with an array of file paths.  This value should be cast to void* and freed with sqlite3_free() when done (not the individual components).  Return non-zero errno on failure and populates errorMessage if non-null, which must be freed with sqlite3_free() */
SQLITE_EXPERIMENTAL int _sqlite3_apple_archive(
    const char* sourceDatabasePath,
    const char* destinationArchivePathBasename,
    int additionalSQLOpenFlags, /* any additional flags to pass to sqlite3_open_v2, like data protection class */
    sqlite_apple_archive_operation operationType,
    int compressionMethod, /* a sqlite_compression_algorithm_extension or compression_algorithm enum value */
    int sourceIsLive, /* should be set to true unless the source is in an immutable mount/snapshot or definitely cannot be in use */
    char*** outputFilePaths, /* a pointer to a char** which will be set to the array of output file paths.  the array will be NULL terminated and must be freed with sqlite3_free().  the individual elements do not need to be freed. */
    char** errorMessage /* if set, an error message which should be free with sqlite3_free() */
);


/* return 0 on success and populates outputFilePaths with an array of file paths.  This value should be cast to void* and freed with sqlite3_free() when done (not the individual components).  Return non-zero errno on failure and populates errorMessage if non-null, which must be freed with sqlite3_free() */
SQLITE_EXPERIMENTAL int _sqlite3_apple_unarchive(
    const char* sourceArchivePath,
    const char* destinationDatabasePath,
    int additionalSQLOpenFlags, /* any additional flags to pass to sqlite3_open_v2, like data protection class */
    int destinationIsLive,  /* should be set to true unless the destination definitely cannot be in use */
    char*** outputFilePaths, /* a pointer to a char** which will be set to the array of output file paths.  the array will be NULL terminated and must be freed with sqlite3_free().  the individual elements do not need to be freed. */
    char** errorMessage /* if set, an error message which should be free with sqlite3_free() */
);


#endif /* sqlite_backup_private_h */

