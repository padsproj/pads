/* ================================================================================ */
/* XXX THESE ARE REQUIRED FOR CKIT ON REDHAT LINUX 7.3 (AND MAYBE OTHERS) */

#ifdef HAVE_VA_LIST
typedef void * va_list;
#endif


#ifdef __LINUX_PREPROCESSOR_FIXES
typedef void * __builtin_va_list;
#define __THROW
/* extern int ftruncate (int __fd, long int __length) ; */

#endif
