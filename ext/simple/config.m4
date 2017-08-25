dnl $Id$
dnl config.m4 for extension simple

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(simple, for simple support,
Make sure that the comment is aligned:
[  --with-simple             Include simple support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(simple, whether to enable simple support,
dnl Make sure that the comment is aligned:
dnl [  --enable-simple           Enable simple support])

if test "$PHP_SIMPLE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-simple -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/simple.h"  # you most likely want to change this
  dnl if test -r $PHP_SIMPLE/$SEARCH_FOR; then # path given as parameter
  dnl   SIMPLE_DIR=$PHP_SIMPLE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for simple files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SIMPLE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SIMPLE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the simple distribution])
  dnl fi

  dnl # --with-simple -> add include path
  dnl PHP_ADD_INCLUDE($SIMPLE_DIR/include)

  dnl # --with-simple -> check for lib and symbol presence
  dnl LIBNAME=simple # you may want to change this
  dnl LIBSYMBOL=simple # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SIMPLE_DIR/$PHP_LIBDIR, SIMPLE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SIMPLELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong simple lib version or lib not found])
  dnl ],[
  dnl   -L$SIMPLE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SIMPLE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(simple, simple.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
