srcdir = /usr/local/src/php-7.1.4/ext/yaf-3.0.4
builddir = /usr/local/src/php-7.1.4/ext/yaf-3.0.4
top_srcdir = /usr/local/src/php-7.1.4/ext/yaf-3.0.4
top_builddir = /usr/local/src/php-7.1.4/ext/yaf-3.0.4
EGREP = /usr/bin/grep -E
SED = /usr/bin/sed
CONFIGURE_COMMAND = './configure' '--with-php-config=/usr/local/phpdebug/bin/php-config' '--enable-yaf-debug'
CONFIGURE_OPTIONS = '--with-php-config=/usr/local/phpdebug/bin/php-config' '--enable-yaf-debug'
SHLIB_SUFFIX_NAME = dylib
SHLIB_DL_SUFFIX_NAME = so
ZEND_EXT_TYPE = zend_extension
RE2C = exit 0;
AWK = awk
shared_objects_yaf = yaf.lo yaf_application.lo yaf_bootstrap.lo yaf_dispatcher.lo yaf_exception.lo yaf_config.lo configs/yaf_config_ini.lo configs/yaf_config_simple.lo yaf_request.lo requests/yaf_request_http.lo requests/yaf_request_simple.lo yaf_response.lo responses/yaf_response_http.lo responses/yaf_response_cli.lo yaf_view.lo views/yaf_view_interface.lo views/yaf_view_simple.lo yaf_controller.lo yaf_action.lo yaf_router.lo routes/yaf_route_interface.lo routes/yaf_route_static.lo routes/yaf_route_simple.lo routes/yaf_route_supervar.lo routes/yaf_route_regex.lo routes/yaf_route_rewrite.lo routes/yaf_route_map.lo yaf_loader.lo yaf_registry.lo yaf_plugin.lo yaf_session.lo
PHP_PECL_EXTENSION = yaf
PHP_MODULES = $(phplibdir)/yaf.la
PHP_ZEND_EX =
all_targets = $(PHP_MODULES) $(PHP_ZEND_EX)
install_targets = install-modules install-headers
prefix = /usr/local/phpdebug
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr/local/phpdebug
phplibdir = /usr/local/src/php-7.1.4/ext/yaf-3.0.4/modules
phpincludedir = /usr/local/phpdebug/include/php
CC = cc
CFLAGS = -g -O0
CFLAGS_CLEAN = $(CFLAGS)
CPP = cc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS = -g -O0
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /usr/local/phpdebug/lib/php/extensions/debug-non-zts-20160303
PHP_EXECUTABLE = /usr/local/phpdebug/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/usr/local/phpdebug/include/php -I/usr/local/phpdebug/include/php/main -I/usr/local/phpdebug/include/php/TSRM -I/usr/local/phpdebug/include/php/Zend -I/usr/local/phpdebug/include/php/ext -I/usr/local/phpdebug/include/php/ext/date/lib
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/sh
INSTALL_HEADERS =
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

all: $(all_targets) 
	@echo
	@echo "Build complete."
	@echo "Don't forget to run 'make test'."
	@echo

build-modules: $(PHP_MODULES) $(PHP_ZEND_EX)

build-binaries: $(PHP_BINARIES)

libphp$(PHP_MAJOR_VERSION).la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp $@ $(phptempdir)/$@ >/dev/null 2>&1

libs/libphp$(PHP_MAJOR_VERSION).bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp$(PHP_MAJOR_VERSION).so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-binaries: build-binaries $(install_binary_targets)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-headers:
	-@if test "$(INSTALL_HEADERS)"; then \
		for i in `echo $(INSTALL_HEADERS)`; do \
			i=`$(top_srcdir)/build/shtool path -d $$i`; \
			paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
		done; \
		$(mkinstalldirs) $$paths && \
		echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
		for i in `echo $(INSTALL_HEADERS)`; do \
			if test "$(PHP_PECL_EXTENSION)"; then \
				src=`echo $$i | $(SED) -e "s#ext/$(PHP_PECL_EXTENSION)/##g"`; \
			else \
				src=$$i; \
			fi; \
			if test -f "$(top_srcdir)/$$src"; then \
				$(INSTALL_DATA) $(top_srcdir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			elif test -f "$(top_builddir)/$$src"; then \
				$(INSTALL_DATA) $(top_builddir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			else \
				(cd $(top_srcdir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
				cd $(top_builddir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
			fi \
		done; \
	fi

PHP_TEST_SETTINGS = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_TEST_SHARED_EXTENSIONS =  ` \
	if test "x$(PHP_MODULES)" != "x"; then \
		for i in $(PHP_MODULES)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d extension=$$dlname"; \
		done; \
	fi; \
	if test "x$(PHP_ZEND_EX)" != "x"; then \
		for i in $(PHP_ZEND_EX)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d $(ZEND_EXT_TYPE)=$(top_builddir)/modules/$$dlname"; \
		done; \
	fi`
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='

test: all
	@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(top_builddir)/tmp-php.ini; \
		else \
			echo > $(top_builddir)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`$(top_srcdir)/build/shtool path -d $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(top_builddir)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -n -c $(top_builddir)/tmp-php.ini $(PHP_TEST_SETTINGS) $(top_srcdir)/run-tests.php -n -c $(top_builddir)/tmp-php.ini -d extension_dir=$(top_builddir)/modules/ $(PHP_TEST_SHARED_EXTENSIONS) $(TESTS); \
		TEST_RESULT_EXIT_CODE=$$?; \
		rm $(top_builddir)/tmp-php.ini; \
		exit $$TEST_RESULT_EXIT_CODE; \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.gcno -o -name \*.gcda | xargs rm -f
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_MILTER_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*

distclean: clean
	rm -f Makefile config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h main/internal_functions_cli.c main/internal_functions.c stamp-h sapi/apache/libphp$(PHP_MAJOR_VERSION).module sapi/apache_hooks/libphp$(PHP_MAJOR_VERSION).module buildmk.stamp Zend/zend_dtrace_gen.h Zend/zend_dtrace_gen.h.bak Zend/zend_config.h TSRM/tsrm_config.h
	rm -f php7.spec main/build-defs.h scripts/phpize
	rm -f ext/date/lib/timelib_config.h ext/mbstring/oniguruma/config.h ext/mbstring/libmbfl/config.h ext/oci8/oci8_dtrace_gen.h ext/oci8/oci8_dtrace_gen.h.bak
	rm -f scripts/man1/phpize.1 scripts/php-config scripts/man1/php-config.1 sapi/cli/php.1 sapi/cgi/php-cgi.1 ext/phar/phar.1 ext/phar/phar.phar.1
	rm -f sapi/fpm/php-fpm.conf sapi/fpm/init.d.php-fpm sapi/fpm/php-fpm.service sapi/fpm/php-fpm.8 sapi/fpm/status.html
	rm -f ext/iconv/php_have_bsd_iconv.h ext/iconv/php_have_glibc_iconv.h ext/iconv/php_have_ibm_iconv.h ext/iconv/php_have_iconv.h ext/iconv/php_have_libiconv.h ext/iconv/php_iconv_aliased_libiconv.h ext/iconv/php_iconv_supports_errno.h ext/iconv/php_php_iconv_h_path.h ext/iconv/php_php_iconv_impl.h
	rm -f ext/phar/phar.phar ext/phar/phar.php
	if test "$(srcdir)" != "$(builddir)"; then \
	  rm -f ext/phar/phar/phar.inc; \
	fi
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f

prof-gen:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-generate all

prof-clean:
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_MILTER_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*

prof-use:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-use all


.PHONY: all clean install distclean test prof-gen prof-clean prof-use
.NOEXPORT:
yaf.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf.c -o yaf.lo 
yaf_application.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_application.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_application.c -o yaf_application.lo 
yaf_bootstrap.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_bootstrap.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_bootstrap.c -o yaf_bootstrap.lo 
yaf_dispatcher.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_dispatcher.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_dispatcher.c -o yaf_dispatcher.lo 
yaf_exception.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_exception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_exception.c -o yaf_exception.lo 
yaf_config.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_config.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_config.c -o yaf_config.lo 
configs/yaf_config_ini.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/configs/yaf_config_ini.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/configs/yaf_config_ini.c -o configs/yaf_config_ini.lo 
configs/yaf_config_simple.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/configs/yaf_config_simple.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/configs/yaf_config_simple.c -o configs/yaf_config_simple.lo 
yaf_request.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_request.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_request.c -o yaf_request.lo 
requests/yaf_request_http.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/requests/yaf_request_http.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/requests/yaf_request_http.c -o requests/yaf_request_http.lo 
requests/yaf_request_simple.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/requests/yaf_request_simple.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/requests/yaf_request_simple.c -o requests/yaf_request_simple.lo 
yaf_response.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_response.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_response.c -o yaf_response.lo 
responses/yaf_response_http.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/responses/yaf_response_http.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/responses/yaf_response_http.c -o responses/yaf_response_http.lo 
responses/yaf_response_cli.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/responses/yaf_response_cli.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/responses/yaf_response_cli.c -o responses/yaf_response_cli.lo 
yaf_view.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_view.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_view.c -o yaf_view.lo 
views/yaf_view_interface.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/views/yaf_view_interface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/views/yaf_view_interface.c -o views/yaf_view_interface.lo 
views/yaf_view_simple.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/views/yaf_view_simple.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/views/yaf_view_simple.c -o views/yaf_view_simple.lo 
yaf_controller.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_controller.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_controller.c -o yaf_controller.lo 
yaf_action.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_action.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_action.c -o yaf_action.lo 
yaf_router.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_router.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_router.c -o yaf_router.lo 
routes/yaf_route_interface.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_interface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_interface.c -o routes/yaf_route_interface.lo 
routes/yaf_route_static.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_static.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_static.c -o routes/yaf_route_static.lo 
routes/yaf_route_simple.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_simple.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_simple.c -o routes/yaf_route_simple.lo 
routes/yaf_route_supervar.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_supervar.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_supervar.c -o routes/yaf_route_supervar.lo 
routes/yaf_route_regex.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_regex.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_regex.c -o routes/yaf_route_regex.lo 
routes/yaf_route_rewrite.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_rewrite.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_rewrite.c -o routes/yaf_route_rewrite.lo 
routes/yaf_route_map.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_map.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/routes/yaf_route_map.c -o routes/yaf_route_map.lo 
yaf_loader.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_loader.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_loader.c -o yaf_loader.lo 
yaf_registry.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_registry.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_registry.c -o yaf_registry.lo 
yaf_plugin.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_plugin.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_plugin.c -o yaf_plugin.lo 
yaf_session.lo: /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_session.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/usr/local/src/php-7.1.4/ext/yaf-3.0.4 $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /usr/local/src/php-7.1.4/ext/yaf-3.0.4/yaf_session.c -o yaf_session.lo 
$(phplibdir)/yaf.la: ./yaf.la
	$(LIBTOOL) --mode=install cp ./yaf.la $(phplibdir)

./yaf.la: $(shared_objects_yaf) $(YAF_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_yaf) $(YAF_SHARED_LIBADD)

