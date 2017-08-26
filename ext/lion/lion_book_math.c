#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h" /* for zend_alter_ini_entry */
#include "Zend/zend_interfaces.h" /* for zend_call_method_with_* */

#include "php_lion.h"
#include "lion_book_math.h"
#include "lion_book_interface.h"

zend_class_entry *lion_book_math_ce;

ZEND_BEGIN_ARG_INFO_EX(lion_book_math_sayhi_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()


PHP_METHOD(lion_book_math, sayhi) {
    zval *name;
    if (zend_parse_parameters_throw(ZEND_NUM_ARGS(), "z", &name) == FAILURE) {
        php_error_docref(NULL, E_ERROR, " param must is zval\n");
        return;
    }

    RETVAL_STR(Z_STR_P(name));
}


zend_function_entry lion_book_math_methods[] = {
        PHP_ME(lion_book_math, sayhi, lion_book_math_sayhi_arginfo, ZEND_ACC_PUBLIC)

        {NULL, NULL, NULL}
};

LION_STARTUP_FUNCTION(book_math) {
    zend_class_entry ce;
    //定义父类，最后使用zend_class_implements函数声明它实现的接口
    INIT_CLASS_ENTRY(ce, "lion_book_math", lion_book_math_methods);
    lion_book_math_ce = zend_register_internal_class(&ce TSRMLS_CC);
    zend_class_implements(lion_book_math_ce TSRMLS_CC, 1, lion_book_interface_ce);

    return SUCCESS;
}
