/**
 * @file        error_functions.h
 * @brief       Declaration for the most requested error handling functions.
 */

#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H
/**
 * @fn          void errMsg(const char *format, ...);
 * @brief       Outputs a message to the standard error output device.
 *
 * Outputs the error text corresponding to the current value of the @var errno variable. This
 * text consists of the error name, for example @var EPERM, supplemented with the error description
 * in the form like it is returned by the @fn strerror() function, and then follows the output,
 * formatted according to the arguments passed.
 *
 * Used to determine the type of errors of system calls and library functions.
 *
 * @params      Arguments is the same as in the @fn printf() function + '\n' in the end.
 * @return      Void
 */
void errMsg(const char *format, ...);

/**
 * @def     __GNUC__
 * @brief   These macros are defined that compiler are GNU.
 */
#ifdef __GNUC__
    /**
     * @def     __GNUC__
     * @brief   This macro blocks compiler warnings when using 'gcc -Wall' commands.
     *
     * If appears warning "control reaches the end of non-void function"
     * and control has reached the end of the function that should return a value if we
     * use the following functions for termination of execution of @fn main() or some
     * other function, which should return a value of a certain type (not void).
     */
    #define NORETURN __attribute__ ((__noreturn__))
#else
    #define NORETURN
#endif

/**
 * @fn          void errExit(const char *format, ...) NORETURN ;
 * @brief       Outputs a message to the standard error output device and stops program.
 *
 * Outputs the error text corresponding to the current value of the @var errno variable.
 * And it also stops the execution of the program, either by calling the exit() function, or if the
 * environment variable EF_DUMPCORE contains a non-empty string value by calling the abort() function to
 * create a kernel dump file for use by the debugger
 *
 * Used to determine the type of errors of system calls and library functions.
 *
 * @params      Arguments is the same as in the @fn printf() function + '\n' in the end.
 * @return      Void
 */
void errExit(const char *format, ...) NORETURN ;
/**
 * @fn          void err_exit(const char *format, ...) NORETURN ;
 * @brief       Outputs a message to the standard error output device and stops program.
 *
 * Outputs the error text corresponding to the current value of the @var errno variable.
 * Doesn't reset the standard output before outputting an error message to it.
 * And it also stops the execution of the program, either by calling the _exit() function.
 *
 * Used to determine the type of errors of system calls and library functions.
 *
 * @params      Arguments is the same as in the @fn printf() function + '\n' in the end.
 * @return      Void
 */
void err_exit(const char *format, ...) NORETURN ;
/**
 * @fn          void errExitEN(int errnum, const char *format, ...) NORETURN ;
 * @brief       Outputs a message to the standard error output device and stops program.
 *
 * Outputs the error text corresponding to the current value of the @var errno variable.
 * And it also stops the execution of the program, either by calling the exit() function, or if the
 * environment variable EF_DUMPCORE contains a non-empty string value by calling the abort() function to
 * create a kernel dump file for use by the debugger. Instead of an error message specific
 * to the current errno value, it outputs the text corresponding to the error number (hence the suffix EN)
 * given in the errnum argument.
 *
 * Used to determine the type of errors of system calls and library functions.
 *
 * @params      Arguments is the same as in the @fn printf() function + '\n' in the end.
 * @return      Void
 */
void errExitEN(int errnum, const char *format, ...) NORETURN ;
/**
 * @fn          void fatal(const char *format, ...) NORETURN ;
 * @brief       Used to determine the type of errors of a general nature (errors of library functions that do not set values for errno).
 *
 * Function outputs formatted output to a standard error output device, and then terminates
 * the program using @fn errExit().
 *
 * To identify other types of errors (other than system calls and library functions), the functions are used.
 *
 * @params      Arguments is the same as in the @fn printf() function + '\n' in the end.
 * @return      Void
 */
void fatal(const char *format, ...) NORETURN ;
/**
 * @fn          void usageErr(const char *format, ...) NORETURN ;
 * @brief       Function designed to determine the types of errors when using commandline arguments
 *
 * Outputs the string Usage:, followed by the formatted output to the standard error output device, after
 * which it terminates the execution of the program by calling @fn exit().
 *
 * To identify other types of errors (other than system calls and library functions), the functions are used.
 *
 * @params      Arguments is the same as in the @fn printf() function + '\n' in the end.
 * @return      Void
 */
void usageErr(const char *format, ...) NORETURN ;
/**
 * @fn          void cmdLineErr(const char *format, ...) NORETURN ;
 * @brief       Function designed to determine the types of errors when using commandline arguments
 *
 * Outputs the string Usage:, followed by the formatted output to the standard error output device, after
 * which it terminates the execution of the program by calling @fn exit().
 * It is designed to determine the types of errors in the command-line arguments passed to the program.
 *
 * To identify other types of errors (other than system calls and library functions), the functions are used.
 *
 * @params      Arguments is the same as in the @fn printf() function + '\n' in the end.
 * @return      Void
 */
void cmdLineErr(const char *format, ...) NORETURN ;

#endif
