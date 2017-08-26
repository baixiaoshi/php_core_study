/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//引入源码中的头文件
#include "php.h"
#include "php_ini.h"
#include "main/SAPI.h"
#include "Zend/zend_alloc.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "php_lion.h"


ZEND_DECLARE_MODULE_GLOBALS(lion)


/* True global resources - no need for thread safety here */
static int le_lion;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
*/
/* }}} */
PHP_INI_BEGIN()
        STD_PHP_INI_ENTRY("lion.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_lion_globals, lion_globals)
        STD_PHP_INI_ENTRY("lion.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_lion_globals, lion_globals)
PHP_INI_END()


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_lion_compiled(string arg)
   Return a string to confirm that the module is compiled in */

//PHP_FUNCTION(confirm_lion_compiled)
//{
//    char *arg = NULL;
//    size_t arg_len, len;
//    zend_string *strg;
//
//    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
//        return;
//    }
//
//    strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "lion", arg);
//
//    zend_string *teststr = zend_string_init("hello", strlen("hello"), 0);
//    zval *myname;
//    ZVAL_STR(myname, teststr);
//    LION_G(name) = myname;
//
//    LION_G(num) = 100;
//
//    //php_printf("num=%d\n", LION_G(num));
//    //php_printf("name=%s\n", Z_STRVAL_P(LION_G(name)));
//    zend_string_release(teststr);
//
//    //获取配置的默认值
//    const char *default_string = INI_ORIG_STR("lion.global_string");
//    php_printf("default_string=%s\n", default_string);
//    //获取用户定义配置
//    const char *global_string = INI_STR("lion.global_string");
//    php_printf("user_string=%s\n", global_string);
//
//    long default_lval = INI_ORIG_INT("lion.global_value");
//    php_printf("default_lval=%ld\n", default_lval);
//
//    long lval = INI_INT("lion.global_value");
//    php_printf("user_lval=%ld\n", lval);
//
//    php_printf("lion_name=%s,lion_lover=%s\n", LION_NAME, LION_LOVER);
//
//
//    RETURN_STR(strg);
//}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_lion_init_globals
 */
/* Uncomment this function if you have INI entries
 * */
/* }}} */
static void php_lion_init_globals(zend_lion_globals *lion_globals)
{
    lion_globals->global_value = 0;
    lion_globals->global_string = NULL;
}



/* {{{ lion_functions[]
 *
 * Every user visible function must have an entry in lion_functions[].
 */
const zend_function_entry lion_functions[] = {
        //PHP_FE(confirm_lion_compiled,   NULL)       /* For testing, remove later. */
        //PHP_FE_END  /* Must be the last line in lion_functions[] */
        {NULL, NULL, NULL}
};


//register methods

/* }}} */


/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(lion)
{
    /* If you have INI entries, uncomment these lines
     * */
    REGISTER_INI_ENTRIES();
    REGISTER_STRING_CONSTANT("LION_NAME", LION_NAME, CONST_PERSISTENT | CONST_CS);

    LION_STARTUP(demo);
    LION_STARTUP(book_interface);

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(lion)
{
    /* uncomment this line if you have INI entries
     * */
    UNREGISTER_INI_ENTRIES();

    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(lion)
{
#if defined(COMPILE_DL_LION) && defined(ZTS)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(lion)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(lion)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "lion support", "enabled");
    php_info_print_table_end();

    /* Remove comments if you have entries in php.ini
     * */
    DISPLAY_INI_ENTRIES();

}
/* }}} */


/* {{{ lion_module_entry
 */
zend_module_entry lion_module_entry = {
        STANDARD_MODULE_HEADER,
        "lion",
        lion_functions,
        PHP_MINIT(lion),
        PHP_MSHUTDOWN(lion),
        PHP_RINIT(lion),        /* Replace with NULL if there's nothing to do at request start */
        PHP_RSHUTDOWN(lion),    /* Replace with NULL if there's nothing to do at request end */
        PHP_MINFO(lion),
        PHP_LION_VERSION,
        STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LION
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(lion)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
