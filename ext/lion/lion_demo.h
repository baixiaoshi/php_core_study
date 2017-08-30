#ifndef PHP_LION_DEMO_H
#define PHP_LION_DEMO_H

extern zend_class_entry *lion_demo_ce;
extern PHPAPI void php_var_dump(zval **struc, int level);

LION_STARTUP_FUNCTION(demo);
#endif