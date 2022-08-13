/**
 * @file        tlpi_hdr.h
 * @brief       Universal header.
 *
 * This header contains the main #include's for
 * projects from the book.
 *
 */

#ifndef TLPI_HDR_H
#define TLPI_HDR_H

/**
 * @def     #include <sys/types.h>
 * @brief   Defenition of essential types.
 */
#include <sys/types.h>
/**
 * @def     #include <stdio.h>
 * @brief   Standart input-output function.
 */
#include <stdio.h>
/**
 * @def     #include <stdlib.h>
 * @brief   Standart library.
 *
 * Prototypes of the most popular functions,
 * EXIT_SUCCESS and EXIT_FAILURE constants.
 */
#include <stdlib.h>
/**
 * @def     #include <unistd.h>
 * @brief   Prototypes of system calls.
 */
#include <unistd.h>
/**
 * @def     #include <errno.h>
 * @brief   Declaration of errno and defenition error's constants.
 */
#include <errno.h>
/**
 * @def     #include <string.h>
 * @brief   The most used string processing functions.
 */
#include <string.h>
/**
 * @def     #include "get_num.h"
 * @brief   Non-standart file.
 *
 * Declaration of our functions for processing numeric
 * arguments (getInt(), getLong())
 */
// #include "get_num.h"
/**
 * @def     #include "get_num.h"
 * @brief   Non-standart file.
 *
 * Declaration of our error processing functions
 */
#include "error_functions.h"
typedef enum { FALSE, TRUE } Boolean;

/**
 * @def     min(m, n)
 * @brief   Return minimal value from m and n.
 */
#define min(m, n) ((m) < (n) ? (m) : (n))
/**
 * @def     min(m, n)
 * @brief   Return maximum value from m and n.
 */
#define max(m, n) ((m) > (n) ? (m) : (n))

#endif
