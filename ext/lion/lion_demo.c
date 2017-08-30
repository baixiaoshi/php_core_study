#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h" /* for zend_alter_ini_entry */
#include "Zend/zend_interfaces.h" /* for zend_call_method_with_* */

#include "php_lion.h"
#include "lion_demo.h"

zend_class_entry *lion_demo_ce;

//这里其实是拼凑一个完整的二维数组来传递多个数组,没错，这里其实就是想初始化数组，真的太他妈的坑爹了啊，
//连这样都可以完成

ZEND_BEGIN_ARG_INFO_EX(lion_demo_void_arginfo, 0, 0, 2)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, age)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(lion_demo_construct_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(lion_demo_hello_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(lion_demo_mydump_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, arr1)
ZEND_END_ARG_INFO()

PHP_METHOD(lion_demo, __construct) {
    php_printf("this is __construct");

    //读取属性呢
    zval *name;
    zval *age;

    zend_class_entry *ce;
    ce = Z_OBJCE_P(getThis());

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &age) == FAILURE) {
        php_error_docref(NULL, E_ERROR, "params is error");
        return ;
    }

    //设置这些值到构造函数
    zend_update_property(ce, getThis(), "name", sizeof("name"), name);
    zend_update_property(ce, getThis(), "age", sizeof("age"), age);



    name = zend_read_property(ce, getThis(), "name", sizeof("name"), 1, NULL);
    
    php_printf("name=%s\n", Z_STRVAL_P(name));

    age = zend_read_property(ce, getThis(), "age", sizeof("age"), 1, NULL);

    php_printf("age=%d\n", Z_LVAL_P(age));
    
}

PHP_METHOD(lion_demo, hello) {
    php_printf("this is hello function\n");
}

PHP_METHOD(lion_demo, mydump) {
    zval *arr1;

    if (zend_parse_parameters_throw(ZEND_NUM_ARGS(), "a", &arr1) == FAILURE) {
        php_error_docref(NULL, E_ERROR, " params arr1 and arr2 must be array\n");
		return;
    }

    ZVAL_UNDEF(arr1);
    RETURN_ARR(Z_ARR_P(arr1));
}


zend_function_entry lion_demo_methods[] = {
        PHP_ME(lion_demo, __construct, lion_demo_construct_arginfo, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_ME(lion_demo, hello, lion_demo_hello_arginfo, ZEND_ACC_PUBLIC)
        PHP_ME(lion_demo, mydump, lion_demo_mydump_arginfo, ZEND_ACC_PUBLIC)
        {NULL, NULL, NULL}
};

LION_STARTUP_FUNCTION(demo) {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "lion_demo", lion_demo_methods);
    lion_demo_ce = zend_register_internal_class(&ce TSRMLS_CC);
    return SUCCESS;
}