#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "php_lion.h"
#include "lion_book_math.h"
#include "lion_book_interface.h"

zend_class_entry *lion_book_interface_ce;

ZEND_BEGIN_ARG_INFO_EX(lion_book_sayhi_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

zend_function_entry lion_book_interface_methods[] = {
        ZEND_ABSTRACT_ME(lion_book, sayhi,  lion_book_sayhi_arginfo)
        {NULL, NULL, NULL}
};
/* }}} */

/** {{{ YAF_STARTUP_FUNCTION
 */
LION_STARTUP_FUNCTION(book_interface) {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "lion_book_interface", lion_book_interface_methods);
    lion_book_interface_ce = zend_register_internal_interface(&ce);

    //加载其实现类
    LION_STARTUP(book_math);

    return SUCCESS;
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

